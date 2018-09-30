    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    vector<int>g[10007];
    int mark[10006];
    int dist[10008];
    int ans;
    int bfs(int u)
    {
     
        memset(dist,0,sizeof(dist));
        memset(mark,0,sizeof(mark));
        queue<int>qu;
        qu.push(u);
        while(!qu.empty()){
     
                int u = qu.front();
                qu.pop();
     
        for(auto i:g[u])
        {
            if(mark[i])continue;
            else{
     
             qu.push(i);
             dist[i]=dist[u]+1;
             mark[i]=1;
            }
     
        }
     
    }
    int co = max_element(dist,dist+10000)-dist;
     ans=dist[co];
    return co;
     
    }
    int main()
    {
        int n;
        cin>>n;
     
        for(int i=0;i<n-1;i++)
        {
            int x,y;
            cin>>x>>y;
            g[x].pb(y);
            g[y].pb(x);
        }
       bfs(bfs(1));
        cout<<ans<<endl;
     
     
     
    }
     
