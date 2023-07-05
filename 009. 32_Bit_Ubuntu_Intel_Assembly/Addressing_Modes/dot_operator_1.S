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

	movl $myDate, %eax 
	movl (%eax), %edx
	movl %edx, dd
	#A var with value 4 cannot be used here, leads to seg fault 
	movl 4(%eax), %edx
	movl %edx, mm
	movl 8(%eax), %edx
	movl %edx, yy

	pushl yy 
	pushl mm 
	pushl dd 
	pushl $msg 
	call printf  
	addl $16, %esp	

	#The values of registers (may) change post inbuilt function call, reset them 
	movl $myDate, %eax 
	movl $2, (%eax) 
	movl $9, 4(%eax)
	movl $1997, 8(%eax)

	movl (%eax), %edx 
	movl %edx, dd 
	movl 4(%eax), %edx 
	movl %edx, mm 
	movl 8(%eax), %edx 
	movl %edx, yy 
 
 	pushl yy 
	pushl mm 
	pushl dd 
	pushl $msg 
	call printf  
	addl $16, %esp

	pushl $0 
	call exit
