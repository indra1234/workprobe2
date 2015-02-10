#ifndef P89V51RD2_H_
#define P89V51RD2_H_
#include <reg52.h>
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
sbit 	LCD_RS=P0^0;
sbit 	LCD_RW=P0^1;
sbit 	LCD_EN=P0^2;
sbit	LCD_BUSY=P1^7;
sbit    BUZZER=P3^3;
sfr		LCD_DATA=0x90;
void 			LCD_Data(unsigned char);
void 			LCD_Command(unsigned char);
void 			LCD_Init(void);
void 			LCD_Decimal(unsigned char pos,unsigned char var);
void 			LCD_Hex(unsigned char pos,unsigned char var);
void 			LCD_String(unsigned char,unsigned char *var);
void 			LCD_Int16(unsigned char pos,unsigned int var,unsigned char n);
void 			LCD_Clear();
void 			Delay(unsigned int tic);  
#endif
void LCD_String(unsigned char pos,unsigned char *var)
{
	LCD_Command(pos);
    while(*var)        //till string ends
    LCD_Data(*var++);  //send characters one by one
}
void LCD_Decimal(unsigned char pos,unsigned char var)
{
	unsigned char d=100;
	LCD_Command(pos);
	while(d!=0)
	{
	LCD_Data(var/d+0x30);
	var=var%d;
	d=d/10;
	}
}
void LCD_Int16(unsigned char pos,unsigned int var,char n)
{
	int d=10000;
	LCD_Command(pos); 
	while(d!=0)
	{
	if((n++)>4)
	LCD_Data(var/d+0x30);
	var=var%d;
	d=d/10;
	}
}
void LCD_Hex(unsigned char pos,unsigned char var)
{
	unsigned char	temp;
	LCD_Command(pos);
	temp=var&0xf0;
	temp=temp>>4;
	if(temp<10)
	LCD_Data(temp+0x30);
	else
	LCD_Data(temp+0x37);

	temp=var&0x0f;
	if(temp<10)
	LCD_Data(temp+0x30);
	else
	LCD_Data(temp+0x37);
}
void LCD_wait()
{
	  LCD_RS=0;
	  LCD_RW=1;
	  LCD_EN=1;
	  LCD_DATA=0x0ff;
	  while(LCD_BUSY==1);
	  LCD_EN=0;
 }
void LCD_Command(unsigned char val)
{
    LCD_wait();
	LCD_RS=0;
	LCD_RW=0;
	LCD_DATA=val;
	LCD_EN=1;
	LCD_EN=0;
}
void LCD_Data(unsigned char val)
{
    LCD_wait();
	LCD_RS=1;
	LCD_RW=0;
	LCD_DATA=val;
	LCD_EN=1;
	LCD_EN=0;
 }
 void LCD_Clear()
 {
   LCD_Command(0x01);
 }
 void LCD_Init()
 {
   LCD_Command(0x38);
   LCD_Command(0x0C);
   LCD_Command(0x06);
   LCD_Command(0x01);
 }
 void Delay(unsigned int tic)
{
	char i;
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