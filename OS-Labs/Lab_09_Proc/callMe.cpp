#include<stdio.h>
#include<string.h>
#include<iostream>
#include<fstream>
#define MAX_SIZE 512
using namespace std;
void _call_me(char*, char*);
void _call_me_parse(char* path, char *_keyword);
int main(){
    printf("Task A(1) Processor Manufacuturer: ");
    _call_me("/proc/cpuinfo", "vendor_id");
    printf("Task A(2) Model: ");
    _call_me("/proc/cpuinfo", "model name");
    printf("Task B Kernel: ");
    _call_me("/proc/version_signature", "Ubuntu");
    printf("Task C Boot Time: ");
    _call_me("/proc/uptime", "");
    printf("Task D Time Spent In Modes (User 1, System 3, Idle 4): ");
    _call_me_parse("/proc/stat", "cpu");
    printf("Task E Memory Configured: ");
    _call_me("/proc/meminfo", "MemTotal");
    printf("Task F Memory Available: ");
    _call_me("/proc/meminfo", "MemFree");
    return 0;
}
void _call_me(char* path, char *_keyword){
   char buff_line[MAX_SIZE];
   ifstream buff_cpuinfo (path);
    while(buff_cpuinfo){
        buff_cpuinfo.getline(buff_line, MAX_SIZE);
        if(strstr(buff_line, _keyword) != NULL){
            printf("%s\n", buff_line);   
        }    
    }
}
void _call_me_parse(char* path, char *_keyword){
   char buff_line[MAX_SIZE];
   ifstream buff_cpuinfo (path);
   char* split_vals;
    while(buff_cpuinfo){
        buff_cpuinfo.getline(buff_line, MAX_SIZE);
        if(strstr(buff_line, _keyword) != NULL){
            split_vals = buff_line;
            break;
        }    
    }
   printf("%s\n", split_vals);
}
