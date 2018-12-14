
#include "stm8s.h"
#include "stm8s_clk.h"
#include "led.h"


#define LED1_ON()  GPIO_WriteLow(GPIOB, GPIO_PIN_4)
#define LED1_OFF() GPIO_WriteHigh(GPIOB, GPIO_PIN_4)

#define LED2_ON()  GPIO_WriteLow(GPIOB, GPIO_PIN_5)
#define LED2_OFF() GPIO_WriteHigh(GPIOB, GPIO_PIN_5)

void delay(int x) {
  unsigned int i, j;
  for(i=0;i<x;i++) {
    for(j=0;j<10000;j++);
  }
}

int main(void)
{
   CLK_HSIPrescalerConfig(CLK_PRESCALER_CPUDIV16);
   GPIO_Init(GPIOB,(GPIO_PIN_4|GPIO_PIN_5), GPIO_MODE_OUT_PP_HIGH_FAST );
   LED1_OFF();
   LED2_OFF();
  while (1)
  {
    LED1_ON();
    delay(200);
    LED1_OFF();
    delay(200);    
  }
}





#ifdef USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param file: pointer to the source file name
  * @param line: assert_param error line source number
  * @retval : None
  */
void assert_failed(u8* file, u32 line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/******************* (C) COPYRIGHT ���iCreateǶ��ʽ���������� *****END OF FILE****/
