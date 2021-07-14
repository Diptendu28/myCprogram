#include <stdio.h>
#include<stdlib.h>
int main(int argc, char* argv[])
{
    int i,j,n;
	n=atoi(argv[1]);
    for(i=1;i<=n; i++)
    {
        for(j=1;j<=(i*2-1);j++)
        {
            printf("%d ",j);
        }
		printf("\n");
    }
}

