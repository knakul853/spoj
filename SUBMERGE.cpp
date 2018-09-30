    #include<bits/stdc++.h>
    #define pb push_back
    #define mp make_pair
    #define vi vector<int>
    #define pi pair<int,int>
    #define ll long long
    #define io ios::sync_with_stdio(false)
    using namespace std;
    const int V = 1e5+5;
    vi g[V];
    int visit[V];
    int t;
    int low[V];
    int disc[V];
    int parent[V];
    int ans=0;
    bool ap[V];
    void dfs(int v)
    {
        visit[v] = 1;
        low[v] = disc[v] = ++t;
        int child=0;
     
        for(auto i:g[v])
        {
            if(!visit[i])
            {
                child++;
                parent[i] = v;
                dfs(i);
                low[v]=min(low[v],low[i]);
                if(parent[v]==-1 && child>1)
                {
                    ap[v]=1;
                    ans++;
     
                }
                if(parent[v]!=-1 && disc[v]<=low[i])
                {
     
                    ans++;
                        //cout<<ans<<endl;
                        ap[v]=1;
                }
            }
            else if(i!=parent[v])
            {
                low[v] = min(disc[i],low[v]);
            }
        }
     
    }
     
    int main()
    {
     
        int v,e;
        while(1){
        cin>>v>>e;
        if(v==0&& e==0)return 0;
        for(int i=0;i<V;i++)
        {
            g[i].clear();
            visit[i] =0;
            parent[i]=-1;
            ap[i] = 0;
            t=0;
            ans=0;
     
        }
       // ap.clear();
     
        for(int j=0;j<e;j++)
        {
     
            int x,y;
            cin>>x>>y;
            --x;--y;
            g[x].pb(y);
            g[y].pb(x);
        }
     
        for(int i=0;i<v;i++)
        {
            if(!visit[i])
            {
                dfs(i);
            }
        }
        int sol=0;
        for(int j=0;j<v;j++)
        {
           if(ap[j]==1)
                sol++;
        }
        cout<<sol<<endl;
     
        //cout<<ans<<endl;
     
        }
     
    }
     
