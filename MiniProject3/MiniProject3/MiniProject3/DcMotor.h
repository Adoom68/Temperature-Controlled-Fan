 /******************************************************************************
 *
 * Module: DcMotor
 *
 * File Name: DcMotor.h
 *
 * Description: header file for the DcMotor driver
 *
 * Author: Adam Farid
 *
 *******************************************************************************/

#ifndef DCMOTOR_H_
#define DCMOTOR_H_
#include "std_types.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define DcMotor_InputPORT    PORTB_ID
#define DcMotor_InputPin_1    PIN0_ID
#define DcMotor_InputPin_2    PIN1_ID
#define DcMotor_Enable        PIN3_ID
/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/

typedef enum
{
	Stop , Clockwise , AntiClockwise
}DcMotor_State;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

void DcMotor_Init(void);
void DcMotor_Rotate(DcMotor_State state,uint8 speed);

#endif /* DCMOTOR_H_ */
