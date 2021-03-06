/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : RTOSTICKLDD1.h
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Component   : TimerUnit_LDD
**     Version     : Component 01.139, Driver 01.09, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2012-12-26, 14:08, # CodeGen: 28
**     Abstract    :
**          This TimerUnit component provides a low level API for unified hardware access across
**          various timer devices using the Prescaler-Counter-Compare-Capture timer structure.
**     Settings    :
**          Component name                                 : RTOSTICKLDD1
**          Module name                                    : SysTick
**          Counter                                        : SYST_CVR
**          Counter direction                              : Down
**          Counter width                                  : 24 bits
**          Value type                                     : Optimal
**          Input clock source                             : Internal
**            Counter frequency                            : Auto select
**          Counter restart                                : On-match
**            Period device                                : SYST_RVR
**            Period                                       : 10 ms
**            Interrupt                                    : Enabled
**              Interrupt                                  : INT_SysTick
**              Interrupt priority                         : medium priority
**          Channel list                                   : 0
**          Initialization                                 : 
**            Enabled in init. code                        : yes
**            Auto initialization                          : no
**            Event mask                                   : 
**              OnCounterRestart                           : Enabled
**              OnChannel0                                 : Disabled
**              OnChannel1                                 : Disabled
**              OnChannel2                                 : Disabled
**              OnChannel3                                 : Disabled
**              OnChannel4                                 : Disabled
**              OnChannel5                                 : Disabled
**              OnChannel6                                 : Disabled
**              OnChannel7                                 : Disabled
**          CPU clock/configuration selection              : 
**            Clock configuration 0                        : This component enabled
**            Clock configuration 1                        : This component enabled
**            Clock configuration 2                        : This component enabled
**            Clock configuration 3                        : This component enabled
**            Clock configuration 4                        : This component enabled
**            Clock configuration 5                        : This component enabled
**            Clock configuration 6                        : This component enabled
**            Clock configuration 7                        : This component enabled
**     Contents    :
**         Init            - LDD_TDeviceData* RTOSTICKLDD1_Init(LDD_TUserData *UserDataPtr);
**         Deinit          - void RTOSTICKLDD1_Deinit(LDD_TDeviceData *DeviceDataPtr);
**         Enable          - LDD_TError RTOSTICKLDD1_Enable(LDD_TDeviceData *DeviceDataPtr);
**         Disable         - LDD_TError RTOSTICKLDD1_Disable(LDD_TDeviceData *DeviceDataPtr);
**         GetCounterValue - RTOSTICKLDD1_TValueType RTOSTICKLDD1_GetCounterValue(LDD_TDeviceData...
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __RTOSTICKLDD1_H
#define __RTOSTICKLDD1_H

/* MODULE RTOSTICKLDD1. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */

#include "PE_LDD.h"
#include "SysTick_PDD.h"
#include "Cpu.h"


#ifndef __BWUserType_RTOSTICKLDD1_TValueType
#define __BWUserType_RTOSTICKLDD1_TValueType
  typedef uint32_t RTOSTICKLDD1_TValueType ; /* Type for data parameters of methods */
#endif
#define RTOSTICKLDD1_CNT_INP_FREQ_U_0 0x01400000UL /* Counter input frequency in Hz */
#define RTOSTICKLDD1_CNT_INP_FREQ_R_0 20971395.017196544F /* Counter input frequency in Hz */
#define RTOSTICKLDD1_CNT_INP_FREQ_COUNT 0U /* Count of predefined counter input frequencies */
#define RTOSTICKLDD1_PERIOD_TICKS 0x00033333UL /* Initialization value of period in 'counter ticks' */
#define RTOSTICKLDD1_NUMBER_OF_CHANNELS 0x00U /* Count of predefined channels */
#define RTOSTICKLDD1_COUNTER_WIDTH 0x18U /* Counter width in bits  */
#define RTOSTICKLDD1_COUNTER_DIR DIR_DOWN /* Direction of counting */
/* Peripheral base address of a device allocated by the component. This constant can be used directly in PDD macros. */
#define RTOSTICKLDD1_PRPH_BASE_ADDRESS  0xE000E010U
  
/* Methods configuration constants - generated for all enabled component's methods */
#define RTOSTICKLDD1_Init_METHOD_ENABLED
#define RTOSTICKLDD1_Deinit_METHOD_ENABLED
#define RTOSTICKLDD1_Enable_METHOD_ENABLED
#define RTOSTICKLDD1_Disable_METHOD_ENABLED
#define RTOSTICKLDD1_GetCounterValue_METHOD_ENABLED

/* Events configuration constants - generated for all enabled component's events */
#define RTOSTICKLDD1_OnCounterRestart_EVENT_ENABLED



LDD_TDeviceData* RTOSTICKLDD1_Init(LDD_TUserData *UserDataPtr);
/*
** ===================================================================
**     Method      :  RTOSTICKLDD1_Init (component TimerUnit_LDD)
**
**     Description :
**         Initializes the device. Allocates memory for the device data
**         structure, allocates interrupt vectors and sets interrupt
**         priority, sets pin routing, sets timing, etc. If the
**         property <"Enable in init. code"> is set to "yes" value then
**         the device is also enabled (see the description of the
**         <Enable> method). In this case the <Enable> method is not
**         necessary and needn't to be generated. This method can be
**         called only once. Before the second call of Init the <Deinit>
**         must be called first.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer will be
**                           passed as an event or callback parameter.
**     Returns     :
**         ---             - Pointer to the dynamically allocated
**                           private structure or NULL if there was an
**                           error.
** ===================================================================
*/

void RTOSTICKLDD1_Deinit(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  RTOSTICKLDD1_Deinit (component TimerUnit_LDD)
**
**     Description :
**         Deinitializes the device. Switches off the device, frees the
**         device data structure memory, interrupts vectors, etc.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by Init method
**     Returns     : Nothing
** ===================================================================
*/

LDD_TError RTOSTICKLDD1_Enable(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  RTOSTICKLDD1_Enable (component TimerUnit_LDD)
**
**     Description :
**         Enables the component - it starts the signal generation.
**         Events may be generated (see SetEventMask). The method is
**         not available if the counter can't be disabled/enabled by HW.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration
** ===================================================================
*/

LDD_TError RTOSTICKLDD1_Disable(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  RTOSTICKLDD1_Disable (component TimerUnit_LDD)
**
**     Description :
**         Disables the component - it stops signal generation and
**         events calling. The method is not available if the counter
**         can't be disabled/enabled by HW.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration
** ===================================================================
*/

RTOSTICKLDD1_TValueType RTOSTICKLDD1_GetCounterValue(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  RTOSTICKLDD1_GetCounterValue (component TimerUnit_LDD)
**
**     Description :
**         Returns the content of counter register. This method can be
**         used both if counter is enabled and if counter is disabled.
**         The method is not available if HW doesn't allow reading of
**         the counter.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     :
**         ---             - Counter value (number of counted ticks).
** ===================================================================
*/

/* {FreeRTOS RTOS Adapter} ISR function prototype */
PE_ISR(RTOSTICKLDD1_Interrupt);
/*
** ===================================================================
**     Method      :  RTOSTICKLDD1_Interrupt (component TimerUnit_LDD)
**
**     Description :
**         The method services the interrupt of the selected peripheral(s)
**         and eventually invokes event(s) of the component.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

/* END RTOSTICKLDD1. */

#endif
/* ifndef __RTOSTICKLDD1_H */
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
