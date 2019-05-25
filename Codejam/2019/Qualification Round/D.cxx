#include<bits/stdc++.h>
using namespace std;
int n,b,f;
char ask[6][1050];
char res[6][1050];
bitset<1050> bt;
void _main()
{
    scanf("%d %d %d",&n,&b,&f);
	bt.reset();
	for(int i=0;i<=4;i++)
	{
		int u=(1<<i);
		for(int j=0;j<n;j++)
		{
			ask[i][j]=((j/u)%2)? '1':'0';
		}
	}
	for(int i=0;i<5;i++)
	{
		ask[i][n]='\0';
		printf("%s\n",ask[i]);
		fflush(stdout);
		scanf("%s",res[i]);
	}
	int idx=0;
	char last='0';
	for(int i=0;i<n-b;i++)
	{
		if(res[4][i]!=last)
		{
			last=res[4][i];
			idx+=16;
		}
		int y=0;
		for(int j=0;j<=3;j++)
			if(res[j][i]=='1')
				y+=(1<<j);
		bt[idx+y]=1;
	}
	for(int i=0;i<n;i++){
		if(!bt[i]){
			b--;
			printf("%d",i);
			if(b)printf(" ");
		}
	}
	printf("\n");
	fflush(stdout);
	int vd;
	scanf("%d",&vd);
	if(vd!=1)assert(0);
}
int main()
{
    int t;scanf("%d",&t);
    for(int i=1;i<=t;i++)
        _main();
}
/*

*/
