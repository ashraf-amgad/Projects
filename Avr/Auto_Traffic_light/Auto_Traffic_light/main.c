/*
 * Auto_Traffic_light.c
 *
 * Created: 9/19/2019 9:18:31 AM
 *  Author: Louda
 */ 

#include "int.h"

s8 counter_down_1;
s8 counter_down_2;

int main(void)
{
	Leds_voidinit();
	seg_voidinit();
	Switches_voidinit();
	
	Switches_voidTurnPullUp(Switch_1);
	
    while(1)
    {
        turnOn_green();
		turnOn_yellow();
		turnOn_red();
    }
	
	return 0;
}
