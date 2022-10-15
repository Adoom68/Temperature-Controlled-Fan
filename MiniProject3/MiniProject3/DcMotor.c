 /******************************************************************************
 *
 * Module: DcMotor
 *
 * File Name: DcMotor.c
 *
 * Description: source file for the DcMotor driver
 *
 * Author: Adam Farid
 *
 *******************************************************************************/
#include <avr/io.h>
#include "std_types.h"
#include "gpio.h"
#include "DcMotor.h"

extern void PWM_Timer0_Start(uint8 duty_cycle);
void DcMotor_Init(void)
{
	/* configure pin PB0 and PB1 as output pins */
	GPIO_setupPinDirection(DcMotor_InputPORT,DcMotor_InputPin_1,PIN_OUTPUT);
	GPIO_setupPinDirection(DcMotor_InputPORT,DcMotor_InputPin_2,PIN_OUTPUT);

	/* Motor is stop at the beginning */
	GPIO_writePin(DcMotor_InputPORT,DcMotor_InputPin_1,LOGIC_LOW);
	GPIO_writePin(DcMotor_InputPORT,DcMotor_InputPin_2,LOGIC_LOW);
}

void DcMotor_Rotate(DcMotor_State state,uint8 speed){

	switch (state){
	case Stop:{
		GPIO_writePin(DcMotor_InputPORT,DcMotor_InputPin_1,LOGIC_LOW );
		GPIO_writePin(DcMotor_InputPORT,DcMotor_InputPin_2,LOGIC_LOW );
		PWM_Timer0_Start(speed);
	}
	break;

	case Clockwise:{
		GPIO_writePin(DcMotor_InputPORT,DcMotor_InputPin_1,LOGIC_HIGH );
		GPIO_writePin(DcMotor_InputPORT,DcMotor_InputPin_2,LOGIC_LOW );
		PWM_Timer0_Start(speed);
	}
	break;

	case AntiClockwise:{
		GPIO_writePin(DcMotor_InputPORT,DcMotor_InputPin_1,LOGIC_LOW );
		GPIO_writePin(DcMotor_InputPORT,DcMotor_InputPin_2,LOGIC_HIGH );
		PWM_Timer0_Start(speed);
	}
	break;
	}






}

