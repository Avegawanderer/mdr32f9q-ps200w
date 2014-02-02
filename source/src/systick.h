/*============================================================================================
 *
 *  (C) 2010, Phyton
 *
 *  ���������������� ������ ��� 1986BE91 testboard
 *
 *  ������ �� ��������������� "��� ����", �.�. ������������� ��� ������, ���������� ���������
 *  ������������� ���������� �� ���������� ��� ����������� Milandr 1986BE91T1. �������� Phyton
 *  �� ����� ������� ��������������� �� ��������� ����������� ������������� �������, ���
 *  �������������� ������������� �� ��� ������, ��.
 *
 *--------------------------------------------------------------------------------------------
 *
 *  ���� systick.h: ������� ������� ������ ��� ������ � ��������� ��������
 *
 *============================================================================================*/

#ifndef __SYSTICK_H
#define __SYSTICK_H

#include "MDR32Fx.h" 

#define HW_IRQ_PERIOD				(16*200)		// in units of 62.5ns, must be <= timer period
#define HW_ADC_CALL_PERIOD			5				// in units of HW_IRQ period
#define HW_UART2_RX_CALL_PERIOD		5				// in units of HW_IRQ period
#define HW_UART2_TX_CALL_PERIOD		5				// in units of HW_IRQ period

#define GUI_UPDATE_INTERVAL			25		// OS ticks
#define CONVERTER_TICK_INTERVAL		50		// OS ticks
#define DISPATCHER_TICK_INTERVAL	10		// OS ticks
#define SOUND_DRIVER_TICK_INTERVAL	5

typedef struct {
	uint32_t max_ticks_in_Systick_hook;
	uint32_t max_ticks_in_Timer2_ISR;
} time_profile_t;


extern time_profile_t time_profile;
extern uint8_t enable_task_ticks;
           
extern uint32_t ticks_per_us;

/* ���������� ��������� �������� */
void SysTickStart(uint32_t ticks);
void SysTickStop(void);

/* ������� �������� (�� ���� systick) */
void SysTickDelay(uint32_t val);

void StartBeep(uint16_t time);
void StopBeep(void);
void Beep(uint16_t time);
void WaitBeep(void);

#endif /* __SYSTICK_H */

/*============================================================================================
 * ����� ����� systick.h
 *============================================================================================*/

