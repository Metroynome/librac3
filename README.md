# librac3

Campaign library for Ratchet & Clank 3 / Up Your Arsenal. Build regional archives
with the existing PS2DEV Makefiles: `make -f Makefile.ntscu`,
`make -f Makefile.pal`, or `make -f Makefile.ntscj`.

## Variable address tables

The original `VariableAddress_t` remains supported and stores 34 absolute
addresses in 136 bytes. `rac3VariableAddressCompact_t` stores the same level
slots in 72 bytes, including EE alignment padding. Veldin is the absolute base;
the other 33 slots store signed four-byte displacements biased by `0x8000`.
Encoded zero means unavailable. An offset of zero uses encoded `0x8000`.

```c
static rac3VariableAddressCompact_t example = {
	.Veldin = RAC3_VA_COMPACT_BASE(0x00400000),
	.Florana = RAC3_VA_COMPACT_OFFSET(0x00400000, 0x00401000),
	.Starship1 = RAC3_VA_COMPACT_OFFSET(0x00400000, 0),
};
```

These example addresses are illustrative, not verified game hooks. The base
macro is required: Veldin's high bit marks the compact format. Other slots must
use the offset macro, which rejects unaligned differences and displacements
outside `-131068..131068` bytes. Use the original full table for outliers.
Omitted slots remain unavailable. Only low EE addresses are supported by the
format tag; do not use it with kernel or uncached address aliases.

`GetAddress`, `GetAddressImmediate`, and the assembly variable-function resolver
accept either format. Campaign IDs 0 through 33 index the fields in declaration
order; negative/menu and unknown IDs return zero. NTSC-U/PAL read the level ID
at `0x001d545c`; NTSC-J uses `0x001de75c`, matching the mod loader's regional
platform definitions. This replaces the previous unused multiplayer-style
39/40..49 lookup and multiplayer state checks in this campaign library.

There is no verified campaign overlay-ready flag in this library. Both public
resolvers currently select by level ID alone: callers must ensure the campaign
overlay is loaded before using a returned address. Compact storage does not
make an address safe during loading or verify that a hook belongs to a region.

Rebuild consumers with the updated library; older resolvers cannot read compact
tables. No populated campaign variable-address tables currently exist in this
library, so the 64-byte saving is per future converted table, not an existing
gameplay binary reduction.

## Verification

All three regional archives build through the mod loader's isolated-library
workflow. A focused harness exercised the actual compiled instructions of all
three resolver entry points in 756 cases, covering both formats, all 34 slots,
missing entries, equal-to-base entries, offset boundaries, and invalid IDs.
Table object sizes were measured with the EE compiler. Campaign gameplay and
loading transitions have not yet been tested in PCSX2 for this change.
