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
    ll seg=0;
    int num;
    Node *l,*r;
    void compute()
    {
        seg=l->seg+r->seg;
        num=l->num+r->num;
    }
    Node():num(0),seg(0),l(nullptr),r(nullptr){}
    Node(Node *l,Node *r):l(l),r(r){
        compute();
    }
}*ps,*ng;
Node *build(int l,int r)
{
    if(l==r)return new Node();
    int md=(l+r)/2;
    return new Node(build(l,md),build(md+1,r));
}
void upt(Node *now,int l,int r,int pos,int val)
{
    if(l==r)
    {
        now->seg += (val*l);
        now->num+=val;
        return;
    }
    int md=(l+r)/2;
    if(pos<=md)upt(now->l,l,md,pos,val);
    else       upt(now->r,md+1,r,pos,val);
    now->compute();
}
int query(Node *now,int l,int r,int x,int y)
{
    // printf("%d %d %d %d %d\n",l,r,x,y,now->num);
    if(y<x)return 0;
    if(y<l || x>r)return 0;
    if(x<=l && r<=y)return now->num;
    int md=(l+r)/2;
    return query(now->l,l,md,x,y)+query(now->r,md+1,r,x,y);
}
int shift[1000005];
bitset<1000005>lazy;
void print(Node *now,int l,int r)
{
    printf("%d %d\n",l,r);
    printf("num = %d  seg = %lld\n",now->num,now->seg);
    if(l==r)return ;
    int md=(l+r)/2;
    print(now->l,l,md);
    print(now->r,md+1,r);
}
int main()
{
    sint3(n,l,q);
    int numps=n;
    int numng=0;
    ps=build(0,l-1);
    ng=build(0,l-1);
    char cmd[2];
    upt(ps,0,l-1,0,n);
    while(q--)
    {
        /*
        printf("ps = \n");
        print(ps,0,l-1);
        printf("ng = \n");
        print(ng,0,l-1);
        // */
        scanf("%s",cmd);
        if(cmd[0]=='s')//shift
        {
            sint2(x,m);
            m=l-m;
            if(lazy[x])
            {
                upt(ng,0,l-1,shift[x],-1);
                /*
                int u=shift[x];
                printf("move 1 from %d %s to %d %s\n",u,"ng",(u+m)%l,"ng");
                // */
                shift[x]+=m;
                shift[x]%=l;
                upt(ng,0,l-1,shift[x],1);
            }
            else
            {
                upt(ps,0,l-1,shift[x],-1);
                /*
                int u=shift[x];
                printf("move 1 from %d %s to %d %s\n",u,"ps",(u+m)%l,"ps");
                // */
                shift[x]+=m;
                shift[x]%=l;
                upt(ps,0,l-1,shift[x],1);
            }
        }
        if(cmd[0]=='q')//query
        {
            sint(m);
            ll ans=0;
            /*
            debug(m*numps);
            debug(ps->seg);
            debug(query(ps,0,l-1,l-m+1,l-1)*l);
            debug((l-m)*numng);
            debug(ng->seg);
            debug(query(ng,0,l-1,l-m,l-1)*l);
            // */
            ans+=((ll)m*(ll)numps)+((ll)ps->seg)-((ll)query(ps,0,l-1,l-m+1,l-1)*(ll)l);
            ans+=((ll)(l-m)*(ll)numng)-((ll)ng->seg)+((ll)query(ng,0,l-1,l-m,l-1)*(ll)l);
            if(m==l)ans-=((ll)query(ng,0,l-1,0,0)*(ll)l);
            // ans-=(query(ng,0,l-1,0,0)*l);
            printf("%lld\n",ans);
        }
        if(cmd[0]=='f')//flip
        {
            sint(x);
            if(lazy[x])
            {
                numps++;
                numng--;
                lazy[x]=0;
                upt(ng,0,l-1,shift[x],-1);
                /*
                int u=shift[x];
                printf("move 1 from %d %s to %d %s\n",u,"ng",u,"ps");
                // */
                upt(ps,0,l-1,shift[x],1);
            }
            else
            {
                numps--;
                numng++;
                lazy[x]=1;
                upt(ps,0,l-1,shift[x],-1);
                /*
                int u=shift[x];
                printf("move 1 from %d %s to %d %s\n",u,"ps",u,"ng");
                // */
                upt(ng,0,l-1,shift[x],1);
            }
        }
    }
}
/*

*/
