#ifndef _PSP2_KERNEL_SUSPEND_H_
#define _PSP2_KERNEL_SUSPEND_H_

#include <psp2kern/types.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef int (* SceSysEventHandler)(int resume, int eventid, void *args, void *opt);

typedef enum SceKernelPowerTickType {
	/** Cancel all timers */
	SCE_KERNEL_POWER_TICK_DEFAULT			= 0,
	/** Cancel automatic suspension timer */
	SCE_KERNEL_POWER_TICK_DISABLE_AUTO_SUSPEND	= 1,
	/** Cancel OLED-off timer */
	SCE_KERNEL_POWER_TICK_DISABLE_OLED_OFF		= 4,
	/** Cancel OLED dimming timer */
	SCE_KERNEL_POWER_TICK_DISABLE_OLED_DIMMING	= 6
} SceKernelPowerTickType;


/**
 * Cancel specified idle timers to prevent entering in power save processing.
 *
 * @param[in] type - One of ::SceKernelPowerTickType
 *
 * @return 0
*/
int sceKernelPowerTick(int type);

/**
 * Register system event handler
 *
 * @param[in] name - Name of handler
 * @param[in] handler - The handler
 * @param[in] args - Handler arguments
 *
 * @return 0 on success, < 0 on error.
*/
int sceKernelRegisterSysEventHandler(const char *name, SceSysEventHandler handler, void *args);

#ifdef __cplusplus
}
#endif

#endif /* _PSP2_KERNEL_SUSPEND_H_ */
