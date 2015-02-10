/*
 * justmisra.h
 *
 *  Created on: Oct 29, 2014
 *      Author: Administrator
 */

#ifndef MSP430_H_
#define MSP430_H_

#include <msp430f5527.h>

#define	LINE1 0x80
#define LINE2 0xC0
#define COLUMN1 0x00
#define COLUMN2 0x01
#define COLUMN3 0x02
#define COLUMN4 0x03
#define COLUMN5 0x04
#define COLUMN6 0x05
#define COLUMN7 0x06
#define COLUMN8 0x07
#define COLUMN9 0x08
#define COLUMN10 0x09
#define COLUMN11 0x0a
#define COLUMN12 0x0b
#define COLUMN13 0x0c
#define COLUMN14 0x0d
#define COLUMN15 0x0e
#define COLUMN16 0x0f
#define LCD_RS       BIT0
#define	LCD_RW       BIT1
#define LCD_EN       BIT2
#define LCD_BUSY     BIT3
#define	LCD_DATA     P4DIR
void LCD_Data(unsigned char);
void LCD_Command(unsigned char);
void LCD_Init(void);
void LCD_Decimal(unsigned char pos,unsigned char var);
void LCD_Hex(unsigned char pos,unsigned char var);
void LCD_String(unsigned char,unsigned char *var);
void LCD_Clear(void);
void Delay(unsigned int tic);
void LCD_start(void);
#endif
volatile unsigned char i;
void Delay(unsigned int tic)
{
        while(tic!=0)
        {
                i=140;
                while(i!=0)
                {
                i--;
                }
                tic--;
        }
}
void LCD_String(unsigned char pos,unsigned char *var)
{
        LCD_Command(pos);
    while(*var)

    LCD_Data(*var++);

}

void LCD_Decimal(unsigned char pos,unsigned char var)
{
        unsigned char d=100;
        LCD_Command(pos);
        while(d!=0)
        {
        LCD_Data(var==var/d+0x30);
        var=(var%d);
        d =(d/10);
        }
        return;
}
void LCD_Hex(unsigned char pos,unsigned char var)
{
        unsigned char        temp;
        LCD_Command(pos);
        temp=(var && 0xf0);
        temp=temp>>4;
        if(temp<10)
        {
        LCD_Data(temp+0x30);
        }
        else
        {
        LCD_Data(temp+0x37);
        temp=(var&& 0x0f);
        }
        if(temp<10)
        {
        LCD_Data(temp+0x30);
        }
        else
        {
        LCD_Data(temp+0x37);
        }
}
void LCD_wait(void);

void LCD_wait(void)
{
          P3DIR |= BIT0;
          P3OUT=0;
          P3DIR |= BIT1;
          P3OUT=0x20;
          P3DIR |= BIT2;
          P3OUT=0x40;
          P4DIR = BIT0 | BIT1 | BIT2 | BIT3 | BIT4 | BIT5 | BIT6 |BIT7 ;
          P4DIR=0xFF;
          while(BIT3==1)
         P3DIR |= BIT2;
          P3OUT =0x00;

 }
void LCD_Command(unsigned char val)
{
        LCD_wait();
        P3DIR |= BIT0;
        P3OUT =0;
        P3DIR |= BIT1;
        P3OUT =0;
        P4DIR = BIT0 | BIT1 | BIT2 | BIT3 | BIT4 | BIT5 | BIT6 |BIT7 ;
        P4DIR=val;
        P3DIR |= BIT2;
        P3OUT =0x40;
        P3DIR |= BIT2;
        P3OUT=0;
}
void LCD_Data(unsigned char val)
{
    LCD_wait();
    P3DIR |= BIT0;
        P3OUT=0x10;
        P3DIR |= BIT1;
        P3OUT =0;
        P4DIR = BIT0 | BIT1 | BIT2 | BIT3 | BIT4 | BIT5 | BIT6 |BIT7 ;
        P4DIR=val;
        P3DIR |= BIT2;
        P3OUT=0x40;
        P3DIR |= BIT2;
        P3OUT=0;
 }
 void LCD_Clear(void)
 {
   LCD_Command(0x01);
 }
 void LCD_Init(void)
 {
   LCD_Command(0x38);
   LCD_Command(0x0C);
   LCD_Command(0x06);
   LCD_Command(0x01);
 }
 volatile unsigned char k;
 void LCD_start(void)
 {
         P3DIR |= LCD_RS;
                 P3OUT &= ~LCD_RS;

                 P3DIR |= LCD_RW;
                 P3OUT &= ~LCD_RW;

                 P3DIR |= LCD_EN;
                 P3OUT &= ~LCD_EN;

                 P3DIR |= LCD_BUSY;
                 P3OUT &= ~LCD_BUSY;
                 k=P4DIR;
                 P4DIR = BIT0 | BIT1 | BIT2 | BIT3 | BIT4 | BIT5 | BIT6 |BIT7 ;
                 P4OUT= 0x00;
 }
