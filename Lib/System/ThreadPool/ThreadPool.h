#ifndef PKLIB_THREADPOOL_H
#define PKLIB_THREADPOOL_H

#include <DataStructures/Lists/Queue/Queue.h>
#include <pthread.h>

typedef struct ThreadPool{
   u32 numThreads;
   u32 active;
   Queue work;
   u8 stop;
   pthread_t* pool;
   pthread_mutex_t lock;
   pthread_cond_t signal;
}TPool;

typedef struct ThreadJob{
    void* (*job)(void* arg);
    void* argument;
}TJob;

void PoolInit(TPool* pool, int nThreads);
void PoolFree(TPool* pool);
void JobInit(TJob* Job, void* (*job)(void* arg), void* arg);
void addWork(TPool* pool, TJob* Job);

#endif //PKLIB_THREADPOOL_H
