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
int lim=1;
double a[25][25];
double b[(1<<20)+5];
int n;
double find(int use,int l)
{
	if(use==lim)
	{
		return 1;
	}
	if(b[use]!=-1)
		return b[use];
	double ok=0;
	for(int i=0;i<n;i++)
	{
		if(!(use&(1<<i)))
		{
			ok=max(ok,find(use|(1<<i),l+1)*a[l][i]);  
		}
	}
	b[use]=ok;
	return b[use];
}
int main()
{
	int1(n);
	lim=(1<<n)-1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%lf",&a[i][j]);
			a[i][j]/=100;
		}
	}
	for(int i=0;i<=lim;i++)
		b[i]=-1;
	printf("%lf\n",find(0,0)*100);
}

