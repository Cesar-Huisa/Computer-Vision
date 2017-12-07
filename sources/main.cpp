#include <iostream>
#include <fstream>
#define cimg_use_jpeg
#include "CImg.h"

using namespace cimg_library;
using namespace std;

template<typename T>
class NodoE
{
public:
	T dat;
	NodoE<T> * fil_sig;
	NodoE<T> * col_sig;
	int fil;
	int col;
	NodoE(T d,int f,int c) {
		dat=d;
		fil=f;
		col=c;
	}
};
template<typename T>
class MatrixE
{
public:
	NodoE<T> **Fila;
	NodoE<T> **Columna;
	int Nfil;
	int Ncol;

	MatrixE(int F,int C) {
		Nfil=F;
		Ncol=C;
		Fila=new NodoE<T> *[F];
		Columna=new NodoE<T> *[C];
		for(int i=0;i<F;i++) {
			Fila[i]=NULL;
		}
		for(int j=0;j<C;j++) {
			Columna[j]=NULL;
		}
	}

	bool find_fil(int f, int c, NodoE<T> ** & p) {
		p = &(Columna[c]);
		while(*p) {
			if ((*p)->fil==f)
				return true;
			if ((*p)->fil >f)
				return false;
			p = &((*p)->fil_sig);
		}
		return false;
	}

	bool find_col(int f, int c, NodoE<T> ** & p) {
		p = &(Fila[f]);
		while(*p) {
			if ((*p)->col==c)
				return true;
			if ((*p)->col>c)
				return false;
			p = &((*p)->col_sig);
		}
		return false;
	}
	void Add(T d, int x, int y) {
		NodoE<T> ** p;
		NodoE<T> ** q;
		bool ff = find_fil(x,y,q);
		bool fc = find_col(x,y,p);
		if(!ff) {
			NodoE<T> * pNuevo = new NodoE<T>(d,x,y);
			pNuevo->col_sig= *p;
			pNuevo->fil_sig = *q;
			*p=*q=pNuevo;
		}
	}

	void  Print( ostream & os) {
		NodoE<T> ** p;
		for(int i =0;i< Nfil; i++) {
			os<<endl;
			for( int j =0;j<Ncol; j++) {
				if (find_fil(i,j,p))
					os<<(*p)->dat<<" ";
				else
					os<<"0 ";
			}
		}
	}

};





int main()
{
    CImg<unsigned char> NX("images/2.jpg");
    NX.display();
    /*
    map<int,map<int,map<int,unsigned char>>> Me;
    int n;
    string tem;
    CImg<unsigned char> im;
    cout<<"Numero de imagenes: "<<endl;
    cin>>n;
    for(int i=0;i<n;i++) {
        tem="/Images/"+i.tostring()+".png"
        im.load(tem);
        for(int k=0; k< img.height(); k++) {
            for(int j=0; j<img.width(); j++) {
                if (img(k,j)!=0) {
                    Me[i,k,j]=im(k,j);
                }
            }
        }
    } */
    //CImg<unsigned int> Matrx(21,21,3,1,2);
	//A.Print(cout);
	//ofstream file("salida.txt");
	//A.Print(file);
	return 0;
}
