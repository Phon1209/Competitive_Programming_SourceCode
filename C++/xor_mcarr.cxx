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
#define endl printf("\n")
#define fastio {ios::sync_with_stdio(false);cin.tie(NULL);}
#define null NULL
#ifdef DEBUG
#define debug(x) cout<< #x << " = " << x;endl;
#define pause system("pause")
#else
#define debug(x)
#define pause
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

int a[100005],ret=20;

struct Node
{
    Node *one,*zero;
    int stp=INT_MAX;
    Node():stp(INT_MAX),one(nullptr),zero(nullptr){}
}*root;

int index44;
struct Ans
{
    int val,x,y;
    bool operator < (const Ans &b)
    {
        if(val == b.val)
        {
            if(x==b.x)return y<b.y;
            return x<b.x;
        }
        return val>b.val;
    }
    void setval(int a,int b,int c){
        val=a;
        x=b;
        y=c;
    }
}ans,t;
void update(Node *now,int idx=ret)
{
    if(idx==-1)
    {
        if(index44<now->stp)now->stp=index44;
        return;
    }
    if(a[index44]&(1<<idx))
    {
        if(!now->one)now->one = new Node();
        update(now->one,idx-1);
    }
    else
    {
        if(!now->zero)now->zero = new Node();
        update(now->zero,idx-1);
    }
}
int use;
void print(int u)
{
	for(int i=20;i>=0;i--)printf("%d",(1<<i)&u? 1:0);
	endl;
}
void query(Node* now,int idx=ret)
{
    if(idx==-1)
    {
		debug(now->stp);
		debug(index44);
		debug(use);
        t.setval(use,min(index44,now->stp),max(index44,now->stp));
        if(t<ans)ans=t;
        return;
    }
    if(a[index44]&(1<<idx))
    {
        if(now->zero)query(now->zero,idx-1);
        else use^=(1<<idx),query(now->one,idx-1);
    }
    else
    {
        if(now->one)use^=(1<<idx),query(now->one,idx-1);
        else query(now->zero,idx-1);
    }
}

int main()
{
    sint(n);
    ans.setval(0,1e9,1e9);
    root=new Node();
    for(int i=1;i<=n;i++)
    {
        int1(a[i]);
        if(i!=1)a[i]^=a[i-1];
    }
	int up=n,qu=n-2;
    for(;qu!=-1;qu--,up--)
    {
		index44=up;
        update(root);
		index44=qu;
		use=a[qu];
		query(root);
    }
    W(ans.val),W(ans.x+1),Wl(ans.y);
}
/*

*/
