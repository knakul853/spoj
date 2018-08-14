#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ll n,c;
        cin>>n>>c;
        ll a[n];
        for(ll i=0;i<n;i++)
        {
            cin>>a[i];
        }

        sort(a,a+n);
        ll beg = 0;
        ll en = a[n-1];
        ll  p = c;
        ll ans = -1;
        while(beg<en)
        {
            ll mid = (beg+en)/2;


            ll k=0;ll f=0;
            for(ll i = 1;i<n;i++)
            {
                if(a[i]-a[k]>=mid)
                {
                    c--;
                   k = i;
                }
                if(c==1)
                {
                    f=1;
                }
            }
            if(f==0)
            {
                en = mid;

            }
            else{

                 if(ans<mid)
                    ans = mid;
                beg = mid+1;
            }
            c = p;
           if(beg==en)
           {
               cout<<ans<<endl;
               break;
           }

        }
    }

}
