#include  "fire.h"
#include "tim.h"
#include "adc.h"

void Fire_Init(void)
{
 HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_1);
 HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_2);
}

void Put_On_Fire(void)
{
 if((HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_3)==0)&(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_4)==1))
 {
	__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_2,36);
  HAL_Delay(200);
  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2,GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3,GPIO_PIN_SET);
  __HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_1,1000);
 }
 if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_4)==0)
 {
	__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_2,136);
  HAL_Delay(200);
  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2,GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3,GPIO_PIN_SET);
  __HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_1,1000);
 }
 if((HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_4)&HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_3))==1)
 {
  __HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_2,86);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2,GPIO_PIN_SET);
  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3,GPIO_PIN_SET);
  __HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_1,0);
 }

}

uint16_t ADC_Value=0;
uint16_t dong_get_adc(void)
{
 HAL_ADC_Start(&hadc1);
 HAL_ADC_PollForConversion(&hadc1,100);
 if(HAL_IS_BIT_SET(HAL_ADC_GetState(&hadc1),HAL_ADC_STATE_REG_EOC))
 {
 return HAL_ADC_GetValue(&hadc1);
 }
 return 0;
}
