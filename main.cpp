// Programer Vinh Nguyen
//This program does awesome stuff:Impporting galaxy data from another source (could be the web)then calculate the estimator for N-point correlation function
#include <iostream>
#include <cmath>
#include <fstream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int main()
{

   int i,p,nd,nr,n;
   float pdr, pdd, prr;
    float x[11],y[11],distance,dd,rr,dr,en,els,xr[11],yr[11];
pdr=pdd=prr=0;
srand((int)time(0));
//This is input part
//ut<<"How many datas are we gonna have:";cin>>n;

//ut<<"First let's type in the dataset"<<endl;

//nd =n;
n = 10;
nd = n;
i=1;
//p=1;

/*while (i<nd+1) {

    cout<<"Please input x"<<i<<":";cin>>x[i];
    i=i+1;
}
i=1;
while (i<nd+1) {
     cout<<"Please input y"<<i<<":";cin>>y[i];
    i=i+1;
} */

//This part displays all the sample values again
cout<<"Sample data again"<<endl;
x[1] = 1.0;
y[1] = 1.2;
x[2] = 1.2;
y[2] = 1.9;
x[3] = 2.0;
y[3] = 4.0;
x[4] = 1.0;
y[4] = 3.0;
x[5] = 3.3;
y[5] = 5.0;
x[6] = 7.0;
y[6] = 3.0;
x[7] = 2.0;
y[7] = 9.0;
x[8] = 4.0;
y[8] = 1.0;
x[9] = 5.0;
y[9] = 1.0;
x[10] = 9.0;
y[10] = 9.0;

i=1;

while (i<11) {
    cout<<x[i] << " " << y[i] <<endl;
    i=i+1;
}

cout<<"Now for the random set:"<<endl;
 srand((int)time(0));
 i = 0;
 while(i++ < 11) {
  int r = (rand() % 250) -350;
 xr[i] = r;
  //cout << "x " << x[i] << endl;
 }

 //srand((int)time(0));
 int j = 0;
 while(j++ < 11) {
  int r = (rand() % 250) -350;
  yr[j] = r;
  //cout << "y " << y[j] << endl;
 }

 for (i=1;i<11;i++)
  //cout << xr[i] << " " << yr[i] << endl;


//This part calculate PDR
float r2 = 30.;
float r1 = 5.;
i=1;
cout<<"Let's calculate PDR"<<endl;
while (i<11)
    {
        p=1;
    while (p<11)
    {
    distance=sqrt((x[i]-xr[p])*(x[i]-xr[p])+(y[i]-yr[p])*(y[i]-yr[p]));
    //cout << i << "  " << p <<"  "<< distance<< endl;
    p=p+1;
    if (distance > r1 and distance < r2)
        {
        pdr=pdr+1;
        }
    }
        i=i+1;
    }
cout<<"PDR="<<pdr<<endl;
//This part calculates PDD
cout<<"Now let's calculate PDD"<<endl;
i=p=1;
while (i<11)
    {
        p=i+1;
        while (p<11)
        {
        distance=sqrt((x[i]-x[p])*(x[i]-x[p])+(y[i]-y[p])*(y[i]-y[p]));
        //cout<<i<<p<<"   "<<distance<<endl;
        if (distance > r1 and distance < r2)
            {
                pdd=pdd+1;
            }
        p=p+1;
        }
        i=i+1;
    }
cout<<"PDD="<<pdd<<endl;
//This part calculates PRR
cout<<"Now let's calculate PRR"<<endl;
i=p=1;
while (i<11)
    {
        p=i+1;
        while (p<11)
        {
        distance=sqrt((xr[i]-xr[p])*(xr[i]-xr[p])+(yr[i]-yr[p])*(yr[i]-yr[p]));
        //cout<<i<<p<<"   "<<distance<<endl;
         if (distance > r1 and distance < r2)
            {
                prr=prr+1;
            }
        p=p+1;
        }
        i=i+1;
    }
cout<<"PRR="<<prr<<endl;

nd = 10;
nr = 10;
//This part canculates normalized counts and finally,the much awaited two points correlation function
cout<<"This part calculates normalized counts and finally,the much awaited two points correlation function estimator"<<endl;
dd=pdd/(nd*(nd-1));
rr=prr/(nr*(nr-1));
dr=pdr/(nd*nr);
en=dd/rr-1;
cout<<"dd="<<dd<<endl;
cout<<"rr="<<rr<<endl;
cout<<"dr="<<dr<<endl;
cout<<"en="<<en<<endl;
els=(dd-2*dr+rr)/rr;
cout<<"els="<<els<<endl;
return 0;
}
