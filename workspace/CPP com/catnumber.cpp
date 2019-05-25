#include<bits/stdc++.h>
using namespace std;
#define sint(a) int a; scanf("%d",&a);
#define sint2(a,b) int a,b; scanf("%d %d",&a,&b);
#define sint3(a,b,c) int a,b,c; scanf("%d %d %d",&a,&b,&c);
#define mp make_pair
#define pb push_back
#define inf 1e9
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
#define sdouble(a) double a; scanf("%lf",&a);
#define slong(a) long long a; scanf("%lld",&a);
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
long long cnt=0;
int g[15];
long long chk[1050];
char a[20];
int main()
{
	sint(n);
	for(int i=0;i<n;i++)
	{
		int tmp=0;
		scanf("%s",a);
		for(int j=0;a[j];j++)
		{
			tmp|=1<<(a[j]-'0');
		}
		a[0]=0;
		chk[tmp]++;
	}
	for(int i=0;i<1024;i++)
	{
		for(int j=i;j<1024;j++)
		{
			if(i==j)
				cnt+=(chk[i]*(chk[i]-1))/2;
			else if(i&j)
			{
				cnt+=(chk[i]*chk[j]);
			}
		}
	}
	printf("%lld\n",cnt);
}


