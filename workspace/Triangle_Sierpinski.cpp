#include<stdio.h>
int i,j,n;
main(){scanf("%d",&n);while(i<n){j=0;while(j<n)printf("%c",(i&j++)? '.':'#' );printf("\n");i++;}}
