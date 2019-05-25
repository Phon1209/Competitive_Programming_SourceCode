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
vi v[400005];
vi::iterator it;
int a[100005];
void build(int idx,int l,int r)
{
    int md=(l+r)/2;
    if(l==r)
    {
//        printf(">%d %d %d\n",idx,l,a[l]);
        v[idx].pb(a[l]);
        return;
    }
    build(idx*2,l,md);
    build(idx*2+1,md+1,r);
    int i=0,j=0;
    int x=md-l,y=r-md-1;
    int L=idx*2,R=idx*2+1;
//    printf(">>%d %d\n",L,R);
//    printf(">>%d %d\n",x,y);
    while(i<=x && j<=y)
    {
//        printf("<%d %d\n",v[L][i],v[R][j]);
        if(v[L][i]<v[R][j])
        {
            v[idx].pb(v[L][i]);
            i++;
        }
        else
        {
            v[idx].pb(v[R][j]);
            j++;
        }
    }
    while(i<=x)
    {
        v[idx].pb(v[L][i]);
        i++;
    }
    while(j<=y)
    {
        v[idx].pb(v[R][j]);
        j++;
    }
    /*
    for(i=0;i<v[idx].size();i++)
    {
        printf("%d ",v[idx][i]);
    }
    endl;
    pause;
    */
}
int queryup(int idx,int l,int r,int x,int y,int k)
{
//    printf("%d %d %d\n",idx,l,r);
    if(r<x || y<l) return 0;
    if(x<=l && r<=y)
    {
//        printf("ok\n");
        it=upper_bound(all(v[idx]),k);
        int u=(v[idx].end()-it);
//        printf("%d\n",u);
        return u;
    }
    int md=(l+r)/2;
    int o=queryup(idx*2,l,md,x,y,k)+queryup(idx*2+1,md+1,r,x,y,k);
//    printf("> %d %d\n",idx,o);
    return o;
}
int querydw(int idx,int l,int r,int x,int y,int k)
{
 //   printf("%d %d %d\n",idx,l,r);
    if(r<x || y<l) return 0;
    if(x<=l && r<=y)
    {
//        printf("ok\n");
        it=lower_bound(all(v[idx]),k);
        int u=(v[idx].end()-it);
//        printf("%d\n",u);
        return u;
    }
    int md=(l+r)/2;
    int o=querydw(idx*2,l,md,x,y,k)+querydw(idx*2+1,md+1,r,x,y,k);
//    printf("> %d %d\n",idx,o);
    return o;
}
int main()
{
    sint2(n,m);
    int mc=0;
    for(int i=1;i<=n;i++)
    {
        int1(a[i]);
        mc=max(mc,a[i]);
    }
    build(1,1,n);
    vector<int> kep;
    for (int i = 1; i < v[1].size(); ++i )
        printf("%d ", v[1][i]);
    endl;


    int last = v[1][0], cnt = 1, j;
    for (int i = 1; i <= v[1].size(); ++i ) {
        if (last != v[1][i] || i == v[1].size()) {
            //printf("%d: %d\n", last, cnt);
            for (j = 0; j < cnt; ++j)
                kep.push_back(cnt);
            if (i < v[1].size())
                last = v[1][i];
            cnt = 1;
        } else {
            ++cnt;
        }
    }
    endl;

    for (int i = 0; i < kep.size(); ++i)
        printf("%d ", kep[i]);
    endl;

    /*
    for(int i=1;i<=2*n;i++)
    {
        printf("%d | ",i);
        for(int j=0;j<v[i].size();j++)
        {
            printf("%d ",v[i][j]);
        }
        endl;
    }
    //*/
    while(m--)
    {
        sint3(x,y,k);
        int mn=0,mx=n-1;
        int o,p;
        int ans=0;
        while(mn<=mx)
        {
            int md=(mn+mx)/2;
            printf("<%d> %d %d\n",v[1][md],mn,mx);
            //o=querydw(1,1,n,x,y,v[1][md]);
            p=queryup(1,1,n,x,y,v[1][md]);

            printf("<%d %d>\n",p,o);
            if(p<k && k<=o)
            {
 //               printf("%d\n",md);
                ans=max(ans,v[1][md]);
                mn=md+1;
            }
            else if(k<p)
            {
                mn=md+1;
            }
            else
            {
                mx=md-1;
            }
        }
        printf("%d\n",ans);
//        printf("%d\n",o);
//        printf(">%d\n",v[1][o]);
//        printf("%d\n",v[1][u-1]);
    }
}
