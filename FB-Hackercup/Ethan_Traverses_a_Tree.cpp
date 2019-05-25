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
class UnionFind
{
private:
    vi p;
public:
    UnionFind(int n)
    {
        p.assign(n+5,0);
        for(int i=0;i<=n;i++)p[i]=i;
    }
    int fs(int i)
    {
        return (p[i]==i)? i:(p[i]=fs(p[i]));
    }
    bool iss(int i,int j)
    {
        return fs(i)==fs(j);
    }
    void us(int i,int j)
    {
        p[fs(i)]=fs(j);
    }
};
int l[2005];
int r[2005];
int val[2005];
vi pre,post;
void preorder(int u)
{
    if(u==0)return;
    //print
    pre.pb(u);
    preorder(l[u]);
    preorder(r[u]);
}
void postorder(int u)
{
    if(u==0)return;
    postorder(l[u]);
    postorder(r[u]);
    post.pb(u);
}
void _main()
{
    pre.clear();
    post.clear();
    memset(l,0,sizeof(l));
    memset(r,0,sizeof(r));
    memset(val,-1,sizeof(val));
    sint2(n,k);
    int comp=n;
    UnionFind uf(n);
    for(int i=1;i<=n;i++)
    {
        int2(l[i],r[i]);
    }
    preorder(1);
    postorder(1);
    /*
    for(int i=0;i<pre.size();i++)
    {
        printf("%d ",pre[i]);
    }
    endl;
    for(int i=0;i<post.size();i++)
    {
        printf("%d ",post[i]);
    }
    endl;
    // */
    for(int i=0;i<n;i++)
    {
        if(!uf.iss(pre[i],post[i]))
        {
            uf.us(pre[i],post[i]);
            comp--;
        }
    }
    int cnt=0;
    if(comp<k)
    {
        printf("Impossible\n");
        delete &uf;
        return;
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            if(val[i]==-1)
            {
                int x=uf.fs(i);
                if(val[x]==-1)
                {
                    val[x]=cnt++;
                    cnt%=k;
                }
                val[i]=val[x];
            }
            printf("%d ",val[i]+1);
        }
    }
    endl;
    delete &uf;
}

int main()
{
    IN("ethan_traverses_a_tree.txt");
    SEND;
    sint(t);
    for(int i=1;i<=t;i++)
    {
        printf("Case #%d: ",i);
        _main();
    }
}
/*

*/
