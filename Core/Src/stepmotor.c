/*
 * stepmotor.c
 *
 *  Created on: 10.05.2023
 *      Author: R. Denner
 */
#include "main.h"
#include "stepmotor.h"

//void moveOneStep(int dir, int ms);

//void moveOneStep(int dir,int ms,int *stat,int *sto)  //phase ABCD


void reset_varstepmotor(struct varstepmotor *stepvalues)
{
	stepvalues->postion=0;
	stepvalues->speed=0;
	stepvalues->state=8;
	stepvalues->steps=0;
	stepvalues->zycle=0;
	stepvalues->stop=0;
}



void moveOneStep(struct varstepmotor *stepvalues,int dir)
{
	//int dir=2;
	int ms=1;
	int z;
	if (dir == 1)
	{
		if (stepvalues->state == 1)
		{
			stepvalues->state=8;
			stepvalues->zycle+=1;
		}
		else
		{
			stepvalues->state=stepvalues->state/2;
		}
	}
	if(dir==2)
	{
		if(stepvalues->state==8)
		{
			stepvalues->state=1;
			stepvalues->zycle-=1;
		}
		else
		{
			stepvalues->state=stepvalues->state*2;

		}
	}
	if ((stepvalues->state==1)&&(stepvalues->stop==0))
	{
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7, GPIO_PIN_SET);
		if (dir==1)
		{
			stepvalues->steps+=1;
		}
		if (dir==2)
		{
			stepvalues->steps-=1;
		}
	}
	if ((stepvalues->state==2)&&(stepvalues->stop==0))
	{
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7, GPIO_PIN_RESET);
		if (dir==1)
		{
			stepvalues->steps+=1;
		}
		if (dir==2)
		{
			stepvalues->steps-=1;
		}
	}
	if ((stepvalues->state==4)&&(stepvalues->stop==0))
	{
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7, GPIO_PIN_RESET);
		if (dir==1)
		{
			stepvalues->steps+=1;
		}
		if (dir==2)
		{
			stepvalues->steps-=1;
		}
	}
	if ((stepvalues->state==8)&&(stepvalues->stop==0))
	{
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7, GPIO_PIN_RESET);
		if (dir==1)
		{
			stepvalues->steps+=1;
		}
		if (dir==2)
		{
			stepvalues->steps-=1;
		}
	}
	if(stepvalues->stop==1)
	{
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7, GPIO_PIN_RESET);

	}
	HAL_Delay(ms);
}
