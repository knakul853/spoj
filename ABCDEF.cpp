/*
a*b+c=d*(e+f)
store the value of left equation in a vector and right in another one !!
use binary search to find the matching value and add in our solution

here we have used lower and upper bound to calculate all mathing range

*/
#include<bits/stdc++.h>
using namespace std;
 
#define MAX 102
 
int n,x[MAX],lower,higher;
long long res=0LL;
vector<int>s1,s2;
 
int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf("%d",&x[i]);
    }
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            for (int k=0;k<n;k++)
            {
                s1.push_back(x[i]*x[j]+x[k]);
            }
        }
    }
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            for (int k=0;k<n;k++)
            {
                if (x[k]==0) continue; // d can't be zero
                s2.push_back((x[i]+x[j])*x[k]);
            }
        }
    }
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    for (int i=0;i<s1.size();i++)
    {
        lo=lower_bound(s2.begin(),s2.end(),s1[i])-s2.begin();
        hi=upper_bound(s2.begin(),s2.end(),s1[i])-s2.begin();
        res+=(hi-lo);
    }
    printf("%lld\n",res);
    return 0;
}
