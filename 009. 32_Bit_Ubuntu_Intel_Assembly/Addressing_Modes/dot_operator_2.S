#Trying to find out another way to handle offset

.section .rodata 
	msg:
	.string "%d-%d-%d\n"

.section .bss 
	.comm dd 4, 4 
	.comm mm 4, 4 
	.comm yy 4, 4

.section .data 
	.global myDate 
	.type myDate, @object 
	.size myDate, 12 
	.align 4 
	myDate: 
	.int 1 
	.int 1 
	.int 1970


.section .text 
.global main 
.type main, @object 
main: 
	pushl %ebp 
	movl %esp, %ebp
	movl $myDate, %eax	#point to base address say 0 
	movl (%eax), %edx 
	movl %edx, dd 
	
	addl $4, %eax 		#base address plus 4
	movl (%eax), %edx
	movl %edx, mm 
	
	addl $4, %eax 		#base address plus 4 + 4 = 8
	movl (%eax), %edx 
	movl %edx, yy

	pushl yy 
	pushl mm 
	pushl dd 
	pushl $msg 
	call printf  
	addl $16, %esp

	pushl $0 
	call exit
