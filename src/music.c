#include "music.h"
#include "interop.h"

#if defined(RAC3_NTSCU) || defined(UYA_NTSCU)
#define MUSIC_BOOT_PLAY (0x3a1bf0)

static const rac3VariableAddressCompactBase_t playLow = {
	.Base = RAC3_VA_COMPACT_CUSTOM_BASE(0x43962c),
	.Florana = RAC3_VA_COMPACT_OFFSET(0x43962c, 0x432318),
	.Starship1 = RAC3_VA_COMPACT_OFFSET(0x43962c, 0x449038),
	.Starship2 = RAC3_VA_COMPACT_OFFSET(0x43962c, 0x43e978),
	.Aquatos = RAC3_VA_COMPACT_OFFSET(0x43962c, 0x43e048),
	.Zeldrin = RAC3_VA_COMPACT_OFFSET(0x43962c, 0x43e660),
	.ObaniMoons = RAC3_VA_COMPACT_OFFSET(0x43962c, 0x431c68),
	.Holostar1 = RAC3_VA_COMPACT_OFFSET(0x43962c, 0x43af40),
	.Koros = RAC3_VA_COMPACT_OFFSET(0x43962c, 0x445d70),
	.CrashSite = RAC3_VA_COMPACT_OFFSET(0x43962c, 0x435348),
	.Thran = RAC3_VA_COMPACT_OFFSET(0x43962c, 0x44f6c0),
	.ObaniDraco = RAC3_VA_COMPACT_OFFSET(0x43962c, 0x432da0),
	.HolostarClank = RAC3_VA_COMPACT_OFFSET(0x43962c, 0x43d2c8),
	.Museum = RAC3_VA_COMPACT_OFFSET(0x43962c, 0x440c58),
	.AquatosBase = RAC3_VA_COMPACT_OFFSET(0x43962c, 0x432ac0),
	.AquatosSewers = RAC3_VA_COMPACT_OFFSET(0x43962c, 0x423598),
	.VidComic0 = RAC3_VA_COMPACT_OFFSET(0x43962c, 0x429bf8),
	.VidComic1 = RAC3_VA_COMPACT_OFFSET(0x43962c, 0x4293b0),
	.VidComic4 = RAC3_VA_COMPACT_OFFSET(0x43962c, 0x432608),
	.VidComic2 = RAC3_VA_COMPACT_OFFSET(0x43962c, 0x42ad50),
	.VidComic3 = RAC3_VA_COMPACT_OFFSET(0x43962c, 0x430040),
	.VidComic5 = RAC3_VA_COMPACT_OFFSET(0x43962c, 0x42a550),
	.VidComic6 = RAC3_VA_COMPACT_OFFSET(0x43962c, 0x4300b0),
};

static const rac3VariableAddressCompactBase_t playHigh = {
	.Base = RAC3_VA_COMPACT_CUSTOM_BASE(0x467bf4),
	.Veldin = RAC3_VA_COMPACT_OFFSET(0x467bf4, 0x45bb60),
	.Marcadia = RAC3_VA_COMPACT_OFFSET(0x467bf4, 0x46b528),
	.Daxx = RAC3_VA_COMPACT_OFFSET(0x467bf4, 0x454360),
	.AnniNation = RAC3_VA_COMPACT_OFFSET(0x467bf4, 0x45ab78),
	.Tyhrranosis = RAC3_VA_COMPACT_OFFSET(0x467bf4, 0x475810),
	.Rilgar = RAC3_VA_COMPACT_OFFSET(0x467bf4, 0x45cec8),
	.Kerwan = RAC3_VA_COMPACT_OFFSET(0x467bf4, 0x46c780),
	.Aridia = RAC3_VA_COMPACT_OFFSET(0x467bf4, 0x46ded0),
	.FinalBoss = RAC3_VA_COMPACT_OFFSET(0x467bf4, 0x47b488),
	.Mylon = RAC3_VA_COMPACT_OFFSET(0x467bf4, 0x461948),
	.KerwanRanger = RAC3_VA_COMPACT_OFFSET(0x467bf4, 0x464248),
	.Ranger2 = RAC3_VA_COMPACT_OFFSET(0x467bf4, 0x466da0),
};

#elif defined(RAC3_PAL) || defined(UYA_PAL)
#define MUSIC_BOOT_PLAY (0x3a1d30)

