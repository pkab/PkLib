#include <System/ThreadPool/ThreadPool.h>
#include <stdio.h>

typedef struct Task{
    int a,b;
}task;
void* add(void *args){
    struct Task* ar = (struct ar*)args;
    printf("Add %d: %d\n",ar->a,ar->a+ar->b);
    return NULL;
}
int main() {
    TPool pool;
    task t[20];
    TJob job[20];
    PoolInit(&pool, 8);
    for(int i=0;i<20;i++){
        t[i].a = i+1;
        t[i].b = i*2;
        JobInit(&job[i], add, &t[i]);
    }
    for(int i=0;i<20;i++){
        addWork(&pool,&job[i]);
    }
    PoolFree(&pool);
    return 0;
}
