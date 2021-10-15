#include <stdint.h>
#define N 8
using namespace std;

typedef struct punto{
	double x;
	double y;
    int ind;
}Punto;

typedef struct vertice{
	char etiq[10];
	double x;
	double y;
}Vertice;

double medio(double x1, double x2){
        return (x1+x2)*0.5;
}

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

double altura(double x,double x1, double x2, double y1, double y2){
    return (y1-y2)*(x-x1)/(x1-x2)+y1;
}

Punto intersec(Vertice A, Vertice B, Vertice C, Vertice D) 
{ 
    // Recta AB a1x + b1y = c1 
    Punto inter;
    double a1 = B.y - A.y; 
    double b1 = A.x - B.x; 
    double c1 = a1*(A.x) + b1*(A.y); 
  
    // Recta CD a2x + b2y = c2 
    double a2 = D.y - C.y; 
    double b2 = C.x - D.x; 
    double c2 = a2*(C.x)+ b2*(C.y); 
  
    double determinant = a1*b2 - a2*b1; 
  
    if (determinant == 0) 
    {  
        inter.x=FLT_MAX;
        inter.y=FLT_MAX;
    } 
    else
    { 
        inter.x = (b2*c1 - b1*c2)/determinant; 
        inter.y = (a1*c2 - a2*c1)/determinant; 
    } 
    return inter;
} 


Vertice *CreaCircle(int n,double r, double x0, double y0, double theta, int op){
    double a,x,y,da;
    a=theta;
    da=2*M_PI/n;
    char etiqueta[10],nchar[2];
    
    Vertice *P = (Vertice*)malloc(sizeof(Vertice)*n);
    //strcpy(etiqueta,"P_");
    for(int i=0; i<n; i++){
        x=x0+(r*cos(a));
        y=y0+(r*sin(a));
        if(op==1){
            strcpy(etiqueta,"P_");
        }else{
            strcpy(etiqueta,"Q_");
        }
        sprintf(nchar, "%i", i);
        strcat(etiqueta, nchar);
        strcat(P[i].etiq,etiqueta);
        P[i].x=x;
        P[i].y=y;
        //cout<<P[i].etiq<<"  x:"<<P[i].x<<"  y:"<<P[i].y<<endl;       
        a += da;
    }

    return P;
}

double deltar(Vertice va, Vertice vi, Vertice vs, Vertice vss){
    Punto Pmv;
    Pmv.x = medio(vi.x,vs.x);
    Pmv.y = medio(vi.y,vs.y);
    Punto Pmd = intersec(vi,vss,va,vs);
    return 0.6*sqrt((Pmv.x-Pmd.x)*(Pmv.x-Pmd.x)+(Pmv.y-Pmd.y)*(Pmv.y-Pmd.y));
}
