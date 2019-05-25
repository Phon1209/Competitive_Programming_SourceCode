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
ll conv(string s,int base)
{
	long long ret=0;
	for(int i=0;i<s.size();i++)
	{
		ret*=base;
		ret+=(s[i]-'0');
	}
	return ret;
}
map<ll,int> mp;
int main()
{
	sint(t);
	while(t--)
	{
		mp.clear();
		sstring(c,10);
		sstring(c2,10);
		for(int i=10;i<=15000;i++)
		{
			mp[conv(c,i)]=i;
		}
		for(int i=10;i<=15000;i++)
		{
			long long tmp=conv(c2,i);
			if(mp.find(tmp)!=mp.end())
			{
				printf("%d %d\n",mp[tmp],i);
				break;
			}
		}
	}
}


