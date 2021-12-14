#ifndef _LED_H_
#define _LED_H_

#include "config.h"

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

void ledr_on();
void ledr_off();
void ledg_on();
void ledg_off();
void ledb_on();
void ledb_off();
void rgbrr();
void motor_on();
void motor_off();

#endif