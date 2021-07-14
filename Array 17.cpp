/*FREQUENCY OF ELEMENTS OF A ARRAY*/
#include<stdio.h>
int main()
{
  int a[20],b[20],c[20],d[20],i,j,m=-1,flag=0,n;
  printf("enter the size of the array");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    printf("enter the elements of the array");
    scanf("%d",&a[i]);
    b[i]=0;
    c[i]=0;
  }
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      if(a[i]==b[j] ){
        flag=1;
        break;
      }
    }
    if(flag==1)
    {
      c[j]++;
      flag=0;
    }
    else
    {
      b[++m]=a[i];
      c[m]++;
    }
  }
  for(i=0;i<=m;i++)
  {
    printf("%d occured %d time(s)\n",b[i],c[i]);
  }
  return 0;
}
