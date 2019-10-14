//am-pm to 24 hr format
#include<bits/stdc++.h>

using namespace std;

int twenty4(){
   string i,r,o,t;
    int h,m,s;
    cout<<"Enter time in 24hr format :: \n    HH:MM:SS";
    cin>>i;
    t=i;

    stringstream j(t);
    j>>h;

    if(h>24){
        cout<<"wrong input";
        return 0;
    }

    t="ab";

    t[0]=i[3];
    t[1]=i[4];
    stringstream j1(t);
    j1>>m;

    if(m>60){
        cout<<"wrong input";
        return 0;
    }

    t[0]=i[6];
    t[1]=i[7];
    stringstream j2(t);
    j2>>s;

    if(s>60){
        cout<<"wrong input";
        return 0;
    }

    t[0]=i[8];
    t[1]=i[9];


    if(h<12)
        h=h-12;
    cout<<h<<":";
    if(m<10)
        cout<<"0";
    cout<<m<<":";
    if(s<10)
     cout<<"0";
    cout<<s<<"\n";

return 0;
}

int AMPM(){
    string i,r,o,t;
    int h,m,s;
    cout<<"Enter time in AM PM format :: \n    hh:mm:ssAM \n";
    cin>>i;
    t=i;

    stringstream j(t);
    j>>h;

    if(h>12){
        cout<<"wrong input";
        return 0;
    }

    t="ab";

    t[0]=i[3];
    t[1]=i[4];
    stringstream j1(t);
    j1>>m;

    if(m>60){
        cout<<"wrong input";
        return 0;
    }

    t[0]=i[6];
    t[1]=i[7];
    stringstream j2(t);
    j2>>s;

    if(s>60){
        cout<<"wrong input";
        return 0;
    }

    t[0]=i[8];
    t[1]=i[9];

    if(h==12&&(t=="AM"||t=="am"))
        h=00;
    if(h<12&&(t=="PM"||t=="pm"))
        h=h+12;
    if(h<10)
        cout<<"0";
    cout<<h<<":";
    if(m<10)
        cout<<"0";
    cout<<m<<":";
    if(s<10)
     cout<<"0";
    cout<<s<<"\n";
}

int main(){
    int x;
        do{cout<<"\n";
           cout<<" Enter 1 for AM PM to 24 \n Enter 2 for 24 to AM PM \n Enter 0 to exit\n";
        cin>>x;
           if(x==1)
                AMPM();
           else if(x==2)
                twenty4();
            else if(x!=0)
                cout<<"enter correct choice";
        }while(x);
    return 0;


}
