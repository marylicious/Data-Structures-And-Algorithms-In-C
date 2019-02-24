#include <stddef.h>
#include <stdio.h>

size_t countBits(unsigned value) {

 size_t rem =0, bit = 0;

  while(value>0) {
    printf("value => %d \n", value);
    printf("remainder => %ld \n", rem);
     printf("bit => %ld \n", bit);
    rem = value % 2;
    value = value / 2;
    
    if(rem == 1) {bit++;}
  }
  printf("bit => %ld", bit);
  return bit;
}

int main () {

 countBits(4);
}