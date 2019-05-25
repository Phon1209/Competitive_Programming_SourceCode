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

int a[100005];
struct Node
{
    ll sum;
    Node *l,*r;
    Node(Node *l,Node *r):sum(l->sum+r->sum),l(l),r(r){}
    Node(int val,Node *l,Node *r):sum(val),l(l),r(r){}
    void update()
    {
        sum = l->sum + r->sum;
    }
};

Node *build(int l,int r)
{
    if(l==r)return new Node(a[l],NULL,NULL);
    int md=(l+r)/2;
    return new Node(build(l,md),build(md+1,r));
}
int query(Node *now,int l,int r,ll find)
{
    if(l==r)return (find==now->sum)? l:-1;
    int md=(l+r)/2;
    if(now->r->sum>=find)return query(now->r,md+1,r,find);
    else return query(now->l,l,md,find-(now->r->sum));
}
void update(Node *now,int l,int r,int pos,ll val)
{
    if(l==r)
    {
        now->sum=val;
        return;
    }
    int md=(l+r)/2;
    if(pos<=md)update(now->l,l,md,pos,val);
    else       update(now->r,md+1,r,pos,val);
    now->update();
}
int main()
{
    sint(n);
    for(int i=1;i<=n;i++)
    {
        int1(a[i]);
    }
    Node *root=build(1,n);
    sint(q);
    while(q--)
    {
        sint(cmd);
        if(cmd==1)
        {
            sint(pos);
            slong(val);
            update(root,1,n,pos,val);
        }
        else if(cmd==2)
        {
            slong(val);
            int ans=query(root,1,n,val);
            printf("%s\n",(ans==-1)? "NO":"YES");
        }
    }
}
/*

*/
