#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n;
    scanf("%d", &n);
  	// Complete the code to print the pattern.

    int j, k, temp;
    for(int i = 0; i < n; i++){
        k = n;
        for(j = 0; j <= i; j++){
            printf("%d ", k-j);
        }
        temp = k-j+1;
        for(; j < n; j++){
            printf("%d ", temp);
        }

        for(j = n-1; j > i+1; j--){
            printf("%d ", temp);
        }

        for(; j > 0; j--){
            printf("%d ", k-j+1);
        }
        printf("\n");
    }

    for(int i = n-1; i > 0; i--){
        k = i;
        for(j = 0; j < i; j++){
            printf("%d ", n-j);
        }

        temp = n-j+1;
        for(; j < n; j++){
            printf("%d ", temp);
        }

        for(j = n-1; j > i; j--){
            printf("%d ",temp);
        }

        for(; j > 0; j--){
            printf("%d ", n-j+1);
        }

        printf("\n");
    }
    
    return 0;
}
