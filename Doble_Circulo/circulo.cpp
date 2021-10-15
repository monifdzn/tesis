#include <bits/stdc++.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include "circulo.h"


int main(){
    ofstream myfile1,myfile2,file1,file2;
    //Generacion de puntos
    //myfile1.open ("CircExt.dat"); //Puntos del circulo exterior
    //myfile2.open ("CircInt.dat"); //Puntos del circulo interior
    //file1.open("Double.dat"); //Puntos del doble circulo enumerados
    file2.open("DobleCirculo.dat");
    srand(time(NULL));
    int n=N;
    double rext = 10.0;
    double dr,rint;
    double x0=0.0;
    double y0=0.0;
    double thetaext = 10*2*M_PI/360;
    double thetaint = thetaext +M_PI/n;
    Vertice *CircExt = CreaCircle(n,rext,x0,y0,thetaext,1);
    dr = deltar(CircExt[0],CircExt[1],CircExt[2],CircExt[3]);
    //for(int i=0; i<n; i++){
    //    myfile1<<CircExt[i].etiq<<" "<<CircExt[i].x<<" "<<CircExt[i].y<<endl;
    //}
    rint = rext-dr;
    Vertice *CircInt = CreaCircle(n,rint,x0,y0,thetaint,2);
    for(int i=0; i<n; i++){
        //myfile2<<CircInt[i].etiq<<" "<<CircInt[i].x<<" "<<CircInt[i].y<<endl;
        //file1<<2*i<<" "<<CircExt[i].x<<" "<<CircExt[i].y<<"\n"<<2*i+1<<" "<<CircInt[i].x<<" "<<CircInt[i].y<<endl;
        file2<<CircExt[i].x<<" "<<CircExt[i].y<<"\n"<<CircInt[i].x<<" "<<CircInt[i].y<<endl;
    }
    //myfile1.close();
    //myfile2.close();
    //file1.close();
    file2.close();
}
