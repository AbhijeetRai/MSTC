/*
Initialised global variables, most of them go on data section 
(Except string literals which go on rodata)
*/

char c = 'A';
unsigned char uc = 125; 
short snum = -100; 
unsigned short usnum = 0xffff; 
int inum = 34535; 
unsigned int uinum = 0xa0b0c0d0;
long l_num = 35435436; 
unsigned long ul_num = 0x46356; 
long long ll_num = 34636364736;
unsigned long long ull_num = 0xa0b0c0d010203040;

static int i = 500;

char* p = "Hello, World!";
char msg[] = "Hello,World!";

int a[5] = {100, 200, 300, 400, 500};
short b[] = {10, 20, 30};

/*
 * No conversion of following statement is present in assembly
 * Because assembly does not have notion of pure declarative statement 
 * It has only two things: definition and use
*/
struct Student { int st_roll; char* st_city; short st_marks; }; 

struct Student st_mstc = {121, "Pune", 78};
struct Student st_arr[] = {
	{207, "Pune", 80},
	{223, "Nagour", 82},
  	{145, "Mumbai", 75},
	{137, "Pune", 90},
	{89, "Mumbai", 95}
};
