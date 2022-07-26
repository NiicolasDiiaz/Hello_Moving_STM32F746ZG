#include <stdio.h>
#include "STM32F7xx.h"

int hola[4] = {272,2,354,16};
int i=0;
int tiempo=1000;
int a=0;

int main(void){
	
		RCC->AHB1ENR=0xE;
	
		GPIOB->MODER=0x11554;
		GPIOB->OTYPER=0;
		GPIOB->OSPEEDR=0x11554;
		GPIOB->PUPDR=0;
	
		GPIOD->MODER=0x5500;
		GPIOD->OTYPER=0;
		GPIOD->OSPEEDR=0X5500;
		GPIOD->PUPDR=0;
	
		SystemCoreClockUpdate();
		SysTick_Config(SystemCoreClock/2);
	
		while(true){
			
			GPIOB->ODR=hola[a];
			GPIOD->ODR=(16<<i); //Habilitador se activa con uno
			i++;
			for(int c=0; c<tiempo; c++);
			a++;			
			if(a==4){a=0;}
			if(i==4){i=0;}
		}
}
extern "C" {
	void SysTick_Handler (void){	
		while(i<3){	
		i++;}
	}
}