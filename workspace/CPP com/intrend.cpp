#include<stdio.h>
#include<set>
#include<bitset>
using namespace std;
bitset<2000005> bt;
int main()
{
	int x,y,z;
	scanf("%d %d %d",&x,&y,&z);
	for(int i=0;i<x+y+z;i++)
	{
		int a;
		scanf("%d",&a);
		bt[a+1000001]=1;
	}
	int cnt=0;
	for(int i=0;i<=2000005;i++)
	{
		if(bt[i])
		{
			cnt++;
		}
	}
	printf("%d\n",cnt);
}
