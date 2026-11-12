#ifndef _LIBRAC3_MUSIC_H_
#define _LIBRAC3_MUSIC_H_

#include <tamtypes.h>

#if defined(RAC3_NTSCJ) || defined(UYA_NTSCJ)
#define MUSIC_LEVEL_ADDRESS (0x1de75c)
#define MUSIC_STREAM_ADDRESS (0x1d62ac)
#define MUSIC_TABLE_ADDRESS (0x1718d8)
#define MUSIC_SECTOR_ADDRESS (0x1718d4)
#define MUSIC_COMMAND_ADDRESS (0x13c518)
#define MUSIC_COMMAND_HOOK (0x13cb68)
#define MUSIC_READ_WAD_ADDRESS (0x13d230)
#else
#define MUSIC_LEVEL_ADDRESS (0x1d545c)
#define MUSIC_STREAM_ADDRESS (0x1cd014)
#define MUSIC_TABLE_ADDRESS (0x168648)
#define MUSIC_SECTOR_ADDRESS (0x168644)
#define MUSIC_COMMAND_ADDRESS (0x13c578)
#define MUSIC_COMMAND_HOOK (0x13cbc8)
#define MUSIC_READ_WAD_ADDRESS (0x13d290)
#endif

typedef struct musicStream {
	/* 0x00 */ u32 handle;
	/* 0x04 */ s16 track;
	/* 0x06 */ s16 volume;
	/* 0x08 */ s16 flags;
	/* 0x0a */ s16 status;
	/* 0x0c */ s16 pause;
	/* 0x0e */ s16 unpause;
	/* 0x10 */ s16 transition;
	/* 0x12 */ s16 fade;
	/* 0x14 */ int queueLength;
	/* 0x18 */ int remaining;
	/* 0x1c */ void* moby;
	/* 0x20 */ int channel;
	/* 0x24 */ int timer;
} musicStream_t;

u32 musicGetPlayAddress(void);
int musicGetLevel(void);
musicStream_t* musicGetStream(void);
const u32* musicGetTable(void);
u32 musicGetSector(void);

#endif
