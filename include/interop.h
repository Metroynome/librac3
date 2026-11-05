/***************************************************
 * FILENAME :		interop.h
 * DESCRIPTION :
 * 		Provides tools to define and reference/invoke addresses in memory by map.
 * NOTES :
 * AUTHOR :			
 */

#ifndef _LIBRAC3_INTEROP_H_
#define _LIBRAC3_INTEROP_H_

#include <tamtypes.h>

typedef struct VariableAddress {
	u32 Veldin;
	u32 Florana;
	u32 Starship1;
	u32 Marcadia;
	u32 Daxx;
	u32 Starship2;
	u32 AnniNation;
	u32 Aquatos;
	u32 Tyhrranosis;
	u32 Zeldrin;
	u32 ObaniMoons;
	u32 Rilgar;
	u32 Holostar1;
	u32 Koros;
	u32 Kerwan;
	u32 CrashSite;
	u32 Aridia;
	u32 Thran;
	u32 FinalBoss;
	u32 ObaniDraco;
	u32 Mylon;
	u32 HolostarClank;
	u32 Museum;
	u32 KerwanRanger;
	u32 AquatosBase;
	u32 AquatosSewers;
	u32 Ranger2;
	u32 VidComic0;
	u32 VidComic1;
	u32 VidComic4;
	u32 VidComic2;
	u32 VidComic3;
	u32 VidComic5;
	u32 VidComic6;
} VariableAddress_t;

/* The first word tags the layout: BASE selects the fixed map base,
 * CUSTOM_BASE selects an explicit Base followed by offsets for every map.
 * Lobby/MainMenu, when present, is an ordinary address at byte 4.
 * Full tables keep their original layout. Rebuild unpublished compact users.
 * Offsets are signed words biased by 0x8000; zero means unavailable.
 */
#define RAC3_VA_COMPACT_BASE(address) ((u32)(address) | (u32)0x80000000)
#define RAC3_VA_COMPACT_CUSTOM_BASE(address) ((u32)(address) | (u32)0xc0000000)
#define RAC3_VA_COMPACT_OFFSET(base, address) ((address) == 0 ? 0 : \
	(u16)(((s32)(address) - (s32)(base)) / 4 + 0x8000 + \
	0 * sizeof(char[((address) == 0 || (((s32)(address) - (s32)(base)) % 4 == 0 && \
	((s32)(address) - (s32)(base)) / 4 >= -32767 && \
	((s32)(address) - (s32)(base)) / 4 <= 32767)) ? 1 : -1])))

typedef struct rac3VariableAddressCompact {
	/* 0x00 */ u32 Veldin;
	/* 0x04 */ u16 Florana;
	/* 0x06 */ u16 Starship1;
	/* 0x08 */ u16 Marcadia;
	/* 0x0a */ u16 Daxx;
	/* 0x0c */ u16 Starship2;
	/* 0x0e */ u16 AnniNation;
	/* 0x10 */ u16 Aquatos;
	/* 0x12 */ u16 Tyhrranosis;
	/* 0x14 */ u16 Zeldrin;
	/* 0x16 */ u16 ObaniMoons;
	/* 0x18 */ u16 Rilgar;
	/* 0x1a */ u16 Holostar1;
	/* 0x1c */ u16 Koros;
	/* 0x1e */ u16 Kerwan;
	/* 0x20 */ u16 CrashSite;
	/* 0x22 */ u16 Aridia;
	/* 0x24 */ u16 Thran;
	/* 0x26 */ u16 FinalBoss;
	/* 0x28 */ u16 ObaniDraco;
	/* 0x2a */ u16 Mylon;
	/* 0x2c */ u16 HolostarClank;
	/* 0x2e */ u16 Museum;
	/* 0x30 */ u16 KerwanRanger;
	/* 0x32 */ u16 AquatosBase;
	/* 0x34 */ u16 AquatosSewers;
	/* 0x36 */ u16 Ranger2;
	/* 0x38 */ u16 VidComic0;
	/* 0x3a */ u16 VidComic1;
	/* 0x3c */ u16 VidComic4;
	/* 0x3e */ u16 VidComic2;
	/* 0x40 */ u16 VidComic3;
	/* 0x42 */ u16 VidComic5;
	/* 0x44 */ u16 VidComic6;
	/* 0x46: two bytes of EE alignment padding. */
} rac3VariableAddressCompact_t;

typedef struct rac3VariableAddressCompactBase {
	/* 0x00 */ u32 Base;
	/* 0x04 */ u16 Veldin;
	/* 0x06 */ u16 Florana;
	/* 0x08 */ u16 Starship1;
	/* 0x0a */ u16 Marcadia;
	/* 0x0c */ u16 Daxx;
	/* 0x0e */ u16 Starship2;
	/* 0x10 */ u16 AnniNation;
	/* 0x12 */ u16 Aquatos;
	/* 0x14 */ u16 Tyhrranosis;
	/* 0x16 */ u16 Zeldrin;
	/* 0x18 */ u16 ObaniMoons;
	/* 0x1a */ u16 Rilgar;
	/* 0x1c */ u16 Holostar1;
	/* 0x1e */ u16 Koros;
	/* 0x20 */ u16 Kerwan;
	/* 0x22 */ u16 CrashSite;
	/* 0x24 */ u16 Aridia;
	/* 0x26 */ u16 Thran;
	/* 0x28 */ u16 FinalBoss;
	/* 0x2a */ u16 ObaniDraco;
	/* 0x2c */ u16 Mylon;
	/* 0x2e */ u16 HolostarClank;
	/* 0x30 */ u16 Museum;
	/* 0x32 */ u16 KerwanRanger;
	/* 0x34 */ u16 AquatosBase;
	/* 0x36 */ u16 AquatosSewers;
	/* 0x38 */ u16 Ranger2;
	/* 0x3a */ u16 VidComic0;
	/* 0x3c */ u16 VidComic1;
	/* 0x3e */ u16 VidComic4;
	/* 0x40 */ u16 VidComic2;
	/* 0x42 */ u16 VidComic3;
	/* 0x44 */ u16 VidComic5;
	/* 0x46 */ u16 VidComic6;
} rac3VariableAddressCompactBase_t;

/* Both formats accept campaign IDs 0..33; menu/unknown IDs return zero.
 * The caller must ensure the campaign overlay is ready before calling a result.
 * No verified campaign loading flag is currently available in this library. */
u32 GetAddress(const void* address);
u32 GetAddressImmediate(const void* address);

#endif // _LIBRAC3_INTEROP_H_