static const rac3VariableAddressCompactBase_t playLow = {
	.Base = RAC3_VA_COMPACT_CUSTOM_BASE(0x439aec),
	.Florana = RAC3_VA_COMPACT_OFFSET(0x439aec, 0x435b28),
	.Starship1 = RAC3_VA_COMPACT_OFFSET(0x439aec, 0x44c7b0),
	.Starship2 = RAC3_VA_COMPACT_OFFSET(0x439aec, 0x441ae8),
	.Aquatos = RAC3_VA_COMPACT_OFFSET(0x439aec, 0x4418a0),
	.Zeldrin = RAC3_VA_COMPACT_OFFSET(0x439aec, 0x4420b8),
	.ObaniMoons = RAC3_VA_COMPACT_OFFSET(0x439aec, 0x435138),
	.Holostar1 = RAC3_VA_COMPACT_OFFSET(0x439aec, 0x43e630),
	.Koros = RAC3_VA_COMPACT_OFFSET(0x439aec, 0x449240),
	.CrashSite = RAC3_VA_COMPACT_OFFSET(0x439aec, 0x438558),
	.ObaniDraco = RAC3_VA_COMPACT_OFFSET(0x439aec, 0x4360b0),
	.HolostarClank = RAC3_VA_COMPACT_OFFSET(0x439aec, 0x440610),
	.Museum = RAC3_VA_COMPACT_OFFSET(0x439aec, 0x444068),
	.AquatosBase = RAC3_VA_COMPACT_OFFSET(0x439aec, 0x435bd8),
	.AquatosSewers = RAC3_VA_COMPACT_OFFSET(0x439aec, 0x426e28),
	.VidComic0 = RAC3_VA_COMPACT_OFFSET(0x439aec, 0x42ce98),
	.VidComic1 = RAC3_VA_COMPACT_OFFSET(0x439aec, 0x42c338),
	.VidComic4 = RAC3_VA_COMPACT_OFFSET(0x439aec, 0x435650),
	.VidComic2 = RAC3_VA_COMPACT_OFFSET(0x439aec, 0x42dc98),
	.VidComic3 = RAC3_VA_COMPACT_OFFSET(0x439aec, 0x433148),
	.VidComic5 = RAC3_VA_COMPACT_OFFSET(0x439aec, 0x42d518),
	.VidComic6 = RAC3_VA_COMPACT_OFFSET(0x439aec, 0x4330f8),
};

static const rac3VariableAddressCompactBase_t playHigh = {
	.Base = RAC3_VA_COMPACT_CUSTOM_BASE(0x468fb8),
	.Veldin = RAC3_VA_COMPACT_OFFSET(0x468fb8, 0x45eef0),
	.Marcadia = RAC3_VA_COMPACT_OFFSET(0x468fb8, 0x46ebf8),
	.Daxx = RAC3_VA_COMPACT_OFFSET(0x468fb8, 0x457db0),
	.AnniNation = RAC3_VA_COMPACT_OFFSET(0x468fb8, 0x45de88),
	.Tyhrranosis = RAC3_VA_COMPACT_OFFSET(0x468fb8, 0x478de0),
	.Rilgar = RAC3_VA_COMPACT_OFFSET(0x468fb8, 0x4603d8),
	.Kerwan = RAC3_VA_COMPACT_OFFSET(0x468fb8, 0x46fd90),
	.Aridia = RAC3_VA_COMPACT_OFFSET(0x468fb8, 0x4717a0),
	.Thran = RAC3_VA_COMPACT_OFFSET(0x468fb8, 0x453158),
	.FinalBoss = RAC3_VA_COMPACT_OFFSET(0x468fb8, 0x47ee18),
	.Mylon = RAC3_VA_COMPACT_OFFSET(0x468fb8, 0x464e60),
	.KerwanRanger = RAC3_VA_COMPACT_OFFSET(0x468fb8, 0x467a58),
	.Ranger2 = RAC3_VA_COMPACT_OFFSET(0x468fb8, 0x46a430),
};

#else
#define MUSIC_BOOT_PLAY (0x3abed8)

static const rac3VariableAddressCompactBase_t playLow = {
	.Base = RAC3_VA_COMPACT_CUSTOM_BASE(0x43c760),
	.Florana = RAC3_VA_COMPACT_OFFSET(0x43c760, 0x43c900),
	.Starship2 = RAC3_VA_COMPACT_OFFSET(0x43c760, 0x448f20),
	.Aquatos = RAC3_VA_COMPACT_OFFSET(0x43c760, 0x4486f0),
	.Zeldrin = RAC3_VA_COMPACT_OFFSET(0x43c760, 0x448d48),
	.ObaniMoons = RAC3_VA_COMPACT_OFFSET(0x43c760, 0x43c290),
	.Holostar1 = RAC3_VA_COMPACT_OFFSET(0x43c760, 0x445668),
	.CrashSite = RAC3_VA_COMPACT_OFFSET(0x43c760, 0x43f970),
	.ObaniDraco = RAC3_VA_COMPACT_OFFSET(0x43c760, 0x43d3c8),
	.HolostarClank = RAC3_VA_COMPACT_OFFSET(0x43c760, 0x447870),
	.Museum = RAC3_VA_COMPACT_OFFSET(0x43c760, 0x44b2c0),
	.AquatosBase = RAC3_VA_COMPACT_OFFSET(0x43c760, 0x43d168),
	.AquatosSewers = RAC3_VA_COMPACT_OFFSET(0x43c760, 0x42dc00),
	.VidComic0 = RAC3_VA_COMPACT_OFFSET(0x43c760, 0x4341a0),
	.VidComic1 = RAC3_VA_COMPACT_OFFSET(0x43c760, 0x433958),
	.VidComic4 = RAC3_VA_COMPACT_OFFSET(0x43c760, 0x43cbb0),
	.VidComic2 = RAC3_VA_COMPACT_OFFSET(0x43c760, 0x4352f8),
	.VidComic3 = RAC3_VA_COMPACT_OFFSET(0x43c760, 0x43a668),
	.VidComic5 = RAC3_VA_COMPACT_OFFSET(0x43c760, 0x434ab8),
	.VidComic6 = RAC3_VA_COMPACT_OFFSET(0x43c760, 0x43a658),
};

