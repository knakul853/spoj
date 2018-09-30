    #include<iostream>
    using namespace std;
    int main()
    {
     
    while(1){
            int n;
            cin>>n;
            if(n==0) return 0;
            int ans=0;
            int i=0;
            while(i<=n)
            {
                ans+=(n-i)*(n-i);
                i++;
     
     
            }
            cout<<ans<<endl;
     
     
    }
     
    }
     

