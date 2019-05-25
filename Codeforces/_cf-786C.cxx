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
struct Node
{
    Node *l,*r;
    int val;
    void compute()
    {
        val = l->val + r->val;
    }
    Node(int val):l(nullptr),r(nullptr),val(val){}
    Node(Node *l,Node *r):l(l),r(r){
        compute();
    }
    Node(Node *x):l(x->l),r(x->r),val(x->val){}
};
Node *ver[100005];
Node *build(int l,int r)
{
    if(l==r)return new Node(0);
    int md=(l+r)/2;
    return new Node(build(l,md),build(md+1,r));
}
Node *update(Node *now,int l,int r,int pos,int val)
{
    Node *New=new Node(now);
    if(l==r)
    {
        New->val+=val;
        return New;
    }
    int md=(l+r)/2;
    if(pos<=md)New->l=update(now->l,l,md,pos,val);
    else New->r=update(now->r,md+1,r,pos,val);
    New->compute();
    return New;
}
Node *update2(Node *now,int l,int r,int pos1,int pos2) // pos1 for +1     pos2 for -1
{
	Node *New=new Node(now);
	int md=(l+r)/2;
	if(pos1<=md == pos2<=md)
	{
		if(pos1<=md)New->l=update2(now->l,l,md,pos1,pos2);
		else New->r=update2(now->r,md+1,r,pos1,pos2);
	}
	else
	{
		if(pos1<=md)
		{
			New->l=update(now->l,l,md,pos1,1);
			New->r=update(now->r,md+1,r,pos2,-1);
		}
		else
		{
			New->l=update(now->l,l,md,pos2,-1);
			New->r=update(now->r,md+1,r,pos1,1);
		}
	}
	New->compute();
	return New;
}
int query(Node *now,int l,int r,int k)
{
    if(l==r)return l;
    int md=(l+r)/2;
    if(now->r->val>=k)return query(now->r,md+1,r,k);
    else return query(now->l,l,md,k-now->r->val);
}
int hsh[100005];
int main()
{
    sint(n);
    ver[0]=build(0,n);
    ver[0]=update(ver[0],0,n,0,1);
    for(int i=1;i<=n;i++)
    {
        sint(tmp);
        if(hsh[tmp]!=-1)
            ver[i]=update2(ver[i-1],0,n,i,hsh[tmp]);
		else
			ver[i]=update(ver[i-1],0,n,i,1);
        hsh[tmp]=i;
    }
    for(int i=1;i<=n;i++)
    {
        int ans=0;
        int st=n;
        while(st!=0)
        {
            st=query(ver[st],0,n,i+1);
            ans++;
        }
        W(ans);
    }
    endl;
    #ifdef TIME
    	printf("Running Time = %d ms\n",int(clock()*1000.0/CLOCKS_PER_SEC));
    #endif
}
/*

*/
