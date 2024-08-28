
/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  main
 *        Author: ahmed wahdan
 *		   Date:  Mar 2, 2024
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/



#include "stm32f10x.h"    
#include "gp_drive.h" 
#include "systick_time.h"
#include "uart_drive.h"
#include "7segment.h"
#include "led_matrex.h"

char chat = 'a';

int t[8]= {0x2, 0x7, 0x2, 0x2, 0x2, 0x2, 0x4, 0x0};
int w[8]={0x0, 0x92, 0x92, 0x92, 0x92, 0x54, 0x38, 0x0};
int a[8]={0x10, 0x28, 0x44, 0x7c, 0x44, 0x44, 0x44, 0x44};
int h[8]={0x22, 0x22, 0x22, 0x3e, 0x22, 0x22, 0x22, 0x22};
int d[8]={0x10, 0x10, 0x1e, 0x11, 0x11, 0x19, 0x16, 0x0};
int n[8]={0x0, 0x42, 0x46, 0x4a, 0x52, 0x62, 0x42, 0x0};

int main(void)
{
systick_init();
UART_init(2,4000000);    // UART2 , 4MHZ 
init_GP(PA,8,OUT50,1);  // red led on
USART2->CR2 = 0XB00;    // CLK of uart2 
	
 init_GP(PA,11,IN,I_PP);
 init_GP(PA,12,IN,I_PP);
 init_GP(PA,15,IN,I_PP);
		
while(1)
	{
		int v=3; short k; 
		short	dw1=0;short dw2=0;short dw3=0;
		int dw11=0; short dw21=0;short dw31=0;
	  short	dw12=0;short dw22=0; short dw32=0;
	  short	dw13=0;short dw23=0;short dw33=0;
	  short	dw14=0;short dw24=0;short dw34=0;
		
	  short f1=0; short f2=0;short f3=0;short f4=0;short f5=0;
		
		
		shift(w,10);shift(a,10);shift(h,10);shift(d,10);shift(a,10);shift(n,10);  // my name
		
		for (int i=0; i<900;i++){
		if(R_GP(PA,11)==1)  { 	v++;  }
		if(R_GP(PA,12)==1)	{		v--	;}
		
		if(R_GP(PA,15)==1)
			{	
      for (int i=0; i<4;i++)  {drow(3,v);drow(4,v);drow(6,v);drow(7,v); k=v;  }
	  	}
			 if (k==3){f1=0;dw1=0; dw2=0; dw3=0;}
			 if (k==0){f2=0;dw11=0; dw21=0; dw31=0;}
			 if (k==7){f3=0;dw12=0; dw22=0; dw32=0;}
			 if (k==2){f4=0;dw13=0; dw23=0; dw33=0;}
			 if (k==5){f5=0;dw14=0; dw24=0; dw34=0;}
			
			 for (int i=0; i<5;i++)
			 { 
      if (f1>=v+10  && k!=3)  { drow(7,3); if(dw1>50){drow(6,3);}  if(dw2>100){drow(5,3);}  if(dw3>150){drow(4,3);}}
		  if (f2>=v+40  && k!=0)  { drow(7,0); if(dw11>50){drow(6,0);}  if(dw21>100){drow(5,0);}  if(dw31>150){drow(4,0);}}
			if (f3>=v+20  && k!=7)  { drow(7,7); if(dw12>50){drow(6,7);}  if(dw22>100){drow(5,7);}  if(dw32>150){drow(4,7);}}
		  if (f4>=v+30  && k!=2)  { drow(7,2); if(dw13>50){drow(6,2);}  if(dw23>100){drow(5,2);}  if(dw33>150){drow(4,2);}}
			if (f5>=v+15  && k!=2)  { drow(7,5); if(dw14>50){drow(6,2);}  if(dw24>100){drow(5,2);}  if(dw34>150){drow(4,5);}}
			  }
		game_tank(v);
     
    f1++; f2++; f3++; f4++;f5++;
		dw1++;  dw2++;  dw3++; 
		dw11++; dw21++; dw31++;
		dw12++; dw22++; dw32++;
		dw13++; dw23++; dw33++;
		dw14++; dw24++; dw34++;
 
	}
		
		//DelayMs(100);

	//	shift(w,10);
		//shift(a,10);
		//shift(h,10);
		//shift(d,10);
		//shift(a,10);
		//shift(n,10);
	//	max_print(t,1000); 
	//	max_print(a,1000);
		//max_print(n,1000);
	
	
		
		
	 // count (99,500);
	//	seg_print0to99(19,500 , 2);
	//	seg_print0to99(4,500 , 2);
	}
}


