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
bitset<105> bt;
int main()
{
    sint2(n,k);
    while(k--)
    {
        bt.reset();
        slong(a);
        sint(b);
        slong(c);
        sint(d);
        int l=inf,r=0;
        for(int i=1;i<=n+1;i++)
        {
            if((a&(1LL<<(i-1)))^((c&(1LL<<(i-1)))))
            {
                bt[i]=1;
                l=min(l,i);
                r=max(r,i);
            }
        }
        l--;
        if(b>=r)
        {
            if(d>l)printf("%d\n",abs(b-l)+abs(d-l));
            else printf("%d\n",abs(b-d));
        }
        else if(b>l)
        {
            if(d>=b)printf("%d\n",2*(b-l)+abs(r-b)+abs(d-r));
            else printf("%d\n",2*abs(r-b)+abs(b-l)+abs(d-l));
        }
        else
        {
            if(d<r)printf("%d\n",abs(r-b)+abs(r-d));
            else printf("%d\n",d-b);
        }
        // debug(l);
        // debug(r);
    }
}
/*

*/
