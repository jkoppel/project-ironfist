
        ************************** Contents ****************************************

Included are Java source code for creating and expanding the AGG ("Aggregate") files used with Heroes of Might and Magic II.

        ************************** Usage   *****************************************

To compile both programs:

     $javac Agg.java
     $javac AggExtract.java

To extract files from an AGG into a new directory:

      $java AggExtract file_name

To aggregate files from a directory into a new AGG file:

      $java Agg directory_name

        ************************** License *****************************************

This code is released under the Apache License, Version 2.0.


        ******************* Specification of AGG Files ****************************


Aggregate files consist of the binary contents of various files concatenated together uncompressed, with a small amount of metadata.

Format for AGG files:

First two bytes: Little endian 16-bit integer describing number of files contained (henceforth, "n")

Next 12n bytes: A 12-byte FileInfo structure for every file consisting of three little-endian 32-bit integers: a file ID (see below), an offset o, and a size s. Bytes in the range [o,o+s-1] will contain the binary contents of the corresponding file.

Next arbitrary number of bytes: A concatenation of the binary contents of all files in the AGG.

Final 15n bytes: For every file, a 13-character (including trailing null) DOS-compatible filename, followed by two padding characters. The ith file here gives the filename of the ith file in the array of FileInfo's included at the beginning.


A file's ID is a 32-bit hash of its filename computed by the following C function or equivalent:

    int hash(char* filename) {
      unsigned int a = 0;
      int b = 0;
      for(int i = strlen(filename)-1; i>=0; i--)
       char c = toupper(filename[i]);
       a=(a<<5)+(a>>25);
       b+=c;
       a+=b+c;
      }
      return a;
    }
