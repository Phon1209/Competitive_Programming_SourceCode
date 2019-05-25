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
int mid[800005];
int sum[800005];
int L[800008];
int R[800005];
int a[200005];
void build(int idx,int l,int r)
{
    if(l==r)
    {
        L[idx]=a[l];
        R[idx]=a[l];
        sum[idx]=a[l];
        mid[idx]=a[l];
        return;
    }
    int md=(l+r)/2;
    build(idx*2,l,md);
    build(idx*2+1,md+1,r);
    sum[idx]=sum[idx*2]+sum[idx*2+1];
    L[idx]=max(L[idx*2],sum[idx*2]+L[idx*2+1]);
    R[idx]=max(R[idx*2+1],R[idx*2]+sum[idx*2+1]);
    mid[idx]=max(max(R[idx*2],max(mid[idx*2],mid[idx*2+1])),max(L[idx*2+1],R[idx*2]+L[idx*2+1]));
   // printf("%d %d %d %d %d %d %d\n",idx,l,r,mid[idx],sum[idx],L[idx],R[idx]);
}
pair<ii,ii> query(int idx,int l,int r,int x,int y)
{
    if(x>r || y<l)return mkp(mkp(0,0),mkp(0,0));
    if(x<=l && r<=y)
    {
        int a1,a2,a3,a4;
        a1=mid[idx];
        a2=sum[idx];
        a3=L[idx];
        a4=R[idx];
        return mkp(mkp(a1,a2),mkp(a3,a4));
    }
    int md=(l+r)/2;
    pair<ii,ii> b,b2;
    if(y<=md)
    {
        b=query(idx*2,l,md,x,y);
//        printf("A %d %d %d %d %d %d %d\n",idx,l,r,b.F.F,b.F.S,b.S.F,b.S.S);
        return b;
    }
    else if(x>md)
    {
        b2=query(idx*2+1,md+1,r,x,y);
//        printf("B %d %d %d %d %d %d %d\n",idx,l,r,b2.F.F,b2.F.S,b2.S.F,b2.S.S);
        return b2;
    }
        b=query(idx*2,l,md,x,y);
        b2=query(idx*2+1,md+1,r,x,y);
    int r1,r2,r3,r4;
    r1=max(max(b.S.S,max(b.F.F,b2.F.F)),max(b2.S.F,b.S.S+b2.S.F));
    r2=b.F.S+b2.F.S;
    r3=max(b.S.F,b.F.S+b2.S.F);
    r4=max(b2.S.S,b2.F.S+b.S.S);
//    printf("A %d %d %d %d %d %d %d\n",idx,l,r,b.F.F,b.F.S,b.S.F,b.S.S);
//    printf("B %d %d %d %d %d %d %d\n",idx,l,r,b2.F.F,b2.F.S,b2.S.F,b2.S.S);
//    printf("C %d %d %d %d %d %d %d\n",idx,l,r,r1,r2,r3,r4);
    return mkp(mkp(r1,r2),mkp(r3,r4));
}
int main()
{
    sint2(n,m);
    for(int i=1;i<=n;i++)
    {
        int1(a[i]);
    }
    build(1,1,n);
    while(m--)
    {
        sint2(x,y);
        x++;
        y++;
        pair<ii,ii> p;
        p=query(1,1,n,x,y);
        printf("%d\n",max(0,max(max(p.F.F,p.F.S),max(p.S.F,p.S.S))));
    }
}
/*
4 5
1 -2 3 -4
0 3
0 0
1 1
2 2
0 3

*/
