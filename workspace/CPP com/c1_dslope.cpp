#include<bits/stdc++.h>
#define sint2(a,b) int a,b; scanf("%d %d",&a,&b);
#define MOD 999999999
using namespace std;
int cumBIT[45][80005];
int howMany[45][80005];
vector<int> values;
void update(int idx, int k, int n,int val)
{
    while(idx<n) {
        cumBIT[k][idx]+=val;
        cumBIT[k][idx]%=MOD;
        idx+=(idx&-idx);
    }
}
 
int getValue(int idx, int k)
{
   int ret = 0;
   while(idx>0) {
 
      ret+=cumBIT[k][idx];
 	  ret%=MOD;
      idx-=(idx& (-idx));
   }
   return ret;
}
int main()
{
    sint2(n,k);
    values=vector<int>(n,0);
    for(int i=0;i<n;i++) {
    	int tmp;
        cin>>tmp;
        values[i]=n-tmp+1;
    }
    int ret = 0;
    for(int i=0;i<n;i++) {
      int index = values[i];
      howMany[1][i]=1;
      update(index,1,n,howMany[1][i]);
      for(int j=2;j<=k;j++) {
         howMany[j][i]=getValue(index-1,j-1);
         howMany[j][i]%=MOD;
         update(index,j,n,howMany[j][i]);
      }
      ret+=howMany[k][i];
      ret%=MOD;
    }
    cout<<ret%MOD<<endl;
 
}
