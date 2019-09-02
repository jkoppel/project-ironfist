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

extern int __fastcall PlaySmacker_orig(int smkID);
extern int __fastcall PlaySmacker(int smkID);
extern void __fastcall ConvertSmackerPalette(unsigned char *);
extern void __fastcall UpdatePalette(signed char *);
extern void __fastcall DoAdvance(struct SmackTag *,int,int,int,int);
extern struct SmackSumTag smksum;

extern SSmackOptions SmackOptions[73];
extern SmackTag* smk1;
extern SmackTag* smk2;
extern int bSmackSound;
extern signed char bSmackNum;

enum SMACKER_VIDEOS {
  SMACKER_LOGO_HEROES = 0,
  SMACKER_LOGO_CYBERLORE = 1,
  SMACKER_WIN = 2,
  SMACKER_LOSE = 3,
  SMACKER_ORIG_CAMPAIGN_MAIN_INTRO = 4,
  SMACKER_ORIG_CAMPAIGN_ROLAND_INTRO = 5,
  SMACKER_ORIG_CAMPAIGN_ROLAND_1 = 6,
  SMACKER_ORIG_CAMPAIGN_ROLAND_2 = 7,
  SMACKER_ORIG_CAMPAIGN_ROLAND_3 = 8,
  SMACKER_ORIG_CAMPAIGN_ROLAND_4 = 9,
  SMACKER_ORIG_CAMPAIGN_ROLAND_5 = 10,
  SMACKER_ORIG_CAMPAIGN_ROLAND_6 = 11,
  SMACKER_ORIG_CAMPAIGN_ROLAND_7 = 12,
  SMACKER_ORIG_CAMPAIGN_ROLAND_8 = 13,
  SMACKER_ORIG_CAMPAIGN_ROLAND_9 = 14,
  SMACKER_ORIG_CAMPAIGN_ROLAND_10 = 15,
  SMACKER_ORIG_CAMPAIGN_ROLAND_11 = 16,
  SMACKER_ORIG_CAMPAIGN_ROLAND_12 = 17,
  SMACKER_LIBRARY = 18,
  SMACKER_ORIG_CAMPAIGN_ARCHIBALD_INTRO = 19,
  SMACKER_ORIG_CAMPAIGN_ARCHIBALD_1 = 20,
  SMACKER_ORIG_CAMPAIGN_ARCHIBALD_2 = 21,
  SMACKER_ORIG_CAMPAIGN_ARCHIBALD_3 = 22,
  SMACKER_ORIG_CAMPAIGN_ARCHIBALD_4 = 23,
  SMACKER_ORIG_CAMPAIGN_ARCHIBALD_5 = 24,
  SMACKER_ORIG_CAMPAIGN_ARCHIBALD_6 = 25,
  SMACKER_ORIG_CAMPAIGN_ARCHIBALD_7 = 26,
  SMACKER_ORIG_CAMPAIGN_ARCHIBALD_8 = 27,
  SMACKER_ORIG_CAMPAIGN_ARCHIBALD_9 = 28,
  SMACKER_ORIG_CAMPAIGN_ARCHIBALD_10 = 29,
  SMACKER_ORIG_CAMPAIGN_ARCHIBALD_11 = 30,
  SMACKER_ORIG_CAMPAIGN_ARCHIBALD_12 = 31,
  SMACKER_ORIG_CAMPAIGN_ARCHIBALD_13 = 32,
  SMACKER_ORIG_CAMPAIGN_ARCHIBALD_14 = 33,
  SMACKER_PRISON = 34,
  SMACKER_ORIG_CAMPAIGN_SELECTION = 35,
  SMACKER_CREDITS = 36,
  SMACKER_EARTH = 37,
  SMACKER_MM6 = 38,
  SMACKER_XCAMPAIGN_PRICE_OF_LOALTY_INTRO = 39,
  SMACKER_XCAMPAIGN_PRICE_OF_LOALTY_1 = 40,
  SMACKER_XCAMPAIGN_PRICE_OF_LOALTY_2 = 41,
  SMACKER_XCAMPAIGN_PRICE_OF_LOALTY_3 = 42,
  SMACKER_XCAMPAIGN_PRICE_OF_LOALTY_4 = 43,
  SMACKER_XCAMPAIGN_PRICE_OF_LOALTY_5 = 44,
  SMACKER_XCAMPAIGN_PRICE_OF_LOALTY_6 = 45,
  SMACKER_XCAMPAIGN_PRICE_OF_LOALTY_7 = 46,
  SMACKER_XCAMPAIGN_DESCENDANTS_INTRO = 47,
  SMACKER_XCAMPAIGN_DESCENDANTS_1 = 48,
  SMACKER_XCAMPAIGN_DESCENDANTS_2 = 49,
  SMACKER_XCAMPAIGN_DESCENDANTS_3 = 50,
  SMACKER_XCAMPAIGN_DESCENDANTS_4 = 51,
  SMACKER_XCAMPAIGN_DESCENDANTS_5 = 52,
  SMACKER_XCAMPAIGN_DESCENDANTS_6 = 53,
  SMACKER_XCAMPAIGN_WIZARDS_ISLE_INTRO = 54,
  SMACKER_XCAMPAIGN_WIZARDS_ISLE_1 = 55,
  SMACKER_XCAMPAIGN_WIZARDS_ISLE_2 = 56,
  SMACKER_XCAMPAIGN_WIZARDS_ISLE_3 = 57,
  SMACKER_XCAMPAIGN_WIZARDS_ISLE_4 = 58,
  SMACKER_XCAMPAIGN_VOYAGE_HOME_INTRO = 59,
  SMACKER_XCAMPAIGN_VOYAGE_HOME_1 = 60,
  SMACKER_XCAMPAIGN_VOYAGE_HOME_2 = 61,
  SMACKER_XCAMPAIGN_VOYAGE_HOME_3 = 62,
  SMACKER_XCAMPAIGN_VOYAGE_HOME_4 = 63,
  SMACKER_DEFEAT = 64,
  SMACKER_LOGO_HEROES_EXPANSION = 65,
  SMACKER_LOGO_NWC = 66,
  SMACKER_XCAMPAIGN_SELECTION = 67,
  SMACKER_XCAMPAIGN_PREVIEW_PRICE_OF_LOALTY = 68,
  SMACKER_XCAMPAIGN_PREVIEW_DESCENDANTS = 69,
  SMACKER_XCAMPAIGN_PREVIEW_WIZARDS_ISLE = 70,
  SMACKER_XCAMPAIGN_PREVIEW_VOYAGE_HOME = 71,
  SMACKER_CREDITS_CYBERLORE = 72
};
#endif