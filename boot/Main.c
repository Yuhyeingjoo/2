#include "stdint.h"
#include "stdbool.h"

#include "HalUart.h"
#include "HalInterrupt.h"
#include "stdio.h"
#include "kernel.h" 

static void Hw_init(void);
static void Printf_test(void);
static void Kernel_init(void);
void User_task0();

void main(void)

{
    Hw_init();

    uint32_t i = 100;
    
	/*
	while(i--)
    {
        Hal_uart_put_char('N');
    }
	*/

    Hal_uart_put_char('\n');
    putstr("Hello World!\n");
	Kernel_init();
    while(true);
}

static void Hw_init(void)
{
    Hal_interrupt_init();
    Hal_uart_init();
}

static void Printf_test(void)
{
    char* str = "printf pointer test";
    char* nullptr = 0;
    uint32_t i = 5;

    debug_printf("%s\n", "Hello printf");
    debug_printf("output string pointer: %s\n", str);
    debug_printf("%s is null pointer, %u number\n", nullptr, 10);
    debug_printf("%u = 5\n", i);
    debug_printf("dec=%u hex=%x\n", 0xff, 0xff);
    debug_printf("print zero %u\n", 0);
}

void User_task0(){
	debug_printf("USer task #0\n");
	while(true){
		Kernel_yield();
	}
}

void User_task1(){
	debug_printf("USer task #1\n");
	while(true){
		Kernel_yield();
	}
}

void User_task2(){
	debug_printf("USer task #2\n");
	while(true){
		Kernel_yield();
	}
}

static void Kernel_init(void){
	uint32_t taskId;
	putstr("Kernel init\n");
	Kernel_task_init();
	
	taskId =Kernel_task_create(User_task0);
	if(taskId ==NOT_ENOUGH_TASK_NUM){
		putstr("Task0 creation failed\n");
	}
	taskId =Kernel_task_create(User_task1);
	if(taskId ==NOT_ENOUGH_TASK_NUM){
		putstr("Task1 creation failed\n");
	}

	taskId =Kernel_task_create(User_task2);
	if(taskId ==NOT_ENOUGH_TASK_NUM){
		putstr("Task2 creation failed\n");
	}
	Kernel_start();
}
