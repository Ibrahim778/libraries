#ifndef _PSP2_KERNEL_CPU_H_
#define _PSP2_KERNEL_CPU_H_

#include <psp2kern/types.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief      Call this when entering a syscall
 *
 * @param      state  The state
 */
#define ENTER_SYSCALL(state) do { \
  asm volatile ("mrc p15, 0, %0, c13, c0, 3" : "=r" (state)); \
  asm volatile ("mcr p15, 0, %0, c13, c0, 3" :: "r" (state << 16) : "memory"); \
} while(0)

/**
 * @brief      Call this when existing a syscall
 *
 * @param      state  The state
 */
#define EXIT_SYSCALL(state) do { \
  asm volatile ("mcr p15, 0, %0, c13, c0, 3" :: "r" (state) : "memory"); \
} while (0)

/**
 * @brief      Save process context
 *
 * @param      context  The context
 */
static inline void sceKernelCpuSaveContext(int context[3]) {
  asm ("mrc p15, 0, %0, c2, c0, 1" : "=r" (context[0]));
  asm ("mrc p15, 0, %0, c3, c0, 0" : "=r" (context[1]));
  asm ("mrc p15, 0, %0, c13, c0, 1" : "=r" (context[2]));
}

/**
 * @brief      Restore process context
 *
 * @param      context  The context, can be from `sceKernelGetPidContext`
 */
static inline void sceKernelCpuRestoreContext(int context[3]) {
  int cpsr;
  int tmp;

  asm volatile ("mrs %0, cpsr" : "=r" (cpsr));
  if (!(cpsr & 0x80)) {
    asm volatile ("cpsid i" ::: "memory");
  }
  asm volatile ("mrc p15, 0, %0, c13, c0, 1" : "=r" (tmp));
  tmp = (tmp & 0xFFFFFF00) | context[2];
  asm volatile ("mcr p15, 0, %0, c13, c0, 1" :: "r" (0));
  asm volatile ("isb" ::: "memory");
  asm volatile ("mcr p15, 0, %0, c2, c0, 1" :: "r" (context[0] | 0x4A));
  asm volatile ("isb" ::: "memory");
  asm volatile ("mcr p15, 0, %0, c13, c0, 1" :: "r" (tmp));
  asm volatile ("mcr p15, 0, %0, c3, c0, 0" :: "r" (context[1] & 0x55555555));
  if (!(cpsr & 0x80)) {
    asm volatile ("cpsie i" ::: "memory");
  }
}

/**
 * @brief      Disabled interrupts
 *
 * @return     Interrupt masks before disabling
 */
int sceKernelCpuDisableInterrupts(void);

/**
 * @brief      Enable interrupts
 *
 * @param[in]  flags  Interrupt masks
 *
 * @return     Zero on success
 */
int sceKernelCpuEnableInterrupts(int flags);

/**
 * @brief      Writeback a range of L1 dcache (without L2)
 *
 * @param      ptr   The pointer
 * @param[in]  len   The length
 *
 * @return     Zero on success
 */
int sceKernelCpuDcacheWritebackRange(void *ptr, size_t len);

/**
 * @brief      Invalidate a range of L1 dcache (without L2)
 *
 * @param      ptr   The pointer
 * @param[in]  len   The length
 *
 * @return     Zero on success
 */
int sceKernelCpuDcacheInvalidateRange(void *ptr, size_t len);

/**
 * @brief      Writeback and invalidate a range of L1 dcache (without L2)
 *
 * @param      ptr   The pointer
 * @param[in]  len   The length
 *
 * @return     Zero on success
 */
int sceKernelCpuDcacheWritebackInvalidateRange(void *ptr, size_t len);

/**
 * @brief      Invalidate all the L1 dcache (without L2)
 *
 * @return     Zero on success
 */
int sceKernelCpuDcacheInvalidateAll(void);

/**
 * @brief      Writeback all the L1 dcache (without L2)
 *
 * @return     Zero on success
 */
int sceKernelCpuDcacheWritebackAll(void);

/**
 * @brief      Writeback and invalidate all the L1 dcache (without L2)
 *
 * @return     Zero on success
 */
int sceKernelCpuDcacheWritebackInvalidateAll(void);

/**
 * @brief      Writeback a range of L1 dcache and L2
 *
 * @param      ptr   The pointer
 * @param[in]  len   The length
 *
 * @return     Zero on success
 */
int sceKernelCpuDcacheAndL2WritebackRange(void *ptr, size_t len);

/**
 * @brief      Writeback and invalidate a range of L1 dcache and L2
 *
 * @param      ptr   The pointer
 * @param[in]  len   The length
 *
 * @return     Zero on success
 */
int sceKernelCpuDcacheAndL2InvalidateRange(void *ptr, size_t len);

/**
 * @brief      Writeback and invalidate a range of L1 dcache and L2
 *
 * @param      ptr   The pointer
 * @param[in]  len   The length
 *
 * @return     Zero on success
 */
int sceKernelCpuDcacheAndL2WritebackInvalidateRange(void *ptr, size_t len);

/**
 * @brief      Invalidate a range of L1 icache (without L2)
 *
 * @param      ptr   The pointer
 * @param[in]  len   The length
 *
 * @return     Zero on success
 */
int sceKernelCpuIcacheInvalidateRange(void *ptr, size_t len);

/**
 * @brief      Invalidate all the L1 icache (without L2)
 *
 * @return     Zero on success
 */
int sceKernelCpuIcacheInvalidateAll(void);

/**
 * @brief      Writeback and invalidate a range of L1 icache and L2
 *
 * @param      ptr   The pointer
 * @param[in]  len   The length
 *
 * @return     Zero on success
 */
int sceKernelCpuIcacheAndL2WritebackInvalidateRange(void *ptr, size_t len);

/**
 * @brief      MMU permission bypassing memcpy
 *
 * This works by writing to the DACR before and after the memcpy.
 *
 * @param      dst   The destination
 * @param[in]  src   The source
 * @param[in]  len   The length
 *
 * @return     Zero on success.
 */
int sceKernelCpuUnrestrictedMemcpy(void *dst, const void *src, size_t len);

/**
 * @brief      Suspend all interrupts (disables IRQs)
 *
 * @param[in]  addr   Mutex associated to the suspend-resume pair
 *
 * @return     The current state of the interrupt controller, to be used with sceKernelCpuResumeIntr.
 */
int sceKernelCpuSuspendIntr(int *addr);

/**
 * @brief      Resume all interrupts (enables IRQs)
 *
 * @param[in]  addr   Mutex associated to the suspend-resume pair
 * @param[in]  prev_state   State obtained from sceKernelCpuSuspendIntr
 *
 * @return     The previous state of the interrupt controller.
 */
int sceKernelCpuResumeIntr(int *addr, int prev_state);


#ifdef __cplusplus
}
#endif

#endif /* _PSP2_KERNEL_CPU_H_ */

