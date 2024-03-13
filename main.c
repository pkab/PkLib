#include <System/ThreadPool/ThreadPool.h>
#include <stdio.h>

typedef struct Task{
    int a,b;
}task;
void* add(void *args){
    struct Task* ar = (struct ar*)args;
    printf("Add %d: %d\n",ar->a,ar->a+ar->b);
    ar->a +=ar->b;
    return NULL;
}
int main() {
    TPool pool;
    task t[200];
    TJob job[200];
    PoolInit(&pool, 8);
    for(int i=0;i<200;i++){
        t[i].a = i+1;
        t[i].b = i*2;
        JobInit(&job[i], add, &t[i]);
    }
    for(int i=0;i<200;i++){
        addWork(&pool,&job[i]);
    }
    PoolFree(&pool);
    return 0;
}
