#include<bits/stdc++.h>
using namespace std;
/*
Learn : -
Problem Type : -
Source : -
*/
#pragma GCC optimize ("Ofast")
#define sint(a) int a; scanf("%d",&a);
#define sint2(a,b) int a,b; scanf("%d %d",&a,&b);
#define sint3(a,b,c) int a,b,c; scanf("%d %d %d",&a,&b,&c);
#define int1(a) scanf("%d",&a);
#define int2(a,b) scanf("%d %d",&a,&b);
#define int3(a,b,c) scanf("%d %d %d",&a,&b,&c);
#define mkp make_pair
#define pb push_back
#define inf INT_MAX
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
#define sdouble(a) double a; scanf("%lf",&a);
#define slong(a) long long a; scanf("%lld",&a);
#define cstring(a,x) char a[x]; scanf("%s",a);
#define sstring(a) string a;cin>>a;
#define rev(s) reverse(all(s));
#define FOR(a,b,c) for(int a=b;a<c;a++)
#define ROF(a,b,c) for(int a=b;a>c;a--)
#define pause system("pause")
#define endl printf("\n")
#define fastio {ios::sync_with_stdio(false);cin.tie(NULL);}
#define null NULL
#define debug(x) cout<< #x << " = " << x;endl;
#define OPEN freopen("input.txt","r",stdin)
#define SEND freopen("output.txt","w",stdout)
#define IN(x) freopen(x,"r",stdin);
#define OUT(x) freopen(x,"w",stdout);

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;

ll phase[10005];
ll simul[20005];
int main()
{
	slong(h);
	sint(n);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&phase[i]);
	}
	bool ok=0;
	ll ans,ans2;
	for(int i=0;i<2*n;i++)
	{
		simul[i+1]+=simul[i]+phase[i%n];
		simul[i+1]=max(simul[i+1],0ll);
		if(simul[i+1]>=h)
		{
			ok=1;
            // debug(i);
            // debug(n);
            // debug(i%n);
			printf("%d %d\n",i/n,i%n);
			return 0;
		}
	}
	ll inc=0;
	if(!ok)
	{
		for(int i=0;i<n;i++)
		{
			inc+=phase[i];
			if(inc<=-h)
			{
				printf("-1 -1\n");
				ok=1;
				return 0;
			}
		}
		if(inc<=0 && !ok)
		{
			printf("-1 -1\n");
			ok=1;
			return 0;
		}
	}
	if(!ok)
	{
		ans=LLONG_MAX;
		ans2=0;
		for(int i=0;i<n;i++)
		{
			ll use=1ll+(ll)(h-simul[n+i+1]+inc-1)/(ll)inc;
			if(use<ans)
			{
				ans=use;
				ans2=i;
			}
		}
		printf("%lld %lld\n",ans,ans2);
	}
}
/*
123456789012 1
123456789013
*/
