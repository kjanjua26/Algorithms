#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<sys/types.h>
/*
	Bidirectional Communication between two processes, parent and child, using pipes in C.
*/
int main(){
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
		char child_writes[] = "Hi Parent Process!";
		int in, out;
		in = child[0];
		out = parent[1];
		read(in, buff, 50);
		printf("Parent Says: %s\n", buff);
		write(out, child_writes, strlen(child_writes) + 1); // send the message to parent. 
	}
	else{
		char parent_writes[] = "Hello Child Process!";
		int in, out;
		in = parent[0];
		out = child[1];
	    write(out, parent_writes, strlen(parent_writes) + 1); // send message to the child. 
	    read(in, buff, 50); // reading the message from the parent.
	    printf("Child Says: %s\n", buff);
	}
	return 0;
}
