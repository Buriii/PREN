/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : DrivingMotor_Step.h
**     Project     : Freedom_LED_Engines
**     Processor   : MKL25Z128VLK4
**     Component   : PPG
**     Version     : Component 02.197, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2018-03-21, 22:24, # CodeGen: 41
**     Abstract    :
**         This component "PPG" implements a programmable
**         pulse generator that generates signal with variable
**         duty and variable cycle (period).
**     Settings    :
**         Used output pin             : 
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       21            |  CMP0_IN5/ADC0_SE4b/PTE29/TPM0_CH2/TPM_CLKIN0
**             ----------------------------------------------------
**
**         Timer name                  : TPM0_CNT [16-bit]
**         Counter                     : TPM0_CNT  [0x40038004]
**         Mode register               : TPM0_SC   [0x40038000]
**         Run register                : TPM0_SC   [0x40038000]
**         Prescaler                   : TPM0_SC   [0x40038000]
**         Compare 1 register          : TPM0_MOD  [0x40038008]
**         Compare 2 register          : TPM0_C2V  [0x40038020]
**         Flip-flop 1 register        : TPM0_SC   [0x40038000]
**         Flip-flop 2 register        : TPM0_C2SC [0x4003801C]
**
**         Interrupt name              : INT_TPM0
**         Interrupt enable reg.       : TPM0_C5SC [0x40038034]
**         Priority                    : 2
**         User handling procedure     : DrivingMotor_Step_OnEnd
**         This event is called when the 1 of cycles is generated
**
**         Output pin
**
**         Port name                   : PTE
**         Bit number (in port)        : 29
**         Bit mask of the port        : 0x20000000
**         Port data register          : GPIOE_PDOR [0x400FF100]
**         Port control register       : GPIOE_PDDR [0x400FF114]
**
**         Runtime setting period      : interval (continual setting)
**             microseconds            : 2 to 3125 microseconds
**             milliseconds            : 1 to 3 milliseconds
**             seconds (real)          : 0.000001001358 to 0.003125 seconds
**             Hz                      : 320 to 998643 Hz
**             kHz                     : 1 to 998 kHz
**
**         Runtime setting ratio       : calculated
**         Initialization:
**              Output level           : low
**              Timer                  : Enabled
**              Event                  : Enabled
**         High speed mode
**             Prescaler               : divide-by-1
**             Clock                   : 20971520 Hz
**           Initial value of            period        pulse width (ratio 2.000%)
**             microseconds            : 2500          50
**             milliseconds            : 3             0
**             seconds (real)          : 0.002500009537 0.000050020218
**
**     Contents    :
**         Enable        - byte DrivingMotor_Step_Enable(void);
**         Disable       - byte DrivingMotor_Step_Disable(void);
**         SetPeriodUS   - byte DrivingMotor_Step_SetPeriodUS(word Time);
**         SetPeriodMS   - byte DrivingMotor_Step_SetPeriodMS(word Time);
**         SetPeriodSec  - byte DrivingMotor_Step_SetPeriodSec(word Time);
**         SetPeriodReal - byte DrivingMotor_Step_SetPeriodReal(float Time);
**         SetFreqHz     - byte DrivingMotor_Step_SetFreqHz(word Freq);
**         SetFreqkHz    - byte DrivingMotor_Step_SetFreqkHz(word Freq);
**         SetFreqMHz    - byte DrivingMotor_Step_SetFreqMHz(word Freq);
**         SetRatio16    - byte DrivingMotor_Step_SetRatio16(word Ratio);
**         SetDutyUS     - byte DrivingMotor_Step_SetDutyUS(word Time);
**         SetDutyMS     - byte DrivingMotor_Step_SetDutyMS(word Time);
**
**     Copyright : 1997 - 2014 Freescale Semiconductor, Inc. 
**     All Rights Reserved.
**     
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**     
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**     
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**     
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**     
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**     
**     http: www.freescale.com
**     mail: support@freescale.com
** ###################################################################*/
/*!
** @file DrivingMotor_Step.h
** @version 01.00
** @brief
**         This component "PPG" implements a programmable
**         pulse generator that generates signal with variable
**         duty and variable cycle (period).
*/         
/*!
**  @addtogroup DrivingMotor_Step_module DrivingMotor_Step module documentation
**  @{
*/         

