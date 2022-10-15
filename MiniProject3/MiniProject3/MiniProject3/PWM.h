 /******************************************************************************
 *
 * Module: PWM
 *
 * File Name: PWM.h
 *
 * Description: Header file for the AVR PWM driver
 *
 * Author: Adam Farid
 *
 *******************************************************************************/

#ifndef PWM_H_
#define PWM_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define Timer_Start_Value  0
#define OC0_PORT  PORTB_ID
#define OC0_PIN   PIN3_ID


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

void PWM_Timer0_Start(uint8 duty_cycle);

#endif /* PWM_H_ */
