#include<stdio.h>//Use for standard I/O Operation
#include <ncurses.h> //for delay(),getch(),gotoxy(),etc.
#include<ctype.h>//se for toupper(), tolower(),etc
#include<string.h>//Use for strcmp(),strcpy(),strlen(),etc
#include<stdlib.h>
#include "hms.h"
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




void Edit_rec(struct patient p)
{
	FILE *ek, *ft;
  int i,b, valid=0;
  char ch;
  char name[20];

  system("cls");
  	Title();// call Title window
 		ft=fopen("temp2.dat","w+");
	   ek=fopen("Record2.dat","r");
	   if(ek==NULL)
	   {
		printf("\n\t Can not open file!! ");
		getch();
		MainMenu();
	   }
       	printf("\n\n\t\t\t!!!!!!!!!!!!!! Edit Patients Record !!!!!!!!!!!!!\n");
	   	gotoxy(12,13);
	   	printf("Enter the First Name of the Patient : ");
	   	scanf(" %s",name);
	   	fflush(stdin);
	   	name[0]=toupper(name[0]);
		gotoxy(12,15);
		
		if(ft==NULL)
		{
			printf("\n Can not open file");
			getch();
			MainMenu();
		}
		while(fscanf(ek,"%s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name, &p.Gender, &p.age, p.Address, p.Contact_no, p.Email, p.Problem, p.Doctor)!=EOF)
		{
			if(strcmp(p.First_Name, name)==0)
			{
				valid=1;
				gotoxy(25,17);
				printf("*** Existing Record ***");
				gotoxy(10,19);
				printf("%s \t%s \t%c \t%i \t%s \t%s \t%s \t%s \t%s\n",p.First_Name,p.Last_Name,p.Gender, p.age,p.Address,p.Contact_no,p.Email,p.Problem,p.Doctor);
				gotoxy(12,22);	
				printf("Enter New First Name: ");
				scanf("%s",p.First_Name);    
				gotoxy(12,24);
				printf("Enter Last Name: ");
				scanf("%s",p.Last_Name);
				gotoxy(12,26);
				printf("Enter Gender: ");
				scanf(" %c",&p.Gender);
				p.Gender=toupper(p.Gender);
				gotoxy(12,28);
				printf("Enter age: ");
				scanf(" %i",&p.age);
				gotoxy(12,30);
				printf("Enter Address: ");
				scanf("%s",p.Address);
				p.Address[0]=toupper(p.Address[0]);
				gotoxy(12,32);
				printf("Enter Contact no: ");
				scanf("%s",p.Contact_no);
				gotoxy(12,34);
				printf("Enter New email: ");
				scanf("%s",p.Email);
			    gotoxy(12,36);
				printf("Enter Problem: ");
				scanf("%s",p.Problem);
				p.Problem[0]=toupper(p.Problem[0]);
			    gotoxy(12,38);
				printf("Enter Doctor: ");
			    scanf("%s",p.Doctor);
			    p.Doctor[0]=toupper(p.Doctor[0]);
			    printf("\nPress U charecter for the Updating operation : ");
				ch=getche();
				if(ch=='u' || ch=='U')
				{
				fprintf(ft,"%s %s %c %i %s %s %s %s %s\n",p.First_Name,p.Last_Name,p.Gender, p.age,p.Address,p.Contact_no,p.Email,p.Problem,p.Doctor);
				printf("\n\n\t\t\tPatient record updated successfully...");
				}					
			}
			else
			{
			fprintf(ft,"%s %s %c %i %s %s %s %s %s\n",p.First_Name,p.Last_Name,p.Gender, p.age,p.Address,p.Contact_no,p.Email,p.Problem,p.Doctor);	
			}
		 }
		 if(!valid) printf("\n\t\tNO RECORD FOUND...");
	   fclose(ft);
	   fclose(ek);
	   remove("Record2.dat");
   	   rename("temp2.dat","Record2.dat");
		getch();
		MainMenu();		
}