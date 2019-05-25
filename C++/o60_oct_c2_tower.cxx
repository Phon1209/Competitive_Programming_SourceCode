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
#define int1(a) scanf("%d",&a);
#define int2(a,b) scanf("%d %d",&a,&b);
#define int3(a,b,c) scanf("%d %d %d",&a,&b,&c);
#define mkp make_pair
#define mkt make_tuple
#define pb push_back
#define eb emplace_back
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
    int mx=0;
    int ans=1;
    bool L=1,R=1;
    bool isLazy=0;
    int lazy=0;
    Node *l,*r;
    void print(int x,int y)
    {
        printf("%d %d\n",x,y);
        printf("mx = %d ans = %d L = %d R = %d isLazy = %d lazy = %d\n",mx,ans,L? 1:0,R? 1:0,isLazy? 1:0,lazy);
        int md=(x+y)/2;
        if(x==y)return;
        l->print(x,md);
        r->print(md+1,y);
    }
    Node(int val):mx(0),ans(1){
        isLazy=lazy=false;
        L=R=true;
    }
    Node(Node *l,Node *r):l(l),r(r){
        compute();
    }
    void compute()
    {
        if(l->mx==r->mx)
        {
            mx=l->mx;
            ans=l->ans+r->ans;
            L=l->L;
            R=r->R;
            if(l->R && r->L)ans--;
        }
        else
        {
            if(l->mx>r->mx)
            {
                mx=l->mx;
                ans=l->ans;
                L=l->L;
                R=0;
            }
            else
            {
                mx=r->mx;
                ans=r->ans;
                R=r->R;
                L=0;
            }
        }
    }
};
Node *build(int l,int r)
{
    if(l==r)return new Node(0);
    int md=(l+r)/2;
    return new Node(build(l,md),build(md+1,r));
}
void uplz(Node *now,int l,int r,int val)
{
    now->isLazy=1;
    now->lazy+=val;
    now->mx+=val;
}
void shift(Node *now,int l,int r)
{
    if(now->isLazy)
    {
        int md=(l+r)/2;
        uplz(now->l,l,md,now->lazy);
        uplz(now->r,md+1,r,now->lazy);
        now->lazy=0;
        now->isLazy=0;
    }
}
void upt(Node *now,int l,int r,int x,int y,int val)
{
    if(x>r || y<l)return;
    if(x<=l && r<=y)
    {
        uplz(now,l,r,val);
        return;
    }
    int md=(l+r)/2;
    shift(now,l,r);
    upt(now->l,l,md,x,y,val);
    upt(now->r,md+1,r,x,y,val);
    now->compute();
}

int main()
{
    sint2(n,m);
    Node *root=build(1,n);
    while(m--)
    {
        sint3(x,y,w);
        upt(root,1,n,x,y,w);
        // root->print(1,n);
        // pause;
        printf("%d %d\n",root->mx,root->ans);
    }
}
/*

*/
