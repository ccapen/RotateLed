#ifndef _LED_H_
#define _LED_H_

#include "config.h"
#include "stc15fxxxx.h"

#define LEDR P34
#define LEDG P35
#define LEDB P36
#define KEY P33
#define MOTORCTL P37
#define LOCASIGNAL P32
#define LOCA_ON 1
#define LOCA_OFF 0
#define T_ON 0
#define T_OFF 1
#define SPD_TWORK 0x40		//(2.56s/r)==(0x80*20ms)//0x40==1.28s/r
#define SPD_TWORKC 0x20		//0x20==0.64s/r
//#define T1MS (65536-MAIN_Fosc/12/1000) //12T@set to 1ms
#define T1MS (65536-MAIN_Fosc/6/100) //12T@set to 20ms
#define DEGREE_DIVMAX 56

extern unsigned char spd_t=0xff;
unsigned char time=0,time_ov=0;


void ledr_on(){
	LEDR = T_ON;
}
void ledr_off(){
	LEDR = T_OFF;
}
void ledg_on(){
	LEDG = T_ON;
}
void ledg_off(){
	LEDG = T_OFF;
}
void ledb_on(){
	LEDB = T_ON;
}
void ledb_off(){
	LEDB = T_OFF;
}
void rgbrr(){
	unsigned char tmp;
	tmp=(P3|0x8f)*2;
	P3 |= 0x70;
	if(tmp&0x80) tmp++;
	else tmp=0xef;
	P3&=tmp;
}
void motor_on(){
	MOTORCTL=T_ON;
}
void motor_off(){
	MOTORCTL=T_OFF;
}

void exint0() interrupt 0       //INT0@LOCASIGNAL
{
	if(time_ov) {time_ov=0;spd_t=0xff;}
	else spd_t=time;
	time=0;
}
void tm0_isr() interrupt 1 using 1       /* Timer0 interrupt routine */
{
	time++;	
	if(time==0xff) time_ov=1;
}


#endif