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
bitset<1000005> pr;
int cnt[1000005];
vi v;
int main()
{
    for(int i=4;i<=1000000;i+=2)pr[i]=1;
    v.pb(2);
    for(int i=3;i<=1000000;i+=2)
    {
        if(pr[i])continue;
        // debug(i);
        v.pb(i);
        cnt[i]=1;
        for(int j=i+i;j<=1000000;j+=i)
            pr[j]=1;
    }
    // debug(1);
    for(int i=2;i<=1000000;i++)
    {
        // debug(i);
        if(cnt[i]==0)
        {
            int tmp=i;
            for(int j=0;j<v.size();j++)
            {
                if((tmp%v[j])==0)
                {
                    cnt[i]=cnt[tmp/v[j]]+1;
                    break;
                }
            }
        }
    }
    // debug(3);
    sint2(a,b);
    sint2(c,d);
    // debug(4);
    int n,m;
    int mx=0;
    int ans1,ans2;
    for(int i=2;i<=max(b,d);i++)
    {
        n=(b/i)*i;
        m=(d/i)*i;
        if(n<a)continue;
        if(m<c)continue;
        int rnk=cnt[i];
        if(rnk==mx)
        {
            if(n+m>ans1+ans2)
            {
                ans1=n;
                ans2=m;
            }
            else if(n+m==ans1+ans2)
            {
                if(n>ans1)
                {
                    ans1=n;
                    ans2=m;
                }
            }
        }
        if(rnk>mx)
        {
            mx=rnk;
            ans1=n;
            ans2=m;
        }
    }
    printf("%d %d\n",ans1,ans2);
}
/*




















*/
