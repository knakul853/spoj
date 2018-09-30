#include<bits/stdc++.h>
#define pb push_back
using namespace std;
int priority(char ch)
{
    if(ch=='^')return 3;
    if(ch=='/' || ch  == '*')return 2;
    if(ch=='+' || ch =='-')return 1;
    return 0;
 
}
bool is_op(char ch)
{
    if(ch =='+' || ch=='-'||ch =='/' || ch=='*'||ch =='^')
    {
 
 
       return true;
    }
    else
      return  false;
 
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int l = s.length();
        vector<char> ans;
         int i=0;
          char ch;
          stack<char> st;
        while(l--)
        {
            ch = s[i++];
            if(isalnum(ch))
                {
                    ans.pb(ch);
 
                }
 
            else if(ch=='(')
            {
                st.push(ch);
 
            }
 
            else if(ch == ')')
            {
 
 
                while(!(st.empty()) && st.top() !='(')
                {
                    ans.pb(st.top());
                    st.pop();
 
 
                }
                st.pop();
 
 
            }
 
            else
            {
                while(!(st.empty()) && (is_op(st.top())==true) && priority(ch)>=priority(st.top()))
                {
                    cout<<is_op(st.top())<<endl;
                    ans.pb(st.top());
                    st.pop();
                }
                st.push(ch);
 
 
            }
 
        }
        while(!(st.empty()))
        {
            ans.pb(st.top());
            st.pop();
        }
        for(int i=0;i<ans.size();i++)
        {
           cout<<ans[i];
        }
        ans.clear();
        cout<<endl;
   }
 
 
    }
