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

u32 GetAddress(VariableAddress_t* address);
u32 GetAddressImmediate(VariableAddress_t* address);

#endif // _LIBRAC3_INTEROP_H_
