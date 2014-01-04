#include <stdio.h>
#include <stdlib.h>
#include <bcm2835.h>

void c_irq_handler(void) {}
void c_fiq_handler(void) {}

#ifdef ENABLE_FRAMEBUFFER
extern void bcm2835_console_begin(void);
#endif

extern void cpu_info(void);
extern void mem_info(void);

extern unsigned int heap_end;

int notmain ( unsigned int earlypc )
{
    bcm2835_uart_begin();

#ifdef ENABLE_FRAMEBUFFER
	bcm2835_console_begin();
#endif

    printf("Hello World!\n");

    uint64_t ts = bcm2835_st_read();

    mem_info();

    printf("\n%ld usec elapsed\n\n", (long int)(bcm2835_st_read() - ts));

	cpu_info();

	int alloc_size = 1;
	void *ptr = NULL;

    do {
		ptr = realloc(ptr, alloc_size);
		if (ptr == NULL ) {
			puts("Out of memory!\nProgram halting.");
			for (;;)
				;
		} else {
			printf("new alloc of %d bytes at address 0x%X\n", alloc_size, (unsigned int) ptr);
			alloc_size <<= 1;
			printf("Heap end = 0x%X\n", (unsigned int) heap_end);
		}
	} while (1);

    return 0;
}