/*
Brief Explanation before proceeding.
Page number = (address reference / page size) Offset = (address reference % page size)
*/
#include<stdio.h>
#include <stdint.h>
#include <inttypes.h> #include<string.h>
#define PAGESIZE 4096 // 4KB void _print_addr(int32_t );
int main(int argc, char* argv[]){
  int32_t phy_address_arr[] = {19986, 20000, 65620, 1000000, 429496200, 4563423,
  5566666};
  for(int i = 0; i < sizeof(phy_address_arr)/sizeof(phy_address_arr[0]); i++)
  _print_addr(phy_address_arr[i]);
}
void _print_addr(int32_t phy_address){
  int page_number = (phy_address/PAGESIZE);
  int offset = (phy_address%PAGESIZE); printf("Page Number: %d\n", page_number); printf("Starting Address: 0x%x\n", page_number); printf("Offset: %d\n", offset);
  printf("\n\n"); 
}
