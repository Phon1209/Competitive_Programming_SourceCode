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

ll a[100005];
ll qs[100005];
int main()
{
    sint(t);
    while(t--)
    {
        memset(a,0,sizeof(a));
        memset(qs,0,sizeof(qs));
        sint(n);
        vi v;
        for(int i=0;i<n;i++)
        {
            sint(tmp);
            v.pb(tmp);
        }
        sort(all(v),greater<int>());
        for(int i=0;i<n;i++)
        {
            a[i+1]=v[i];
        }
        for(int i=1;i<=n;i++)
        {
            qs[i]=qs[i-1]+a[i];
        }
        bool ok=true;
        for(int i=1;i<=n-1;i++)
        {
            ll p=qs[i];
            ll chk=(i*(i-1));
            if(a[i+1]<=i)
                chk+=qs[n]-qs[i];
            else
            {
                // debug(1);
                int l=i,r=n,md;
                int len=0;
                while(l<=r)
                {
                    md=(l+r)/2;
                    if(a[md]>=i)len=max(len,md),l=md+1;
                    else r=md-1;
                }
                chk+=(len-i)*i;
                chk+=qs[n]-qs[len];
            }
            if(p>chk)
            {
                ok=false;
            }
        }
        if(a[1]>=n)ok=false;
        if(qs[n]%2)ok=false;
        printf("%s\n",(ok)? "Yes":"No");
    }
}
/*
4
4
3 2 3 3
5
3 3 2 2 1
3
2 2 2
5
1 3 3 3 2
*/
