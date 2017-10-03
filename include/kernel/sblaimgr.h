#ifndef _PSP2_KERNEL_SBLACMGR_H_
#define _PSP2_KERNEL_SBLACMGR_H_

#include <psp2kern/types.h>

#ifdef __cplusplus
extern "C" {
#endif

int sceSblAimgrGetSMI(void);
int sceSblAimgrIsTest(void);
int sceSblAimgrIsTool(void);
int sceSblAimgrIsDEX(void);
int sceSblAimgrIsCEX(void);
int sceSblAimgrIsVITA(void);
int sceSblAimgrIsDolce(void);
int sceSblAimgrIsGenuineVITA(void);
int sceSblAimgrIsGenuineDolce(void);

#ifdef __cplusplus
}
#endif

#endif /* _PSP2_KERNEL_SBLAIMGR_H_ */
