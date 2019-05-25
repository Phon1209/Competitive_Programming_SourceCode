#include<bits/stdc++.h>
using namespace std;

int ask[]={16,9,5,7,11,13,17};
int table[1000005];
int main()
{
    int t,n,m;
    scanf("%d %d %d",&t,&n,&m);
    int ans=0;
    while(t--)
    {
        memset(table,0,sizeof(table));
        for(int i=0;i<7;i++)
        {
            int x=ask[i];
            for(int j=0;j<18;j++)
            {
                if(j!=0)printf(" ");
                printf("%d",x);
            }
            printf("\n");
            fflush(stdout);
            int res=0;
            for(int j=0;j<18;j++)
            {
                int tmp;
                scanf("%d",&tmp);
                res+=tmp;
                res%=x;
            }
            for(int j=res;j<=1000000;j+=x)
            {
                table[j]++;
            }
        }
        for(int i=0;i<=1000000;i++)
        {
            if(table[i]==7)
            {
                printf("%d\n",i);
                fflush(stdout);
                int vd;
                scanf("%d",&vd);
                assert(vd==1);
                break;
            }
        }
    }
}
/*

*/
