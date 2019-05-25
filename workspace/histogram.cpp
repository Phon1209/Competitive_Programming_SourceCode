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
#define sss(a,b,c) stringstream a; a<<b; a>>c
#define rev(s) reverse(all(s));
#define FOR(a,b,c) for(int a=b;a<c;a++)
#define ROF(a,b,c) for(int a=b;a>c;a--)
#define pause system("pause")
#define endl printf("\n")
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;

int main()
{
    while(1)
    {
        sint(n);
        ll cnt=0;
        ll ans=0;
        if(!n)break;
        stack<pair<ll,ll> > st;
        for(int i=0;i<n;i++)
        {
            slong(tmp);
            if(st.empty())
            {
                 st.push(mkp(tmp,1));
                 ans=max(ans,tmp);
                 continue;
            }
            cnt=0;
            while(!st.empty())
            {
                if(st.top().F>=tmp)
                {
                    cnt+=st.top().S;
                    ll u=st.top().F;
                    ans=max(ans,u*cnt);
                    st.pop();
                }
                else break;
            }
            st.push(mkp(tmp,cnt+1));
            ans=max(ans,(tmp*(cnt+1)));
        }
        cnt=0;
        while(!st.empty())
        {
            cnt+=st.top().S;
            ll u=st.top().F;
            ans=max(ans,u*cnt);
            st.pop();
        }
        printf("%lld\n",ans);
    }
}
