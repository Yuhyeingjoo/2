/*
	kernel.c

	22/01/06

	Author: HJ
*/

#include "stdint.h"
#include "stdbool.h"

#include "kernel.h"

void Kernel_start(void){
	Kernel_task_start();
}

void Kernel_yield(void){
	Kernel_task_scheduler();
}
