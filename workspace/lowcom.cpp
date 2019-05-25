#include<bits/stdc++.h>
using namespace std;
#define sint(a) int a; scanf("%d",&a);
#define sint2(a,b) int a,b; scanf("%d %d",&a,&b);
#define sint3(a,b,c) int a,b,c; scanf("%d %d %d",&a,&b,&c);
#define int1(a) scanf("%d",&a)
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
    int n;
    while(int1(n)!=EOF)
    {
        if(n==0)
        {
            printf("ZER X\n");
            printf("PRN X\n");
            continue;
        }
        if(n==1)
        {
            printf("ONE X\n");
            printf("PRN X\n");
            continue;
        }
        printf("ONE X\n");
        int cnt=0;
        while(n!=0)
        {
            if(n%2==1)
            {
                printf("PUH X\n");
                cnt++;
                n--;
            }
            if(n==0)break;
            printf("PUH X\n");
            printf("PUH X\n");
            printf("ADD\n");
            n/=2;
            if(n==0 ||n==1)break;
            printf("POP X\n");

        }
        while(cnt>0)
        {
            printf("ADD\n");
            cnt--;
        }
        printf("POP X\nPRN X\n");
    }
}
