#include<bits/stdc++.h>

using namespace std;


long long int lcm(int x,int y)
{
    int a,b,i=1;
    if(x>y)
      {a=y;b=x;}
    else
      {a=x;b=y;}
    do{
        if((b*i)%a==0)
            break;
        else
            i++;
    }while(1);

    return b*i;
}

long long int gcf(int x,int y)
{
    int a,b,i=1;
    if(x>y)
      {a=y;b=x;}
    else
      {a=x;b=y;}
    do{
        if((b*i)%a==0)
            break;
        else
            i++;
    }while(1);

    return a/i;
}

int main(){
    int n,m,l,g,i;
    cout<<"enter no of elements to input in first list ";
    cin>>m;
    cout<<"enter no of elements to input in second list ";
    cin>>n;
    int a[m],b[n];

    for(i=0;i<m;i++)//a
    {
        cout<<"enter value of elements of first list at position ["<<i+1<<"] "; 
        cin>>a[i];
    }

    cout<<"\n";
    
    for(i=0;i<n;i++)//b
    {
        cout<<"enter value of elements of second list at position ["<<i+1<<"] ";
        cin>>b[i];
    }



    if(n==1)
        g=b[0];
    else{
    g=gcf(b[n-2],b[n-1]);

    for(i=(n-3);i>=0;i--)
    {
        g=gcf(g,b[i]);
    }}

    if(g==1)
    cout<<0;
else{
    if(m==1)
        l=a[0];
    else{
    l=lcm(a[m-2],a[m-1]);

    for(i=(m-3);i>=0;i--)
    {
        l=lcm(l,a[i]);;
    }
    }

int c=0;i=1;

while(g>=(l*i)){
    if(g%(l*i)==0)
      c++;
    i++;
  };

cout<<"\n result "<<c;}

return 0;
}


