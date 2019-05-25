/*
 *	Task: c1_ternary
 *	Lang: C/C++11
 *	Author: comtalyst
 *	Site: ProProg
 *	Last Update: 2/10/2017
 */

#include <bits/stdc++.h>
//#pragma GCC optimize ("O3")
using namespace std;

/* Note
----------------------------
Learned :
Bugs found & solved :
- when choosing double childs --> need to check that whin[] don't overlap to each other
Optimizations :
----------------------------
*/

#define x first
#define y second
#define umap unordered_map
#define pqueue priority_queue
#define mset multiset
#define mp make_pair
#define mt make_tuple
#define MOD 1000000007
#define MAX INT_MAX
#define FILEIN freopen("__in.txt","r",stdin)
#define FILEOUT freopen("__out.txt","w",stdout)

long long pre[105],in[105],whin[105],data[105][105],whpre[105];
long long dp(long long x,long long r){
	long long i,y,ldp=1LL,rdp=0LL,mxx=0,mnn,p;
	multiset<long long> fck;
	if(data[x][r] != -1){
		return data[x][r];
	}
	if(x > r){
		return data[x][r] = 0;
	}
	if(x == r){
		return data[x][r] = 1;
	}
	y = x;
	while(y <= r && whin[pre[y]] <= whin[pre[x]]){
		y++;
	}
	if(whin[pre[x+1]] < whin[pre[x]]){
		ldp = dp(x+1,y-1);
		ldp %= MOD;
	}
	for(i = y+1; i <= r; i++){
		fck.emplace(whin[pre[i]]);
	}
	mxx = whin[pre[y]];
	for(i = y+1; i <= r; i++){
		mnn = *fck.begin();
		if(whin[pre[y]] < whin[pre[i]] && mxx < mnn){
			rdp += (dp(y,i-1)*dp(i,r)) % MOD;
			rdp %= MOD;
		}
		fck.erase(fck.find(whin[pre[i]]));
		mxx = max(mxx,whin[pre[i]]);
	}
	rdp += (dp(y,r)*2LL) % MOD;
	rdp %= MOD;
	if(!rdp){
		rdp = 1LL;
	}
	return data[x][r] = (ldp*rdp) % MOD;
}

main(){
	long long t,i,j,n,m;
	memset(data,-1,sizeof data);

	scanf("%lld",&n);
	for(i = 1; i <= n; i++){
		scanf("%lld",&pre[i]);
		pre[i]++;
		whpre[pre[i]] = i;
	}
	for(i = 1; i <= n; i++){
		scanf("%lld",&in[i]);
		in[i]++;
		whin[in[i]] = i;
	}
	printf("%lld\n",dp(1,n));


	return 0;
}
