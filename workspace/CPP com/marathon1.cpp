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
int a[100005][5];
int main()
{
	sint(n);
	vii v;
	for(int i=0;i<n;i++)
	{
		sint2(x,y);
		v.pb(mkp(x,y));
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<2;j++)
		{
			a[i][j]=inf;
		}
	}
	a[0][0]=0;
	for(int i=1;i<n;i++)
	{
		if(i==1)
		{
			int w;
			w=abs(v[i].F-v[i-1].F)+abs(v[i].S-v[i-1].S);
			a[i][0]=(w);
		}
		else
		{
			int w;
			w=abs(v[i].F-v[i-1].F)+abs(v[i].S-v[i-1].S);
			a[i][0]=w+a[i-1][0];
			int w2;
			w2=abs(v[i].F-v[i-2].F)+abs(v[i].S-v[i-2].S);
			a[i][1]=min(a[i-2][0]+w2,a[i-1][1]+w);
		}
	}
	/*
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<2;j++)
		{
			printf("%d ",a[i][j]);
		}
		endl;
	}
	*/
	printf("%d\n",min(a[n-1][0],a[n-1][1]));
}


