#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[107];
ll dp[1002][1003];
ll sum(int i,int k)
{
    ll ans=0;
    for(int j = i;j<=k;j++)
    {
        ans+=a[j];
        ans%=100;
    }
    return ans;
 
}
 
ll solve(int i,int j )
{
    if(i>=j)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    dp[i][j] = 9999999;
    for(int k = i ; k<=j; k++)
    {
        dp[i][j] = min(dp[i][j],solve(i,k)+solve(k+1,j)+sum(i,k)*sum(k+1,j));
    }
    return dp[i][j];
}
int main()
{
    ll n;
    while((scanf("%lld",&n))!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int  i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
            dp[i][j]=-1;
            }
        }
 
        cout<<solve(0,n-1)<<endl;
    }
 
}
