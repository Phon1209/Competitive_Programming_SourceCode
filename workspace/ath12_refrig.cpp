#include<bits/stdc++.h>
using namespace std;
int a[205],n;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int mn=INT_MAX;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            mn=min(mn,a[i]);
        }
        for(int i=0;i<n;i++)
        {
            a[i]-=mn;
        }
        int tmp=mn,ok=0,use=0;
        while(tmp>0)
        {
            int cnt=0;
            for(int i=0;i<n;i++)
            {
                if(a[i]==ok)
                {
                    a[i]++;
                    cnt++;
                }
            }
///            printf("%d %d %d\n",tmp,cnt,ok);
            tmp-=cnt;
            tmp++;
            if(tmp<=0)break;
            ok++;
            use++;
        }
        printf("%d\n",mn+use);
    }
}
