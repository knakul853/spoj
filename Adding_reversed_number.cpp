#include <iostream>
using namespace std;
 
int main() {
	// your code goes here
	int n,i;
	cin>>n;   // I will take a test case input from user.
	for(i=0;i<n;i++)
	{
		int a,b,x=0,y=0,r,z,l=0;  
		cin>>a>>b;           //  I  will take a input value from user.
		while(a>0){          //  then i will reverse the first value.
		r=a%10;
		a=a/10;
		x=x*10+r;             // and store into a variable y.
		}
		while(b>0){          // I will reverse a second value.
		r=b%10;
		b=b/10;
		y=y*10+r;              // and store into another variable y.
		}
		z=x+y;                 // and sum of reversed value.  
		while(z>0){           // then I will reverse a sum of reverse value.
		r=z%10;
		z=z/10;
		l=l*10+r;             // and store in to another variable z. 
		}
		cout<<l<<endl;       // print the reverse of sum of reverse value.
	}
	return 0;
} 
