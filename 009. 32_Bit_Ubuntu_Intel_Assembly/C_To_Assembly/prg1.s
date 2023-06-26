.section .rodata 
.globl p 
.type p, @object 
.size p, 13 
.align 4 
p:
.string "Hello, World"

.section .data 
.global c 
.type c, @object
.size c, 1 
.align 4 
c:
.ascii "A"


