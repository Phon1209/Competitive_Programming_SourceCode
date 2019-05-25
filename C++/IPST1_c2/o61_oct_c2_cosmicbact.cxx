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
ll ans[100005];
vector<pair<pair<ll,ll> ,int> > v;
int main()
{
    sint(n);
    slong(l);
    for(int i=0;i<n;i++)
    {
        slong(x);
        slong(y);
        v.pb(mkp(mkp(x,i+y),i));
    }
    sort(all(v));
    /*
    for(int i=0;i<v.size();i++)
    {
        printf("%lld %lld %d\n",v[i].F.F,v[i].F.S,v[i].S);
    }
    */
    // endl;
    stack<int> st;
    st.push(0);
    // clock_t bg=clock();
    // return 0;
    for(int i=1;i<v.size();i++)
    {
        ll pos,pos2;
        pos=v[st.top()].F.F;
        pos2=v[i].F.F;

        ll day=v[st.top()].F.S;
        ll day2=v[i].F.S;

        int type,type2;
        type=v[st.top()].S;
        type2=v[i].S;

        if((day+pos2-pos==day2 && type<type2) || (day+pos2-pos<day2))
        {
            continue;
        }
        else if((day2+pos2-pos==day && type2<type) || (day2+pos2-pos<day))
        {
            st.pop();
            while(!st.empty())
            {
                pos=v[st.top()].F.F;
                day=v[st.top()].F.S;
                type=v[st.top()].S;
                if((day2+pos2-pos==day && type2<type) || (day2+pos2-pos<day))
                {
                    st.pop();
                    continue;
                }
                else break;
                // debug(1);
            }
            st.push(i);
        }
        else
        {
            st.push(i);
        }
    }
    // printf("%lf\n",(clock()-bg)/CLOCKS_PER_SEC);
    // return 0;
    /*
    while(1)
    {
        int *wer=new int;
    }
    */
    vi tmp;
    while(!st.empty())
    {
        tmp.pb(st.top());
        // printf("%d\n",st.top());
        // printf("%lld %lld %d\n",v[st.top()].F.F,v[st.top()].F.S,v[st.top()].S);
        st.pop();
    }
    //S = type       F.F = pos     F.S = day
    sort(all(tmp));
    ans[v[tmp[0]].S]=v[tmp[0]].F.F;
    for(int i=0;i<tmp.size()-1;i++)
    {
        /*
        for(int i=0;i<n;i++)
        {
            printf("%lld\n",ans[i]);
        }
        endl;
        // */
        // range pos -> pos2-1
        ll x,y;
        ll day,day2,pos,pos2;
        int type,type2;
        pos=v[tmp[i]].F.F;
        pos2=v[tmp[i+1]].F.F;
        day=v[tmp[i]].F.S;
        day2=v[tmp[i+1]].F.S;
        type=v[tmp[i]].S;
        type2=v[tmp[i+1]].S;
        /*
        debug(type);
        debug(type2);
        debug(pos);
        debug(pos2);
        debug(day);
        debug(day2);
        // */
        x=pos;
        y=pos2;
        ll ok=x;
        while(x<=y)
        {
            // find land
            ll md=(x+y)/2;
            // debug(md);
            if((day+md-pos < day2+pos2-md) || (day+md-pos == day2+pos2-md && type<type2))
            {
                x=md+1;
                ok=max(ok,md);
            }
            else
            {
                y=md-1;
            }
        }
        // debug(ok);
        ans[type]+=(ok-pos+1);
        ans[type2]+=(pos2-ok-1);
    }
    ans[v[tmp[tmp.size()-1]].S]+=(l-v[tmp[tmp.size()-1]].F.F+1);
    for(int i=0;i<n;i++)
    {
        printf("%lld\n",ans[i]);
    }
}
/*

*/
