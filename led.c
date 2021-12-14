#ifndef _LED_H_
#define _LED_H_

#include "led.h"
#include "config.h"

#define LEDR P34			//seems to a compiler bug, indirect macro definitions are invalid
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

#endif