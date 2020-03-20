#include<iostream>
#include<complex>
#include<stdio.h>

using namespace std;

// int M[10005][100005];
int MAX_ITER = 250;

std::complex<double> f(std::complex<double> z,std::complex<double> c) {
  //std::complex<double> c(-0.8,0.156); 
  // std::complex<double> c(0.285,0.01); 
  return z*z + c;
  // return exp((std::complex<double>(1,0))/z);
  // return z*z*z - std::complex<double>(1,0);
}

int iters_till_convergence(std::complex<double> c,std::complex<double> w) {
  std::complex<double> z;
  z = c;
  int n=0;
  while(abs(z) <= 2 && n <= MAX_ITER) {
    n += 1;
    z = f(z,w);
  } 
  return n;
}

void save_image(double M[][1005],int x_resolution,int y_resolution,char filename[]) {
  FILE* pgmimg; 
  pgmimg = fopen(filename, "wb"); 
  // Writing Magic Number to the File 
  int width = x_resolution;
  int height = y_resolution;
  int i,j;
  fprintf(pgmimg, "P2\n");  
  // Writing Width and Height 
  fprintf(pgmimg, "%d %d\n", width, height);  
  // Writing the maximum gray value 
  fprintf(pgmimg, "255\n");  
  int count = 0; 
  for (i = 0; i < height; i++) { 
      for (j = 0; j < width; j++) { 
          double temp = M[j][i]; 
          fprintf(pgmimg, "%d ", (int)temp); 
      } 
      fprintf(pgmimg, "\n"); 
  } 
  fclose(pgmimg); 
}

void output_julia(double x_min,double x_max,double y_min,double y_max,int x_resolution,int y_resolution,std::complex<double> w,char filename[]) {
  double a = y_min;
  double b = x_min;
  double M[1005][1005];
  int i = 0;
  int j = 0;
  int max_val = -1000;
  int min_val = 1000;
  while(a < y_max) {
    b = x_min;    
    i = 0;
    while(b < x_max) {
      std::complex<double> c(b,a);
      //cout << c << '\n';
       //M[i][j] = MAX_ITER - iters_till_convergence(c);
       // cout << (MAX_ITER - iters_till_convergence(c,w)) << " ";
      M[i][j] = iters_till_convergence(c,w);
      if(M[i][j] < min_val) min_val = M[i][j];
      if(M[i][j] > max_val) max_val = M[i][j];
      i++;
      b += (x_max - x_min)/x_resolution; 
    }
    j++;
    a += (y_max - y_min)/y_resolution; 
    // cout << "reached\n";
    // cout << '\n';
  }
  save_image(M,x_resolution,y_resolution,filename);
}

int main(int argc, char **argv) {
/*  double x_min = -0.65;
  double x_max = -0.37;
  double y_min = -0.732;
  double y_max = -0.5;
*/
  double x_min = -2;
  double x_max = 2;
  double y_min = -2;
  double y_max = 2;

  int x_resolution,y_resolution;
  x_resolution = 1000;
  y_resolution = 1000;
  double a = strtod(argv[1],NULL);
  double b = strtod(argv[2],NULL);
  std::complex<double> w(a,b);
  output_julia(x_min,x_max,y_min,y_max,x_resolution,y_resolution,w,argv[3]);

  return 0;
}