/* task.h    
 *
 *
 * Context / Scheduler 
 * 9/30
 *
 * YHJ
 * */


#ifndef KERNEL_TASK_H_
#define KERLEN_TASK_H_

#include "MemoryMap.h"

#define NOT_ENOUGH_TASK_NUM 0XFFFFFFFF

#define USR_TASK_STACK_SIZE 0X100000
#define MAX_TASK_NUM (TASK_STACK_SIZE / USR_TASK_STACK_SIZE)

typedef struct KernelTaskContex_t{
	uint32_t spsr; 
	uint32_t r0_r12[13]; 
	uint32_t pc; 

	uint8_t * staclbase;
}KernelTaskContext_t;

typedef struct KernelTcb_t{
	uint32_t sp;
	uint8_t* stack_base;

}KernalTcb_t;


typedef void (*KernelTaskFunc_t)(void);

void Kernal_task_init(void);
uint32_t Kernel_task_create(kernelTaskFunc_t startFunc);
#endif /* task.h */

