#include<reg51.h>
sbit m1n=P2^0; 
sbit m1p=P2^1;
sbit m2n=P2^2;
sbit m2p=P2^3;
//motor control connection.//
void main (){
unsigned char x; //	
//UART serail communication configuration.//	
SCON=0x50;	//Set serial reception enable and Mode 1 8-bit UART.
TMOD=0x20;	//Set Timer 1 in Mode 2 8-bit Auto reload. 
TH1=0xFD;	//Set timer 1 for BAUD=9600 HZ.
TR1=1;		//Start Timer 1.
//Serial Reception
  while(1)
  {
   while(RI==0);   //Wait unitl RI flag is set
    x=SBUF;  			
    RI=0;					
    SBUF=x;	// Test simulation
    while(TI==0);	  
    TI=0;
 	 switch (x) {
            case 'F':	//Robot move forword
                m1p=1; m1n=0;
		m2p=1; m2n=0;
                break;
            case 'B':
                m1p=0; m1n=1;
                m2p=0; m2n=1;

                break;
            case 'L':	//Robot turn left
                m1p=1; m1n=0;
                m2p=0; m2n=1;

                break;
            case 'R':	//Robot turn right
                m1p=0; m1n=1;
                m2p=1; m2n=0;

                break;

            case 'S':	//Robot stop
                m1p=0; m1n=0;
                m2p=0; m2n=0;

                break;
           default:   //Robot stop
                m1p=0; m1n=0;
                m2p=0; m2n=0;

                break;

        }
  }


} 



