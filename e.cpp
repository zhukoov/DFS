#include<stdio.h>
#include<cstdio>
#include<iostream>
using namespace std;
int main ()
{
	double e=1;			//e=1  + 1/1! + ... 
	double p=1.0;		//p 是分母 
	double count=1;		//count 是阶乘的数 
	while(p>1e-10)
	{
		p/=count;		//分母除以阶乘的最大数 
		count+=1;		//阶乘最大数自增1 
		e+=p;			//e加下一项 
	}
	printf("%lf",e);
}
