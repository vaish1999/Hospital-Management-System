#include "hms.h"
#include<stdio.h>//Use for standard I/O Operation
#include <ncurses.h> //for delay(),getch(),gotoxy(),etc.
#include<ctype.h>//se for toupper(), tolower(),etc
#include<string.h>//Use for strcmp(),strcpy(),strlen(),etc
#include<stdlib.h>
void Title(void)//function for title screen
{
	printf("\n\n\t\t----------------------------------------------------------------------------------");
	printf("\n\t\t\t\t       PK HOSPITAL Management System         ");
	printf("\n\t\t----------------------------------------------------------------------------------");
}