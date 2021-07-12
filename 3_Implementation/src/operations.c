

#include"fun.h"

#include <stdio.h>

//include<stdio.h>
#include <string.h>
#include <stdbool.h>
#include<stdlib.h>


/*******/
//long int crs,tch,room,dys,lects,tmptch,tmproom,set,settmp,done;
long int crs,tch,room,dys,lects,tmptch,tmproom,set=10,settmp,done;
/*******/
void input()
{
	int i,j,k;
	printf("enter total days in week\nTotal periods in a day\ntotal branches in your institue\nnumber of teachers available\ntotal number of rooms available\n");
	scanf("%ld %ld %ld %ld %ld",&dys,&lects,&crs,&tch,&room);
	//rooms...
	for(i=0;i<room;i++)
	{
		printf("enter room name %d ",i);
		scanf("%s",ro[i].room);
	}
	//tchrs
	for(i=0;i<tch;i++)
	{
		printf("enter teachr name %d ",i);
		scanf("%s",th[i].name);
	}
	//courses
	for(i=0;i<crs;i++)
	{
		printf("enter course name ");
		scanf("%s",co[i].name);

		printf("enter total subjects ");//less than m x n
		scanf("%d",&co[i].totsub);

		for(j=0;j<co[i].totsub;j++)
		{
			printf("enter subject name %d\n",j);
			scanf("%s",co[i].subject[j]);

			printf("enter subject creadit ");
			scanf("%d",&co[i].creadit[j]);

			co[i].allsub+=co[i].creadit[j];//less than m x m

			printf("select a teacher for subject %d",j);
			for(k=0;k<tch;k++)
			printf(" %d.%s\t",k,th[k].name);
			scanf("%ld",&tmptch);

			co[i].ctchr[j]=tmptch;
			th[tmptch].sub[th[tmptch].totsub]=j; //not used yet
			th[tmptch].cors[th[tmptch].totsub]=i;//not used yet

			th[tmptch].totsub++;	//	less than m x n

			th[tmptch].allsub+=co[i].creadit[j];
			/*if(th[tmptch].allsub>lects*dys-dys)//check total sub limit for a teacher
			{
				printf("more than limited sub to a teacher");
				//getch();
				exit(0);
			}*/

		}
		printf("enter a room for this course\n");
		for(j=0;j<room;j++)
		{
			printf(" room %d %s",j,ro[j].room);
		}
		scanf("%ld",&tmproom);
		co[i].room=tmproom;
		ro[tmproom].allsub+=co[i].allsub;
		

		/*if(ro[tmproom].allsub>lects*dys-dys)//check total room sub limit
		{
        printf("more than limited sub in a room");
			getch();
			exit(0);
		}*/


	}


}
/****/
void save(int x)
{
	int i,j,k;
	for(i=0;i<=x;i++)
	for(j=0;j<lects;j++)
	for(k=0;k<dys;k++)
	{
		strcpy(fitch[i].fitch[j].fitch[k].fitch,tmptchr[i].tmptchr[j].tmptchr[k].tmptchr);
		strcpy(fisub[i].fisub[j].fisub[k].fisub,tmpsub[i].tmpsub[j].tmpsub[k].tmpsub);
	}
}



