#include<bits/stdc++.h>
using namespace std;
#define sint(a) int a; scanf("%d",&a);
#define sint2(a,b) int a,b; scanf("%d %d",&a,&b);
#define sint3(a,b,c) int a,b,c; scanf("%d %d %d",&a,&b,&c);
#define int1(a) scanf("%d",&a);
#define int2(a,b) scanf("%d %d",&a,&b);
#define int3(a,b,c) scanf("%d %d %d",&a,&b,&c);
#define mkp make_pair
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
#define OPEN freopen("input.txt","r",stdin);
#define SEND freopen("output.txt","w",stdout);
#define IN(x) freopen(x,"r",stdin);
#define OUT(x) freopen(x,"w",stdout);

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
int ball[300005];
struct Node
{
    int val;
    Node *l,*r;
};
Node *build(int l,int r)
{
    Node *now=new Node();
    if(l==r)
    {
        now->val=l;
        return now;
    }
    int md=(l+r)/2;
    now->l=build(l,md);
    now->r=build(md+1,r);
    return now;
}
int query(Node *now,int l,int r,int pos)
{
    if(l==r)
    {
        return now->val;
    }
    int md=(l+r)/2;
    if(pos<=md) return query(now->l,l,md,pos);
    return query(now->r,md+1,r,pos);
}
Node *upt(Node *now,int l,int r,int pos,int val)
{
    Node *New=new Node();
    if(l==r)
    {
        New->val=val;
        return New;
    }
    int md=(l+r)/2;
    New->l=now->l;
    New->r=now->r;
    if(pos<=md)New->l=upt(now->l,l,md,pos,val);
    else New->r=upt(now->r,md+1,r,pos,val);
    return New;
}
Node *ver[600005];
Node *S[300005];
void print(Node *now,int l,int r)
{
    if(l==r)
    {
        printf("%d ",now->val);
        return ;
    }
    int md=(l+r)/2;
    print(now->l,l,md);
    print(now->r,md+1,r);
}
int main()
{
    OPEN;
    SEND;
    sint2(n,m);
    ver[0]=build(1,n);
    S[0]=ver[0];
    int cnt=1;
    int num=1;
    for(int i=1;i<=m;i++)ball[i]=i;
    for(int i=0;i<m;i++)
    {
        sint(tmp);
        swap(ball[tmp],ball[tmp+1]);
        int x,y;
        x=query(ver[cnt-1],1,n,ball[tmp]);
        y=query(ver[cnt-1],1,n,ball[tmp+1]);
        ver[cnt]=upt(ver[cnt-1],1,n,ball[tmp+1],x);
        cnt++;
        ver[cnt]=upt(ver[cnt-1],1,n,ball[tmp],y);
        S[num++]=ver[cnt++];
    }
    /*
    for(int i=1;i<=m;i++)
    {
        print(S[i],1,n);
        endl;
    }
    */
    sint(q);
    int ans=0;
    while(q--)
    {
        sint2(k,j);
        k^=ans;
        j^=ans;
        // printf(">%d %d\n",k,j);
        ans=query(S[j],1,n,k);
        printf("%d\n",ans);
    }
}
