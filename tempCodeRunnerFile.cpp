#include<iostream>
using namespace std;
class complex{
    int re1,re2;
    int im1,im2;
    int realresult,imgresult;
    public:
        void input();
        void process(complex ,complex );
        void output();
};

 void complex::input(){
    cout<<"Enter real 1 ";
    cin>>re1;
    cout<<"Enter im 1";
    cin>>im1;
    cout<<"Enter real 2 ";
    cin>>re2;
    cout<<"Enter im 2";
    cin>>im2;
 }
 void complex::process(complex c1,complex c2){
    realresult=c1.re1+c2.re2;
    imgresult=c1.im1+c2.im2;
 }

 void complex::output(){
    cout<<"Sum is "<<realresult<<" + "<<imgresult<<" i";
 }

 int main(){
    complex c;
    c.input();
    c.process(c,c);
    c.output();
    return 0;
 }