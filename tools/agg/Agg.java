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

public class Agg {

    private static class FileInfo {
	public int hash;
	public int offset;
	public int size;
	public File file;
	
    }
    
    public static int hash(String filename) {
	filename = filename.toUpperCase();
        int a = 0;
	int b = 0;
	for(int i = filename.length()-1; i>=0; i--) {
	    int c = (int)filename.charAt(i);
	    a=(a<<5)+(a>>>25);
	    b+=c;
	    a+=b+c;
	}
	return a;
    }

    private static short toLittleEndian(short s) {
	int a = 0xFF & s;
	int b = 0xFF & ( s >>> 8);
	return (short)((a<<8) | b);
    }

    private static int toLittleEndian(int n) {
	return (n<<24) | ((n & 0xFF00) << 8) | ((n>>>8) & 0xFF00) | (n >>> 24);
    }

    public static void main(String[] args) {
	if(args.length != 1) {
	    System.out.println("agg combines all files in a directory into a HoMM II aggregate (.agg) file");
	    System.out.println("Usage: java Agg dir_name");
	    return;
	}

	DataOutputStream agg = null;
	InputStream curIn = null;
	
	try {
	    
	    File dir = new File(args[0]);
	    File[] files = dir.listFiles();
	    
	    FileInfo[] fileInfos = new FileInfo[files.length];
	    
	    for(int i = 0; i < files.length; i++) {

		if(files[i].getName().length() > 12) {
		    System.err.println("Files in AGGs cannot be longer than 12 characters");
		    System.err.println("Offender: "+files[i].getName());
		}
		
		fileInfos[i] = new FileInfo();
		fileInfos[i].hash = hash(files[i].getName());
		fileInfos[i].file = files[i];
		fileInfos[i].size = (int)files[i].length();
	    }

	    int offset = 2+12*files.length;
	    for(int i = 0; i < files.length; i++) {
		fileInfos[i].offset = offset;
		offset += fileInfos[i].size;
	    }

	    
	    
	    String dirname = dir.getName();
	    File aggfile = new File(dirname+".agg");
	    agg = new DataOutputStream(new BufferedOutputStream(new FileOutputStream(aggfile)));

	    agg.writeShort(toLittleEndian((short)files.length));

	    for(int i = 0; i < files.length; i++) {
		agg.writeInt(toLittleEndian(fileInfos[i].hash));
		agg.writeInt(toLittleEndian(fileInfos[i].offset));
		agg.writeInt(toLittleEndian(fileInfos[i].size));
	    }

	    for(int i = 0; i < files.length; i++) {
		curIn = new BufferedInputStream(new FileInputStream(fileInfos[i].file));
		byte[] buf = new byte[(int)fileInfos[i].file.length()];
		
		if(curIn.read(buf) != fileInfos[i].file.length()) {
		    throw new IOException("Unexpected EOF");
		}
		
		agg.write(buf);

		curIn.close();
		curIn = null;
	    }
	    
	    for(int i = 0; i < files.length; i++) {
		for(int j = 0; j < 15; j++) {
		    if(j < files[i].getName().length())
			agg.write(files[i].getName().charAt(j));
		    else
			agg.write(0);
		}
	    }
	    
	} catch(IOException e) {
	    System.err.println("An unexpected error occured when reading or writing files.");
	    e.printStackTrace();
	} finally {
	    try {
		if(agg != null)
		    agg.close();
		if(curIn != null)
		    curIn.close();
	    } catch(IOException e) {
		System.err.println("Failed to properly close files");
	    }
	}
    }
}