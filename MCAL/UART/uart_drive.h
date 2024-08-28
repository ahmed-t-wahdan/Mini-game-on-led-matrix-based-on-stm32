/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  
 *        Author: ahmed wahdan
 *		   Date:  Mar 2, 2024
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/

/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  main
 *        Author: ahmed wahdan
 *		   Date:  Mar 2, 2024
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#define UART_DRIVE_H_
#define UART_DRIVE_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

#include "stm32f10x.h"  
#include "gp_drive.h" 

unsigned long USART_BRR(unsigned short usart, unsigned long BR);
void UART_init(unsigned short usart, unsigned long BR);
char UART_RX(unsigned short uart);
void UART_TX(unsigned short uart,int c);
