.section .rodata 
#char* p = "Hello,World!"
.global p
.type p, @object 
.size p, 13 
.align p, 1 
p:
.string "Hello,World!"

str0: 
.string "Pune"

str1:
.string "Nagpur"

str2:
.string "Mumbai"

.section .data 

#char c = 'A'
.global c
.type c, @object 
.size c, 1
.align c, 4 
c:
.ascii "A"

#unsigned char uc = 125 
.global uc 
.type uc, @object 
.size uc, 1
.align uc, 4 
uc: 
.byte 125

#short snum = -100 
.global snum 
.type snum, @object 
.size uc, 2
.align snum, 4
snum: 
.value -100

#unsigned short usnum = 0xffff; 
.global usnum 
.type usnum, @object 
.size usnum 2
.align usnum, 4
usnum:
.value 0xffff

#int inum = 34535 
.global inum 
.type inum, @object 
.size inum, 4 
.align inum, 4 
inum:
.int 34535 

#unsigned int uinum = 0xa0b0c0d0 
.global uinum 
.align uinum 4 
.size uinum 4 
.type uinum, @object 
uinum:
.int 0xa0b0c0d0

#long lnum = 36435436
.global lnum 
.type lnum, @object 
.size lnum, 4 
.align lnum, 4 
lnum: 
.long 36435436 

#unsigned long ul_num = 0x46356 
.global ul_num
.type ul_num, @object 
.size ul_num, 4 
.align ul_num, 4 
ul_num:
.long 0x46356

#long long ll_num = 34636364736 
#hex = 0x8107CFBC0
.global ll_num 
.type ll_num, @object 
.size ll_num, 8
.align ll_num, 8
ll_num:
.long 0x107CFBC0	
.long 0x00000008	

#unsigned long long ull_num = 0xa0b0c0d010203040;
.global ull_num 
.type ull_num, @object 
.size ull_num, 8
.align ull_num, 8
ull_num: 
.long 0x10203040
.long 0xa0b0c0d0

#static int i = 500 
.type i, @object 
.size i, 4 
.align i, 4 
i: 
.int 500 

#char msg[] = "Hello,World!"; 
.global msg 
.type msg, @object 
.size msg, 13 
.align msg, 4 
msg: 
.string "Hello, World!" 


#int a[5] = {100, 200, 300, 400, 500}
.global a
.type a, @object 
.size a, 20
.align a, 4 
a: 
.int 100 
.int 200 
.int 300
.int 400
.int 500 

#short b[] = {10, 20, 30} 
.global b 
.type b, @object 
.size b, 6 
.align b, 4
b: 
.value 10, 20, 30


#struct Student st_mstc = {121, "Pune", 78} 
.global st_mstc 
.type st_mstc, @object 
.size st_mstc, 12 
.align st_mstc, 4
st_mstc: 
.int 121 
.long str0 
.value 78 
.zero 2

#Global array 
.global st_arr 
.type st_arr, @object 
.size st_arr, 60 
.align st_arr, 4
st_arr: 
.int 207
.long str0 
.value 80 
.zero 2 	#index 0 end

.int 223 
.long str1 
.value 82 
.zero 2 	#index 1 end