#ifndef __DrivingMotor_Step_H
#define __DrivingMotor_Step_H

/* MODULE DrivingMotor_Step. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */
#include "PpgLdd2.h"

#include "Cpu.h"


#define DrivingMotor_Step_PERIOD_VALUE PpgLdd2_PERIOD_TICKS /* Initial period value in ticks of the timer. It is available only if the bean is enabled in high speed mode. */
#define DrivingMotor_Step_PERIOD_VALUE_HIGH PpgLdd2_PERIOD_TICKS_0 /* Period value in ticks of the timer in high speed mode. It is available only if the bean is enabled in high speed mode. */
#ifdef PpgLdd2_SPUS_MIN
#define DrivingMotor_Step_SPUS_MIN PpgLdd2_SPUS_MIN /* Lower bound of interval for parameter of method SetPeriodUS */
#endif
#ifdef PpgLdd2_SPUS_MAX
#define DrivingMotor_Step_SPUS_MAX PpgLdd2_SPUS_MAX /* Upper bound of interval for parameter of method SetPeriodUS */
#endif
#ifdef PpgLdd2_SPMS_MIN
#define DrivingMotor_Step_SPMS_MIN PpgLdd2_SPMS_MIN /* Lower bound of interval for parameter of method SetPeriodMS. */
#endif
#ifdef PpgLdd2_SPMS_MAX
#define DrivingMotor_Step_SPMS_MAX PpgLdd2_SPMS_MAX /* Upper bound of interval for parameter of method SetPeriodMS. */
#endif
#ifdef PpgLdd2_SPSEC_MIN
#define DrivingMotor_Step_SPSEC_MIN PpgLdd2_SPSEC_MIN /* Lower bound of interval for parameter of method SetPeriodSec. */
#endif
#ifdef PpgLdd2_SPSEC_MAX
#define DrivingMotor_Step_SPSEC_MAX PpgLdd2_SPSEC_MAX /* Upper bound of interval for parameter of method SetPeriodSec. */
#endif
#ifdef PpgLdd2_SPREAL_MIN
#define DrivingMotor_Step_SPREAL_MIN PpgLdd2_SPREAL_MIN /* Lower bound of interval for parameter of method SetPeriodReal. */
#endif
#ifdef PpgLdd2_SPREAL_MAX
#define DrivingMotor_Step_SPREAL_MAX PpgLdd2_SPREAL_MAX /* Upper bound of interval for parameter of method SetPeriodReal. */
#endif
#ifdef PpgLdd2_SFREQ_HZ_MIN
#define DrivingMotor_Step_SFREQ_HZ_MIN PpgLdd2_SFREQ_HZ_MIN /* Lower bound of interval for parameter of method SetFreqHz. */
#endif
#ifdef PpgLdd2_SFREQ_HZ_MAX
#define DrivingMotor_Step_SFREQ_HZ_MAX PpgLdd2_SFREQ_HZ_MAX /* Upper bound of interval for parameter of method SetFreqHz. */
#endif
#ifdef PpgLdd2_SFREQ_KHZ_MIN
#define DrivingMotor_Step_SFREQ_KHZ_MIN PpgLdd2_SFREQ_KHZ_MIN /* Lower bound of interval for parameter of method SetFreqkHz. */
#endif
#ifdef PpgLdd2_SFREQ_KHZ_MAX
#define DrivingMotor_Step_SFREQ_KHZ_MAX PpgLdd2_SFREQ_KHZ_MAX /* Upper bound of interval for parameter of method SetFreqkHz. */
#endif
#ifdef PpgLdd2_SFREQ_MHZ_MIN
#define DrivingMotor_Step_SFREQ_MHZ_MIN PpgLdd2_SFREQ_MHZ_MIN /* Lower bound of interval for parameter of method SetFreqMHz. */
#endif
#ifdef PpgLdd2_SFREQ_MHZ_MAX
#define DrivingMotor_Step_SFREQ_MHZ_MAX PpgLdd2_SFREQ_MHZ_MAX /* Upper bound of interval for parameter of method SetFreqMHz. */
#endif



