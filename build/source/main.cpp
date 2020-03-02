/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "semphr.h"

/* Hardware includes. */
#include "MKE18F16.h"
#include "pin_mux.h"
#include "clock_config.h"

#include "gpio.h"
#include "adc.h"

using namespace BSP;

void turn( void *pvParameters )
{

    vTaskDelay( 1000 );
    gpio::GPIO::set(gpio::PortD, 1);
    vTaskDelay( 1000 );
    gpio::GPIO::set(gpio::PortD, 0);
    vTaskDelay( 1000 );
    gpio::GPIO::set(gpio::PortB, 7);
    vTaskDelay( 1000 );
    gpio::GPIO::set(gpio::PortB, 6);
    vTaskDelay( 1000 );
    gpio::GPIO::set(gpio::PortE, 3);
    vTaskDelay( 1000 );
    gpio::GPIO::set(gpio::PortD, 16);
    vTaskDelay( 1000 );
    gpio::GPIO::set(gpio::PortD, 15);
    vTaskDelay( 1000 );
    gpio::GPIO::set(gpio::PortE, 9);
    vTaskDelay( portMAX_DELAY );

    for (;;)
    {

    }
}


void lcread( void *pvParameters ){

	static uint16_t v[9];

	static uint16_t i[9];

	adc::ADC& adc = adc::ADC::StaticClass();

	for (;;) {

		v[1] = adc.read(ADC0, 9);
		v[2] = adc.read(ADC0, 10);
		v[3] = adc.read(ADC0, 11);
		v[4] = adc.read(ADC0, 12);
		v[5] = adc.read(ADC0, 13);
		v[6] = adc.read(ADC0, 14);
		v[7] = adc.read(ADC0, 15);
		v[8] = adc.read(ADC0, 0);

		i[1] = adc.read(ADC0, 1);
		i[2] = adc.read(ADC0, 2);
		i[3] = adc.read(ADC0, 3);
		i[4] = adc.read(ADC1, 10);
		i[5] = adc.read(ADC2, 14);
		i[6] = adc.read(ADC1, 11);
		i[7] = adc.read(ADC0, 7);
		i[8] = adc.read(ADC0, 8);

	}
}

int main( void )
{
    BOARD_InitBootClocks();
    BOARD_InitBootPins();

    adc::ADC::ConstructStatic(NULL);

    // you gotta make a task right here
    xTaskCreate(lcread, "lcread", 100, NULL, 0, NULL );
    xTaskCreate(turn, "turn", 100, NULL, 1, NULL );
    
	/* Start the scheduler. */
	vTaskStartScheduler();

	/* Infinite loop */
	for( ;; );
}

extern "C" {

/*-----------------------------------------------------------*/
void vApplicationMallocFailedHook( void )
{
	/* vApplicationMallocFailedHook() will only be called if
	configUSE_MALLOC_FAILED_HOOK is set to 1 in FreeRTOSConfig.h.  It is a hook
	function that will get called if a call to pvPortMalloc() fails.
	pvPortMalloc() is called internally by the kernel whenever a task, queue,
	timer or semaphore is created.  It is also called by various parts of the
	demo application.  If heap_1.c or heap_2.c are used, then the size of the
	heap available to pvPortMalloc() is defined by configTOTAL_HEAP_SIZE in
	FreeRTOSConfig.h, and the xPortGetFreeHeapSize() API function can be used
	to query the size of free heap space that remains (although it does not
	provide information on how the remaining heap might be fragmented). */
	taskDISABLE_INTERRUPTS();
	for( ;; );
}
/*-----------------------------------------------------------*/

void vApplicationIdleHook( void )
{
	/* vApplicationIdleHook() will only be called if configUSE_IDLE_HOOK is set
	to 1 in FreeRTOSConfig.h.  It will be called on each iteration of the idle
	task.  It is essential that code added to this hook function never attempts
	to block in any way (for example, call xQueueReceive() with a block time
	specified, or call vTaskDelay()).  If the application makes use of the
	vTaskDelete() API function (as this demo application does) then it is also
	important that vApplicationIdleHook() is permitted to return to its calling
	function, because it is the responsibility of the idle task to clean up
	memory allocated by the kernel to any task that has since been deleted. */
}
/*-----------------------------------------------------------*/

void vApplicationStackOverflowHook( TaskHandle_t pxTask, char *pcTaskName )
{
	( void ) pcTaskName;
	( void ) pxTask;

	/* Run time stack overflow checking is performed if
	configCHECK_FOR_STACK_OVERFLOW is defined to 1 or 2.  This hook
	function is called if a stack overflow is detected. */
	taskDISABLE_INTERRUPTS();
	for( ;; );
}
/*-----------------------------------------------------------*/

void vApplicationTickHook( void )
{
	/* This function will be called by each tick interrupt if
	configUSE_TICK_HOOK is set to 1 in FreeRTOSConfig.h.  User code can be
	added here, but the tick hook is called from an interrupt context, so
	code must not attempt to block, and only the interrupt safe FreeRTOS API
	functions can be used (those that end in FromISR()). */
}
/*-----------------------------------------------------------*/

}
