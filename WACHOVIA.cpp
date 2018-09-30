    #include<bits/stdc++.h>
    using namespace std;
     
    int main()
    {
        int t;
        cin>>t;
        while(t--)
        {
            int w,n;
            cin>>w>>n;
            int dp[n+1][w+1];
            
            int wt[n],pr[n];
            for(int i=0;i<=n;i++){
                        for(int j=0;j<=w;j++)
                        {
     
                             dp[i][j]=0;
                        }
            }
            
            for(int i=0;i<n;i++)
            {
                cin>>wt[i]>>pr[i];
     
            }
     
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=w;j++)
                {
                    if(wt[i-1]<=j)
                    {
                        dp[i][j] = max(dp[i-1][j],dp[i-1][j-wt[i-1]]+pr[i-1]);
                    }
                    else
                    {
                        dp[i][j]=dp[i-1][j];
                    }
                }
     
            }
            cout<<"Hey stupid robber, you can get "<<dp[n][w]<<"."<<endl;
     
            
        }
     
    }
     
