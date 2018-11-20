#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#define BUFF_SIZE 100
/*
	Bidirectional Communication between two processes, parent and child, using pipes in C.
*/
int main(){
    FILE *fp_ = fopen("sample.txt", "r");
    char storage_[BUFF_SIZE+1];
    if(fp_ == NULL){
        perror("File not open\n");
        exit(1);
    }
    fscanf(fp_, "%[^\n]", storage_);
    fclose(fp_);
	int parent[2]; // reading and writing for parent. 
	int child[2]; // reading and writing for child. 
	char buff[50];
	if(pipe(parent) == -1 || pipe(child) == -1){
		perror("Pipe Error.");
		exit(-1);
	}
	pipe(parent); pipe(child);
	int pid = fork(); // forking process. 
	if(pid == -1){
		perror("Fork Unsuccessful.");
		exit(-1);
	}
	if(pid == 0){
		char child_writes[] = "Hi Parent Process, File Received!";
		int in, out;
		in = child[0];
		out = parent[1];
		read(in, buff, BUFF_SIZE+1);
		printf("Parent Says: %s\n", buff);
		write(out, child_writes, strlen(child_writes) + 1); // send the message to parent.
	}
	else{
		int in, out;
		in = parent[0];
		out = child[1];
	    write(out, storage_, strlen(storage_) + 1); // send message to the child.
	    read(in, buff, 50); // reading the message from the parent.
	    printf("Child Says: %s\n", buff);
	}
	return 0;
}
