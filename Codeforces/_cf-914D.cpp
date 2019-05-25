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
#define OPEN freopen("input.txt","r",stdin)
#define SEND freopen("output.txt","w",stdout)
#define IN(x) freopen(x,"r",stdin);
#define OUT(x) freopen(x,"w",stdout);

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
int a[500005];
struct Node
{
    int val;
    Node *l,*r;
    void getval()
    {
        val=__gcd(l->val,r->val);
    }
};
Node *build(int l,int r)
{
    Node *now=new Node();
    if(l==r)
    {
        now->val=a[l];
        return now;
    }
    int md=(l+r)/2;
    now->l=build(l,md);
    now->r=build(md+1,r);
    now->getval();
    return now;
}
void upt(Node *now,int l,int r,int pos,int val)
{
    if(l==r)
    {
        now->val=val;
        return;
    }
    int md=(l+r)/2;
    if(pos<=md)upt(now->l,l,md,pos,val);
    else       upt(now->r,md+1,r,pos,val);
    now->getval();
    return;
}
int cnt=0;
void query(Node *now,int l,int r,int x,int y,int use)
{
    // printf(">%d %d %d %d %d\n",l,r,x,y,use);
    // printf(">>%d\n",now->val);
    if(cnt>1)throw -1;
    // debug(2);
    if(y<l || x>r)return;
    // debug(3);
    if(x<=l && r<=y && now->val%use==0)return;
    // debug(4);
    if(l==r)
    {
        // printf(">>%d\n",now->val);
        if(now->val%use!=0)cnt++;//,printf("Dam\n")
        return;
    }
    // debug(5);
    int md=(l+r)/2;
    query(now->l,l,md,x,y,use);
    query(now->r,md+1,r,x,y,use);
    if(cnt>1)throw -1;
    return;
}
void printval(Node *now,int l,int r)
{
    printf("<%d %d %d>\n",l,r,now->val);
    if(l==r)return;
    int md=(l+r)/2;
    printval(now->l,l,md);
    printval(now->r,md+1,r);
}
int main()
{
    // OPEN;
    // SEND;
    sint(n);
    for(int i=1;i<=n;i++)
    {
        int1(a[i]);
    }
    Node *root=build(1,n);
    sint(q);
    while(q--)
    {
        // printval(root,1,n);
        sint(cmd);
        if(cmd==1)
        {
            sint3(l,r,x);
            try
            {
                cnt=0;
                query(root,1,n,l,r,x);
                printf("YES\n");
                continue;
            }
            catch(...)
            {
                printf("NO\n");
            }
        }
        if(cmd==2)
        {
            sint2(pos,val);
            upt(root,1,n,pos,val);
        }
    }
}
