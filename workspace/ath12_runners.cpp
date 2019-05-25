#include<bits/stdc++.h>
using namespace std;
#define sint(a) int a;scanf("%d",&a);
#define sint2(a,b) int a,b; scanf("%d %d",&a,&b);
#define sint3(a,b,c) int a,b,c; scanf("%d %d %d",&a,&b,&c);
#define mkp make_pair
#define pb push_back
#define inf INT_MAX
#define pause system("pause");
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        // time acc num
        vector<pair<double,pair<double,int> > > v;
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++)
        {
            double s,st;
            scanf("%lf %lf",&s,&st);
            // s=acc
  //          printf(">%lf %lf %d\n",(((double)m/s)+(st/1000)),-s,i+1);
            v.push_back(make_pair((((double)m/s)+(st/1000)),make_pair(-s,i+1)));
        }
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++)
        {
            printf("%d\n",v[i].second.second);
        }
    }
}
