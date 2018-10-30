/*
    This code has synchronization mechanism using the mutex. 
*/
#include <stdio.h>
#include <pthread.h>
#include <time.h>
#define array_size 100
#define _NO_THREADS 4

float _global_arr[array_size];
int global_index = 0;
int sum = 0;
pthread_mutex_t _sum_mutex;

void *run(void *argv){
    int *tid = (int *) argv;
    int local_index, _local_sum = 0;
    do{
        pthread_mutex_lock(&_sum_mutex);
        local_index = global_index;
        global_index++;
        pthread_mutex_unlock(&_sum_mutex);
        if (local_index < array_size)
            _local_sum += *(_global_arr + local_index);
    }while(local_index < array_size);
    pthread_mutex_lock(&_sum_mutex);
    sum += _local_sum;
    printf("Working of Thread # %d at Sum %d\n", *tid, sum);
    pthread_mutex_unlock(&_sum_mutex);
    return 0;
}

int main(){
    clock_t _time_;
    int _local_sum_main_ = 0;
    srand(time(NULL));
    pthread_t threadArr[_NO_THREADS]; // creating 4 threads.
    pthread_mutex_init(&_sum_mutex, NULL); 
    for (int i = 0; i < array_size; i++){
        _global_arr[i] = rand() % 10;
        _local_sum_main_ += _global_arr[i];
    }
    _time_ = clock(); 
    for (int i = 0; i < _NO_THREADS; i++)
        pthread_create(&threadArr[i], NULL, run, (void *)&threadArr[i]);
    for (int i = 0; i < _NO_THREADS; i++)
        pthread_join(threadArr[i], NULL);
    _time_ = clock() - _time_;
    double time_taken = ((double)_time_)/CLOCKS_PER_SEC; // in seconds
    printf("The Global Sum: %d\n", sum);
    printf("The Local Sum: %d\n", _local_sum_main_);
    printf("Total Time: %f secs\n", time_taken);
    pthread_mutex_destroy(&_sum_mutex);
    pthread_exit (NULL);
    return 0;
}
