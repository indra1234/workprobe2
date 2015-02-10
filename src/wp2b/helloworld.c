/**
 *  @file      src
 *  @brief     PC based multiple Sensor Control.This is the microcontroller based project where I just interfaced sensors with P89VRD2BN/PIC18F458 microcontroller. In here I used two optical or light sensors, microcontroller and motor. The main object of this project is control the motor speed or motion with respect to sensor value. Its applications in everywhere just like as in Automation industry, Aerospace and Biomedical industry. In here I just used two optical sensors for control the A.C or D.C motors. The main skills used Embedded system, programming in c and Analogy & Digital Circuit in Multisim.
 *  @version   1.00, 
 *             programming language "C",
 *             development tool chain "keil "
 *             and "Microelectronika "
 *             and "Code composer studio"
 *  @date      2015-01-31
 *  @copyright Apache License, Version 2.0
 *
 *  
 *
 *  Copyright 1988-2015 Indrajit Paul
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing,
 *  software distributed under the License is distributed on an
 *  "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 *  either express or implied.
 *  See the License for the specific language governing permissions
 *  and limitations under  the License. .....*/

#include<reg52.h>
#include<stdio.h>
#include "8051.H"
//#include "justmisra.h"

void main(void)
{
char str[20];
	int a=234;
    #ifndef P89V51RD2
	BUZZER=0; 
	#endif
	LCD_Init();	
	LCD_String(0x80,"Hello World");//Print the count at 2nd Line, 3rd Column //
	Delay(1000);
	sprintf(str,"i = %d ",a);
	LCD_String(LINE2+COLUMN3,str);// Print the count at 2nd Line, 3rd Column //
	while(1); //Embedded Program never Ends //
}
