#include "ultrasonic.h"
#include "tim.h"


int time_pulse=0;
int real_distance=0;
int time=0;


/*Trig引脚拉高电平发送脉冲，放入主函数循环之中使用*/
void Impulse_Transmission(void)
{
	  real_distance=time_pulse;
		time_pulse=0;
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_3,GPIO_PIN_SET);
		HAL_Delay(2);
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_3,GPIO_PIN_RESET);
    HAL_Delay(30);
}


/*Echo引脚接收电平，写入中断中，判断目标与超声波传感器距离*/
void Distance_Judge(void)
{
	time=HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_4);
	if(time)
	{
	 time_pulse++;
	}
}

