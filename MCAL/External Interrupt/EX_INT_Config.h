#ifndef _EX_INT_CONFIG_H_
#define _EX_INT_CONFIG_H_


/*General Interrupt Control Register – GICR*/
#define INT1  7  

#define INT0  6

#define INT2  5

/*MCU Control and Status Register – MCUCSR*/

#define ISC2  6

/*MCU Control Register – MCUCR*/

#define ISC11 3

#define ISC10 2

#define ISC01 1

#define ISC00 0


/*****************************************************************************/
/***************************   MODE OF INTERRUPT   ************************/
/*****************************************************************************/

#define Falling_Adge  0
#define Rising_Adge   1
#define Low_Level     2
#define Any_Change    3   











#endif
