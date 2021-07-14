#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include"printIO.h"

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;
//----------------------------------------------------------
void sort_by_area(triangle *tr, int n){
    float *area = (float*)malloc(n*sizeof(float));
    for (int i = 0; i < n; i++){
       float p = (tr[i].a + tr[i].b + tr[i].c)*0.5;
       area[i] = sqrt(p*(p-tr[i].a)*(p-tr[i].b)*(p-tr[i].c));
    }
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-1-i; j++){
            if(area[j]>area[j+1]){
                // swap areas
                float f = area[j];
                area[j] = area[j+1];
                area[j+1] = f;
                // swap triangles
                triangle t = tr[j];
                tr[j] = tr[j+1];
                tr[j+1] = t;
            }
        }
    }
}
//------------------------------------------------------------------
int main()
{
    OpenIO(fopen("Small_Triangles_Large_Triangles.c", "a"));
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