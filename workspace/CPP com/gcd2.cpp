#include<bits/stdc++.h>
using namespace std;
#define sint(a) int a; scanf("%d",&a);
#define sint2(a,b) int a,b; scanf("%d %d",&a,&b);
#define sint3(a,b,c) int a,b,c; scanf("%d %d %d",&a,&b,&c);
#define mkp make_pair
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
char y[100005];
int main()
{
	slong(x);
	scanf("%s",y);
	unsigned long long Y=0,X=x;
	if(X==0)
	{
		printf("%s\n",y);
	}
	else if(y[0]=='0')
	{
		printf("%lld\n",X);
	}
	else
	{
		for(int i=0;y[i];i++)
		{
			Y*=10;
			Y%=X;
			Y+=y[i]-'0';
			Y%=X;
		}
		printf("%lld\n",__gcd(X,Y));
	}
}

