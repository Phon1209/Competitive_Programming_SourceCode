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

int main()
{
	sint3(r,s,t);
	sint(n);
	for(int i=0;i<n;i++)
	{
		sint(p);
		p-=r;
		if(p<=0)
		{
			printf("no\n");
			continue;
		}
		p%=(s+t);
		if(p<=s)
		{
			printf("yes\n");
		}
		else
		{
			printf("no\n");
		}
	}
}

