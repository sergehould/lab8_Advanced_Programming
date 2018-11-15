 /******************************************************************************
 * File Name: main.c
 * Description: Lab8: Pre-emptive scheduler and priority setting
 *  
 * Author           Date    			Comments
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Serge Hould      Nov.15  2018       v1.0.0
 *
 *
 * TO DO 
 * Add a file all_tasks.c and all_tasks.h  and populate with 9 tasks   
 *********************************************************************************/

/* Standard includes. */
#include <stdio.h>

/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "config.h"

#include "include/pmp_lcd.h"
#include "include/initBoard.h"
#include "process.h"

/*-----------------------------------------------------------*/
/* Task prototypes */
void vTask1( void *pvParameters );
void vTask2( void *pvParameters );
void vTask3( void *pvParameters );
void vTask4( void *pvParameters );
void vTask5( void *pvParameters );
void vTask6( void *pvParameters );
void vTask7( void *pvParameters );
void vTask8( void *pvParameters );
void vTask9( void *pvParameters );

/* Semaphores and mutexes declarations*/
xSemaphoreHandle xMutex1;

int main( void )
{
    OSCILLATOR_Initialize();

    /* The explorer 16 board has LED's on port A.  All bits are set as output
	so PORTA is read-modified-written directly. */
    initIO();
    LCDInit();
    
	//xBinSema = xSemaphoreCreateBinary();
    xMutex1 = xSemaphoreCreateMutex();


	xTaskCreate( vTask1, NULL, 240, NULL, 1, NULL );
    xTaskCreate( vTask2, NULL, 240, NULL, 1, NULL );
    xTaskCreate( vTask3, NULL, 240, NULL, 1, NULL );
	xTaskCreate( vTask4, NULL, 240, NULL, 1, NULL );
    xTaskCreate( vTask5, NULL, 240, NULL, 1, NULL );
    xTaskCreate( vTask6, NULL, 240, NULL, 1, NULL );
	xTaskCreate( vTask7, NULL, 240, NULL, 1, NULL );
    xTaskCreate( vTask8, NULL, 240, NULL, 3, NULL );
    xTaskCreate( vTask9, NULL, 240, NULL, 2, NULL );
  
    
    /* Finally start the scheduler. */
    vTaskStartScheduler();

	/* Will only reach here if there is insufficient heap available to start
	the scheduler. */
    while(1);
	return 0;
}
/*-----------------------------------------------------------*/

void vTask1( void *pvParameters ){
    pvParameters = pvParameters;
    portTickType xLastWakeTime;
    xLastWakeTime = xTaskGetTickCount();
	/* As per most tasks, this task is implemented in an infinite loop. */
	while(1){
		vTaskDelayUntil( &xLastWakeTime, 1000 / portTICK_RATE_MS );
        process1();
        if(!S4) {
            while(1);  // Crash simulation
        }
     //   
    }
}


void vTask2( void *pvParameters ){
    pvParameters = pvParameters;
    portTickType xLastWakeTime;
    xLastWakeTime = xTaskGetTickCount();
	/* As per most tasks, this task is implemented in an infinite loop. */
	while(1){
		vTaskDelayUntil( &xLastWakeTime, 1000 / portTICK_RATE_MS );
        process2();
    }
}


void vTask3( void *pvParameters ){
    pvParameters = pvParameters;
    portTickType xLastWakeTime;
    xLastWakeTime = xTaskGetTickCount();
	/* As per most tasks, this task is implemented in an infinite loop. */
	while(1){
		vTaskDelayUntil( &xLastWakeTime, 1000 / portTICK_RATE_MS );
        process3();
    }
}

void vTask4( void *pvParameters ){
    pvParameters = pvParameters;
    portTickType xLastWakeTime;
    xLastWakeTime = xTaskGetTickCount();
	/* As per most tasks, this task is implemented in an infinite loop. */
	while(1){
		vTaskDelayUntil( &xLastWakeTime, 1000 / portTICK_RATE_MS );
        process4();
    }
}
void vTask5( void *pvParameters ){
    pvParameters = pvParameters;
    portTickType xLastWakeTime;
    xLastWakeTime = xTaskGetTickCount();
	/* As per most tasks, this task is implemented in an infinite loop. */
	while(1){
		vTaskDelayUntil( &xLastWakeTime, 1000 / portTICK_RATE_MS );
        process5();
        
    }
}
void vTask6( void *pvParameters ){
    pvParameters = pvParameters;
    portTickType xLastWakeTime;
    xLastWakeTime = xTaskGetTickCount();
	/* As per most tasks, this task is implemented in an infinite loop. */
	while(1){
		vTaskDelayUntil( &xLastWakeTime, 1000 / portTICK_RATE_MS );
        process6();      
    }
}
void vTask7( void *pvParameters ){
    pvParameters = pvParameters;
    portTickType xLastWakeTime;
    xLastWakeTime = xTaskGetTickCount();
	/* As per most tasks, this task is implemented in an infinite loop. */
	while(1){
		vTaskDelayUntil( &xLastWakeTime, 1000 / portTICK_RATE_MS );       
        process7();     
    }
}

void vTask8( void *pvParameters ){
    pvParameters = pvParameters;
    portTickType xLastWakeTime;
    xLastWakeTime = xTaskGetTickCount();
	/* As per most tasks, this task is implemented in an infinite loop. */
	while(1){
        vTaskDelayUntil( &xLastWakeTime, 125 / portTICK_RATE_MS ); 
        process8();
    }
}

void vTask9( void *pvParameters ){
    pvParameters = pvParameters;
    portTickType xLastWakeTime;
    xLastWakeTime = xTaskGetTickCount();
	/* As per most tasks, this task is implemented in an infinite loop. */
	while(1){
        vTaskDelayUntil( &xLastWakeTime, 500 / portTICK_RATE_MS );
        process9();   
    }
}

void vApplicationIdleHook( void )
{

}
/*-----------------------------------------------------------*/

void vApplicationStackOverflowHook( TaskHandle_t pxTask, char *pcTaskName )
{
    pcTaskName=pcTaskName;
    pxTask=pxTask;
    for( ;; );
}
