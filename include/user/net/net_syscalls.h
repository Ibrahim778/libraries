#ifndef _PSP2_NET_NET_SYSCALLS_H_
#define _PSP2_NET_NET_SYSCALLS_H_

#include <psp2/net/net.h>

#ifdef __cplusplus
extern "C" {
#endif

int sceNetConnectForSyscalls(int s, const SceNetSockaddr *name, unsigned int namelen);

#ifdef __cplusplus
}
#endif

#endif /* _PSP2_NET_NET_SYSCALLS_H_ */
