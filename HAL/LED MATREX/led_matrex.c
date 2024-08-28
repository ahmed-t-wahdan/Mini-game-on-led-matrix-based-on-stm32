#include "led_matrex.h"
#include "gp_drive.h"
#include "uart_drive.h"
#include "systick_time.h"

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

void init_led(){

}



void max_print(int t[],unsigned short dlay_ms)
{
	dlay_ms=dlay_ms/30;
 for(int y=0;y<dlay_ms;y++)
 {
	  int value =0b111111110;
    int i=0;
 	 for (i=0;i<=8;i++)
	 {
	  UART_TX(2,t[i]);
	  UART_TX(2,value);
		DelayMs(1);
    toggle_GP(PA,8);
	  toggle_GP(PA,8);
	  value = ~value;                // Invert the bits
    value = value & 0b11111111;    // Mask to keep only the last 8 bits
    value = value <<1;
    value = ~value;
    value = value &0b11111111 ;
		
   	 }
	  
	
	}
}

void shift(int t[],short spped)
{

 for(int y=0;y<7;y++)
 {
   for(int s=0;s<spped;s++)
	 { 
		 int value =0b111111110;
 	 for (int i=0;i<=8;i++)
	 {
	  UART_TX(2,t[i]);
	  UART_TX(2,value);
		DelayMs(1);
    toggle_GP(PA,8);
	  toggle_GP(PA,8);
	  value = ~value;                // Invert the bits
    value = value & 0b11111111;    // Mask to keep only the last 8 bits
    value = value <<1;
    value = ~value;
    value = value &0b11111111 ;
   	 }
	 } 
			for (int ii=0;ii<=8;ii++)
		   {	t[ii]=t[ii]<<1; }
	}
      for(int yo=0;yo<7;yo++)
      {
      for (int io=0;io<=8;io++)
		   {	t[io]=t[io]>>1; }
		  }
		}

		
		void drow(unsigned short x,unsigned short y) 
		{
		unsigned char	xx=0x00;                //   |----x  all off
	  unsigned char yy=0b11111111;          //  y|       all off
    
	  unsigned char mask = ~(1 << y);   // Create a mask by shifting 1 to the left to target the 4th bit, then invert it         
    yy = yy & mask;                   // Apply the mask to clear the 4th bit
			
    xx = xx | (1 << x);             	// Set the 4th bit by shifting 1 to the left by 4 positions
				
	  UART_TX(2,xx);                    // transmet
	  UART_TX(2,yy);
		//DelayMs(1);
    for(int i=0;i<2800;i++){}
    toggle_GP(PA,8);
	  toggle_GP(PA,8);
			
		}
		
		void game_tank(unsigned char y)
		{
			for (int v=0;v<10;v++){
		drow(1,y);
		drow(0,y);
		drow(0,y+1);
		drow(0,y-1);
			}
		}
	






