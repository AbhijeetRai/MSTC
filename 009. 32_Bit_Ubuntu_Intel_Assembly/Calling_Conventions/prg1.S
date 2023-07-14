#When we do push'l' pushl, l = 4 bytes 
#esp is subtracted by 4 bytes and pushed data is loaded on stack 
#on popl most recently pushed data is popped and esp is added by 4 bytes 

#To degub this code do: 
	#i) gcc -g prg1.S
 	#ii) gdb a.out 
	#iii) b main 
	#iv) run 
	v) press n until instruction popl%ebx comes. popl %eax would be executed by now 
	vi) %eax by print/u $eax 

.section .text 
.global main 
.type main, @function 
main: 
	pushl %ebp 
	movl %esp, %ebp 
	
	pushl $100
	pushl $200 
	
	popl %eax 	#200 in eax
	popl %ebx 	#100 in ebx

	movl %ebp, %esp
	popl %ebp 
	ret
