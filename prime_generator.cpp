#include<bits/stdc++.h>
#define ll long long
#define size1 45000
#include<vector>
void setprime();
void printprime(int a,int b);
int p[size1]; //stores the all possible prime factor of given no
void setprime(){
int temp=sqrt(size1);
int k=0;
for(int i=2;i<=size1;i++){    //creating all prime factor

        int x=sqrt(i);
       int flag=0;
        for(int j=2;j<=x;j++){

            if((i%j)==0){
                    flag=1;
            break;

            }
        }
        if(flag==0){
            p[k++]=i;
                }
}
}


void printprime(int a,int b){   //seive making using prime factors
    int f;
    setprime();

      for(int i=a;i<=b;i++){
            f=0;
        for(int j=0;p[j]<=sqrt(i);j++){
              if((i%p[j])==0){
                f=1;break;
              }

        }
      if(f==0 &&i!=1){
        printf("%d\n",i);
      }

      }
}
using namespace std;
int main() {
int n;
scanf("%d",&n);
while(n--){
int a,b,f;
scanf("%d %d",&a,&b);
printprime(a,b);

}
	return 0;
}
