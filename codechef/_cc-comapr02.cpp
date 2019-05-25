#include<bits/stdc++.h>
using namespace std;
/*
Learn : -
Problem Type : -
Source : -
*/
#pragma GCC optimize ("Ofast")
#define sint(a) int a; scanf("%d",&a);
#define sint2(a,b) int a,b; scanf("%d %d",&a,&b);
#define sint3(a,b,c) int a,b,c; scanf("%d %d %d",&a,&b,&c);
#define slong2(a,b) ll a,b; scanf("%lld %lld",&a,&b);
#define int1(a) scanf("%d",&a);
#define int2(a,b) scanf("%d %d",&a,&b);
#define int3(a,b,c) scanf("%d %d %d",&a,&b,&c);
#define mkp make_pair
#define mkt make_tuple
#define pb push_back
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
#define debug(x) cout<< #x << " = " << x;endl;
#define OPEN freopen("input.txt","r",stdin)
#define SEND freopen("output.txt","w",stdout)
#define IN(x) freopen(x,"r",stdin);
#define OUT(x) freopen(x,"w",stdout);

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;

struct Node
{
    int val=0;
    int lz=0;
    bool lazy=0;
    Node *l,*r;
    Node(Node *l,Node *r):l(l),r(r)
    {
        compute();
    }
    Node(int val):l(nullptr),r(nullptr),val(val){}
    void compute()
    {
        val = max(l->val,r->val);
    }
};
void deBUG(Node *now,int x,int y)
{
    printf("%d %d>>%d %d\n",x,y,now->val,now->lz);
}
void uplz(Node *now,int l,int r,int add)
{
    now->lz+=add;
    now->lazy=1;
    now->val+=add;
}
void shift(Node *now,int x,int y)
{
    if(now->l && now->r && now->lazy)
    {
        now->lazy=0;
        int md=(x+y)/2;
        uplz(now->l,x,md,now->lz);
        uplz(now->r,md+1,y,now->lz);
        now->lz=0;
    }
}
Node *build(int l,int r)
{
    if(l==r)return new Node(0);
    int md=(l+r)/2;
    return new Node(build(l,md),build(md+1,r));
}
void update(Node *now,int l,int r,int x,int y,int val)
{
    if(y<l || x>r)return;
    int md=(l+r)/2;
    if(x<=l && r<=y)
    {
        uplz(now,l,r,val);
        return;
    }
    shift(now,l,r);
    update(now->l,l,md,x,y,val);
    update(now->r,md+1,r,x,y,val);
    now->compute();
}
int sum=0;
void query(Node *now,int l,int r,int x,int y)
{
    if(y<l || x>r)return;
    if(x<=l && r<=y)
    {
        sum=max(sum,now->val);
        return;
    }
    int md=(l+r)/2;
    shift(now,l,r);
    query(now->l,l,md,x,y);
    query(now->r,md+1,r,x,y);
}

int main()
{

}
/*

*/
