#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define int long long
#define fast ios::sync_with_stdio(false)

const int N = 1e5+5;

vector<int>g[N];
vector<bool>visit(N , false);
int ans = 0;
int tmin[N];
int low[N];
int t = 0;
int v,e;
int arr[N];

void dfs(int v,int p=-1)
{
    visit[v] = true;
    tmin[v] = low[v] = ++t;
    int child = 0;

    for(auto i:g[v])
    {
        if(p == i)continue;
        if(visit[i])
        {
               low[v] = min(low[v] , tmin[i]);
        }
        else
        {
           dfs(i,v);
           low[v] = min(low[i],low[v]);
           if(low[i] >= tmin[v] && p!=-1 )
               arr[v]=1;
               child++;

        }

        if(p == -1 && child > 1)arr[v]=1;
       
    }



}

void reset()
{
     for(int i=0;i<N;i++)
    {
        g[i].clear();
        visit[i]=false;
        ans = 0;
        t = 0;
        arr[i]=0;
        tmin[i] = -1;
        low[i] = -1;
    }

}
void make_graph()
{
    for(int i=1;i<=e;i++)
    {
        int x,y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }

}

void solve()
{
    reset();
    make_graph();
    for(int i=1;i<=v;i++)
    {
        if(!visit[i])
        {
            dfs(i);
        }
    }
    for(int i=1;i<=v;i++)
    {
        if(arr[i])ans++;
    }
    cout<<ans<<"\n";
}


int32_t main()
{
    while(1)
    {
        cin >> v >> e;
        if(v == 0 && e == 0)return 0;
         solve();
    }
    return 0;
}
