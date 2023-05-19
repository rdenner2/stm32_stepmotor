/*
 * stepmotor.h
 *
 *  Created on: May 14, 2023
 *      Author: R. Denner
 */

#ifndef INC_STEPMOTOR_H_
#define INC_STEPMOTOR_H_

struct varstepmotor
{
	int state;
	int steps;
	int zycle;
	double postion;
	double speed;
	int stop;
};

void reset_varstepmotor(struct varstepmotor *stepvalues);

void moveOneStep(struct varstepmotor *stepvalues ,int dir);


#endif /* INC_STEPMOTOR_H_ */
