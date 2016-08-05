#ifndef _PSP2_POWER_H_
#define _PSP2_POWER_H_

#include <psp2/types.h>

#ifdef __cplusplus
extern "C" {
#endif

/* callback */
typedef void (*ScePowerCallback)(int unknown, int powerInfo);

/* prototypes */
int scePowerRegisterCallback(int slot, SceUID cbid);
int scePowerIsBatteryCharging();
int scePowerGetBatteryLifePercent();
int scePowerSetConfigurationMode(int mode); //?
SceBool scePowerIsSuspendRequired(); //?
int scePowerIsPowerOnline();
int scePowerGetBatteryLifeTime();
int scePowerGetBatteryRemainCapacity(); //?
int scePowerIsLowBattery();
int scePowerUnregisterCallback(int slot);
int scePowerGetBatteryFullCapacity(); //?
int scePowerGetArmClockFrequency(); //Get Clock Frequency of the ARM
int scePowerGetBusClockFrequency(); //Get Clock Frequency of the BUS
int scePowerGetGpuClockFrequency(); //Get Clock Frequency of the Gpu
int scePowerSetArmClockFrequency(int freq); // Set Cet Clock Frequency of the ARM

#ifdef __cplusplus
}
#endif

#endif /* _PSP2_POWER_H_ */
