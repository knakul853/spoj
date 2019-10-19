#include<bits/stdc++.h>
using namespace std;
#define N 100000
long long int bit[N+1],a[N+1];
int parent[N+2];
void build(int n)
{
    for(int i=1;i<=n;i++)
    {
        int ind=i;
        while(ind<=n)
        {
            bit[ind]+=a[i];
            ind+=ind &(-ind);
        }
    }
}
long long int que(int ind)
{
    long long int ans=0;
    while(ind>0)
    {
        ans+=bit[ind];
        ind-=ind &(-ind);
    }
return ans;
}
void update(int ind,long long int val,int n)
{
    while(ind<=n)
    {
        bit[ind]+=val;
        ind+=ind &(-ind);
    }
}
int find(int x)
{
    while(parent[x]!=x)
    {
        parent[x]=parent[parent[x]];
        x=parent[x];
    }
    return x;
}
void connect(int l,int r,int n)
{
    int k=find(l);
    while(k<=r)
    {
        long long int diff=a[k];
        a[k] = (long long int)(sqrtl(1.0 * a[k]));
        update(k,a[k]-diff,n);
        if(a[k]==1)
            parent[k]=k+1;
        k=find(k+1);
    }
}
int main()
{
    int n,m,o,l,r,z=1;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
            scanf("%lld",&a[i]),parent[i]=i;
            parent[n+1]=n+1;
            build(n);
        scanf("%d",&m);
        printf("Case #%d:\n",z++);
        while(m--)
        {
            scanf("%d%d%d",&o,&l,&r);
            if(l>r)
                swap(l,r);
            if(!o)
                connect(l,r,n);
            else
               printf("%lld\n",que(r)-que(l-1));
        }
        printf("\n");
        for(int i=1;i<=n;i++)
            bit[i]=0;
    }
}
