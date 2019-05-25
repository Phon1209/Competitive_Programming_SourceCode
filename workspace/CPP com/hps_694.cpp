#include<bits/stdc++.h>
using namespace std;
#define sint(a) int a; scanf("%d",&a);
#define sint2(a,b) int a,b; scanf("%d %d",&a,&b);
#define sint3(a,b,c) int a,b,c; scanf("%d %d %d",&a,&b,&c);
#define mkp make_pair
#define pb push_back
#define inf 1e9
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
#define sdouble(a) double a; scanf("%lf",&a);
#define slong(a) long long a; scanf("%lld",&a);
#define sstring(a,b) char b[a]; scanf("%s",b);
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
int move[100005];
int a[100005][25][5];
int main() 
{
	freopen("hps.in","r",stdin);
	freopen("hps.out","w",stdout);
    sint2(n,m);
    for(int i=1;i<=n;i++)
    {
    	sstring(5,s);
    	if(s[0]=='H')move[i]=0;
    	if(s[0]=='P')move[i]=1;
    	if(s[0]=='S')move[i]=2;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			for(int k=0;k<3;k++)
			{
				if(j==0)
				{
					a[i][j][k]=a[i-1][j][k]+(move[i]==k);
				}
				else
				{
					int o,o2;
					o=(k+1)%3;
					o2=(k+2)%3;
					a[i][j][k]=max(max(a[i-1][j][k],a[i-1][j-1][o]),a[i-1][j-1][o2])+(move[i]==k);
				}
			}
		}
	}
	int ans;
	ans=max(a[n][m][0],max(a[n][m][1],a[n][m][2]));
	printf("%d\n",ans);
}

