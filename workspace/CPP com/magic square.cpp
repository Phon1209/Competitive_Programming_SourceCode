#include<bits/stdc++.h>
using namespace std;
#define sint(a) int a; scanf("%d",&a)
#define sint2(a,b) int a,b; scanf("%d %d",&a,&b)
#define sint3(a,b,c) int a,b,c; scanf("%d %d %d",&a,&b,&c)
#define int1(a) scanf("%d",&a)
#define int2(a,b) scanf("%d %d",&a,&b)
#define int3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define mkp make_pair
#define pb push_back
#define inf 1e9
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
#define sdouble(a) double a; scanf("%lf",&a)
#define slong(a) long long a; scanf("%lld",&a)
#define sstring(a,x) char a[x]; scanf("%s",a)
#define sss(a,b,c) stringstream a; a<<b; a>>c
#define rev(s) reverse(all(s))
#define FOR(a,b,c) for(int a=b;a<c;a++)
#define ROF(a,b,c) for(int a=b;a>c;a--)
#define pause system("pause")
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
int a[1000][1000],x,y,n,cnt=0;
void pt()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%*d ",cnt,a[i][j]);
		}
		printf("\n");
	}
}
void place(int d,int r,int p)
{
	a[d][r]=p;
}
void re(int d,int r)
{
	x--;
	y++;
	x+=n;
	x%=n;
	y%=n;
	if(a[x][y]!=-1)
	{
		x=d+1;
		x%=n;
		y=r;
	}
//	printf("%d %d\n",x,y);
}
int main()
{
	int1(n);
	x=0;
	y=n/2;
	int tmp=(n*n);
	while(tmp>0)
	{
		tmp/=10;
		cnt++;
	}
	memset(a,-1,sizeof(a));
	for(int i=1;i<=(n*n);i++)
	{
		place(x,y,i);
		re(x,y);
//		pt();
//		pause;
	}
	pt();
}


