#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{
    int MYCOUNT=25000;
    double data[MYCOUNT][4];
    double a[MYCOUNT],b[MYCOUNT],c[MYCOUNT]/*,d[MYCOUNT]*/;
    ifstream infile;
    infile.open("25000data.txt");
    if (infile.is_open())
    {
        // myfile.open("galaxy.txt");
    for (int i=0;i<MYCOUNT;i++)
    {
            infile >> data[i][1];a[i]=data[i][1];
            infile >> data[i][2];b[i]=data[i][2];
            infile >> data[i][3];c[i]=data[i][3];
            //infile >> data[i][4];d[i]=data[i][4];


    }

    }
    else cout <<"Unable to open file"<<endl;
    for (int i=0;i<MYCOUNT;i++)
    {
        cout<<a[i]<<","<<b[i]<<","<<c[i]/*<<","<<d[i]*/<<endl;

    }

    return 0;
}

