/*
 * MeasurmentHandler.c
 *
 *  Created on: May 3, 2018
 *      Author: burak
 */

#include "MeasurmentHandler.h"
#include "Stepper.h"
#include "Lockup_Table.h"
#include "PE_Types.h"
#include "PE_Const.h"

static double calculationDistance_YAxis(uint32_t steps){
	// Function for the different Distance
	return 0.00685f * (float)steps;
}

float Measurment_XAxis(uint32_t steps){
	return lockupTableForMeasurment_XAxisGround[steps];
}

float Measurment_YAxis(uint32_t steps){
	float sum1 = lockupTableForMeasurment_YAxis[steps];
	float sum2 = calculationDistance_YAxis(LiftingMotor.Steps/8);
	float result = sum1 - sum2; 
	return result;
}

void MeasurmentInit(void){
	;
}

