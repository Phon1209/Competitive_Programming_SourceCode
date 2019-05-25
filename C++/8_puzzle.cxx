#include <utility>

#include <utility>

#include<bits/stdc++.h>

using namespace std;
 #define DEBUG
 #define TIME
/*
Learn : -
Problem Type : -
Source : -
*/
#pragma GCC optimize ("Ofast")
#define sint( a ) int a; qread(a);
#define sint2( a, b ) int a,b; qread(a),qread(b);
#define sint3( a, b, c ) int a,b,c; qread(a),qread(b),qread(c);
#define int1( a ) qread(a);
#define int2( a, b ) qread(a),qread(b);
#define int3( a, b, c ) qread(a),qread(b),qread(c);
#define mkp make_pair
#define mkt make_tuple
#define pb emplace_back
#define inf INT_MAX
#define all( x ) (x).begin(),(x).end()
#define F first
#define S second
#define sdouble( a ) double a; scanf("%lf",&a);
#define slong( a ) long long a; scanf("%lld",&a);
#define cstring( a, x ) char a[x]; scanf("%s",a);
#define sstring( a ) string a;cin>>a;
#define rev( s ) reverse(all(s));
#define FOR( a, b, c ) for(int a=b;a<c;a++)
#define ROF( a, b, c ) for(int a=b;a>c;a--)
#define pause system("pause")
#define endl printf("\n")
#define fastio {ios::sync_with_stdio(false);cin.tie(NULL);}
#define null NULL
#ifdef DEBUG
#define debug(x) cout<< #x << " = " << x;endl;
#else
#define debug( x )
#endif
#define OPEN freopen("input.txt","r",stdin)
#define SEND freopen("output.txt","w",stdout)
#ifdef COM
#define IN(x)
#define OUT(x)
#else
#define IN( x ) freopen(x,"r",stdin);
#define OUT( x ) freopen(x,"w",stdout);
#endif
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector <ii> vii;
typedef long long ll;

void qread( int &x )
{
	int neg = 1;
	x = 0;
	register char c = getchar();
	while(c < '0' || c > '9')
	{
		if(c == '-')neg = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9')x = 10 * x + c - '0', c = getchar();
	x *= neg;
}

void Wl( int x )
{
	printf("%d\n", x);
}

void Wl( double x )
{
	printf("%lf\n", x);
}

void Wl( const string &x )
{
	printf("%s\n", x.c_str());
}

void Wl( ll x )
{
	printf("%lld\n", x);
}

void W( int x )
{
	printf("%d ", x);
}

void W( double x )
{
	printf("%lf ", x);
}

void W( const string &x )
{
	printf("%s ", x.c_str());
}

void W( ll x )
{
	printf("%lld ", x);
}
string final="123456780";
int h(string s)
{
	int ret=0;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			int cnt=(i*3)+j;
			if(s[cnt]!='0')
			{
				int u=s[cnt]-'0';
				u--;
				int x=(u)/3;
				int y=(u)%3;
				ret+=(abs(x-i)+abs(y-j));
			}
		}

	}
	return ret;
}
map<string,string> hsh;
map<string,int >cnt;
priority_queue<tuple<int,int,string> > pq;
void add(string s,int zero,int sw,int step)
{
	if(zero%3==0 && sw==zero-1)return;
	if(zero%3==2 && sw==zero+1)return;
	if(zero/3==0 && sw==zero-3)return;
	if(zero/3==2 && sw==zero+3)return;
	string tmp=s;
	swap(tmp[zero],tmp[sw]);
	if(hsh.find(tmp)!=hsh.end())return;
	hsh[tmp]=s;
	cnt[tmp]=step+1;
	pq.emplace(-(step+1+h(tmp)),-(step+1),tmp);
}
int main()
{
	string init="";
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			sint(tmp);
			init+=(char)('0'+tmp);
		}
	}
	hsh[init]="-1";
	pq.emplace(h(init),0,init);
	while(!pq.empty())
	{
		int w=-get<1>(pq.top());
		string now=get<2>(pq.top());
		pq.pop();
		if(now==final)
		{
			printf("Found at step  %d !!\n",w);
			stack<string> st;
			while(hsh.find(now)!=hsh.end())
			{
				st.emplace(now);
				now=hsh[now];
				if(now=="-1")break;
			}
			int t=0;
			while(!st.empty())
			{
				string u=st.top();
				printf("Step %d : \n",t++);
				for(int i=0;i<3;i++)
				{
					for(int j=0;j<3;j++)
					{
						printf("%c ",u[(i*3)+j]);
					}
					endl;
				}
				endl;
				st.pop();
			}
			break;
		}
		for(int i=0;i<9;i++)
		{
			if(now[i]=='0')
			{
				add(now,i,i+1,w);
				add(now,i,i-1,w);
				add(now,i,i-3,w);
				add(now,i,i+3,w);
			}
		}
	}
}
/*
8 5 6
2 0 7
3 1 4
*/
