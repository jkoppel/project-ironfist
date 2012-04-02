/*
 * Copyright 2011 James Koppel
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

import java.io.*;
    
public class AggExtract {

    private static class FileInfo {
	public int hash;
	public int offset;
	public int size;
	public File file;
	
    }
    
    public static void main(String[] args) {
	if(args.length != 1) {
	    System.out.println("agg_extract extracts all files from Heroes of Might and Magic II aggregate (.agg) archives");
	    System.out.println("into a new subdirectory of the current directory");
	    System.out.println("Usage: java AggExtract filename");
	    return;
	}

	DataInputStream agg = null;
	OutputStream curOut = null;
	
	try {
	    
	    agg = new DataInputStream(new BufferedInputStream(new FileInputStream(args[0])));

	    String aggname = new File(args[0]).getName(); 
	    
	    String dirname = aggname.substring(0, aggname.indexOf("."));
	    File dir = new File(dirname);
	    if(!dir.mkdir())) {
		throw new IOException("Could not create directory");
	    }
	    
	    short nofiles = toBigEndian(agg.readShort());
	    FileInfo[] files = new FileInfo[nofiles];

	    for(int i = 0; i < nofiles; i++) {
		files[i] = new FileInfo();
		files[i].hash = toBigEndian(agg.readInt());
		files[i].offset = toBigEndian(agg.readInt());
		files[i].size = toBigEndian(agg.readInt());
		files[i].file = File.createTempFile(Integer.toString(i), "", dir);
	    }

	    for(int i = 0; i < nofiles; i++) {
		curOut = new BufferedOutputStream(new FileOutputStream(files[i].file));
		byte[] contents = new byte[files[i].size];
		int n = agg.read(contents);

		if(n != files[i].size) {
		    throw new IOException("Unexpected EOF");
		}

		curOut.write(contents);
		curOut.close();
		curOut = null;
	    }

	    
	    byte[] buf = new byte[15];
				       
	    for(int i = 0; i < nofiles; i++) {
		if(agg.read(buf) != 15) {
		    throw new IOException("Unexpected EOF");
		}
		String name = new String(buf);
		files[i].file.renameTo(new File(dirname+"/"+name));
	    }
	    
	} catch(IOException e) {
	    System.err.println("An unexpected error occured when reading or writing files.");
	    e.printStackTrace();
	} finally {
	    try {
		if(agg != null)
		    agg.close();
		if(curOut != null)
		    curOut.close();
	    } catch(IOException e) {
		System.err.println("Failed to properly close files");
	    }
	}
    }

    private static short toBigEndian(short s) {
	int a = 0xFF & s;
	int b = 0xFF & ( s >>> 8);
	return (short)((a<<8) | b);
    }

    private static int toBigEndian(int n) {
	return (n<<24) | ((n & 0xFF00) << 8) | ((n>>>8) & 0xFF00) | (n >>> 24);
    }
}