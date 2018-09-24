#include<bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;
const ll N = 1e5+3;
ll hist[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while(1)
    {
          ll n;
    cin>>n;
    if(n==0)
    {
        return 0;
    }
    for(ll i=0;i<n;i++)
    {
        cin>>hist[i];
    }
        ll ar=0;
        ll max_ar=0;
         ll i=0;
         ll tp;
         stack<ll> st;
         while(i<n)
         {
             if(st.empty() || hist[st.top()]<=hist[i])
             {
                 st.push(i);
                 i++;
             }
             else{
                tp = st.top();
                st.pop();
 
                    ar = hist[tp]*((st.empty())?i:i-st.top()-1);
                max_ar =  max(ar,max_ar);
 
 
 
             }
 
 
 
         }
         while(!(st.empty()))
         {
             tp = st.top();
                st.pop();
 
                    ar = hist[tp]*((st.empty())?i:i-st.top()-1);
                max_ar =  max(ar,max_ar);
 
         }
         cout<<max_ar<<endl;
 
 
    }
 
 
}
