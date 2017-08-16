#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

void isPalindrome(char* str) {
    int x=strlen(str);
  char str2[x];
  int y,m;
  for(y=x-1, m=0;m<x;y--,m++)
    str2[m]=str[y];
  //for(y=0;y<x;y++){
  //  if(str2[y]!=str[y])printf("NAO\n");
  //}
  for(y=0;y<x;y++){
    if(str2[y]!=str[y]){
        printf("NAO\n");
        break;
    }
    else{
        printf("SIM\n");
        break;
    }
  }
}

int main() {
    char* str = (char *)malloc(512000 * sizeof(char));
    scanf("%s", str);
    isPalindrome(str);
    return 0;
}

