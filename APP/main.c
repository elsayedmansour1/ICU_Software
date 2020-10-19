/*
 * main.c
 *
 *  Created on: Oct 13, 2020
 *      Author: elsay
 */
#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include "util/delay.h"
#include "../MCAL/DIO/DIO_INT.h"
#include "../MCAL/DIO/DIO_config.h"
#include "../HAL/LCD/LCD_Interface.h"
#include "../MCAL/TIMER0/TIMER0_Int.h"
#include "../MCAL/TIMER2/TIMER2_Reg.h"
#include "../MCAL/TIMER2/TIMER2_Int.h"
#include "../MCAL/Global Interrupt/GIE_INT.h"
#include "../MCAL/External Interrupt/EX_INT_Int.h"
#include "../MCAL/External Interrupt/EX_INT_Config.h"




volatile u16 Ton=0;
volatile u16 Toff=0;
volatile u16 T=0;
volatile u16 OVF=0;
volatile u8  Flag=0;


void ex0_isr(void);
void tmr2_isr(void);

int main(void)
{

	DIO_VidSetPinDirection(DIO_PORTA, PIN3, OUTPUT);
	DIO_VidSetPinDirection(DIO_PORTA, PIN4, OUTPUT);
	DIO_VidSetPinDirection(DIO_PORTA, PIN5, OUTPUT);
	u8 Duty_Cycle=0;
	u8 Freq=0;

	/*LCD INIT*/
	LCD_VidInit();

	/*WRITE welcome in lcd*/
	LCD_VidWriteString("welcome");
	_delay_ms(2000);
	LCD_VidWriteCommend(1);

	/*External Interrupt*/
	EX_INT0_enable();
	EX_INT0_Sence_Mode(Rising_Adge);
	DIO_VidSetPinDirection(DIO_PORTD, PIN2, INPUT);

	/*set_CallBack*/
	INT0_SetCallBack(ex0_isr);
	TMR2_OF_SetCallBack(tmr2_isr);

	/*timer2 enable--->counter*/
	TIMER2_INIT();

	/*timer0 enable--->output*/
	TIMER0_INIT();
	DIO_VidSetPinDirection(DIO_PORTB, PIN3, OUTPUT);

	/*set_duty_cycle in timer 0 to generate pwm*/
	TIMER0_Set_Duty_Cycle(20);

	/*global interrupt Enable*/
	GIE_Vid_Enable();

	while(1)
	{
		if(Flag==3)
		{
		LCD_GoToXY(0, 0);
		LCD_VidWriteString("Ton=");
		LCD_GoToXY(0, 4);
		LCD_VidWriteNumber(Ton);
		LCD_GoToXY(1, 0);
		LCD_VidWriteString("Toff=");
		LCD_GoToXY(1, 5);
		LCD_VidWriteNumber(Toff);
		Flag=0;
		}
	}
	return 0;
}


void ex0_isr(void)
{
	if(Flag==0)
	{
	DIO_VidSetPinValue(DIO_PORTA, PIN3, HIGH);
	OVF=0;
	TCNT2=0;
	EX_INT0_Sence_Mode(Falling_Adge);
	Flag=1;
	}
	else if(Flag==1)
	{
	DIO_VidSetPinValue(DIO_PORTA, PIN4, HIGH);
	Ton=TCNT2+(OVF*256);
	TCNT2=0;
	OVF=0;
	EX_INT0_Sence_Mode(Rising_Adge);
	Flag=2;
	}
	else if(Flag==2)
	{
	DIO_VidSetPinValue(DIO_PORTA, PIN5, HIGH);
	Toff=TCNT2+(OVF*256);
	TCNT2=0;
	OVF=0;
	Flag=3;
	}
}
void tmr2_isr(void)
{
	OVF++;
}

