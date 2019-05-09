#include <iostream>
#include <fstream>
#include <cmath>


using namespace std;

int main()
{
  int T=6;
  int X=1;
  double dx=0.01;
  double dt=0.01;
  int nx=int(X/dx)+1;
  int nt=int(T/dt)+1;
  double c=1;
  double b=c*(dt/dx);
  double ola[2][nx];
    
    
  ofstream outfile;
  outfile.open("datos.dat");  
    
  for (int i=0; i<nx;i++)
  {
    double x=i*dx;
    ola[0][i]=sin(4*M_PI*x)/2;
  }

  
  for(int t=0;t<nt;t++)
  {
      for(int x=0;x<(nx-1);x++)
      {
          ola[1][x]=ola[0][x]- (b/4)*(pow(ola[0][x+1],2)-pow(ola[0][x-1],2)) +(pow(b,2)/8)*( (ola[0][x+1]+ola[0][x])*(pow(ola[0][x+1],2)-pow(ola[0][x],2)) -(ola[0][x]+ola[0][x-1])*(pow(ola[0][x],2)-pow(ola[0][x-1],2)));
      }
      for(int x=0;x<nx;x++)
      {
          outfile << ola[0][x] << " ";
      }
      outfile << "\n";
      for(int i=1;i<(nx-1);i++)
      {
          ola[0][i]=ola[1][i];
      }  
  }  
  return 0;
}


