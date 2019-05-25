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
    int val,idx;
    Node *l,*r;
    void compute()
    {
        if(l->val > r->val)
        {
            val=l->val;
            idx=l->idx;
        }
        else
        {
            val=r->val;
            idx=r->idx;
        }
    }
    Node(int idx):val(0),idx(idx){}
    Node(Node *l,Node *r):l(l),r(r){
        compute();
    }
};
Node *build(int l,int r)
{
    if(l==r)return new Node(l);
    int md=(l+r)/2;
    return new Node(build(l,md),build(md+1,r));
}
void upt(Node *now,int l,int r,int pos,int val)
{
    if(l==r)
    {
        now->val+=val;
        return;
    }
    int md=(l+r)/2;
    if(pos<=md)upt(now->l,l,md,pos,val);
    else upt(now->r,md+1,r,pos,val);
    now->compute();
}
int main()
{
    sint3(n,l,r);
    l+=r;
    Node *root=build(1,n);
    char s[5];
    while(l--)
    {
        scanf("%s",s);
        int idx=root->idx;
        if(s[0]=='R')
        {
            printf("%d\n",idx);
            continue;
        }
        if(s[0]=='D'){
            upt(root,1,n,idx,INT_MIN);
            continue;
        }
        sint2(x,y);
        if(s[0]=='L')upt(root,1,n,y,1);
        if(s[0]=='C')upt(root,1,n,y,3);
    }
}
/*

*/
