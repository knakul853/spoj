#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<ll,ll>
#define pb push_back
#define MOD 100000000
const ll N =  1e5+7;
vector<pi>a(N);
ll n;
ll dp[N][2];
void sol()
{
    vector<ll>ent;
    memset(dp,0,sizeof(dp[0][0])*N*2);

        ent.pb(a[0].first);
    dp[0][1] = 1;
    for(ll i=1 ; i<n;i++)
    {
        dp[i][0] = dp[i-1][0]+dp[i-1][1];

        if(dp[i][0]>=MOD) dp[i][0]-=MOD;

        if(a[i].second<ent[0])
        {

            dp[i][1]=1;
        }
        else
        {
            auto it=upper_bound(ent.begin(),ent.end(),a[i].second)-ent.begin()-1;
            dp[i][1] = 1+dp[it][0]+dp[it][1];

            if(dp[i][1]>=MOD) dp[i][1]-=MOD;


        }
        ent.pb(a[i].first);

    }
    printf("%0.8d\n",(dp[n-1][0]+dp[n-1][1])%MOD);
}
int main()
{

    while(1)
    {
        cin>>n;

        if(n==-1)break;

        for(ll j=0;j<n;j++)
        {
            cin>>a[j].second;
            cin>>a[j].first;
        }
        sort(a.begin(),a.begin()+n);
        sol();
        a.clear();

    }

}
