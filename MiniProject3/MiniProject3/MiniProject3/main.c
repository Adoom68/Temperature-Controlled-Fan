 /******************************************************************************
 *
 * File Name: main.c
 *
 * Description: source file for the Application
 *
 * Author: Adam Farid
 *
 *******************************************************************************/

#include "adc.h"
#include "DcMotor.h"
#include "lcd.h"
#include "lm35_sensor.h"
#include <avr/io.h> /* To use the SREG register */
int main(void){
	uint8 temp_value;
	ADC_ConfigType adc_config={Internal_Vref,Div8};
	ADC_init(&adc_config);       /*to intiate the ADC*/
	DcMotor_Init();              /*to intiate the DcMotor*/
	LCD_init();                  /*to intiate the LCD*/

	while(1){
		temp_value=LM35_getTemperature();

		if(temp_value<30)
		{
			DcMotor_Rotate(Stop,0);
			LCD_displayStringRowColumn(0,3,"FAN IS OFF");
			LCD_displayStringRowColumn(1,3,"Temp = ");
			LCD_intgerToString(temp_value);
			LCD_displayCharacter('C');
		}
		else if ((temp_value<60)&&(temp_value>=30))
		{
			DcMotor_Rotate(Clockwise,25);
			LCD_displayStringRowColumn(0,3,"FAN IS OFF");
			LCD_displayStringRowColumn(1,3,"Temp = ");
			LCD_intgerToString(temp_value);
			LCD_displayCharacter('C');
		}
		else if((temp_value<90)&&(temp_value>=60))
		{
			DcMotor_Rotate(Clockwise,50);
			LCD_displayStringRowColumn(0,3,"FAN IS OFF");
			LCD_displayStringRowColumn(1,3,"Temp = ");
			LCD_intgerToString(temp_value);
			LCD_displayCharacter('C');
		}
		else if((temp_value<120)&&(temp_value>=90))
		{
			DcMotor_Rotate(Clockwise,75);
			LCD_displayStringRowColumn(0,3,"FAN IS OFF");
			LCD_displayStringRowColumn(1,3,"Temp = ");
			LCD_intgerToString(temp_value);
			LCD_displayCharacter('C');
		}
		else if(temp_value>=120)
		{
			DcMotor_Rotate(Clockwise,100);
			LCD_displayStringRowColumn(0,3,"FAN IS OFF");
			LCD_displayStringRowColumn(1,3,"Temp = ");
			LCD_intgerToString(temp_value);
			LCD_displayCharacter('C');
		}
	}
}
