#include<bits/stdc++.h>
using namespace std;
const int N = 100;
int mark[N][N];
char mat[N][N];
int n,m;
int dx[]={1,1,1,-1,-1,-1,0,0};
int dy[]={1,-1,0,-1,1,0,1,-1};
 
int ans;
int ok(int r,int c)
{
    if(r<n && r>=0 && c<m && c>=0)
    {
        return 1;
    }
    return 0;
}
 
void dfs(int r,int c,int h)
{
    ans=max(ans,h);
    for(int i=0;i<8;i++)
    {
        int tx =r+dx[i];
        int ty = c+dy[i];
        if(ok(tx,ty) && mark[tx][ty]==0 && mat[tx][ty]==mat[r][c]+1)
        {
            mark[tx][ty]=1;
            dfs(tx,ty,h+1);
        }
 
    }
}
 
int main()
{
    int t=0;
    while(1)
    {
         t++;
 
         cin>>n>>m;
         if(n==0 && m==0)return 0;
         for(int i=0;i<n;i++)
         {
             for(int j=0;j<m;j++)
             {
                 cin>>mat[i][j];
                 mark[i][j]=0;
             }
         }
 
          for(int i=0;i<n;i++)
         {
             for(int j=0;j<m;j++)
             {
                if(mat[i][j]=='A')
                {
                    mark[i][j]=1;
                    dfs(i,j,1);
                }
             }
         }
         cout<<"Case "<<t<<": "<<ans<<endl;
         ans=0;
 
 
    }
 
 
}
