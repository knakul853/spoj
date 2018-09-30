    #include<bits/stdc++.h>
    using namespace std;
    int main(){
    int n;
    cin>>n;
    char txt[1000000];
    char pt[1000000];
    while(n--){
     
        scanf("%s",txt);
        scanf("%s",pt);
        int lp = strlen(pt);
        int lt = strlen(txt);
        int lsp[lp];
        lsp[0]=0;
        int i=0,j=1;
        while(j<lp){
     
            if(pt[i]==pt[j]){
     
                lsp[j]=i+1;
                j++;i++;
            }
            else{
                if(i==0)
                {
                    lsp[j]=i;
                    j++;
     
                }
                else{
                    i=lsp[i-1];
                }
     
            }
     
        }
     
        int f=1;
      i=0;
      j=0;
      vector<int> ans;
       while(j<lt)
       {
           if(pt[i]==txt[j])
           {
               i++;j++;
           }
           else if(pt[i] != txt[j])
           {
               if(i==0)
               {
                   j++;
               }
               else
               {
                   i=lsp[i-1];
               }
           }
           if(i==lp)
           {
               ans.push_back(j-i+1);
               f=0;
           }
     
       }
       if(f==1){
        cout<<"\n"<<"Not Found"<<"\n"<<endl;
       }
    else{
        int l=ans.size();
        cout<<l<<endl;
        for(int i=0;i<l;i++)
            cout<<ans[i]<<" ";
     
    }
     
    }
    }
     

