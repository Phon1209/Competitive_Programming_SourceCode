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
struct Suffix
{
    int r1,r2,idx;
    Suffix(int a,int b,int c):r1(a),r2(b),idx(c){}
    bool operator < (const Suffix &b)
    {
        if(r1==b.r1)return r2<b.r2;
        return r1<b.r1;
    }
    bool operator == (const Suffix &b)
    {
        return ((r1==b.r1) && (r2==b.r2));
    }
};
int rnk[1005];
int  ans=0,K;
void K0(string s)
{
    queue<char> q,q2;
    for(int i=1;i<s.size();i++)
    {
        while(!q.empty())q.pop(),q2.pop();
        ll dif=1;
        for(int j=0;j<i;j++)dif*=13;
        ll h=0,h2=0;
        int st=0,st2=i;
        for(;st2<s.size();st++,st2++)
        {
            h*=13;
            h2*=13;
            h+=s[st];
            h2+=s[st2];
            q.push(s[st]);
            q2.push(s[st2]);
            while(q.size()>i)
            {
                h-=dif*(q.front());
                q.pop();
                h2-=dif*(q2.front());
                q2.pop();
            }
            if(q.size()==i && h==h2)ans++;
        }
        // debug(ans);
    }
    Wl(ans);
}
void N200(string s)
{
    for(int i=1;i<s.size();i++)
    {
        int st=0,st2=i;
        for(;st2<s.size();st++,st2++)
        {
            int nub=0;
            for(int k=0;k<i;k++)
            {
                if(s[st-k]!=s[st2-k])nub++;
            }
            if(nub==K)ans++;
        }
    }
    Wl(ans);
}
int main()
{
    int1(K);
    sstring(s);
    if(K==0)K0(s);
    else if(s.size()<=200)N200(s);
    #ifdef TIME
    	printf("Running Time = %d ms\n",int(clock()*1000.0/CLOCKS_PER_SEC));
    #endif
}
/*
0
aaaaaa
*/
