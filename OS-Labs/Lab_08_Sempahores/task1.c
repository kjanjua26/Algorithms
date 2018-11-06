#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<windows.h>
sem_t _lock_eve, _lock_odd;
#define MAX 10
void *print_even_nums(void *params);
void *print_odd_nums(void *params);

int main(int argc, char *argv[]){
	pthread_t _eve_theard, _odd_thread;
	sem_init(&_lock_eve, 0, 1);
	sem_init(&_lock_odd, 0, 0);
	pthread_create(&_eve_theard, 0, print_even_nums, 0);
	pthread_create(&_odd_thread, 0, print_odd_nums, 0);
	pthread_join(_eve_theard, NULL);
	pthread_join(_odd_thread, NULL);
	return 0;
}
void *print_even_nums(void *params){
	int _local_count = 0;
	do{
		sem_wait(&_lock_eve); // lock the even semaphore. 
		Sleep(3);
		printf("%d ", _local_count);
		_local_count += 2;
		sem_post(&_lock_odd); // unlock the mutex, fancy in semaphores.
	} while (_local_count < MAX);
	sem_destroy(&_lock_eve); // destroy the mutex. 
	return NULL;
}
void *print_odd_nums(void *params){
	int _local_count = 1;
	do{
		sem_wait(&_lock_odd);
		Sleep(4);
		printf("%d ", _local_count);
		_local_count += 2;
		sem_post(&_lock_eve); // unlock the mutex, fancy in semaphores.
	} while (_local_count < MAX);
	sem_destroy(&_lock_odd); // destroy the mutex. 
	return NULL;
}
