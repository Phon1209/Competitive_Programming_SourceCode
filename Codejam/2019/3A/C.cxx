#include<bits/stdc++.h>
using namespace std;
#define DEBUG
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

int n,m;
map<string,bool> mp;
bool alpha(string s)
{
	if(mp.find(s)!=mp.end())return mp[s];
	bool ret=false;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(s[i*m+j]=='.')
			{
				string tmp=s;
				bool no=false;
				for(int k=i;k<n;k++) // V type
				{
					if(tmp[j+k*m]=='.')tmp[j+k*m]='@';
					else if(tmp[j+k*m]=='@')break;
					else if(tmp[j+k*m]=='#')no=true;
				}
				for(int k=i-1;k>=0;k--)
				{
					if(tmp[j+k*m]=='.')tmp[j+k*m]='@';
					else if(tmp[j+k*m]=='@')break;
					else if(tmp[j+k*m]=='#')no=true;
				}
				if(!no)
				{
					ret|=alpha(tmp);
				}
				no=false;
				tmp=s;
				for(int k=j;k<m;k++) // H type
				{
					if(tmp[i*m+k]=='.')tmp[i*m+k]='@';
					else if(tmp[i*m+k]=='@')break;
					else if(tmp[i*m+k]=='#')no=true;
				}
				for(int k=j-1;k>=0;k--) // H type
				{
					if(tmp[i*m+k]=='.')tmp[i*m+k]='@';
					else if(tmp[i*m+k]=='@')break;
					else if(tmp[i*m+k]=='#')no=true;
				}
				if(!no)
				{
					ret|=alpha(tmp);
				}
				if(ret)
				{
					mp[s]=!ret;
					return !ret;
				}
			}
		}
	}
	mp[s]=!ret;
	return !ret;
}


void _main()
{
    int2(n,m);
	string st="";
	for(int i=0;i<n;i++)
	{
		sstring(q);
		st+=q;
	}
	int ans=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(st[i*m+j]=='.')
			{
				string tmp=st;
				bool no=false;
				for(int k=i;k<n;k++) // V type
				{
					if(tmp[j+k*m]=='.')tmp[j+k*m]='@';
					else if(tmp[j+k*m]=='@')break;
					else if(tmp[j+k*m]=='#')no=true;
				}
				for(int k=i-1;k>=0;k--)
				{
					if(tmp[j+k*m]=='.')tmp[j+k*m]='@';
					else if(tmp[j+k*m]=='@')break;
					else if(tmp[j+k*m]=='#')no=true;
				}
				if(!no)ans+=(alpha(tmp))? 1:0;
				no=false;
				tmp=st;
				for(int k=j;k<m;k++) // H type
				{
					if(tmp[i*m+k]=='.')tmp[i*m+k]='@';
					else if(tmp[i*m+k]=='@')break;
					else if(tmp[i*m+k]=='#')no=true;
				}
				for(int k=j-1;k>=0;k--) // H type
				{
					if(tmp[i*m+k]=='.')tmp[i*m+k]='@';
					else if(tmp[i*m+k]=='@')break;
					else if(tmp[i*m+k]=='#')no=true;
				}
				if(!no)ans+=(alpha(tmp))? 1:0;
			}
		}
	}
	Wl(ans);
}
int main()
{
    sint(t);
    for(int i=1;i<=t;i++)
    {
		mp.clear();
        printf("Case #%d: ",i);
        _main();
    }
    #ifdef TIME
    	printf("Running Time = %d ms\n",int(clock()*1000.0/CLOCKS_PER_SEC));
    #endif
}
/*

*/
