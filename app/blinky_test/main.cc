// #include <cstdint> // defines fixed width integer types

extern "C" void SystemInit(void)
{
    // does something
}
/* OFFSET ADDRESS */

#define RCC_OFFSET (0x00001000UL)

#define AHB2ENR_OFFSET (0x4CUL)

#define ODR_OFFSET (0x14UL)

/* BASE ADDRESS */

#define AHB1_BASE (0x40020000UL)

#define AHB2_BASE (0x48000000UL)

#define GPIOA_BASE (0x48000000UL)

#define RCC_BASE (0x40021000UL)

/* REGISTERS */

#define RCC_AHB2ENR (*(volatile unsigned int *)(RCC_BASE + AHB2ENR_OFFSET))

#define GPIOA_MODER (*(volatile unsigned int *)(GPIOA_BASE + 0x00UL))

#define GPIOA_ODR (*(volatile unsigned int *)(GPIOA_BASE + ODR_OFFSET))

int main (void) {

    /* Enable the GPIO peripheral of Port A */
    RCC_AHB2ENR |= (1U << 0); // turn on bit 0

    /* Set PA5's MODER to output, which is MODER5 */
    GPIOA_MODER |= (1U << 10); // set bit 10 to 1
    GPIOA_MODER &= ~(1U << 11); // set bit 11 to 0

    while (1) {
        /* Toggle PA5 on and off repeatedly by writing to its ODR */
        GPIOA_ODR ^= (1U << 5); // XOR bit 5

        for (int i = 0; i < 1E6; ++i) {
            __asm__("nop"); // do nothing, just waste time
        }
    }
    return 0;
}