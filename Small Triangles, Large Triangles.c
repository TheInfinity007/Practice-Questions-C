#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;
float getArea(triangle tr){
    float p = (tr.a + tr.b + tr.c)/2.0;
    float area;
    
    area = sqrt(p* (p-tr.a) * (p-tr.b) * (p-tr.c));
    return area;
}

void sort_by_area(triangle* tr, int n) {
	/**
	* Sort an array a of the length n
	*/

    triangle temp;
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-1; j++){
            float a1 = getArea(tr[j]);
            float a2 = getArea(tr[j+1]);
            if(a1 > a2){
                temp = tr[j];
                tr[j] = tr[j+1];
                tr[j+1] = temp;
            }
        }
    }
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}

/*
You are given  triangles, specifically, their sides ,  and . Print them in the same style but sorted by their areas from the smallest one to the largest one. It is guaranteed that all the areas are different.

The best way to calculate a volume of the triangle with sides ,  and  is Heron's formula:

 where .

Input Format

First line of each test file contains a single integer .  lines follow with ,  and  on each separated by single spaces.

Constraints

, and 
Output Format

Print exactly  lines. On each line print  integers separated by single spaces, which are ,  and  of the corresponding triangle.

Sample Input 0

3
7 24 25
5 12 13
3 4 5
Sample Output 0

3 4 5
5 12 13
7 24 25
*/