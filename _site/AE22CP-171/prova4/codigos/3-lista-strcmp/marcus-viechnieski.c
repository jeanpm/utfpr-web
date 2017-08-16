#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
  char* str_a[200];
  char* str_b[200];
  scanf("%s", str_a);
  scanf("%s", str_b);

  int x,a,b,m=0;

  a=strlen(str_a);
  b=strlen(str_b);

  if(a>=b){
    for(x=0;x<a;x++){
      if('str_a[x]'>'str_b[x]'&&m==0){
        printf("A maior que B");
        m++;
      }
      if('str_a[x]'<'str_b[x]'&&m==0){
        printf("A maior que B");
        m++;
      }
    }
  }
    else if(a<b){
      for(x=0;x<b;x++){
        if('str_a[x]'>'str_b[x]'&&m==0){
          printf("A menor que B");
          m++;}
          
        if('str_a[x]'>'str_b[x]'&&m==0){
          printf("A menor que B");
          m++;
        }
      }
    }
  
  return 0;
}
