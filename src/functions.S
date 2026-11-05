
/* Campaign level ID: Veldin is 0. NTSC-J has a different resident global.
 * These addresses match uya-mod-loader's platformMode regional definitions. */
#if defined(RAC3_NTSCJ) || defined(UYA_NTSCJ)
#define GAME_MAP_ID (0x001de75c)
#else
#define GAME_MAP_ID (0x001d545c)
#endif

// fixed address function
#define FUNCTION(name, address) \
	.set	push;		        \
	.set	noreorder;	        \
	.section	.text.##name,"ax",@progbits; \
	.align 2;		            \
	.globl	name;		        \
	.type	name,@function;	    \
	.ent	name,0;		        \
name:	j address;              \
	nop;			            \
	.end	name;		        \
	.size	name,.-name;	    \
	.set	pop;

// variable address function
#define VARIABLE_FUNCTION(name, variable_address_struct) \
	.set	push;		        				\
	.set	noreorder;	        		\
	.section	.text.##name,"ax",@progbits; \
	.align 2;		            			\
	.globl	name;		        			\
	.type	name,@function;	    		\
	.ent	name,0;		        			\
	.extern variable_address_struct; \
name:														\
		addiu $sp, $sp, -0x40;			\
		sq $ra, 0x00($sp);					\
		sq $a0, 0x10($sp);					\
		sq $a1, 0x20($sp);					\
		sq $s0, 0x30($sp);					\
		la $a0, variable_address_struct; \
		la $a1, ##name##_return;				\
		j __LocalGetAddress;        \
		nop;			            			\
##name##_return:										\
		beq $zero, $v0, ##name##_exit;	\
		nop;												\
		lq $a1, 0x20($sp);					\
		jalr $v0;										\
		lq $a0, 0x10($sp);					\
##name##_exit:											\
		lq $ra, 0x00($sp);					\
		lq $s0, 0x30($sp);					\
		jr $ra;											\
		addiu $sp, $sp, 0x40;				\
	.end	name;		        				\
	.size	name,.-name;	   			 	\
	.set	pop;

// 
	.set	push;
	.set	noreorder;
	.section	.text.__LocalGetAddress,"ax",@progbits;
	.align 2;
	.globl	__LocalGetAddress;
	.type	__LocalGetAddress,@function;
	.ent	__LocalGetAddress,0;
__LocalGetAddress:
	// Campaign IDs index all 34 fields directly; reject menus and unknown IDs.
	lw $v1, GAME_MAP_ID;
	sltiu $v0, $v1, 34;
	beqz $v0, __LocalGetAddress_exit;
	move $v0, $zero;
	lw $v0, 0($a0);
	bltz $v0, __LocalGetAddress_compact;
	nop;
	sll $v1, $v1, 2;
	addu $v1, $a0, $v1;
	b __LocalGetAddress_exit;
	lw $v0, 0($v1);
__LocalGetAddress_compact:
	sll $v0, $v0, 1;
	beqz $v1, __LocalGetAddress_exit;
	srl $v0, $v0, 1;
	sll $v1, $v1, 1;
	addu $v1, $a0, $v1;
	lhu $v1, 2($v1);
	bnez $v1, __LocalGetAddress_offset;
	nop;
	b __LocalGetAddress_exit;
	move $v0, $zero;
__LocalGetAddress_offset:
	xori $v1, $v1, 0x8000;
	sll $v1, $v1, 16;
	sra $v1, $v1, 14;
	addu $v0, $v0, $v1;
__LocalGetAddress_exit:
	jr $a1;
	nop;
	.end	__LocalGetAddress;
	.size	__LocalGetAddress,.-__LocalGetAddress;
	.set	pop;

// 
	.set	push;
	.set	noreorder;
	.section	.text.GetAddress,"ax",@progbits;
	.align 2;
	.globl	GetAddress;
	.type	GetAddress,@function;
	.ent	GetAddress,0;
GetAddress:
	// Campaign IDs index all 34 fields directly; reject menus and unknown IDs.
	lw $v1, GAME_MAP_ID;
	sltiu $v0, $v1, 34;
	beqz $v0, GetAddress_exit;
	move $v0, $zero;
	lw $v0, 0($a0);
	bltz $v0, GetAddress_compact;
	nop;
	sll $v1, $v1, 2;
	addu $v1, $a0, $v1;
	b GetAddress_exit;
	lw $v0, 0($v1);
GetAddress_compact:
	sll $v0, $v0, 1;
	beqz $v1, GetAddress_exit;
	srl $v0, $v0, 1;
	sll $v1, $v1, 1;
	addu $v1, $a0, $v1;
	lhu $v1, 2($v1);
	bnez $v1, GetAddress_offset;
	nop;
	b GetAddress_exit;
	move $v0, $zero;
GetAddress_offset:
	xori $v1, $v1, 0x8000;
	sll $v1, $v1, 16;
	sra $v1, $v1, 14;
	addu $v0, $v0, $v1;
GetAddress_exit:
	jr $ra;
	nop;
	.end	GetAddress;
	.size	GetAddress,.-GetAddress;
	.set	pop;

// 
	.set	push;
	.set	noreorder;
	.section	.text.GetAddressImmediate,"ax",@progbits;
	.align 2;
	.globl	GetAddressImmediate;
	.type	GetAddressImmediate,@function;
	.ent	GetAddressImmediate,0;
GetAddressImmediate:
	// Campaign IDs index all 34 fields directly; reject menus and unknown IDs.
	lw $v1, GAME_MAP_ID;
	sltiu $v0, $v1, 34;
	beqz $v0, GetAddressImmediate_exit;
	move $v0, $zero;
	lw $v0, 0($a0);
	bltz $v0, GetAddressImmediate_compact;
	nop;
	sll $v1, $v1, 2;
	addu $v1, $a0, $v1;
	b GetAddressImmediate_exit;
	lw $v0, 0($v1);
GetAddressImmediate_compact:
	sll $v0, $v0, 1;
	beqz $v1, GetAddressImmediate_exit;
	srl $v0, $v0, 1;
	sll $v1, $v1, 1;
	addu $v1, $a0, $v1;
	lhu $v1, 2($v1);
	bnez $v1, GetAddressImmediate_offset;
	nop;
	b GetAddressImmediate_exit;
	move $v0, $zero;
GetAddressImmediate_offset:
	xori $v1, $v1, 0x8000;
	sll $v1, $v1, 16;
	sra $v1, $v1, 14;
	addu $v0, $v0, $v1;
GetAddressImmediate_exit:
	jr $ra;
	nop;
	.end	GetAddressImmediate;
	.size	GetAddressImmediate,.-GetAddressImmediate;
	.set	pop;


#--------------------------------------------------------
#------------------- STANDARD LIBRARY -------------------
#--------------------------------------------------------
// SDK console output, shared by the verified NTSC-U/PAL/NTSC-J campaign cores.
// The game CRT printf at 0x0011af48 does not provide this debug output path.
FUNCTION(printf, 0x00121760)
FUNCTION(fprintf, 0x00118950)
#FUNCTION(sprintf, 0x00118cc8)
FUNCTION(memset, 0x0011a264)
FUNCTION(memcpy, 0x0011a0b0)
FUNCTION(strncpy, 0x0011bb58)
FUNCTION(strncmp, 0x0011b9a0)
FUNCTION(malloc, 0x001194e8)
FUNCTION(free, 0x00119540)

#--------------------------------------------------------
#------------------------ RANDOM ------------------------
#--------------------------------------------------------
FUNCTION(randSeed, 0x0019d650)
