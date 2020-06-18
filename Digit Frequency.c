#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    char *s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s)+1);

    int arr[10] = {0};
    int len = strlen(s);

    for(int i = 0; i < len; i++){
        if(s[i] <= '9' && s[i] >= '0')
            arr[s[i]-48]++;
    }
    for(int i = 0; i < 10; i++)
        printf("%d ", arr[i]);

    return 0;
}

/*
Given a string, s, consisting of alphabets and digits, find the frequency of each digit in the given string.

Input Format

The first line contains a string, num which is the given number.

Constraints
1 <= len(num) <= 1000

All the elements of num are made of english alphabets and digits.

Output Format

Print ten space-separated integers in a single line denoting the frequency of each digit from 0 to 9.

Sample Input 0

a11472o5t6
Sample Output 0

0 2 1 0 1 1 1 1 0 0 
Explanation 0

In the given string:

 occurs two times.
 and  occur one time each.
The remaining digits  and  don't occur at all.
Sample Input 1

lw4n88j12n1
Sample Output 1

0 2 1 0 1 0 0 0 2 0
*/