int generate(int i,int j,int k)
{
	if (i==1 && j==2 && k==3)
	{
		return -1;
	}
	

	int x;
	if((i<crs)&&(set>crs))
	{
		if(((j==(lects/2)-1 && (ro[co[i].room].busy[j+1].busy[k].busy==false)) && (ro[co[i].room].lunch[0].lunch[k].lunch==false)) || (j==(lects/2) && (ro[co[i].room].busy[j-1].busy[k].busy==true) && (ro[co[i].room].lunch[1].lunch[k].lunch==false))  )
		{
			strcpy(tmptchr[i].tmptchr[j].tmptchr[k].tmptchr,"     ");
			strcpy(tmpsub[i].tmpsub[j].tmpsub[k].tmpsub,"lunch");
			if(j==(lects/2)-1)
			ro[co[i].room].lunch[0].lunch[k].lunch=true;
			else
			ro[co[i].room].lunch[1].lunch[k].lunch=true;
			co[i].breaks++;

			generate(i+(j+(k+1)/dys)/lects,(j+(k+1)/dys)%lects,(k+1)%dys);
			if(!done)
			{
			if(j==(lects/2)-1)
			ro[co[i].room].lunch[0].lunch[k].lunch=false;
			else
			ro[co[i].room].lunch[1].lunch[k].lunch=false;
			co[i].breaks--;}


		}
		for(x=0;x<co[i].totsub;x++)
		{
			if((th[co[i].ctchr[x]].busy[j].busy[k].busy==false) && (ro[co[i].room].busy[j].busy[k].busy==false) && (co[i].creadit[x]>0) && (co[i].allsub<=((dys*lects)-co[i].breaks)))
			{
				strcpy(tmptchr[i].tmptchr[j].tmptchr[k].tmptchr,th[co[i].ctchr[x]].name);
				strcpy(tmpsub[i].tmpsub[j].tmpsub[k].tmpsub,co[i].subject[x]);

				co[i].creadit[x]--;

				th[co[i].ctchr[x]].busy[j].busy[k].busy=true;
				ro[co[i].room].busy[j].busy[k].busy=true;

				if(j==(lects-1) && k==(dys-1))
					set++;

				if(settmp<set)
				{
					settmp=set;
					save(i);
				}
				generate(i+(j+(k+1)/dys)/lects,(j+(k+1)/dys)%lects,(k+1)%dys);

				if(!done)
				{
				if(j==(lects-1) && k==(dys-1))				//backtrack start
					set--;

				co[i].creadit[x]++;

				th[co[i].ctchr[x]].busy[j].busy[k].busy=false;
				ro[co[i].room].busy[j].busy[k].busy=false;

				tmptchr[i].tmptchr[j].tmptchr[k].tmptchr[0]='\0';
				tmpsub[i].tmpsub[j].tmpsub[k].tmpsub[0]='\0';
				}

			}
		}

		//breaks****
		if(co[i].allsub<((lects*dys)-(co[i].breaks)))
		{

			co[i].breaks++;
				strcpy(tmptchr[i].tmptchr[j].tmptchr[k].tmptchr,"Nill");
				strcpy(tmpsub[i].tmpsub[j].tmpsub[k].tmpsub,"brk");

			if(j==(lects-1) && k==(dys-1))
				set++;

			if(settmp<set)
			{
				settmp=set;
				save(i);
				//print();
			}

			generate(i+(j+(k+1)/dys)/lects,(j+(k+1)/dys)%lects,(k+1)%dys);

			if(!done)
			{
				if(j==(lects-1) && k==(dys-1))				//backtrack start
				set--;
				co[i].breaks--;
			}
		}
	}
	else
	{
		done=1; printf("..............................done..........................\n");

		}
	return 1;
}
/*****/
int print()
{
	int i,j,k;
	for(i=0;i<crs;i++)
	{
		printf("\t");
		for(j=0;j<dys;j++)
		printf("\t  day %d\t",j+1);
		printf("\n............................................................................\n");
		for(j=0;j<lects;j++)
		{
			printf("  lecture %d   ",j+1);
			for(k=0;k<dys;k++)
			{
				//printf("%s \t",fitch[i].fitch[j].fitch[k].fitch);//tmptchr[i].tmptchr[j].tmptchr[k].tmptchr);
				printf(" %9s\t",fisub[i].fisub[j].fisub[k].fisub);//
				//printf("%s ",tmpsub[i].tmpsub[j].tmpsub[k].tmpsub);
			}
			printf("\n              ");
			for(k=0;k<dys;k++)
			{
				printf(" %9s\t",fitch[i].fitch[j].fitch[k].fitch);//tmptchr[i].tmptchr[j].tmptchr[k].tmptchr);
				//printf("\t %9s ",fisub[i].fisub[j].fisub[k].fisub);//
				//printf("%s ",tmpsub[i].tmpsub[j].tmpsub[k].tmpsub);
			}
			printf("\n\n");
		}printf("\n\n");
	}
	return 1;
}