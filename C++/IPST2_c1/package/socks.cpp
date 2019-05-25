#include <iostream>
#include <vector>
#include "sockslib.h"

using namespace std;

int main() {
  int n;
  n = num();
  vector<int> v = {1,2,3};
  cout << ask( v ) << endl;
  match(1,2);
}
/*
#include<bits/stdc++.h>
#include"sockslib.h"
using namespace std;
// #define DEBUG
// #define TIME
Learn : -
Problem Type : -
Source : -
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
int ret[2005][2005];
void compute(int l,int r)
{
	vi v;
	for(int i=l;i<=r;i++)
	{
		v.pb(i);
	}
	ret[l][r]=ask(v);
	if(l==r)return;
	compute(l,md);
	compute(md+1,r);
}
int main()
{
    int n=num();
	vi v;
	compute(n+1,2*n);
	for(int i=1;i<=n;i++)
	{
		int l=n+1,r=2*n;
		v.clear();
		v.pb(i);
		for(int j=l;j<=r;j++)
		{
			v.pb(j);
		}
		int r=ask(v);
		if(r==ret[l][r])
		{
			while(l<r)
			{
				v.clear();
				int md=(l+r)/2;
				debug(l);
				debug(r);
				debug(md);
				v.pb(i);
				for(int j=l;j<=md;j++){
					v.pb(j);
				}
				r=ask(v);
				if(r==ret[l][md])
				{
					r=md;
				}
				else
				{
					l=md+1;
				}
			}
		}
		else
		{
			g1.pb(i);
		}
	}
}

*/
