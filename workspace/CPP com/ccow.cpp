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
int a[5][100005];
int main()
{
	sint(n);
	sstring(s,100005);
	for(int i=1;i<=n;i++)
	{
		if(s[i-1]=='C')
		{
			a[0][i]=1;
		}
		else if(s[i-1]=='O')
		{
			a[1][i]=1;
		}
		else if(s[i-1]=='W')
		{
			a[2][i]=1;
		}
	}
	for(int j=1;j<=n;j++)
	{
		a[2][j]+=a[2][j-1];
	}
	for(int j=1;j<=n;j++)
	{
		if(a[1][j])
		{
			a[1][j]*=a[2][n]-a[2][j];
		}
	}
	for(int j=1;j<=n;j++)
	{
		a[1][j]+=a[1][j-1];
	}
	long long cnt=0;
	for(int j=1;j<=n;j++)
	{
		if(a[0][j])
		{
			a[0][j]*=a[1][n]-a[1][j];
			cnt+=a[0][j];
		}
	}
	printf("%lld\n",cnt);
}