static const rac3VariableAddressCompactBase_t playHigh = {
	.Base = RAC3_VA_COMPACT_CUSTOM_BASE(0x46aef8),
	.Veldin = RAC3_VA_COMPACT_OFFSET(0x46aef8, 0x4660b0),
	.Starship1 = RAC3_VA_COMPACT_OFFSET(0x46aef8, 0x453588),
	.Marcadia = RAC3_VA_COMPACT_OFFSET(0x46aef8, 0x475a78),
	.Daxx = RAC3_VA_COMPACT_OFFSET(0x46aef8, 0x45e948),
	.AnniNation = RAC3_VA_COMPACT_OFFSET(0x46aef8, 0x465088),
	.Tyhrranosis = RAC3_VA_COMPACT_OFFSET(0x46aef8, 0x47f9e0),
	.Rilgar = RAC3_VA_COMPACT_OFFSET(0x46aef8, 0x467458),
	.Koros = RAC3_VA_COMPACT_OFFSET(0x46aef8, 0x4503d8),
	.Kerwan = RAC3_VA_COMPACT_OFFSET(0x46aef8, 0x476cd0),
	.Aridia = RAC3_VA_COMPACT_OFFSET(0x46aef8, 0x4784e0),
	.Thran = RAC3_VA_COMPACT_OFFSET(0x46aef8, 0x459da8),
	.FinalBoss = RAC3_VA_COMPACT_OFFSET(0x46aef8, 0x485a18),
	.Mylon = RAC3_VA_COMPACT_OFFSET(0x46aef8, 0x46bf58),
	.KerwanRanger = RAC3_VA_COMPACT_OFFSET(0x46aef8, 0x46e798),
	.Ranger2 = RAC3_VA_COMPACT_OFFSET(0x46aef8, 0x4713b0),
};

#endif

/*
 * NAME : musicGetLevel
 * DESCRIPTION : Read the campaign disc level ID.
 * NOTES :
 * ARGS :
 * RETURN : Level ID, or -1 at boot.
 * AUTHOR : Troy "Metroynome" Pruitt
 */
int musicGetLevel(void)
{
	return *(volatile int*)MUSIC_LEVEL_ADDRESS;
}

/*
 * NAME : musicGetPlayAddress
 * DESCRIPTION : Resolve the current overlay music entry point.
 * NOTES :
 * ARGS :
 * RETURN : Play address, or zero when unavailable.
 * AUTHOR : Troy "Metroynome" Pruitt
 */
u32 musicGetPlayAddress(void)
{
	u32 address;
	if (musicGetLevel() == -1)
		return MUSIC_BOOT_PLAY;
	address = GetAddress(&playLow);
	return address ? address : GetAddress(&playHigh);
}

/*
 * NAME : musicGetStream
 * DESCRIPTION : Return the resident campaign music state.
 * NOTES :
 * ARGS :
 * RETURN : Main music stream.
 * AUTHOR : Troy "Metroynome" Pruitt
 */
musicStream_t* musicGetStream(void)
{
	return (musicStream_t*)MUSIC_STREAM_ADDRESS;
}

/*
 * NAME : musicGetTable
 * DESCRIPTION : Return the native stereo descriptor table.
 * NOTES :
 * ARGS :
 * RETURN : Descriptor table.
 * AUTHOR : Troy "Metroynome" Pruitt
 */
const u32* musicGetTable(void)
{
	return (const u32*)MUSIC_TABLE_ADDRESS;
}

/*
 * NAME : musicGetSector
 * DESCRIPTION : Read the native music sector base.
 * NOTES :
 * ARGS :
 * RETURN : Disc sector.
 * AUTHOR : Troy "Metroynome" Pruitt
 */
u32 musicGetSector(void)
{
	return *(volatile u32*)MUSIC_SECTOR_ADDRESS;
}

