#include "ThreadPool.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void* threadJob(void* arg);


void PoolInit(TPool* pool,int nThreads){
    pool->numThreads=nThreads;
    pool->active=1;
    pool->stop=0;
    QueueInit(&pool->work);
    pool->lock = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
    pool->signal = (pthread_cond_t)PTHREAD_COND_INITIALIZER;
    pthread_mutex_lock(&pool->lock);
    pool->pool = (pthread_t*) malloc(sizeof(pthread_t)*nThreads);
    for(int i=0; i < nThreads; i++){
        pthread_create(&pool->pool[i], NULL, threadJob, pool);
    }

    pthread_mutex_unlock(&pool->lock);
}

void PoolFree(TPool* pool){
    while(!isEmpty(&pool->work));
    pool->active=0;
    for(int i=0; i < pool->numThreads; i++){
        pthread_cond_broadcast(&pool->signal);
    }
    for(int i=0; i < pool->numThreads; i++){
//        pthread_join(pool->pool[i], NULL);
    }
    free(pool->pool);
    QueueFree(&pool->work);
}

void JobInit(TJob* Job, void* (*job_function)(void* args), void* arg){
    Job->job = job_function;
    Job->argument = arg;
}
void* threadJob(void* arg){
    TPool *pool = (TPool*)arg;
    while(pool->active){
        pthread_mutex_lock(&pool->lock);
        while(!pool->stop && isEmpty(&pool->work))
            pthread_cond_wait(&pool->signal,&pool->lock);
        TJob task= *(TJob*)(QPeek(&pool->work)->data);
        Dequeue(&pool->work);
        pthread_mutex_unlock(&pool->lock);
        if(task.job) task.job(task.argument);
    }
    return NULL;
}

void addWork(TPool* pool,  TJob* Job){
    pthread_mutex_lock(&pool->lock);
    Enqueue(&pool->work, Job, Other, sizeof(TJob));
    pthread_cond_broadcast(&pool->signal);
    pthread_mutex_unlock(&pool->lock);

}