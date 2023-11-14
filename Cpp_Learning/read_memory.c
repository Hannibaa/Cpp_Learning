#include <stdio.h>
//#include <MyLib/Console_Library/escape_code.h>

#define GREEN_FG               "\x1b[32m"
#define RESETMODE              "\x1b[0m"
#define BLACK_FG               "\x1b[30m"
#define RED_FG                 "\x1b[31m"
#define GREEN_FG               "\x1b[32m"
#define YELLOW_FG              "\x1b[33m"
#define BLUE_FG                "\x1b[34m"
#define CYAN_FG                "\x1b[36m"
#define MAGENTA_FG             "\x1b[35m"
#define WHITE_FG               "\x1b[37m"
#define WHITE2_FG              "\x1b[38m"
#define DEFAULT_FG             "\x1b[39"

#define newline_                putc('\n',stdout)
#define Print_(color , text )   printf("%s%s %s", color,text, RESETMODE)


typedef unsigned long long int ui64;


int main() {

	printf("%s \t\t\t This Program In C to Read Momory %s ", GREEN_FG,RESETMODE );
	newline_;
	Print_(RED_FG, "Hello world"); 0xff;

	ui64 mem = 0x00'b6'f7'ee;

	ui64* ptr = (ui64*)(mem);

	char c = 'a';
	char* ptr_c = &c;

	printf("memory is ptr %p \n", ptr_c);
	printf("memory have this : %c \n", *ptr);
	 

	getchar();
	return 0;
}