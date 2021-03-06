#define _REENTRANT
#include <iostream>
#include <thread>

/* sample array data structure */
class Dat{
        std::mutex data_lock[5];
        int     int_val[5];
        float   float_val[5];
        } ;

/* thread function */
void *Add_to_Value(void *arg);

main()
{

Dat Data;

int i;

std::thread th[5];

/* initialize the mutexes and data */
for (i=0; i<5; i++) {
        //mutex_init(&Data.data_lock[i], USYNC_THREAD, 0);
        Data.int_val[i] = 0;
        Data.float_val[i] = 0;
        }

/* set concurrency and create the threads */
//thr_setconcurrency(4);

for (i=0; i<5; i++){
    th[i]=std::thread(Add_to_Value,(void *)2*i);
    th[i].join();
}

/* print the results */
printf("Final Values.....\n");

for (i=0; i<5; i++) {
        printf("integer value[%d] =\t%d\n", i, Data.int_val[i]);
        printf("float value[%d] =\t%.0f\n\n", i, Data.float_val[i]);
        }

return(0);
}


/* Threaded routine */
void *Add_to_Value(void *arg)
{
int inval = (int) arg;
int i;

for (i=0;i<10000;i++){
    std::lock_guard<std::mutex> guard(&Data.data_lock[i%5]);
       Data.int_val[i%5] += inval;
       Data.float_val[i%5] += (float) 1.5 * inval;
    //mutex_unlock(&Data.data_lock[i%5]);
    }

return((void *)0);
}