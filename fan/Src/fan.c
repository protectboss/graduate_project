#include "fan.h"
#include "adc.h"


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
