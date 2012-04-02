import java.awt.Color;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.*;

import javax.imageio.ImageIO;


public class ICNWriter {
    static class icn_header {
        short offX;
        short offY;
        short w;
        short h;
        char ignore; /* =0 */
        int pos;
    }

    static Map<Integer,Byte> palette = new HashMap<Integer,Byte>();

    private static Byte getColor(Map<Integer,Byte> pal, int c) {
        if(c==0) //black
            return 36;
        if(pal.containsKey(c))
            return pal.get(c);
        
        int red = (c>>16)&0xFF;
        int green = (c>>8)&0xFF;
        int blue = (c>>0)&0xFF;

        int minDist = 1000000000;
        byte best = 0;

        for(int x : pal.keySet()) {
            int xred = (x>>16)&0xFF;
            int xgreen = (x>>8)&0xFF;
            int xblue = (x>>0)&0xFF;

            int d =
                (red-xred)*(red-xred)+
                (green-xgreen)*(green-xgreen)+
                (blue-xblue)*(blue-xblue);

            if(d<minDist) {
                minDist = d;
                best = pal.get(x);
            }
        }
        
        return best;
    }
    
    static List<Byte> L = new ArrayList<Byte>();
    static icn_header[] headers;

    private static void dump(List<Byte> bytes) {
        if(bytes.size() == 0)
            return;
        L.add((byte)bytes.size());
        L.addAll(bytes);
        bytes.clear();
    }

    public static void main(String[] args) {
        if(args.length < 1) {
            System.out.println("Usage: directory [palette = KB.PAL] [background = 00000000");
            System.exit(-1);
        }

        String pal_file = args.length >=2 ? args[1] : "KB.PAL";
        int background = args.length >= 3 ? (int)Long.parseLong(args[2],16) : 0x00000000;
        FileInputStream pal = null;
        try { pal = new FileInputStream(new File(pal_file)); }
        catch(IOException e) {
            System.out.printf("Couldn't open %s\n", pal_file);
            System.exit(-4);
        }
        byte color[] = new byte[3];
        byte color_index = 0;
        try {
            while(pal.read(color) >= 0) {
                /* The bit shifts are off by 2 because all values were divided by 4 */
                            /* R                G            B */
                int rgb = ((color[0]<<18) + (color[1]<<10) + (color[2]<<2));
                palette.put(rgb, color_index);
                color_index++;
            }
        }
        catch(IOException e) {
            System.out.printf("Error in reading colors from %s\n", pal_file);
            System.exit(-5);
        }

        File dir = new File(args[0]);
        if(!dir.isDirectory()) {
            System.out.println("Argument must be a directory");
            System.exit(-2);
        }

        int ix = -1;
        BufferedImage img = null;
        File[] files = dir.listFiles();
        headers = new icn_header[files.length];
        for(File png:files) {
            ix++;
            headers[ix] = new icn_header();
            try {
                img = ImageIO.read(png);
            } catch (IOException e) {
                System.out.printf("Couldn't read %s as an image\n", png.toString());
                System.exit(-3);
            }

            headers[ix].offX = -25;
            headers[ix].offY = -64;
            headers[ix].ignore = (char)0;
            headers[ix].h = (short)img.getHeight();
            headers[ix].w = (short)img.getWidth();
            int w = headers[ix].w;
            int h = headers[ix].h;
            headers[ix].pos = L.size();

            for(int y=0; y<h; y++) {
                List<Byte> curL = new ArrayList<Byte>();
                for(int x=0; x<w; x++) { // Write byte-by-byte, not compressed at all
                    if(curL.size() == 127)
                        dump(curL);
                    int pixel = img.getRGB(x,y);

                    int alpha = (pixel >> 24) & 0xff;
                    int red   = (pixel >> 16) & 0xff;
                    int green = (pixel >>  8) & 0xff;
                    int blue  = (pixel      ) & 0xff;

                    if(alpha == 0 || pixel == background) { // Transparent
                        dump(curL);
                        L.add((byte)0x81); // One transparent byte
                        continue;
                    }
                    if(alpha == 0x40) { // Shadow
                        dump(curL);
                        L.add((byte)0xC0);
                        L.add((byte)0x01);
                    }

                    int rgb = blue + (green<<8) + (red<<16);
                    //System.err.printf("%x %d %d\n", rgb, getColor(palette, rgb), alpha);
                    curL.add(getColor(palette, rgb));
                }
                dump(curL);
                if(y==h-1)
                    L.add((byte)0x80); //end of file
                else
                    L.add((byte)0x00); // end-of-line byte
            }
        }
        ix++;

        for(int i = 0; i < ix; i++) {
            headers[i].pos += 13*ix;
        }

        write_short(ix); //How many
         write_int(L.size()+ix*13); //Total size in bytes of the output
         for(int i=0; i<ix; i++)
             write_header(headers[i]);
         for(int i=0; i<L.size(); i++) {
             System.out.write(L.get(i));
             }
         System.out.flush();
    }
    public static void write_header(icn_header h) {
        write_short(h.offX);
        write_short(h.offY);
        write_short(h.w);
        write_short(h.h);
        System.out.write(h.ignore);
        write_int(h.pos);
    }
    public static void write_short(int n) {
        System.out.write(n&0xFF);
        System.out.write( (n>>8)&0xFF );
    }
    public static void write_int(int n) {
        write_short(n&0xFFFF);
        write_short((n>>16)&0xFFFF);
    }
}
/*
   The palette file contains 768 bytes, a sequence of 256 colors in RGB
format, except that, for some reason, the values are all divided by 4.
   Some of the indices are special and reserved for palette swapping stuff,
but that shouldn't concern you --
           except when finding the index for pure black (RGB #000000). The
first and last 10 colors are all black; don't use those.

    DATA SECTION VALUES: for each byte, check against
     the large list
    = 0x00
     -> end of horizontal line (can only set pixels in horizontal
     lines)

    < 0x80 -> set next (this byte) pixels to palette[bytes after this one]
      [ex: [0x04 0x00 0x01 0x02 0x03] means set the next four pixels to
      the colors pal(0x00) pal(0x01) pal(0x02) pal(0x03)]

    = 0x80 -> end of data, stop reading

    > 0x80 & < 0xC0 -> skip ((this byte) - 0x80) horizontal pixels
      (i.e. fully transparent)

    = 0xC0 -> special (labeled 'seek', used for shadow)
      s(byte)'s last two bits (byte % 4) == 0?
      yes -> ignore s(byte), set next (s(s(byte))) horizontal pixels to
shadow
        [0xC0 0b??????00 0xZZ] -> set next 0xZZ pixels to shadow
      no -> set next (s(byte) % 4) horizontal pixels to shadow
        [0xC0 0b??????zz] -> set next 0bzz pixels to shadow

    = 0xC1 -> set the next s(byte) pixels to pal[s(s(byte))]
      [ex: 0xC1 0x05 0xAA means set the next 5 pixels to the color
pal[0xAA]]

    >
     0xC1 -> set the next (s(byte)-0xC0) pixels to pal[s(s(byte))]
*/