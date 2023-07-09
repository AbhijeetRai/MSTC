.section .rodata 
	fmt: 
	.string "inA2.c=%c, inA2.snum=%hd, iA2.inum=%d\n"	

.section .data 
	.global inA1 
	.type inA1, @object 
	.align 8 
	.size inA1, 8 
	inA1: 
	.byte 	65
	.zero	1
	.value  100 
	.int	-100 

.section .bss 
	.comm inA2, 8, 8 

.section .text 
.global main 
.type main, @function 
main: 
	pushl %ebp 
	movl  %esp, %ebp 
	
	movl $inA1, %eax 
	movl $inA2, %ebx 

	movb (%eax), %cl 
	movb %cl, (%ebx)

	movw 2(%eax), %cx
	movw %cx, 2(%ebx)

	movl 4(%eax), %ecx
	movl %ecx, 4(%ebx) 

	movb (%ebx), %dl
	movw 2(%ebx), %si
	movl 4(%ebx), %edi

	pushl %edi 
	pushl %esi 
	pushl %edx
	pushl $fmt 
	call printf 
	addl $16, %esp
	
	movl $0, %eax
	movl %ebp, %esp 
	popl %ebp 
	ret
