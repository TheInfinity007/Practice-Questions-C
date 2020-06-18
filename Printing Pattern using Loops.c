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

/*

n this problem, you need to print the pattern of the following form containing the numbers from 1 to n.

                            4 4 4 4 4 4 4  
                            4 3 3 3 3 3 4   
                            4 3 2 2 2 3 4   
                            4 3 2 1 2 3 4   
                            4 3 2 2 2 3 4   
                            4 3 3 3 3 3 4   
                            4 4 4 4 4 4 4   
Input Format

The input will contain a single integer n.

Constraints
1 <= n <=1000

Output Format

Print the pattern mentioned in the problem statement.

Sample Input 0

2
Sample Output 0

2 2 2
2 1 2
2 2 2

Sample Input 1

5
Sample Output 1

5 5 5 5 5 5 5 5 5 
5 4 4 4 4 4 4 4 5 
5 4 3 3 3 3 3 4 5 
5 4 3 2 2 2 3 4 5 
5 4 3 2 1 2 3 4 5 
5 4 3 2 2 2 3 4 5 
5 4 3 3 3 3 3 4 5 
5 4 4 4 4 4 4 4 5 
5 5 5 5 5 5 5 5 5
*/
