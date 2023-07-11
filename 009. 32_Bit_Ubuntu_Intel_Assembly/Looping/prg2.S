.section .rodata 
	output:	
		.string "arr[%d]:%d\n"
	end:
	 	.string "End of code"

.section .data 
	.global arr
	.type arr, @object 
	.size arr, 20 
	.align 4 
	arr: 
	.int 10, 20, 30, 40, 50

.section .bss 
	.comm cnt, 4, 4

.section .text 
.global main 
.type main, @function 
main: 
	pushl %ebp 
	movl %esp, %ebp 

	movl $0, cnt
	jmp cond  
	
	loop: 	
		movl cnt, %ebx
		movl arr(, %ebx, 4), %eax
		pushl %eax
		pushl cnt 
		pushl $output
		call printf 
		addl $12, %esp
		addl $1, cnt 

	cond: 
		movl cnt, %eax 
		cmpl $5, %eax 
		jl loop

	pushl $end 
	call puts 
	addl $4, %esp 
	pushl $0 
	call exit	
