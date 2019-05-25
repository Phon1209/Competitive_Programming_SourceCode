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
ll qs[100005];
map<ll,int> mp;
int dp[100005];
struct Node
{
    int val;
    Node *l,*r;
    void compute()
    {
        val = max(l->val,r->val);
    }
    Node(Node *l,Node *r):l(l),r(r){
        compute();
    }
    Node(int val):l(nullptr),r(nullptr),val(val){}
};
Node *build(int l,int r)
{
    if(l==r)return new Node(INT_MIN);
    int md=(l+r)/2;
    return new Node(build(l,md),build(md+1,r));
}
int query(Node *now,int l,int r,int x,int y)
{
    if(y<l || x>r)return INT_MIN;
    if(x<=l && r<=y)return now->val;
    int md=(l+r)/2;
    return max(query(now->l,l,md,x,y),query(now->r,md+1,r,x,y));
}
void update(Node *now,int l,int r,int pos,int val)
{
    if(l==r)
    {
        now->val = val;
        return;
    }
    int md=(l+r)/2;
    if(pos<=md)update(now->l,l,md,pos,val);
    else update(now->r,md+1,r,pos,val);
    now->compute();
}
int main()
{
    sint(n);
    for(int i=1;i<=n;i++)
    {
        sint(tmp);
        qs[i]=qs[i-1]+tmp;
        mp[qs[i]];
    }
    int cnt=0;
    auto it=mp.begin();
    while(it!=mp.end())
    {
        mp[(*it).F]=++cnt;
        it++;
    }
    Node *root=build(1,n);
    for(int i=1;i<=n;i++)
    {
        int u=query(root,1,n,1,mp[qs[i]]-1);
        if(u==INT_MIN)
        {
            if(qs[i]>0)dp[i]=1;
            else if(qs[i]==0)dp[i]=0;
            else dp[i]=INT_MIN;
        }
        else dp[i]=u+1;
        update(root,1,n,mp[qs[i]],dp[i]);
    }
    Wl(dp[n]);
    #ifdef TIME
    	printf("Running Time = %d ms\n",int(clock()*1000.0/CLOCKS_PER_SEC));
    #endif
}
/*

*/
