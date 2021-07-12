#ifndef __HMS_H
#define __HMS_H
struct patient//list of global variable
{
	int age;
	char Gender;
	char First_Name[20];
	char Last_Name[20]; 
	char Contact_no[15];
	char Address[30];
	char Email[30];
	char Doctor[20];
	char Problem[20];
};


void Title(void);
void Add_rec(int,int,int,struct patient);//Add_rec function declaration
void func_list(struct patient);//function to list the patient details 
void Search_rec(char,struct patient);//Search_rec function declaration
void Edit_rec(struct patient);//Edit_rec function declaration
void Dlt_rec(struct patient);//Dlt_rec function declaration
void ex_it(void);//exit function declaration
#endif
