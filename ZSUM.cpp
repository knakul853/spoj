#include<bits/stdc++.h>
#define ll  long long
#define MOD 10000007
using namespace std;
ll mod(ll a,ll b){
if(b==0)return 1;
if(!(b&1)){
    ll res = mod(a,b/2);
    return (res*res)%MOD;
}
else{
    return(a%MOD * (mod(a,b-1)))%MOD;
}
}
int main(){
    ll n,k;
    //cout<<mod(3,4)<<endl;
    while(1){
    scanf("%lld %lld",&n,&k);
    if(n==0&&k==0)break;
    ll res1,res2,res3,res4,res;
    res1=mod(n,k);
    res2=mod((n-1),k);
    res2 = (2*res2)%MOD;
    //res +=mod(2*(n+1),k);
    res3=mod(n,n);
    res4=mod((n-1),n-1);
    res4 =(2*res4)%MOD;
 
    //res +=mod(2*(n+1),n+1);
    res=(res1+res2+res3+res4)%MOD;
    cout<<res<<endl;
    }
}
