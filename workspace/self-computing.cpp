#include<bits/stdc++.h>
using namespace std;char n=10,q=34;
string a[10];
int main()
{
    a[0]="#include<stdio.h>";
    a[1]="using namespace std;char n=10,q=34;";
    a[2]="string a[10];";
    a[3]="int main()";
    a[4]="printf(\"string a[%d]=%c%s%c\n\",i,q,(a[i]).c_str(),q);";
    a[5]="printf(\"printf(%c%cs\%cc%c,a[%d].c_str(),n)%c\",q,37,37,q,i,n);";
    printf("%s%c",a[0].c_str(),n);
    printf("%s%c",a[1].c_str(),n);
    printf("%s%c",a[2].c_str(),n);
    printf("%s%c",a[3].c_str(),n);
    printf("{%c",n);
    for(int i=0;i<6;i++)printf("string a[%d]=%c%s%c\n",i,q,(a[i]).c_str(),q);
    for(int i=0;i<4;i++)printf("printf(%c%cs\%cc%c,a[%d].c_str(),n)%c",q,37,37,q,i,n);
}
/*

*/
