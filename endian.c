#include <stdio.h>

int main(void) {
  int x = 1;
  if (1 == (int)(((char *)&x)[0])){
    printf("little");
  }
  else{
    printf("big");
  }
  return 0;
}
