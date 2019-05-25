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
ll cnt[55];
int _main()
{
    memset(cnt,0,sizeof(cnt));
    sint2(n,k);
    slong(m);
    vector<string> v;
    for(int i=0;i<n;i++)
    {
        sstring(s);
        v.pb(s);
    }
    ll use=(m-1)*k;
    ll sep=use/n;
    ll rem=use-(sep*n);
    int last=0;
    for(int i=0;i<n;i++)
    {
        cnt[i]+=sep;
        if(rem>0)
        {
            cnt[i]++;
            rem--;
            last=i+1;
        }
    }
    vector<pair<int,string> > ans;
    while(k--)
    {
        ans.pb(mkp(last,v[last]));
        last++;
        last%=n;
    }
    sort(all(ans));
    for(int i=0;i<ans.size();i++)
    {
        printf("%s ",ans[i].S.c_str());
    }
    endl;
    return 0;
}
int main()
{
    IN("tourist.txt");
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