/*
** ===================================================================
**     Method      :  DrivingMotor_Step_Enable (component PPG)
**     Description :
**         This method enables the component - it starts the signal
**         generation. Events may be generated (<DisableEvent>
**         /<EnableEvent>).
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
#define DrivingMotor_Step_Enable() (PpgLdd2_Enable(PpgLdd2_DeviceData))

/*
** ===================================================================
**     Method      :  DrivingMotor_Step_Disable (component PPG)
**     Description :
**         This method disables the component - it stops the signal
**         generation and events calling. When the timer is disabled,
**         it is possible to call <ClrValue> and <SetValue> methods.
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
#define DrivingMotor_Step_Disable() (PpgLdd2_Disable(PpgLdd2_DeviceData))

/*
** ===================================================================
**     Method      :  DrivingMotor_Step_SetPeriodUS (component PPG)
**     Description :
**         This method sets the new period of the output signal. The
**         period is expressed in microseconds as a 16-bit unsigned integer
**         number.
**         This method is only available when the runtime setting type
**         'from interval' is selected in the Timing dialog box of
**         the Runtime setting area.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Time       - Period to set [in microseconds]
**                      (2 to 3125 microseconds)
**     Returns     :
**         ---        - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_MATH - Overflow during evaluation
**                           ERR_RANGE - Parameter out of range
** ===================================================================
*/
byte DrivingMotor_Step_SetPeriodUS(word Time);

/*
** ===================================================================
**     Method      :  DrivingMotor_Step_SetPeriodMS (component PPG)
**     Description :
**         This method sets the new period of the output signal. The
**         period is expressed in milliseconds as a 16-bit unsigned integer
**         number.
**         This method is only available when the runtime setting type
**         'from interval' is selected in the Timing dialog box of
**         the Runtime setting area.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Time       - Period to set [in milliseconds]
**                      (1 to 3 milliseconds)
**     Returns     :
**         ---        - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_MATH - Overflow during evaluation
**                           ERR_RANGE - Parameter out of range
** ===================================================================
*/
byte DrivingMotor_Step_SetPeriodMS(word Time);

/*
** ===================================================================
**     Method      :  DrivingMotor_Step_SetPeriodSec (component PPG)
**     Description :
**         This method sets the new period of the output signal. The
**         period is expressed in seconds as a 16-bit unsigned integer
**         number.
**         This method is only available when the runtime setting type
**         'from interval' is selected in the Timing dialog box of
**         the Runtime setting area.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Time       - Period to set [in seconds]
**         Note: The interval is too narrow. The method will return
**               just the error code.
**     Returns     :
**         ---        - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_MATH - Overflow during evaluation
**                           ERR_RANGE - Parameter out of range
** ===================================================================
*/
byte DrivingMotor_Step_SetPeriodSec(word Time);

/*
** ===================================================================
**     Method      :  DrivingMotor_Step_SetPeriodReal (component PPG)
**     Description :
**         This method sets the new period of the output signal. The
**         period is expressed in seconds as a real number.
**         This method is only available when the runtime setting type
**         'from interval' is selected in the Timing dialog box of
**         the Runtime setting area.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Time       - Period to set [in seconds]
**                      (0.000001001358 to 0.003125 seconds)
**     Returns     :
**         ---        - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_MATH - Overflow during evaluation
**                           ERR_RANGE - Parameter out of range
** ===================================================================
*/
byte DrivingMotor_Step_SetPeriodReal(TPE_Float Time);

/*
** ===================================================================
**     Method      :  DrivingMotor_Step_SetFreqHz (component PPG)
**     Description :
**         This method sets the new frequency of the output signal. The
**         frequency is expressed in Hz as a 16-bit unsigned integer
**         number.
**         This method is only available when the runtime setting type
**         'from interval' is selected in the Timing dialog box of
**         the Runtime setting area.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Freq       - Frequency to set [in Hz]
**                      (320 to 65535 Hz)
**     Returns     :
**         ---        - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_MATH - Overflow during evaluation
**                           ERR_RANGE - Parameter out of range
** ===================================================================
*/
byte DrivingMotor_Step_SetFreqHz(word Freq);

