#include<iostream>
#include<complex>

using namespace std;

// int M[10005][100005];
int MAX_ITER = 500;
float max_val = 2;
int M[2000][2000];


void output_buddhabrot(double x_min,double x_max,double y_min,double y_max,int x_resolution,int y_resolution) {
  double a = y_min;
  double b = x_min;
  double delta_x = (x_max - x_min)/x_resolution;
  double delta_y = (y_max - y_min)/y_resolution;
  while(a < y_max) {
    b = x_min;    
    while(b < x_max) {
      std::complex<double> c(b,a);
      int n=0;
      std::complex<double> z;
      z = 0;
      while(abs(z) <= max_val && n <= MAX_ITER) {
        n += 1;
        z = z*z + c;
      }
      z = 0;
      if(n <= MAX_ITER) {
        for(int k = 0;k<n;k++) {
          z = z*z + c;
          int i = ((real(z) - x_min)/delta_x);
          int j = ((imag(z) - y_min)/delta_y);
          // cout << i << " " << j << " ";
          if(i < x_resolution && j < y_resolution && i >= 0 && j >= 0) M[i][j]++;
        }  
      }
      b += delta_x;
    }
    a += delta_y;

  }
}

int main() {
  // double x_min = -0.65;
  // double x_max = -0.37;
  // double y_min = -0.732;
  // double y_max = -0.5;


  // double x_min = -0.434;
  // double x_max = -0.396;
  // double y_min = -0.614;
  // double y_max = -0.578;
/*
  double x_min = -0.4198868;
  double x_max = -0.4115724;
  double y_min = -0.594236;
  double y_max = -0.586827;
*/

  double x_min = -2;
  double x_max = 1;
  double y_min = -1.5;
  double y_max = 1.5;

  
  int x_resolution,y_resolution;
  x_resolution = 2000;
  y_resolution = 2000;
  for(int i=0;i<x_resolution;i++) {
    for(int j=0;j<y_resolution;j++) {
      M[i][j] = 0;
    }
  }
  output_buddhabrot(x_min,x_max,y_min,y_max,x_resolution,y_resolution);

  for(int j=0;j<y_resolution;j++) {
    for(int i=0;i<x_resolution;i++) {
      cout << M[i][j] << " ";
    }
    cout << "\n";
  }


  return 0;
}