#ifndef _SYS_CALLS_H_
#define _SYS_CALLS_H_
<<<<<<< HEAD
int GetPid();
void Sleep(int);

int Spawn();
int SemInit();
void SemWait();
void SemPost();
=======

#include "types.h"

int GetPid();
void Sleep(int);
int Spawn(func_ptr_t);
int SemInit(int);
void SemWait(int);
void SemPost(int);
void MsgSnd(int, msg_t *);
void MsgRcv(int, msg_t *);
>>>>>>> b8a9e70220cc217dedb00b209013c8d21b381054
#endif
