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
//#pragma GCC optimize ("O3")
int sg[800000],lz[800000];
int pos[800000],pos2[800000];
int cnt[800000];
void lzup(int idx,int l,int r,int val)
{
    sg[idx]+=val;
    lz[idx]+=val;
}
void shift(int idx,int l,int r)
{
    if(lz[idx]!=0)
    {
        int md=(l+r)/2;
        lzup(idx*2,l,md,lz[idx]);
        lzup(idx*2+1,md+1,r,lz[idx]);
        lz[idx]=0;
    }
}
void query(int idx,int l,int r,int val,int x,int y)
{
    if(y<l || x>r)return;
    // printf("%d %d %d %d %d %d\n",idx,l,r,x,y,val);
    if(x<=l && r<=y)
    {
        lzup(idx,l,r,val);
        return;
    }
    shift(idx,l,r);
    int md=(l+r)/2;
    query(idx*2,l,md,val,x,y);
    query(idx*2+1,md+1,r,val,x,y);
    pos[idx]=pos2[idx]=0;
    if(sg[idx*2]==sg[idx*2+1])
    {
        // printf("A\n");
        sg[idx]=sg[idx*2];
        cnt[idx]=cnt[idx*2]+cnt[idx*2+1];
        if(pos2[idx*2]==1 && pos[idx*2+1]==1)
        {
            cnt[idx]--;
        }
        pos[idx]=pos2[idx]=0;
        if(pos[idx*2]==1) pos[idx]=1;
        if(pos2[idx*2+1]==1)pos2[idx]=1;
    }
    else
    {
        if(sg[idx*2]>sg[idx*2+1])
        {
            // printf("B\n");
            sg[idx]=sg[idx*2];
            cnt[idx]=cnt[idx*2];
            if(pos[idx*2]==1)
            {
                pos2[idx]=0;
                pos[idx]=1;
            }
        }
        else
        {
            // printf("C\n");
            sg[idx]=sg[idx*2+1];
            cnt[idx]=cnt[idx*2+1];
            if(pos2[idx*2+1]==1)
            {
                pos[idx]=0;
                pos2[idx]=1;
            }
        }
    }
    // printf("%d %d %d %d %d\n",idx,sg[idx],pos[idx],pos2[idx],cnt[idx]);
}
void build(int idx,int l,int r)
{
    int md=(l+r)/2;
    if(l==r)
    {
        sg[idx]=0;
        cnt[idx]=1;
        pos[idx]=1;
        pos2[idx]=1;
        return;
    }
    build(idx*2,l,md);
    build(idx*2+1,md+1,r);
    sg[idx]=sg[idx*2];
    cnt[idx]=1;
    pos[idx]=1;
    pos2[idx]=1;
}
int main()
{
    sint2(n,m);
    build(1,1,n);
    while(m--)
    {
        sint3(x,y,w);
        query(1,1,n,w,x,y);
        printf("%d %d\n",sg[1],cnt[1]);
    }
}
/*

*/
