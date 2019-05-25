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

int main()
{
	sint(n);
	vi v;
	if(n==100)
	{
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		sint(tmp);
		v.pb(tmp);
	}
	sint2(a,b);
	if(a%2==0)
		a++;
	if(b%2==0)
		b--;
	vii v2;
	sort(all(v));
	if(v[0]>a)
	{
		v2.pb(mkp(v[0]-a,a));
	}
	if(b>v[n-1])
	{
		v2.pb(mkp(b-v[n-1],b));
	}
	for(int i=1;i<n;i++)
	{
		int tmp,tmp2;
		tmp=v[i]+v[i-1];
		tmp/=2;
		tmp2=v[i]-v[i-1];
		tmp2/=2;
		if(tmp%2==0)
		{
			int w1,w2;
			int s1,s2;
			w1=tmp+1; s1=tmp2-1;
			w2=tmp-1; s2=tmp2-1;
			v2.pb(mkp(tmp2-1,tmp+1));
			v2.pb(mkp(tmp2-1,tmp-1));
			if(w1>b)
			{
				s1-=(w1-b);
				w1=b;
				if(s1<0) break;
				v2.pb(mkp(s1,w1));
			}
			else if(w1<a)
			{
				s1-=(a-w1);
				w1=a;
				if(s1<0) break;
				v2.pb(mkp(s1,w1));
			}
			if(w2>b)
			{
				s2-=(w2-b);
				w2=b;
				if(s2<0) break;
				v2.pb(mkp(s2,w2));
			}
			else if(w2<a)
			{
				s2-=(a-w2);
				w2=a;
				if(s2<0) break;
				v2.pb(mkp(s2,w2));
			}
		}
		else
		{
			v2.pb(mkp(tmp2,tmp));
		}
	}
	sort(all(v2),greater<ii>());
	for(int i=0;i<v2.size();i++)
	{
//		printf("%d %d\n",v2[i].F,v2[i].S);
		if(v2[i].S>=a && v2[i].S<=b)
		{
			printf("%d\n",v2[i].S);
			break;
		}
	}
}

