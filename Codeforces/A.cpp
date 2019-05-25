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

int ans[1005][1005];
int row[1005];

int main()
{
    sint3(n,a,b);
    if(a==n && b==1){
        printf("YES\n");
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)printf("0");
            endl;
        }
        return 0;
    }
    if(b==n && a==1)
    {
        printf("YES\n");
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)printf("%d",(i==j)? 0:1);
            endl;
        }
        return 0;
    }
    if((a>1 && b>1))
    {
        printf("NO\n");
        return 0;
    }
    memset(ans,0,sizeof(ans));
    int cnt=1,cnt2=2;
    for(int i=0;i<n-a;i++)
    {
        ans[cnt][cnt2]=1;
        ans[cnt2][cnt]=1;
        row[cnt]++;
        row[cnt2]++;
        if(row[cnt]==n-1)b--;
        if(row[cnt2]==n-1)b--;
        cnt++;
        cnt2++;
        if(cnt2>n)cnt2=1;
    }
    // 1 to cnt is connected
    b--;
    cnt2=1;
    while(b!=0)
    {
        for(int i=1;i<=n;i++)
        {
            if(i==cnt2)continue;
            if(ans[i][cnt2]==0)
            {
                ans[cnt2][i]=1;
                ans[i][cnt2]=1;
                row[cnt2]++;
                row[i]++;
                if(row[i]==n-1)b--;
                if(row[cnt2]==n-1)b--;
            }
            if(b<0)
            {
                printf("NO\n");
                return 0;
            }
            if(b==0)break;
        }
        if(b==0)break;
        cnt2++;
    }
    printf("YES\n");
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            printf("%d",ans[i][j]);
        }
        endl;
    }
}
/*

*/
