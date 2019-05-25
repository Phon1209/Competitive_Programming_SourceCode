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
        val = l->val + r->val;
    }
    Node(int val):val(val),l(nullptr),r(nullptr){}
    Node(Node *l,Node *r):l(l),r(r){
        compute();
    }
    Node(Node *x):val(x->val),l(x->l),r(x->r){}
}*ver[105];
char s[300005];
Node *build(int l,int r)
{
    if(l==r)return new Node(s[l-1]-'0');
    int md=(l+r)/2;
    return new Node(build(l,md),build(md+1,r));
}
Node *update(Node *now,int l,int r,int pos)
{
    Node *New=new Node(now);
    if(l==r)
    {
        New->val = 1-New->val;
        return New;
    }
    int md=(l+r)/2;
    if(pos<=md)New->l=update(now->l,l,md,pos);
    else New->r=update(now->r,md+1,r,pos);
    New->compute();
    return New;
}
int query(Node *now,int l,int r,int x,int y)
{
    if(y<l || x>r)return 0;
    if(x<=l && r<=y)return now->val;
    int md=(l+r)/2;
    return query(now->l,l,md,x,y)+query(now->r,md+1,r,x,y);
}
void inspect(Node *now,int l,int r)
{
    printf("%d %d %d\n",l,r,now->val);
    int md=(l+r)/2;
    if(l==r)return;
    inspect(now->l,l,md);
    inspect(now->r,md+1,r);
}
int main()
{
    sint2(n,q);
    scanf("%s",s);
    // debug(s);
    ver[0]=build(1,n);
    for(int t=1;t<=q;t++)
    {
        // inspect(ver[t-1],1,n);
        sstring(w);
        if(w=="query")
        {
            sint2(x,y);
            int ans=0;
            for(int i=0;i<t;i++)
            {
                // debug(query(ver[i],1,n,x,y-1));
                if(query(ver[i],1,n,x,y-1)==y-x)ans++;
            }
            Wl(ans);
            ver[t]=ver[t-1];
        }
        else if(w=="toggle")
        {
            sint(tmp);
            ver[t]=update(ver[t-1],1,n,tmp);
        }
    }
    #ifdef TIME
    	printf("Running Time = %d ms\n",int(clock()*1000.0/CLOCKS_PER_SEC));
    #endif
}
/*

*/
