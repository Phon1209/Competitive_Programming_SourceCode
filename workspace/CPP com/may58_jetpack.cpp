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
		sint2(n,m);
		map<int,int> mp;
		map<int,int>::iterator it;
		vi v;
		v.resize(n+1);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&v[i]);
		}
		for(int i=1;i<=n;i++)
		{
//			printf("%d %d\n",v[i],v[i-1]);
			if(v[i]-v[i-1]>0)
			{
				mp[v[i]-v[i-1]]++;
//				printf("%d %d\n",v[i]-v[i-1],i);
			}
		}
		int mx=0;
		it=mp.end();
		it--;
		while(1)
		{
			mx=max((*it).first,mx);
//			printf(">%d\n",mx);
//			printf(">>%d %d\n",(*it).first,(*it).second);
			if(m<=0)
				break;
			if(m>=(*it).second)
			{
				m-=(*it).second;
				mx=0;
			}
			else
			{
				break;
			}
			if(it==mp.begin())
				break;
			it--;
		}
		printf("%d\n",mx);
	}
}

