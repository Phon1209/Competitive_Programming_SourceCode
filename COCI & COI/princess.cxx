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
void debugii(ii now)
{
    printf("now = %d %d\n",now.F,now.S);
}
int main()
{
    //y-x = /   v
    set<pair<int,ii> > s,s2;
    //x+y =     v2
    sint2(n,k);
    cstring(c,k+5);
    ii now={inf,inf};
    while(n--)
    {
        sint2(x,y);
        if(now==mkp(inf,inf))now={x,y};
        s.insert(mkp(y-x,mkp(x,y)));
        s2.insert(mkp(x+y,mkp(x,y)));
    }
    /*
    To plant (x+P, y+P), for any positive integer P. Call this direction A.
    To plant (x+P, y−P), for any positive integer P. Call this direction B.
    To plant (x−P, y+P), for any positive integer P. Call this direction C.
    To plant (x−P, y−P), for any positive integer P. Call this direction D.
    */
    // debugii(now);
    for(int i=0;c[i];i++)
    {
        // debugii(now);
        if(c[i]=='A') // use v
        {
            // printf("using A\n");
            auto it=s.lower_bound(mkp(now.S-now.F,mkp(now.F,now.S)));
            auto it2=it;
            if(it==--s.end())continue;
            it2++;
            if((*it).F==(*it2).F)
            {
                // printf("Jump!!\n");
                ii tmp=now;
                now=(*it2).S;
                s.erase(it);
                s2.erase(s2.lower_bound(mkp(tmp.S+tmp.F,mkp(tmp.F,tmp.S))));
            }
            else continue;
        }
        if(c[i]=='B') // use v2
        {
            // printf("using B\n");
            auto it=s2.lower_bound(mkp(now.S+now.F,mkp(now.F,now.S)));
            auto it2=it;
            if(it==--s2.end())continue;
            it2++;
            if((*it).F==(*it2).F)
            {
                // printf("Jump!!\n");
                ii tmp=now;
                now=(*it2).S;
                s2.erase(it);
                s.erase(s.lower_bound(mkp(tmp.S-tmp.F,mkp(tmp.F,tmp.S))));
            }
            else continue;
        }
        if(c[i]=='C') // use v2
        {
            // printf("using C\n");
            auto it=s2.lower_bound(mkp(now.S+now.F,mkp(now.F,now.S)));
            // printf("search found %d %d %d\n",(*it).F,(*it).S.F,(*it).S.S);
            if(it==s2.begin())continue;
            auto it2=it;
            it2--;
            // printf("next found %d %d %d\n",(*it2).F,(*it2).S.F,(*it2).S.S);
            if((*it).F==(*it2).F)
            {
                // printf("Jump!!\n");
                ii tmp=now;
                now=(*it2).S;
                s2.erase(it);
                s.erase(s.lower_bound(mkp(tmp.S-tmp.F,mkp(tmp.F,tmp.S))));
            }
            else continue;
        }
        if(c[i]=='D') // use v
        {
            // printf("using D\n");
            auto it=s.lower_bound(mkp(now.S-now.F,mkp(now.F,now.S)));
            if(it==s.begin())continue;
            auto it2=it;
            it2--;
            if((*it).F==(*it2).F)
            {
                // printf("Jump!!\n");
                ii tmp=now;
                now=(*it2).S;
                s.erase(it);
                s2.erase(s2.lower_bound(mkp(tmp.S+tmp.F,mkp(tmp.F,tmp.S))));
            }
            else continue;
        }
    }
    printf("%d %d\n",now.F,now.S);
}
/*

*/
