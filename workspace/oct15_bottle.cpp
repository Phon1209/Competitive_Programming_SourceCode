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
#define debug(x) cout<< #x << " = " << x;endl;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
vii v;
bool hsh[100005];
int main()
{
    sint2(n,m);
    for(int i=0;i<n;i++)
    {
        sint(tmp);
        hsh[i]=1;
        v.pb(mkp(tmp,i));
    }
    n=v.size();
    while(m--)
    {
        sint(p);
        int idx=upper_bound(all(v),mkp(p,0))-v.begin();
        int tmp=idx;
        int cnt=0;
        for(;idx<n;idx++)
        {
            // printf("%d %d\n",(*it).F,(*it).S);
            int pos=v[idx].S;
            if(!hsh[pos])continue;
            hsh[pos]=0;
            cnt++;
            if(hsh[pos+1])hsh[pos+1]=0,cnt++;
            if(hsh[pos-1])hsh[pos-1]=0,cnt++;
        }
        n=idx;
        debug(cnt);
    }
}
