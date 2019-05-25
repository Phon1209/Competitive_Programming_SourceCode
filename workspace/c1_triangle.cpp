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
#define MOD 1000000007
long long dp[105][105],dpsu[105][105],dpsl[105][105];

int main(){
	long long t,i,j,k,n,m,res=0;
	dp[0][0] = dpsu[0][0] = dpsl[0][0] = 1;
	for(i = 0; i <= 100; i++){
		dpsu[i][0] = dpsl[0][i] = 1;
	}

	scanf("%lld %lld",&n,&m);
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++){
			for(k = i-2; k >= 0; k--){
				dp[i][j] += (min(i-k-1,m))*(dpsl[k][j-1]);
				dp[i][j] %= MOD;
			}
			for(k = j-2; k >= 0; k--){
				dp[i][j] += (min(j-k-1,m))*(dpsu[i-1][k]);
				dp[i][j] %= MOD;
			}
			res += dp[i][j];
			res %= MOD;
			dpsu[i][j] = dpsu[i-1][j] + dp[i][j];
			dpsu[i][j] %= MOD;
			dpsl[i][j] = dpsl[i][j-1] + dp[i][j];
			dpsl[i][j] %= MOD;
		}
	}
	printf("%lld\n",res);
}
/*

*/
