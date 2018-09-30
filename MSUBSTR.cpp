#include<bits/stdc++.h>
using namespace std;
int p[1000002*2];
int ct=0;
string convert(string s)
{
    string newstring ="@";
    for(int i=0;i<=s.size();i++)
    {
        newstring+="#"+s.substr(i,1);
    }
    newstring+="$";
    return newstring;
}
string palindromic(const string &s)
{
    string newstring = convert(s);
    int c=0,r=0;
    int l =newstring.length();
 
    for(int i=0;i<l-1;i++)
    {
 
        int mir = 2*c-i;
 
        if(r>i)
        {
            p[i] = min(r-i,p[mir]);// r-i to handle the boundaries condition
 
        }
 
        while(newstring[i+1+p[i]]==newstring[i-1-p[i]])p[i]++;
 
        if(i+p[i]>r)
        {
            c=i;
            r=i+p[i];
        }
    }
    int ans=0,cen=0;
    for(int i=0;i<l-1;i++)
    {
        if(ans<p[i])
        {
            ans=p[i];
            cen=i;
        }
    }
    for(int i=0;i<l-1;i++)
    {
        if(ans==p[i])
        {
            ct++;
        }
    }
 
 
 
    return s.substr((cen-1-ans)/2,ans);
 
}
int main()
{
 
 
    int t;
    cin>>t;
    while(t--){
    string s;
    cin>>s;
    cout<<(palindromic(s).length())<<" ";
    cout<<ct<<endl;
    ct=0;
 
        memset(p,0,sizeof(p));
    }
 
}
 
