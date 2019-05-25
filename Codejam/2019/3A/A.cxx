#include<bits/stdc++.h>
using namespace std;
// #define DEBUG
// #define TIME
/*
Learn : -
Problem Type : -
Source : -
*/
#pragma GCC optimize ("Ofast")
#define sint(a) int a; qread(a);
#define sint2(a,b) int a,b; qread(a),qread(b);
#define sint3(a,b,c) int a,b,c; qread(a),qread(b),qread(c);
#define int1(a) qread(a);
#define int2(a,b) qread(a),qread(b);
#define int3(a,b,c) qread(a),qread(b),qread(c);
#define mkp make_pair
#define mkt make_tuple
#define pb emplace_back
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
#ifdef DEBUG
#define debug(x) cout<< #x << " = " << x;endl;
#else
#define debug(x)
#endif
#define OPEN freopen("input.txt","r",stdin)
#define SEND freopen("output.txt","w",stdout)
#ifdef COM
#define IN(x)
#define OUT(x)
#else
#define IN(x) freopen(x,"r",stdin);
#define OUT(x) freopen(x,"w",stdout);
#endif
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
void qread(int &x){
	int neg=1;x=0;
	register char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')neg=-1;c=getchar();}
	while(c>='0'&&c<='9')x=10*x+c-'0',c=getchar();
	x*=neg;
}
void Wl(int x)
{
    printf("%d\n",x);
}
void Wl(double x)
{
    printf("%lf\n",x);
}
void Wl(string x)
{
    printf("%s\n",x.c_str());
}
void Wl(ll x)
{
    printf("%lld\n",x);
}
void W(int x)
{
    printf("%d ",x);
}
void W(double x)
{
    printf("%lf ",x);
}
void W(string x)
{
    printf("%s ",x.c_str());
}
void W(ll x)
{
    printf("%lld ",x);
}

bitset<300> bn;
void _main()
{
    sint(n);
	vector<string> v;
	vi R,P,S;
	bn.reset();
	for(int i=0;i<n;i++)
	{
		sstring(s);
		v.pb(s);
	}
	string ans="";
	int cnt=0;
	while(1)
	{
		debug(cnt);
		for(int i=0;i<n;i++)
		{
			if(bn[i])continue;
			if(v[i][cnt%v[i].size()]=='P')P.pb(i);
			if(v[i][cnt%v[i].size()]=='R')R.pb(i);
			if(v[i][cnt%v[i].size()]=='S')S.pb(i);
		}
		debug((int)P.size());
		debug((int)R.size());
		debug((int)S.size());
		if(P.size() && R.size() && S.size())
		{
			debug(1);
			printf("IMPOSSIBLE\n");
			return;
		}
		if(P.size() && R.size() && S.empty())
		{
			debug(2);
			ans+="P";
			for(int i=0;i<R.size();i++)bn[R[i]]=1;
		}
		if(P.empty() && R.size() && S.size())
		{
			debug(3);
			ans+="R";
			for(int i=0;i<S.size();i++)bn[S[i]]=1;

		}
		if(P.size() && R.empty() && S.size())
		{
			debug(4);
			ans+="S";
			for(int i=0;i<P.size();i++)bn[P[i]]=1;
		}
		if(P.size() && R.empty() && S.empty())
		{
			debug(5);
			ans+="S";
			break;
		}
		if(P.empty() && R.size() && S.empty())
		{
			debug(6);
			ans+="P";
			break;

		}
		if(P.empty() && R.empty() && S.size())
		{
			debug(7);
			ans+="R";
			break;
		}
		P.clear();
		R.clear();
		S.clear();
		debug(ans);
		cnt++;
	}
	Wl(ans);
}
int main()
{
    sint(t);
    for(int i=1;i<=t;i++)
    {
        printf("Case #%d: ",i);
        _main();
    }
    #ifdef TIME
    	printf("Running Time = %d ms\n",int(clock()*1000.0/CLOCKS_PER_SEC));
    #endif
}
/*

*/