/*
** ===================================================================
**     Method      :  DrivingMotor_Step_SetFreqkHz (component PPG)
**     Description :
**         This method sets the new frequency of the output signal. The
**         frequency is expressed in kHz as a 16-bit unsigned integer
**         number.
**         This method is only available when the runtime setting type
**         'from interval' is selected in the Timing dialog box of
**         the Runtime setting area.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Freq       - Frequency to set [in kHz]
**                      (1 to 998 kHz)
**     Returns     :
**         ---        - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_MATH - Overflow during evaluation
**                           ERR_RANGE - Parameter out of range
** ===================================================================
*/
byte DrivingMotor_Step_SetFreqkHz(word Freq);

/*
** ===================================================================
**     Method      :  DrivingMotor_Step_SetFreqMHz (component PPG)
**     Description :
**         This method sets the new frequency of the output signal. The
**         frequency is expressed in MHz as a 16-bit unsigned integer
**         number.
**         This method is only available when the runtime setting type
**         'from interval' is selected in the Timing dialog box of
**         the Runtime setting area.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Freq       - Frequency to set [in MHz]
**         Note: The interval is too narrow. The method will return
**               just the error code.
**     Returns     :
**         ---        - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_MATH - Overflow during evaluation
**                           ERR_RANGE - Parameter out of range
** ===================================================================
*/
byte DrivingMotor_Step_SetFreqMHz(word Freq);

/*
** ===================================================================
**     Method      :  DrivingMotor_Step_SetRatio16 (component PPG)
**     Description :
**         This method sets a new duty-cycle ratio. Ratio is expressed
**         as a 16-bit unsigned integer number. Value 0 - 65535 value
**         is proportional to ratio 0 - 100%. 
**         Note: Calculated duty depends on the timer possibilities and
**         on the selected period.
**         The method is available only if method <SetPeriodMode> is
**         not selected.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Ratio           - Ratio to set. 0 - 65535 value is
**                           proportional to ratio 0 - 100%
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
#define DrivingMotor_Step_SetRatio16(Ratio) (PpgLdd2_SetRatio16(PpgLdd2_DeviceData, Ratio))

/*
** ===================================================================
**     Method      :  DrivingMotor_Step_SetDutyUS (component PPG)
**     Description :
**         This method sets the new duty value of the output signal. The
**         duty is expressed in microseconds as a 16-bit unsigned integer
**         number.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Time       - Duty to set [in microseconds]
**                      (0 to 2 us, resp. to 3125 us
**                      in high speed mode)
**     Returns     :
**         ---        - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_MATH - Overflow during evaluation
**                           ERR_RANGE - Parameter out of range
** ===================================================================
*/
byte DrivingMotor_Step_SetDutyUS(word Time);

/*
** ===================================================================
**     Method      :  DrivingMotor_Step_SetDutyMS (component PPG)
**     Description :
**         This method sets the new duty value of the output signal. The
**         duty is expressed in milliseconds as a 16-bit unsigned integer
**         number.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Time       - Duty to set [in milliseconds]
**                      (0 to 1 ms, resp. to 3 ms
**                      in high speed mode)
**     Returns     :
**         ---        - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_MATH - Overflow during evaluation
**                           ERR_RANGE - Parameter out of range
** ===================================================================
*/
byte DrivingMotor_Step_SetDutyMS(word Time);

/*
** ===================================================================
**     Method      :  DrivingMotor_Step_OnEnd (component PPG)
**
**     Description :
**         The method services the interrupt of the selected peripheral(s)
**         and eventually invokes event(s) of the component.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void PpgLdd2_OnEnd(LDD_TUserData *UserDataPtr);

/* END DrivingMotor_Step. */

#endif 
/* ifndef __DrivingMotor_Step_H */
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
