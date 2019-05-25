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
int a[105];
int main()
{
	sint(t);
	while(t--)
	{
		sint(n);
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i]-a[i-1]>0)
				ans=max(ans,a[i]-a[i-1]);
		}
//		printf(">%d\n",ans);
		for(int i=1;i<n;i++)
		{
			swap(a[i],a[i+1]);
				int cnt=0;
				for(int k=1;k<=n;k++)
				{
					if(a[k]-a[k-1]>0)
						cnt=max(cnt,a[k]-a[k-1]);
				}
//				printf("%d\n",cnt);	
				ans=min(ans,cnt);
			swap(a[i],a[i+1]);
		}
		printf("%d\n",ans);
	}
}

