#ifndef SMACKER_H
#define SMACKER_H

#pragma pack(push, 1)

struct SSmackOptions {
  char name[9];
  char name2[9];
  char slowName[9];
  char slowName2[9];
  char fadeFlag;
  char flag2;
  char flag3;
  char flag4;
  char flag5;
  short offsetX;
  short offsetY;
};

struct SmackTag {
  unsigned Version;           // SMK2 only right now
  unsigned Width;             // Width (1 based, 640 for example)
  unsigned Height;            // Height (1 based, 480 for example)
  unsigned Frames;            // Number of frames (1 based, 100 = 100 frames)
  unsigned MSPerFrame;        // Frame Rate
  unsigned SmackerType;       // bit 0 set=ring frame
  unsigned LargestInTrack[7]; // Largest single size for each track
  unsigned tablesize;         // Size of the init tables
  unsigned codesize;          // Compression info   
  unsigned absize;            // ditto
  unsigned detailsize;        // ditto
  unsigned typesize;          // ditto
  unsigned TrackType[7];      // high byte=0x80-Comp,0x40-PCM data,0x20-16 bit,0x10-stereo
  unsigned extra;             // extra value (should be zero)
  unsigned NewPalette;        // set to one if the palette changed
  unsigned char Palette[772]; // palette data
  unsigned PalType;           // type of palette
  unsigned FrameNum;          // Frame Number to be displayed
  unsigned FrameSize;         // The current frame's size in bytes
  unsigned SndSize;           // The current frame sound tracks' size in bytes
  int LastRectx;              // Rect set in from SmackToBufferRect (X coord)
  int LastRecty;              // Rect set in from SmackToBufferRect (Y coord)
  int LastRectw;              // Rect set in from SmackToBufferRect (Width)
  int LastRecth;              // Rect set in from SmackToBufferRect (Height)
  unsigned OpenFlags;         // flags used on open
  unsigned LeftOfs;           // Left Offset used in SmackTo
  unsigned TopOfs;            // Top Offset used in SmackTo
  unsigned LargestFrameSize;  // Largest frame size
  unsigned Highest1SecRate;   // Highest 1 sec data rate
  unsigned Highest1SecFrame;  // Highest 1 sec data rate starting frame
  unsigned ReadError;         // Set to non-zero if a read error has ocurred
  unsigned addr32;            // translated address for 16 bit interface
};

#pragma pack(pop)

extern void __fastcall ConvertSmackerPalette(unsigned char *);
extern void __fastcall UpdatePalette(signed char *);
extern void __fastcall DoAdvance(struct SmackTag *,int,int,int,int);
extern struct SmackSumTag smksum;

extern SSmackOptions SmackOptions[73];
extern SmackTag* smk1;
extern SmackTag* smk2;
extern int bSmackSound;
extern signed char bSmackNum;

#endif