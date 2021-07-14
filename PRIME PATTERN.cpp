 /* 2
   3 5
   7 11 13 (USER DEPENDENT) */
#include<stdio.h>
int main()
{
	int i,j,k,s=2,q,p,n;
	printf(" enter no of rows");
	scanf("%d",&n);
	for(k=1;k<=n;k++)
	{
		for(j=1;j<=k;j++)
		{
			for(i=0;i>=0;i++)
			{
				q=1;
				for(i=2;i<=s/2;i++)
			{
				
					if(s%i==0)
				{
					q=0;
					break;
				}
				else
				continue;
			}
				if(q==0)
				{
					s=s+1;
					q=1;
				}
				else
				break;
				
			}
			printf("%d ",s);
			s=s+1;
		}
		printf("\n");
	}
}
