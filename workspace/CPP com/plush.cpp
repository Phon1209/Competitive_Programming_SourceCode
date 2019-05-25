#include<bits/stdc++.h>
using namespace std;
#define sint(a) int a; scanf("%d",&a);
#define sint2(a,b) int a,b; scanf("%d %d",&a,&b);
#define sint3(a,b,c) int a,b,c; scanf("%d %d %d",&a,&b,&c);
#define int1(a) scanf("%d",&a);
#define int2(a,b) scanf("%d %d",&a,&b);
#define int3(a,b,c) scanf("%d %d %d",&a,&b,&c);
#define mkp make_pair
#define pb push_back
#define inf 1e9
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
#define sdouble(a) double a; scanf("%lf",&a);
#define slong(a) long long a; scanf("%lld",&a);
#define sstring(a,x) char a[x]; scanf("%s",a);
#define sss(a,b,c) stringstream a; a<<b; a>>c
#define rev(s) reverse(all(s));
#define FOR(a,b,c) for(int a=b;a<c;a++)
#define ROF(a,b,c) for(int a=b;a>c;a--)
#define pause system("pause")
#define endl printf("\n")
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
int sz[25];
int a[25][100005];
int b[1<<20];
int main()
{
	sint2(n,m);
	for(int i=1;i<=n;i++)
	{
		sint(y);
		y--;
		sz[y]++;
		a[y][i]=1;
	}
	for(int i=0;i<m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			a[i][j]+=a[i][j-1];
		}
	}
	for(int i=0;i<(1<<m);i++)
		b[i]=inf;
	b[0]=0;
	for(int i=0;i<(1<<m);i++)
	{
		int s=0;
		for(int j=0;j<m;j++)
		{
			if(i&(1<<j))
			{
				s+=sz[j];
			}
		}
		for(int j=0;j<m;j++)
		{
			if(i&(1<<j)) continue;
			b[i+(1<<j)]=min(b[i+(1<<j)],b[i]+sz[j]-(a[j][s+sz[j]]-a[j][s]));
		}
	}
	printf("%d\n",b[(1<<(m))-1]);
}


