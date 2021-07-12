//HEADER FILES
#include"hms.h"
#include<stdio.h>//Use for standard I/O Operation
#include <ncurses.h> //for delay(),getch(),gotoxy(),etc.
#include<ctype.h>//se for toupper(), tolower(),etc
#include<string.h>//Use for strcmp(),strcpy(),strlen(),etc
#include<stdlib.h>
// struct patient//list of global variable
// {
// 	int age;
// 	char Gender;
// 	char First_Name[20];
// 	char Last_Name[20]; 
// 	char Contact_no[15];
// 	char Address[30];
// 	char Email[30];
// 	char Doctor[20];
// 	char Problem[20];
// };
struct patient  p,temp_c;
char ans=0; 
int ok;
int b, valid=0;
//FUNCTION DECLERATION
void WelcomeScreen(void);//WelcomeScreen function decleration
//void Title(void);//Title function decleration
void MainMenu(void);//MainMenu function decleration
void LoginScreen(void);//LoginScreen function decleration
void Add_rec(int,int,int,struct patient);//Add_rec function declaration
void func_list(struct patient);//function to list the patient details 
void Search_rec(char,struct patient);//Search_rec function declaration
void Edit_rec(struct patient);//Edit_rec function declaration
void Dlt_rec(struct patient);//Dlt_rec function declaration
void ex_it(void);//exit function declaration
//Defines gotoxy() for ANSI C compilers.
void gotoxy(short x, short y) {
// COORD pos = {x, y};//sets co-ordinates in (x,y).
// SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
printf("\033[%d;%dH",y+1,x+1);
}






int main(void)
{
	
    WelcomeScreen();//Use to call WelcomeScreen function
	Title();//Use to call Title function
	LoginScreen();//Use to call Menu function
	return 0;
	
	

}
/* ************************************************* Welcome Screen ********************************************* */
void WelcomeScreen(void) //function for welcome screen
{
	
	printf("\n\n\n\n\n\n\n\t\t\t\t#########################################");
	printf("\n\t\t\t\t#\t\t WELCOME TO\t\t#");
	printf("\n\t\t\t\t#   PK HOSPITAL MANAGEMENT SYSTEM    #");
	printf("\n\t\t\t\t#########################################");
	printf("\n\n\n\n\n Press any key to continue......\n");
	getch();//Use to holds screen for some seconds
	system("cls");//Use to clear screen
	
}
/* ************************************************* Title Screen ********************************************* */

/* ************************************************* Main Menu ********************************************* */
void MainMenu(void)//function decleration
{
	system("cls");
	int choose;
	Title();// call Title function
	printf("\n\n\n\n\n\t\t\t\t1. Add Patients Record\n");
	printf("\n\t\t\t\t2. List Patients Record\n");
	printf("\n\t\t\t\t3. Search Patients Record\n");
	printf("\n\t\t\t\t4. Edit Patients Record\n");
	printf("\n\t\t\t\t5. Delete Patients Record\n");
	printf("\n\t\t\t\t6. Exit\n");
	printf("\n\n\n \n\t\t\t\tChoose from 1 to 6:");
	scanf("%i", &choose);
	
	switch(choose)//switch to differeht case
	{
	
	case 1:
	Add_rec(b,valid,ok,p);//Add_rec function is called
    	break;
    case 2:
    	func_list(p);
    	break;
	case 3:
	Search_rec(ans,p);//View_rec function is call
    	break;
	case 4:
		Edit_rec(p);//Edit_rec function is call
		break;
	case 5:
		Dlt_rec(p);//Dlt_rec function is call
		break;
	case 6:
		ex_it();//ex_it function is call
    	break;

	default:
		printf("\t\t\tInvalid entry. Please enter right option :)");
		getch();//holds screen
	}//end of switch
		
	
}
/* ************************************************* Exit Screen ********************************************* */

/* ************************************************* Login Screen ********************************************* */
void LoginScreen(void)//function for login screen
{
//list of variables	
int e=0	;
char Username[50];
char Password[50];
char Hospital_name[50]="PK Hospital Management";
char original_Username[50]="rakshitapatilkulkarni";
char original_Password[50]="LTTS";

do
{
	printf("\n\n\n\n\t\t\t\tEnter your Username and Password :)");
	printf("\n\n\n\t\t\t\t\tUSERNAME:");
	scanf("%s",Username);
	
	printf("\n\n\t\t\t\t\tPASSWORD:");
	scanf("%s",Password);
	
	if (strcmp(Username,original_Username)==0 && strcmp(Password,original_Password)==0)
	{
		printf("\n\n\n\t\t\t\t\t...Login Successfull...");
		
		
		getch();
		MainMenu();//call MainMenu function
		break;
	}
	else
	{
		printf("\n\t\t\tPassword is incorrect:( Try Again :)");
		e++;
		getch();
	}

}
while(e<=2);
	if(e>2)
	{
	printf("You have cross the limit. You cannot login. :( :(");
	getch();
    ex_it();
	}
 
system("cls");
}



/* **************************************ADD RECORD*******************************************/


/* **************************************VIEW RECORD*******************************************/






 
