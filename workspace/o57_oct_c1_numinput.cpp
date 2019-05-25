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
#define sstring(a,x) char a[x]; scanf("%s",a);
#define rev(s) reverse(all(s));
#define FOR(a,b,c) for(int a=b;a<c;a++)
#define ROF(a,b,c) for(int a=b;a>c;a--)
#define pause system("pause")
#define endl printf("\n")
#define fastio {ios::sync_with_stdio(false);cin.tie(NULL);}
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
#define MOD 9901
vi v;
vii chk;
int combi[2005][2005];
int main()
{
    sint2(n,m);
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sint(tmp);
        v.pb(tmp);
        sum+=tmp;
    }
    chk.pb(mkp(1,1));
    for(int i=0;i<m;i++)
    {
        sint(tmp);
        int u=tmp;
        int cnt=1;
        for(int j=0;j<v.size();j++)
        {
            tmp-=v[j];
            if(tmp<=0)
            {
                break;
            }
            cnt++;
        }
        chk.pb(mkp(u,cnt));
    }
    chk.pb(mkp(sum,n));
    ll ans=1;
    combi[0][0]=1;
    for(int i=1;i<=2000;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(j==0)
            {
                combi[i][j]=combi[i-1][j];
            }
            else
            {
                combi[i][j]=combi[i-1][j]+combi[i-1][j-1];
            }
            combi[i][j]%=MOD;
        }
    }
    for(int i=1;i<chk.size();i++)
    {
//        if(chk[i-1].F!=chk[i].F)
        {
            ll tmp;
            int star=chk[i].F-chk[i-1].F;
            int bar=chk[i].S-chk[i-1].S;
//            printf("%d %d %d\n",star,bar,combi[star][bar]);
            tmp=combi[star][bar];
//            printf(">%lld\n",tmp);
//            tmp+=(2*cmb(star,bar));
//            printf(">>%lld\n",tmp);
            ans*=tmp;
            ans%=MOD;
        }
    }
    printf("%lld\n",ans);
}
/*

*/
