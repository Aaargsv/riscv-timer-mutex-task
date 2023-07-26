#ifndef MUTEX_H
#define MUTEX_H

typedef int Mutex;
extern void mutex_lock(Mutex *m);
extern void mutex_unlock(Mutex *m);
	
#endif