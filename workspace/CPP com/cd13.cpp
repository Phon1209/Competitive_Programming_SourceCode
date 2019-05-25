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
	sint(t);
	while(t--)
	{
		sint2(n,k);
		int ans;
		if(k==13)
		{
			k=12;
		}
		if(k<=12)
		{
			ans=(n/k);
			if(n%k!=0)
				ans++;
		}
		else
		{
			ans=(n/k);
			if(n%k==13)
			{
				if(k>14)
				{
					if(ans==0)
					{
						ans++;
					}
					ans++;
				}
				else
				{
					ans+=2;
				}
			}
			else if(n%k!=0)
			{
				ans++;
			}
		}
		printf("%d\n",ans);
	}
}

