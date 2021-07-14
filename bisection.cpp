#include<stdio.h>
#include<math.h>
float func(float x,float p,float q,float r) 
{ 
    return p*x*x+q*x+r; 
}
void bisection(float a,float b,float p,float q,float r,float e) 
{ 
	float t,h;
	printf("The intermediate roots are:\n");
	do
	{
		t=(a+b)/2.0;
		printf("%f\n",t);
		if(func(a,p,q,r)*func(t,p,q,r)<0)
			b=t;
		else
			a=t;
		h=(a+b)/2.0;
	}while(fabs(t-h)>e);
	printf("The root is: %f",t);
} 
int main() 
{ 
    float p,q,r,prev=0,next=1,a,b,e,h,t;
    printf("Enter the coefficient of x*2: ");
    scanf("%f",&p);
    printf("Enter the coefficient of x*1: ");
    scanf("%f",&q);
    printf("Enter the coefficient of x*0: ");
    scanf("%f",&r);
	printf("Enter the value of precision: ");
	scanf("%f",&e);
	while(1)
	{
    	if(func(prev,p,q,r)*func(next,p,q,r)>0)
    	{
    		prev=next;
    		next++;
	  	}
	  	else
	 	{
	 		a=prev;
	 		b=next;
		 	break;
	 	}
	}
	bisection(a,b,p,q,r,e);
  	return 0; 
}

