/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : LED_Onboard_Green.c
**     Project     : FRDM_KL25Z_Shell_Test
**     Processor   : MKL25Z128VLK4
**     Component   : LED
**     Version     : Component 01.074, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2018-03-07, 11:47, # CodeGen: 6
**     Abstract    :
**          This component implements a universal driver for a single LED.
**     Settings    :
**          Component name                                 : LED_Onboard_Green
**          Turned On with initialization                  : no
**          HW Interface                                   : 
**            On/Off                                       : Enabled
**              Pin                                        : LEDpin
**            PWM                                          : Disabled
**            High Value means ON                          : no
**          Shell                                          : Enabled
**            Shell                                        : CLS1
**            Utility                                      : UTIL1
**     Contents    :
**         On           - void LED_Onboard_Green_On(void);
**         Off          - void LED_Onboard_Green_Off(void);
**         Neg          - void LED_Onboard_Green_Neg(void);
**         Get          - uint8_t LED_Onboard_Green_Get(void);
**         Put          - void LED_Onboard_Green_Put(uint8_t val);
**         SetRatio16   - void LED_Onboard_Green_SetRatio16(uint16_t ratio);
**         ParseCommand - uint8_t LED_Onboard_Green_ParseCommand(const unsigned char *cmd, bool...
**         Deinit       - void LED_Onboard_Green_Deinit(void);
**         Init         - void LED_Onboard_Green_Init(void);
**
**     * Copyright (c) 2013-2017, Erich Styger
**      * Web:         https://mcuoneclipse.com
**      * SourceForge: https://sourceforge.net/projects/mcuoneclipse
**      * Git:         https://github.com/ErichStyger/McuOnEclipse_PEx
**      * All rights reserved.
**      *
**      * Redistribution and use in source and binary forms, with or without modification,
**      * are permitted provided that the following conditions are met:
**      *
**      * - Redistributions of source code must retain the above copyright notice, this list
**      *   of conditions and the following disclaimer.
**      *
**      * - Redistributions in binary form must reproduce the above copyright notice, this
**      *   list of conditions and the following disclaimer in the documentation and/or
**      *   other materials provided with the distribution.
**      *
**      * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**      * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**      * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**      * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**      * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**      * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**      * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**      * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**      * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**      * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
** ###################################################################*/
/*!
** @file LED_Onboard_Green.c
** @version 01.00
** @brief
**          This component implements a universal driver for a single LED.
*/         
/*!
**  @addtogroup LED_Onboard_Green_module LED_Onboard_Green module documentation
**  @{
*/         

/* MODULE LED_Onboard_Green. */

#include "LED_Onboard_Green.h"

static uint8_t PrintStatus(const CLS1_StdIOType *io) {
  CLS1_SendStatusStr((unsigned char*)"LED_Onboard_Green", (unsigned char*)"\r\n", io->stdOut);
  if (LED_Onboard_Green_Get()!=0) {
    CLS1_SendStatusStr((unsigned char*)"  on", (unsigned char*)"yes\r\n", io->stdOut);
  } else {
    CLS1_SendStatusStr((unsigned char*)"  on", (unsigned char*)"no\r\n", io->stdOut);
  }
  return ERR_OK;
}

static uint8_t PrintHelp(const CLS1_StdIOType *io) {
  CLS1_SendHelpStr((unsigned char*)"LED_Onboard_Green", (unsigned char*)"Group of LED_Onboard_Green commands\r\n", io->stdOut);
  CLS1_SendHelpStr((unsigned char*)"  help|status", (unsigned char*)"Print help or status information\r\n", io->stdOut);
  CLS1_SendHelpStr((unsigned char*)"  on|off|neg", (unsigned char*)"Turns it on, off or toggle it\r\n", io->stdOut);
  return ERR_OK;
}

/*
** ===================================================================
**     Method      :  LED_Onboard_Green_ParseCommand (component LED)
**     Description :
**         Shell Command Line parser. This method is enabled/disabled
**         depending on if you have the Shell enabled/disabled in the
**         properties.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * cmd             - Pointer to command string
**       * handled         - Pointer to variable which tells if
**                           the command has been handled or not
**       * io              - Pointer to I/O structure
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint8_t LED_Onboard_Green_ParseCommand(const unsigned char *cmd, bool *handled, const CLS1_StdIOType *io)
{
  if (UTIL1_strcmp((char*)cmd, CLS1_CMD_HELP)==0 || UTIL1_strcmp((char*)cmd, "LED_Onboard_Green help")==0) {
    *handled = TRUE;
    return PrintHelp(io);
  } else if ((UTIL1_strcmp((char*)cmd, CLS1_CMD_STATUS)==0) || (UTIL1_strcmp((char*)cmd, "LED_Onboard_Green status")==0)) {
    *handled = TRUE;
    return PrintStatus(io);
  } else if (UTIL1_strcmp((char*)cmd, "LED_Onboard_Green on")==0) {
    *handled = TRUE;
    LED_Onboard_Green_On();
    return ERR_OK;
  } else if (UTIL1_strcmp((char*)cmd, "LED_Onboard_Green off")==0) {
    *handled = TRUE;
    LED_Onboard_Green_Off();
    return ERR_OK;
  } else if (UTIL1_strcmp((char*)cmd, "LED_Onboard_Green neg")==0) {
    *handled = TRUE;
    LED_Onboard_Green_Neg();
    return ERR_OK;
  }
  return ERR_OK;
}

/*
** ===================================================================
**     Method      :  LED_Onboard_Green_On (component LED)
**     Description :
**         This turns the LED on.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void LED_Onboard_Green_On(void)
{
  *** This method is implemented as macro in the header file
}
*/

/*
** ===================================================================
**     Method      :  LED_Onboard_Green_Off (component LED)
**     Description :
**         This turns the LED off.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void LED_Onboard_Green_Off(void)
{
  *** This method is implemented as macro in the header file
}
*/

/*
** ===================================================================
**     Method      :  LED_Onboard_Green_Neg (component LED)
**     Description :
**         This negates/toggles the LED
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void LED_Onboard_Green_Neg(void)
{
  *** This method is implemented as macro in the header file
}
*/

/*
** ===================================================================
**     Method      :  LED_Onboard_Green_Get (component LED)
**     Description :
**         This returns logical 1 in case the LED is on, 0 otherwise.
**     Parameters  : None
**     Returns     :
**         ---             - Status of the LED (on or off)
** ===================================================================
*/
/*
uint8_t LED_Onboard_Green_Get(void)
{
  *** This method is implemented as macro in the header file
}
*/

/*
** ===================================================================
**     Method      :  LED_Onboard_Green_Put (component LED)
**     Description :
**         Turns the LED on or off.
**     Parameters  :
**         NAME            - DESCRIPTION
**         val             - value to define if the LED has to be on or
**                           off.
**     Returns     : Nothing
** ===================================================================
*/
/*
void LED_Onboard_Green_Put(uint8_t val)
{
  *** This method is implemented as macro in the header file
}
*/

/*
** ===================================================================
**     Method      :  LED_Onboard_Green_Init (component LED)
**     Description :
**         Performs the LED driver initialization.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void LED_Onboard_Green_Init(void)
{
#if MCUC1_CONFIG_SDK_VERSION_USED != MCUC1_CONFIG_SDK_PROCESSOR_EXPERT
  LEDpin2_Init();
#endif
  LED_Onboard_Green_Off();
}

/*
** ===================================================================
**     Method      :  LED_Onboard_Green_Deinit (component LED)
**     Description :
**         Deinitializes the driver
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void LED_Onboard_Green_Deinit(void)
{
#if MCUC1_CONFIG_SDK_VERSION_USED != MCUC1_CONFIG_SDK_PROCESSOR_EXPERT
  LEDpin2_Deinit();
#endif
}

/*
** ===================================================================
**     Method      :  LED_Onboard_Green_SetRatio16 (component LED)
**     Description :
**         Method to specify the duty cycle. If using a PWM pin, this
**         means the duty cycle is set. For On/off pins, values smaller
**         0x7FFF means off, while values greater means on.
**     Parameters  :
**         NAME            - DESCRIPTION
**         ratio           - Ratio value, where 0 means 'off' and
**                           0xffff means 'on'
**     Returns     : Nothing
** ===================================================================
*/
void LED_Onboard_Green_SetRatio16(uint16_t ratio)
{
  /* on/off LED: binary on or off */
  if (ratio<(0xffff/2)) {
    LED_Onboard_Green_Off();
  } else {
    LED_Onboard_Green_On();
  }
}

/* END LED_Onboard_Green. */

/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.09]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
