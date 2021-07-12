#include<stdio.h>//Use for standard I/O Operation
#include <ncurses.h> //for delay(),getch(),gotoxy(),etc.
#include<ctype.h>//se for toupper(), tolower(),etc
#include<string.h>//Use for strcmp(),strcpy(),strlen(),etc
#include<stdlib.h>
#include "hms.h"
void ex_it(void)//function to exit
{
	system("cls");
	Title();// call Title function
	printf("\n\n\n\n\n\t\t\tTHANK YOU FOR VISITING :)");
	getch();//holds screen
	
}