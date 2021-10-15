/*
 * task.c
 *
 * Context & Scheduler
 *
 * yhj
 *
 * */
#include "stdint.h"
#include "stdbool.h"

#include "ARMv7AR.h"
#include "task.h"

static KernelTcb_t  sTask_list[MAX_TASK_NUM];
static uint32_t     sAllocated_tcb_index;

void Kernal_task_init(){
	sAllocated_tcp_index = 0;

	for(uint32_t i=0; i<MAX_TASK_NUM; i++){
		sTask_list[i].sp = 
	}


	
}


