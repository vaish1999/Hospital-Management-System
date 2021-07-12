#include <stdio.h>


//include<stdio.h>
#include <string.h>
#include <stdbool.h>
#include<stdlib.h>

#define MAX 100

void input();
int print();
int generate(int i,int j,int k);


struct course
	{
		char name[20];
		char subject[20][15];
		int creadit[20];
		int room;
		int totsub;
		int ctchr[20];
		int allsub;
		int breaks;
	};
	struct course co[20];

/*******/
struct teach
	{
		char name[20];
		int sub[11];
		int cors[11];
		int totsub;
		int allsub;
		struct
		{
			struct
			{
				bool busy;
			}
		busy[10];
	}
	busy[10];

	};
	struct teach th[20];
/*******/
struct room
{
	char room[10];
	int allsub;
	struct
	{
		struct
		{
			bool busy;
		}
		busy[10];
	}
	busy[10];
	struct
	{
		struct
		{
			bool lunch;
		}
		lunch[10];
	}lunch[2];

	};struct room ro[20];
/*******/

struct tmpsub
	{
	struct
	{
		struct
		{
			char tmpsub[20];
		}
		tmpsub[20];
	}
	tmpsub[20];
	}
	tmpsub[20];
/*******/
struct tmptchr
	{
	struct
	{
		struct
		{
			char tmptchr[20];
		}
		tmptchr[20];
	}
	tmptchr[20];
	}
	tmptchr[20];
/*******/
struct fisub
	{
	struct
	{
		struct
		{
			char fisub[20];
		}
		fisub[20];
	}
	fisub[20];
	}
	fisub[20];
/****oom for this cou***/
struct fitch
	{
	struct
	{
		struct
		{
			char fitch[20];
		}
		fitch[10];
	}
	fitch[20];
	}
	fitch[20];
