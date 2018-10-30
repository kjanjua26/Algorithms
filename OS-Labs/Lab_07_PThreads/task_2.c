/*
	This code uses no synchronization mechanism and works by being distributed.
*/
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>  
#include <pthread.h> 
#include <time.h>
int _sum_ = 0;
int _global_arr[100];

void *run1(void *vargp){ 
    int *myid = (int *)vargp; 
    for(int i = 0; i <= 25; i++)
    	_sum_ += _global_arr[i]; 
    printf("Thread ID: %d, Sum: %d\n", *myid, _sum_); 
} 
void *run2(void *vargp){ 
    int *myid = (int *)vargp; 
    for(int i = 26; i <= 50; i++)
    	_sum_ += _global_arr[i]; 
    printf("Thread ID: %d, Sum: %d\n", *myid, _sum_); 
} 
void *run3(void *vargp){ 
    int *myid = (int *)vargp; 
    for(int i = 51; i <= 75; i++)
    	_sum_ += _global_arr[i]; 
    printf("Thread ID: %d, Sum: %d\n", *myid, _sum_); 
} 
void *run4(void *vargp){ 
    int *myid = (int *)vargp; 
    for(int i = 76; i <= 100; i++)
    	_sum_ += _global_arr[i]; 
    printf("Thread ID: %d, Sum: %d\n", *myid, _sum_); 
} 
int main() {  
	clock_t _time_;
	int _local_sum = 0;
    srand(time(NULL));
    for(int i = 0; i < 100; i++){
    	_global_arr[i] = rand() % 10;
    	_local_sum += _global_arr[i];
    }
    pthread_t _th1; pthread_t _th3;
    pthread_t _th2; pthread_t _th4;
    _time_ = clock(); 
    pthread_create(&_th1, NULL, run1, (void *)&_th1); 
    pthread_create(&_th2, NULL, run2, (void *)&_th2);
    pthread_create(&_th3, NULL, run3, (void *)&_th3);
    pthread_create(&_th4, NULL, run4, (void *)&_th4);
    _time_ = clock() - _time_;
    double time_taken = ((double)_time_)/CLOCKS_PER_SEC; // in seconds
    printf("\nTotal Time Taken: %f secs\n", time_taken);
   	pthread_exit(NULL); 
    return 0; 
}
