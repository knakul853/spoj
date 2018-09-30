    #include<bits/stdc++.h>
    using namespace std;
    int main(){
        int n,f;
        char pt[1000000];
        char txt[1000000];
     
    while(scanf("%d",&n)!= EOF){
       scanf("%s %s",pt,txt);
       //cout<<pt[5]<<"   "<<txt[5];
       int lp = strlen(pt);
       int lt = strlen(txt);
       int lps[lp];
    f=0;
       int i=0;
       int j=1;
       lps[0]=0;
       while(j<lp)
       {
           if(pt[j]==pt[i])
           {
               lps[j]=i+1;
               i++;j++;
           }
           else{
     
            if(i>0)
            {
                i=lps[i-1];
     
            }
            else{
                lps[j]=i;
                j++;
            }
     
     
           }
     
       }
       f=0;
       i=0;j=0;
       while(j<lt){
        if(pt[i]==txt[j])
        {
            i++;j++;
        }
        else if(pt[i] !=txt[j])
            {
            if(i==0)
            {
                j++;
            }
            else{
                i=lps[i-1];
            }
           }
    if(i==lp){
            cout<<j-i<<endl;
            i=lps[i-1];
            f=1;
     
        }
     
     
       }
     
       if(f==0){
        cout<<"\n"<<endl;
       }
     
     
    }
     
    }
     
