#include<stdio.h>
#include<cstdio>
#include<iostream>
using namespace std;
int main ()
{
	double e=1;			//e=1  + 1/1! + ... 
	double p=1.0;		//p �Ƿ�ĸ 
	double count=1;		//count �ǽ׳˵��� 
	while(p>1e-10)
	{
		p/=count;		//��ĸ���Խ׳˵������ 
		count+=1;		//�׳����������1 
		e+=p;			//e����һ�� 
	}
	printf("%lf",e);
}
