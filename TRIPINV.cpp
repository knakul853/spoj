#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//const ll N = 1e5+9;
ll bit1[1<<20];
ll bit[1<<20];
ll n;
void update(ll *bit,ll id,ll val)
{
    while(id<=n)
    {
        bit[id]+=val;
        id+=id&-id;
    }
}
ll query(ll *bit,ll id)
{
    ll sum = 0;
    while(id>0)
    {
        sum+=bit[id];
        id-=id&-id;
    }
    return sum;
}
int main()
{
 
    cin>>n;
    ll a[n],temp[n];
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
        temp[i]=a[i];
    }
    sort(temp,temp+n);
    for(ll i=0;i<n;i++)
    {
        a[i] = lower_bound(temp,temp+n,a[i])-temp+1;
    }
    ll ans=0;
    for(ll i = n-1;i>=0;i--)
    {
        update(bit,a[i],1);
        ll t = query(bit,a[i]-1);
        update(bit1,a[i],t);
        ans+=query(bit1,a[i]-1);
    }
    cout<<ans<<endl;
    ans=0;
    return 0;
}
