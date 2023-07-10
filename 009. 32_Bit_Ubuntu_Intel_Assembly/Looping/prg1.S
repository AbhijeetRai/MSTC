.section .rodata 
	msg: 
	.string "i = %d\n" 

	end: 
	.string "End of code" 

.section .bss 
	.comm i, 4, 4 


.section .text 
.global main 
.type main, @function 
main:	
	pushl %ebp 
	movl %esp, %ebp 
	
	movl $0, i
	movl $5, %ebx 
	jmp cond 

	loop_body: 
		pushl i 
		pushl $msg 
		call printf 
		addl $8, %esp 
		addl $1, i	

	cond: 
	movl i, %eax
	cmpl %ebx, %eax 
	jl loop_body
	
	out:
		pushl $end
		call puts 
		addl $4, %esp
		pushl $0 
		call exit
