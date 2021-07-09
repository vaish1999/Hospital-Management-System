/**
 * @file shms.h
 * @author Rakshita
 * @brief Hospital management program implementation
 * @version 0.1
 * @date 2021-04-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#ifndef __SHMS_H__
#define __SHMS_H__

#include <stdio.h>
#include<string.h>
#include <stdlib.h>


struct ad
{
    char name;
    char disease;
    int cabin,phone,age;
}x[100] ;

int n,i,j=0,a=0,sum=0,g,flag,num;
void read();
void add();
void view();
void search();
void edit();
void del();
void show();



#endif
