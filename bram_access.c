#include <stdio.h>
#include "xparameters.h"
#include "platform.h"
#include "xil_printf.h"

// Get these from xparamters.h
#define BRAMBASE_ADDR XPAR_BRAM_0_BASEADDR
#define BRAMHIGH_ADDR XPAR_BRAM_0_HIGHADDR
#define No_of_TXN    10  //  No of Memory location you want

int main()
{
	init_platform();

	xil_printf("Hello World, Testing Memory Region : 0x%x - 0x%x\n", BRAMBASE_ADDR, BRAMHIGH_ADDR);

	xil_printf("Writing %d Words to memory region:\n", No_of_TXN);
	volatile uint32_t *ptr_w = (volatile uint32_t*)(BRAMBASE_ADDR);
	for (int i = 0; i < No_of_TXN; i++) {
		*ptr_w++ = 0xCDAC2020 + i;
	}
	print("Reading a Word from memory region:\n");

	volatile uint32_t *ptr_r = (volatile uint32_t*)(BRAMBASE_ADDR);
	for (int h = 0; h < No_of_TXN; h++) {
		xil_printf("0x%p: %x\n", ptr_r, *ptr_r);
		*ptr_r++;
	}

	cleanup_platform();
	return 0;
}
