#include <reg51.h>

sbit signal = P3^7;
sbit LED = P2^0;
sbit receiverOutput = P3^3;

int sign = 1;
int overflow = 1;
void Timer1_ISR (void) interrupt 3{
		
		
	
		if(sign == 0){
			signal = 0;
		}else if(sign == 1){
			signal = ~signal;
		}
	
	}

	
void Timer0_ISR (void) interrupt 1{
	
	TH0 = 0xFB;
	TL0 = 0xAE;
	TF0 = 0;

	if(sign == 0){
	
		if(overflow == 33){
			sign = 1;
			overflow = 0;
		}else{
			overflow++;
	} 
		
	}else if(sign == 1)sign=0;
		

	}

void main(){
	
	TMOD = 0x29;
	TH0 = 0xFB;
	TL0 = 0xAE;
	TF0 = 0;
	TR0 = 1;
	
	
	
	
	
	TH1 = 0xE8;
	TR1 = 1;
	
	EA = 1;
	ET0 = 1;
	ET1 = 1;
	
	while(1){
		if(receiverOutput == 0) LED=0;	//LED on
		else if(receiverOutput == 1) LED=1;	//LED off
	}

}