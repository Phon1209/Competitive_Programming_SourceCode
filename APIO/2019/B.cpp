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
struct Node
{
    int val;
    Node *l,*r;
    void compute()
    {
        val = l->val < r->val ? l->val : r->val;
    }
    Node(int val):val(val),l(nullptr),r(nullptr){}
    Node(Node *l,Node *r):l(l),r(r){
        compute();
    }
};
int s[300005];
Node *build(int l,int r)
{
    if(l==r)return new Node(s[l]);
    int md=(l+r)/2;
    return new Node(build(l,md),build(md+1,r));
}
void update(Node *now,int l,int r,int pos,int Time)
{
    if(l==r)
    {
        now->val = Time;
        return;
    }
    int md=(l+r)/2;
    if(pos<=md)update(now->l,l,md,pos,Time);
    else update(now->r,md+1,r,pos,Time);
    now->compute();
}
int query(Node *now,int l,int r,int x,int y)
{
    if(y<l || x>r)return 0;
    if(x<=l && r<=y)return now->val;
    int md=(l+r)/2;
    return min(query(now->l,l,md,x,y),query(now->r,md+1,r,x,y));
}
int re[50005];
int main()
{
    sint2(n,m);
    for(int i=0;i<m;i++)
    {
        sint3(x,y,w);
        s[y]=w;
        re[i+1]=y;
    }
    sint(q);
    Node *root=build(1,n);
    while(q--)
    {
        sint(t);
        if(t==1) //change W
        {
            sint2(x,w);
            update(root,1,n,re[x],w);
        }
        if(t==2)
        {
            sint2(s,w);
            int ans=1;
            bool ok=false;
            int l=s+1,r=n;
            while(l<=r)
            {
                int md=(l+r)/2;
                if(query(root,1,n,s+1,md)<=w)
                {
                    l=md+1;
                    ok=true;
                }
                else r=md-1;
            }
            int got=0;
            if(ok)ans+=(l-s);
            l=1,r=s-1;
            while(l<=r)
            {
                int md=(l+r)/2;
                if(query(root,1,n,md,s)<=w)
                {
                    r=md-1;
                    got=max(got,s-md+1);
                }
                else l=md+1;
            }
            Wl(ans+got);
        }
    }
    #ifdef TIME
    	printf("Running Time = %d ms\n",int(clock()*1000.0/CLOCKS_PER_SEC));
    #endif
}
/*
3 4
1 2 5
2 3 2
3 1 4
2 3 8
5
2 1 5
1 4 1
2 2 5
1 1 1
2 3 2
*/
