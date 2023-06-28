.section .data 
	.globl	b_num
	.type	b_num, @object 
	.size	b_num, 1 
	.align 4 
	b_num:
	.byte 	0xa0 

	.globl 	s_num 
	.type	s_num, @object
	.size	s_num, 2 
	.align 	4 
	s_num: 
	.value 	0xa0b0 

	.globl	i_num 
	.type	i_num, @object
	.size	i_num, 4 
	.align	4 
	i_num: 
	.int 	0xa0b0c0d0 

# ll_num == 0x10203040a0b0c0d0; 
	.globl	ll_num
	.type	ll_num, @object 
	.size	ll_num, 8 
	.align	4 
	ll_num: 
	.long 	0xa0b0c0d0
	.long	0x10203040

	.globl	int_128 
	.type	int_128, @object 
	.size	int_128, 16 
	.align	16 
	int_128: 
	.int	0xa0b0c0d0
	.int	0x10203040
	.int	0x19283745
	.int	0xf0e0d0c0

.section .bss 
	.comm	u8, 1, 4 
	.comm	u16, 2, 4 
	.comm	u32, 4, 4 
	.comm	u64, 8, 8 
	.comm	u128, 16, 16 

.section .text
.globl 	main 
.type	main, @function 
main: 
	# PROLOGUE 
	pushl	%ebp 
	movl	%esp, %ebp 
	# PROLOGUE END 
	
	# 8 bit operand combinations 
	movb	b_num, %al 	# mem8, reg8 
	movb	%al, %dl 	# reg8, reg8 
	addb	$1, %dl 	# imm8, reg8
	movb	%dl, u8 	# reg8, mem8 
	movb	$0xff, u8 	# imm8, mem8 

	# 16 bit operand combinations 
	movw 	s_num, %bx 
	movw	%bx, %cx 
	addw	$3, %cx 
	movw	%cx, u16 
	movw	$0xffff, u16 

	# 32 bit operand combinations 
	movl	i_num, %esi 
	movl	%esi, %edi 
	addl	$5, %edi 
	movl	%edi, u32 
	movl	$0xffffffff, u32 

	# 64 bit operand combinations 
	movq	ll_num, %mm0	
	movq	%mm0, %mm3 
	movq	%mm3, u64 

	# 128 bit operand combinations 
	movdqu	int_128, %xmm1 
	movdqu	%xmm1, %xmm7 
	movdqu	%xmm7, u128 

	# exit() from the application 
	pushl	$0 
	call	exit 

