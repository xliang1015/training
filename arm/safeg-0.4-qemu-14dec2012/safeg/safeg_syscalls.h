/*
 *  TOPPERS/SafeG Dual-OS monitor
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Safety Gate Dual-OS monitor
 *
 *  Copyright (C) 2009-2011 by Embedded and Real-Time Systems Laboratory
 *     Graduate School of Information Science, Nagoya University, JAPAN
 *
 *  �嵭����Ԥϡ��ʲ���(1)��(4)�ξ������������˸¤ꡤ�ܥ��եȥ���
 *  �����ܥ��եȥ���������Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ������
 *  �ѡ������ۡʰʲ������ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
 *  (1) �ܥ��եȥ������򥽡��������ɤη������Ѥ�����ˤϡ��嵭������
 *      ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ��꤬�����Τޤޤη��ǥ���
 *      ����������˴ޤޤ�Ƥ��뤳�ȡ�
 *  (2) �ܥ��եȥ������򡤥饤�֥������ʤɡ�¾�Υ��եȥ�������ȯ�˻�
 *      �ѤǤ�����Ǻ����ۤ�����ˤϡ������ۤ�ȼ���ɥ�����ȡ�����
 *      �ԥޥ˥奢��ʤɡˤˡ��嵭�����ɽ�����������Ѿ�浪��Ӳ���
 *      ��̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *  (3) �ܥ��եȥ������򡤵�����Ȥ߹���ʤɡ�¾�Υ��եȥ�������ȯ�˻�
 *      �ѤǤ��ʤ����Ǻ����ۤ�����ˤϡ����Τ����줫�ξ�����������
 *      �ȡ�
 *    (a) �����ۤ�ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭����
 *        �ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *    (b) �����ۤη��֤��̤�������ˡ�ˤ�äơ�TOPPERS�ץ��������Ȥ�
 *        ��𤹤뤳�ȡ�
 *  (4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»
 *      ������⡤�嵭����Ԥ����TOPPERS�ץ��������Ȥ����դ��뤳�ȡ�
 *      �ޤ����ܥ��եȥ������Υ桼���ޤ��ϥ���ɥ桼������Τ����ʤ���
 *      ͳ�˴�Ť����ᤫ��⡤�嵭����Ԥ����TOPPERS�ץ��������Ȥ�
 *      ���դ��뤳�ȡ�
 *
 *  �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥ�
 *  ���TOPPERS�ץ��������Ȥϡ��ܥ��եȥ������˴ؤ��ơ�����λ�����Ū
 *  ���Ф���Ŭ������ޤ�ơ������ʤ��ݾڤ�Ԥ�ʤ����ޤ����ܥ��եȥ���
 *  �������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������������ʤ�»���˴ؤ��Ƥ⡤��
 *  ����Ǥ�����ʤ���
 *
 */
#ifndef _SAFEG_SYSCALLS_H_
#define _SAFEG_SYSCALLS_H_

/*
 * SAFEG System Monitor Calls
 *
 * T_: Trust calls
 * NT_: Non-Trust calls
 *
 * template: safeg_syscall(int num, int *arg0, int *arg1)
 *
 * indentation:
 *      num
 *          arg0
 *              arg1
 *                  arg2
 *                      arg3
 *                          arg4
 */
#define T_SMC_SWITCH  0 /* switch to NT */
#define     T_SMC_SWITCH_OK      0 /* no error */
#define     T_SMC_SWITCH_ERR     1 /* error, return to T */
#define     T_SMC_SWITCH_HANDLER 2 /* NT returns, raise safeg handler*/
#define     T_SMC_SWITCH_RET     3 /* NT returns */
#define     T_SMC_SWITCH_SHVAR   4 /* NT returns, arg1 = shared variable */
#define     T_SMC_SWITCH_VERIFY  5 /* obj_safeg_monitor */

#define T_SMC_REBOOT  1 /* reboot NT */
#define     T_SMC_REBOOT_OK      0 /* no error */
#define     T_SMC_REBOOT_ERR     1 /* error, return to T */

#define T_SMC_PROF_INIT  2 /* initialize profile data */
#define     T_SMC_PROF_INIT_OK      0 /* no error */
#define     T_SMC_PROF_INIT_ERR     1 /* error, return to T */

#define T_SMC_PROF_GET  3 /* get profile data */
#define     T_SMC_PROF_GET_OK      0 /* no error */
#define     T_SMC_PROF_GET_ERR     1 /* error, return to T */

#define T_SMC_PROF_GET_PTR  4 /* get profile data pointer*/
#define     T_SMC_PROF_GET_PTR_OK      0 /* no error */
#define     T_SMC_PROF_GET_PTR_ERR     1 /* error, return to T */

#define T_SMC_FIFO_WRITE 5 /* write to fifo */
#define T_SMC_FIFO_READ  6 /* read from fifo */

#define NT_SMC_SWITCH 0 /* switch to T */
#define     NT_SMC_SWITCH_OK     0 /* no error */
#define     NT_SMC_SWITCH_ERR    1 /* error, return to NT */

#define NT_SMC_INV_CACHE 1 /* invalidate cache and return to NT */
#define     NT_SMC_INV_CACHE_OK   0 /* no error */
#define     NT_SMC_INV_CACHE_ERR  1 /* error, return to T */
#define     NT_SMC_INV_CACHE_D    2 /* invalidate data cache */
#define     NT_SMC_INV_CACHE_I    3 /* invalidate instruction cache */
#define     NT_SMC_INV_CACHE_ALL  4 /* invalidate both caches */

#define NT_SMC_SOFTIRQ    2 /* generate a software interrupt in Trust world */
#define NT_SMC_FIFO_WRITE 3 /* write to fifo */
#define NT_SMC_FIFO_READ  4 /* read from fifo */
#define NT_SMC_WRITE_REG  5 /* write a register in secure mode */
#define NT_SMC_READ_REG   6 /* read a register in secure mode */
#define NT_SMC_MEMCPY4    7 /* copy 4 words */

#endif /* _SAFEG_SYSCALLS_H_ */