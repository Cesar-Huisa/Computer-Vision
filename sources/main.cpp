#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include "CImg.h"
#define cimg_use_jpeg

using namespace cimg_library;
using namespace std;


template<typename N>
string nnTost(N Number) {
	stringstream ss;
	ss << Number;
	return ss.str();
}

int main()
{
    //CImg<unsigned char> NX("images/2.jpg");
    //NX.display();
    map<int,map<int,map<int,unsigned char> > > Me;
    int n;
    string tem;
    CImg<unsigned char> img;
    cout<<"Numero de imagenes: "<<endl;
    cin>>n;
    for(int i=1;i<=n;i++) {
        string tem="images/"+nnTost(i)+".jpg";
        const char * cim = tem.c_str();
        img.load(cim);
        for(int k=0; k< img.height(); k++) {
            for(int j=0; j<img.width(); j++) {
                if (img(k,j)!=0) {
                    //ikj
                    Me[i][k][j]=img(k,j);
                }
            }
        }
    }
    //CImg<unsigned int> Matrx(21,21,3,1,2);
	//A.Print(cout);
	//ofstream file("salida.txt");
	//A.Print(file);
	return 0;
}
