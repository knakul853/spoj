#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
 int t;
 cin>>t;
 while(t--){
  int x , y;
  cin>>x>>y;
  if( y < (x - 2) || y == x - 1 || x<y){
   cout<<"No Number"<<endl;
   continue;
  }
  if( (x&1) && (y&1)){
 
   cout<<x+y-1<<endl;
   continue;
 
  }
  cout<<x+y<<endl;
 }
 return 0;
}
 
