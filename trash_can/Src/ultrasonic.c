#include "ultrasonic.h"
#include "tim.h"


int time_pulse=0;
int real_distance=0;
int time=0;


/*Trig�������ߵ�ƽ�������壬����������ѭ��֮��ʹ��*/
void Impulse_Transmission(void)
{
	  real_distance=time_pulse;
		time_pulse=0;
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_3,GPIO_PIN_SET);
		HAL_Delay(2);
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_3,GPIO_PIN_RESET);
    HAL_Delay(30);
}


/*Echo���Ž��յ�ƽ��д���ж��У��ж�Ŀ���볬��������������*/
void Distance_Judge(void)
{
	time=HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_4);
	if(time)
	{
	 time_pulse++;
	}
}

