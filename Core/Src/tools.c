/*
 * tools.c
 *
 *  Created on: 16.05.2023
 *      Author: R. Denner
 */
#include "main.h"
#include "tools.h"

char* itos(int zahl)
{
	char text[6]={};
	int temp1,temp2;
	int fzero=0;
	temp1=zahl;
	for(int i=5;i>-1;i--)
	{
		if (temp1/10>0)
		{
			temp2=temp1%10;
			text[i]=ztos(temp2);
			if (temp2==0) text[i]='0';
			if (temp2==1) text[i]='1';
			if (temp2==2) text[i]='2';
			if (temp2==3) text[i]='3';
			if (temp2==4) text[i]='4';
			if (temp2==5) text[i]='5';
			if (temp2==6) text[i]='6';
			if (temp2==7) text[i]='7';
			if (temp2==8) text[i]='8';
			if (temp2==9) text[i]='9';
			temp1/=10;
			if (temp1<10)
				text[i-1]=ztos(temp1);
		}
	}
	return text;
}

char ztos(int a)
{
	char b='0';
	if (a==0) b='0';
	if (a==1) b='1';
	if (a==2) b='2';
	if (a==3) b='3';
	if (a==4) b='4';
	if (a==5) b='5';
	if (a==6) b='6';
	if (a==7) b='7';
	if (a==8) b='8';
	if (a==9) b='9';
	return b;
}

