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
vi v;
set<int> ones;
map<int,int> mp,dis;
int ans=0;
int pos=-1;
void chk(int x)
{
    int ret=0;
    for(int i=1;i*i<=x+5;i++)
    {
        if(x%i==0)
        {
            // debug(x);
            // debug(i);
            int tmp=x/i;
            int curr=v[pos];
            for(int j=pos;j<v.size();j++)
            {
                // debug(curr);
                // debug(v[j]);
                if(curr!=v[j] && v[j]!=-1)
                {
                    break;
                }
                if(j==v.size()-1)
                {
                    ret=max(ret,tmp);
                }
                curr=(curr+1)%tmp;
                if(curr==0)curr=tmp;
            }

            curr=v[pos];
            for(int j=pos;j<v.size();j++)
            {
                if(curr!=v[j] && v[j]!=-1)
                {
                    break;
                }
                if(j==v.size()-1)
                {
                    ret=max(ret,i);
                }
                curr=(curr+1)%i;
                curr++;
            }
        }
    }
    ans=max(ans,ret);
}
void _main()
{
    // printf("You Can Print Now\n");
    v.clear();
    ones.clear();
    mp.clear();
    dis.clear();
    ans=0;
    pos=-1;
    sint(n);
    for(int i=0;i<n;i++)
    {
        sint(tmp);
        v.pb(tmp);
    }
    bool im=0;
    int now=-1;
    for(int i=v.size()-1;i>=0;i--)
    {
        if(now<=0)now=-1;
        if(v[i]!=-1)
        {
            if(now==-1)now=v[i];
            else if(now!=v[i])
            {
                im=1;
                break;
            }
        }
        v[i]=now;
        now--;
    }
    if(im)
    {
        // debug(1);
        printf("impossible\n");
        return;
    }
    int mx=0;
    int gcd=0;
    bool gt=0;
    for(int i=0;i<v.size();i++)
    {
        if(v[i]!=-1)
        {
            if(i>0)
            {
                if(v[i]==1)
                {
                    mx=max(mx,v[i-1]);
                    if(!gt)
                    {
                        for(int j=i-1,cnt=0;j>=0;j--,cnt++)
                        {
                            if(v[j]!=-1){
                                mx=max(mx,v[j]+cnt);
                                break;
                            }
                        }
                        gt=1;
                    }
                }
            }
            if(pos==-1)pos=i;
            if(mp.find(v[i])==mp.end())
            {
                mp[v[i]]=i;
            }
            else
            {
                if(dis.find(v[i])==dis.end())
                {
                    dis[v[i]]=i-mp[v[i]];
                    if(gcd==0)gcd=dis[v[i]];
                    else gcd=__gcd(gcd,dis[v[i]]);
                }
                else
                {
                    dis[v[i]]=__gcd(dis[v[i]],i-mp[v[i]]);
                    gcd=__gcd(gcd,dis[v[i]]);
                }
                // debug(gcd);
                mp[v[i]]=i;
            }
        }
    }
    // debug(gcd);
    // debug(mx);
    if(!gcd && !mx)
    {
        printf("inf\n");
        return;
    }
    ans=0;
    if(gcd)chk(gcd);
    // debug(1);
    if(mx)chk(mx);
    // debug(ans);
    if(ans==0)printf("impossible\n");
    else printf("%d\n",ans);
}
int main()
{
    sint(t);
    while(t--)_main();
}
/*

*/
