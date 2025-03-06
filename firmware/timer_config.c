#include "timer_config.h"
#include "stm32f4xx.h"

volatile uint32_t pulseCount = 0;

void TIM2_IRQHandler() {
    if (TIM2->SR & TIM_SR_UIF) {  // Check if update interrupt flag is set
        TIM2->SR &= ~TIM_SR_UIF;  // Clear flag
        pulseCount++;
    }
}

void setupTimer() {
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN; // Enable TIM2 clock

    TIM2->PSC = 16000 - 1; // Set prescaler (1ms tick)
    TIM2->ARR = 1000;      // Auto-reload value (1s period)
    TIM2->DIER |= TIM_DIER_UIE; // Enable update interrupt
    TIM2->CR1 |= TIM_CR1_CEN;   // Enable timer

    NVIC_EnableIRQ(TIM2_IRQn);  // Enable TIM2 interrupt in NVIC
}
