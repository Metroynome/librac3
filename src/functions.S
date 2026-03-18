
#define GAME_ACTIVE                         (0x00241BD0)
#define SCENE_LOADED                        (0x002459C8)
// currently only for NTSCU
#define GAME_MAP_ID                         (0x001507E0)

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
	.section	.text.##__LocalGetAddress,"ax",@progbits;
	.align 2;
	.globl	__LocalGetAddress;
	.type	__LocalGetAddress,@function;
	.ent	__LocalGetAddress,0;
__LocalGetAddress:
	// if scene is loading, then we have no address
	li $v1, 1;
	lw $v0, SCENE_LOADED;
	bne $v0, $v1, __LocalGetAddress_exit;
	li $v0, 0;

	// if in menus then return lobby address
	lw $v0, GAME_MAP_ID;
  li $v1, 39;
	beq $v0, $v1, __LocalGetAddress_exit;
	lw $v0, 0($a0)

	// if not in game then no address
	lw $v0, GAME_ACTIVE;
	beq $v0, $zero, __LocalGetAddress_exit;
	nop;

	// otherwise in game
	// return address by map
	lw $v0, GAME_MAP_ID;
	
	// map local map ids (50+) to real map ids (40+)
	addiu $v1, $v0, -10;
	slti $s0, $v0, 50;
	movz $v0, $v1, $s0;

	// return 0 if map is not between 40 and 50
	addiu $v1, $v0, -40
	sltiu $v0, $v1, 10
	beqzl $v0, __LocalGetAddress_exit;
	move $v0, $zero;

	// load offset into VariableAddress struct by map id
	sll $v1, $v1, 2; // multiply map id [0,9] by 4
	addiu $v0, $v1, 4; // offset by 4 to skip lobby address

	// load address from struct
	addu $a0, $v0;
	lw $v0, 0($a0);

	// return to calling function
__LocalGetAddress_exit:
	jr $a1;
	nop;
	.end	__LocalGetAddress;
	.size	__LocalGetAddress,.-__LocalGetAddress;
	.set	pop;

// 
	.set	push;
	.set	noreorder;
	.section	.text.##GetAddress,"ax",@progbits;
	.align 2;
	.globl	GetAddress;
	.type	GetAddress,@function;
	.ent	GetAddress,0;
GetAddress:
	// if scene is loading, then we have no address
	li $v1, 1;
	lw $v0, SCENE_LOADED;
	bne $v0, $v1, GetAddress_exit;
	li $v0, 0;

	// if in menus then return lobby address
	lw $v0, GAME_MAP_ID;
  li $v1, 39;
	beq $v0, $v1, GetAddress_exit;
	lw $v0, 0($a0)

	// if not in game then no address
	lw $v0, GAME_ACTIVE;
	beq $v0, $zero, GetAddress_exit;
	nop;

	// otherwise in game
	// return address by map
	lw $v0, GAME_MAP_ID;
	
	// map local map ids (50+) to real map ids (40+)
	addiu $v1, $v0, -10;
	slti $t0, $v0, 50;
	movz $v0, $v1, $t0;

	// return 0 if map is not between 40 and 50
	addiu $v1, $v0, -40
	sltiu $v0, $v1, 10
	beqzl $v0, GetAddress_exit;
	move $v0, $zero;

	// load offset into VariableAddress struct by map id
	sll $v1, $v1, 2; // multiply map id [0,9] by 4
	addiu $v0, $v1, 4; // offset by 4 to skip lobby address

	// load address from struct
	addu $a0, $v0;
	lw $v0, 0($a0);

	// return to calling function
GetAddress_exit:
	jr $ra;
	nop;
	.end	GetAddress;
	.size	GetAddress,.-GetAddress;
	.set	pop;

// 
	.set	push;
	.set	noreorder;
	.section	.text.##GetAddress,"ax",@progbits;
	.align 2;
	.globl	GetAddressImmediate;
	.type	GetAddressImmediate,@function;
	.ent	GetAddressImmediate,0;
GetAddressImmediate:
	// if scene is loading, then we have no address
	//li $v1, 1;
	//lw $v0, SCENE_LOADED;
	//bne $v0, $v1, GetAddressImmediate_exit;
	//li $v0, 0;

	// if in menus then return lobby address
	lw $v0, GAME_MAP_ID;
  li $v1, 39;
	beq $v0, $v1, GetAddressImmediate_exit;
	lw $v0, 0($a0)

	// if not in game then no address
	//lw $v0, GAME_ACTIVE;
	//beq $v0, $zero, GetAddressImmediate_exit;
	//nop;

	// otherwise in game
	// return address by map
	lw $v0, GAME_MAP_ID;
	
	// map local map ids (50+) to real map ids (40+)
	addiu $v1, $v0, -10;
	slti $t0, $v0, 50;
	movz $v0, $v1, $t0;

	// return 0 if map is not between 40 and 50
	addiu $v1, $v0, -40
	sltiu $v0, $v1, 10
	beqzl $v0, GetAddressImmediate_exit;
	move $v0, $zero;

	// load offset into VariableAddress struct by map id
	sll $v1, $v1, 2; // multiply map id [0,9] by 4
	addiu $v0, $v1, 4; // offset by 4 to skip lobby address

	// load address from struct
	addu $a0, $v0;
	lw $v0, 0($a0);

	// return to calling function
GetAddressImmediate_exit:
	jr $ra;
	nop;
	.end	GetAddressImmediate;
	.size	GetAddressImmediate,.-GetAddressImmediate;
	.set	pop;


#--------------------------------------------------------
#------------------- STANDARD LIBRARY -------------------
#--------------------------------------------------------
FUNCTION(printf, 0x0011c1f8)
FUNCTION(sprintf, 0x00118cc8)
FUNCTION(memset, 0x00115484)
FUNCTION(memcpy, 0x001153d4)
FUNCTION(strncpy, 0x00115ac0)
FUNCTION(strcmp, 0x00008f998)
FUNCTION(strncmp, 0x001158f8)
#FUNCTION(strlen, 0x0008fadc)

#--------------------------------------------------------
#------------------------ RANDOM ------------------------
#--------------------------------------------------------
FUNCTION(randSeed, 0x0019d650)
