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
int a[200005];
struct Data
{
    bool all=0;
    int ans=0,ml=0,mr=0;
    void combine(Data *x,Data *y)
    {
        if(!x->all)ml = x->ml;
        else ml = x->ans + y->ml;

        if(!y->all)mr=y->mr;
        else mr = y->ans + x->mr;

        if(x->all && y->all)all=1;
        else all=0;

        ans=max(max(ml , max(mr , x->mr+y->ml)) , max(x->ans , y->ans));
    }
    void setval(int val)
    {
        all=ans=ml=mr=val;
    }
    Data()
    {
        all=ans=ml=mr=0;
    }
    void preview()
    {
        printf("all = %d  ans = %d  ml = %d  mr = %d\n",all? 1:0,ans,ml,mr);
    }
};
struct Node
{
    Data val;
    Data tmp=Data();
    Node *l,*r;
    void compute()
    {
        val.combine(&l->val,&r->val);
    }
    Node(int x):l(nullptr),r(nullptr){
        val.setval(x);
    }
    Node(Node *l,Node *r):l(l),r(r){
        compute();
    }
};
Node *build(int l,int r)
{
    if(l==r)return new Node(a[l]);
    int md=(l+r)/2;
    return new Node(build(l,md),build(md+1,r));
}
Data empty_data=Data();
Data *query(Node *now,int l,int r,int x,int y)
{
    if(y<l || x>r)
        return &empty_data;
    if(x<=l && r<=y)return &now->val;
    int md=(l+r)/2;
    now->tmp.combine(query(now->l,l,md,x,y),query(now->r,md+1,r,x,y));
    return &now->tmp;
}
void travel(Node *now,int l,int r)
{
    // debug(1);
    if(!now)return;
    printf("%d %d\n",l,r);
    now->val.preview();
    int md=(l+r)/2;
    // printf("%d\n",&now->l);
    travel(now->l,l,md);
    travel(now->r,md+1,r);
}
int main()
{
    sint3(n,q,k);
    for(int i=1;i<=n;i++)
    {
        int1(a[i]);
        a[i+n]=a[i];
    }
    Node *root=build(1,2*n);
    Data *Get;
    // travel(root,1,2*n);
    // /*
    cstring(s,q+5);
    int cnt=2*n;
    for(int i=0;i<q;i++)
    {
        if(s[i]=='!')
        {
            cnt--;
            if(cnt==n)cnt+=n;
            // printf("Push cnt to %d\n",cnt);
        }
        if(s[i]=='?')
        {
            Get=query(root,1,2*n,cnt-n+1,cnt);
            printf("%d\n",min(k,Get->ans));
        }
    }
    // */
}
/*

*/
