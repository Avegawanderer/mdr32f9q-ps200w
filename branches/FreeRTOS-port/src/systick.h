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



#define GUI_UPDATE_INTERVAL			25		// OS ticks
#define CONVERTER_TICK_INTERVAL		50		// OS ticks
#define DISPATCHER_TICK_INTERVAL	10		// OS ticks


typedef struct {
	uint32_t max_ticks_in_Systick_hook;
	uint32_t max_ticks_in_Timer2_ISR;
} time_profile_t;


extern time_profile_t time_profile;

           
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

