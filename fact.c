#include<stdio.h>

//int fact(unsigned int);


int fact(unsigned int x)
{
	unsigned int f=1;
	for(int i=1;i<=x;i++)
	{
		f=f*i;
		printf("%d\t",f);
	}
	return f;
}

int main()
{
	printf(" %d\n",fact(4));
	return 0;
}
