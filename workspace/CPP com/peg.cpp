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
#define inf 1e9
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
char a[10][10];
int mu[]={1,0,0,-1},me[]={0,1,-1,0};
int mu2[]={2,0,0,-2},me2[]={0,2,-2,0};
int main()
{
	for(int i=0;i<7;i++)
	{
		gets(a[i]);
	}
	int cnt=0;
	for(int i=0;i<7;i++)
	{
		for(int j=0;j<7;j++)
		{
			if(a[i][j]=='o')
			{
				for(int k=0;k<4;k++)
				{
					if(a[i+mu[k]][j+me[k]]=='o')
					{
						if(a[i+mu2[k]][j+me2[k]]=='.')
						{
							cnt++;
						}
					}
				}
			}
		}
	}
	printf("%d\n",cnt);
}

