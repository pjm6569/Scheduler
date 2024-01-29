#include "types.h"
#include "stat.h"
#include "user.h"

#define PNUM 3

void scheduler_func(){
    int pids[PNUM];
    int prior[PNUM] ={1, 10, 11};
    int timer[PNUM] = {110, 60, 60};

    setFlag(1);
    printf(1, "start scheduler test\n");
    for(int i = 0; i<PNUM; i++){
        pids[i] =fork();
        if(pids[i] == 0){
            set_sche_info(prior[i], timer[i]);
            for(;;);
        }
    }
    for(int i = 0; i<PNUM; i++){
        wait();
    }
    printf(1, "end of scheduler_test\n");
    setFlag(0);
}

int main(void){
    scheduler_func();
    exit();
}