#include<bits/stdc++.h>
#define INT_MIN -999999      
using namespace std;
struct node{          // structure for storing the the prefix,suffix,sum and answer.
int pre,suff,ans,sum;
 
};
node seg[4*50010];
int ar[50010];
//since every leaf node will have the same prefix,suffix sum and answer !
void leaf(int a,int b)
{
    seg[a].pre=ar[b];
    seg[a].suff=ar[b];
    seg[a].ans=ar[b];
    seg[a].sum=ar[b];
}
//plese dry run on paper for better understanding the function of comb.
/*the idea is 
  1. use prefix and suffix value for best subarray .
  2.sum store the entire array  sum.
  than take the best possible answer.
*/
void comb(int pos)       
{
seg[pos].sum = (seg[2*pos+1].sum+seg[2*pos+2].sum);
seg[pos].pre = max(seg[2*pos+1].pre,seg[2*pos+1].sum+seg[2*pos+2].pre);
seg[pos].suff = max(seg[2*pos+2].suff,seg[2*pos+2].sum+seg[2*pos+1].suff);
seg[pos].ans = max(max(seg[2*pos+1].ans,seg[2*pos+2].ans),seg[2*pos+2].pre+seg[2*pos+1].suff);
 
}
void build(int l,int h,int pos)
{
 
    if( l==h)
    {
        leaf(pos,l);
        return;
    }
    int mid = (l+h)/2;
    build(l,mid,2*pos+1);
    build(mid+1,h,2*pos+2);
    comb(pos);     
 
}
node query(int l,int h,int ql,int qh,int pos)
{
    if(qh<l ||ql>h){
 
        return (node)
        {                   //constructor for invalid case !
            INT_MIN,
            INT_MIN,
            INT_MIN,
            0,
        };
    }
    if(ql<=l&&h<=qh)
    {
        return seg[pos];
    }
    int mid = (l+h)/2;
    node p =query(l,mid,ql,qh,2*pos+1);
    node q= query(mid+1,h,ql,qh,2*pos+2);
    node res;
    res.sum = p.sum+q.sum;
    res.pre = max(p.pre,p.sum+q.pre);
    res.suff = max(q.suff,p.suff+q.sum);
    res.ans =max(max(p.ans,q.ans),p.suff+q.pre);
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>ar[i];
    build(0,n-1,0);
    int q;
    cin>>q;
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        --l;--r;
        node an;
       an= query(0,n-1,l,r,0);
       cout<<max(max(an.ans,an.sum),max(an.pre,an.suff))<<endl;
    }
 
}
