#include<iostream>
#include<complex>

using namespace std;

// int M[10005][100005];
int MAX_ITER = 200;
float max_val = 2;

int iters_till_convergence(std::complex<double> c) {
  std::complex<double> z(0,0);
  int n=0;

  while(abs(z) <= max_val && n <= MAX_ITER) {
    n += 1;
    z = z*z + c;
  } 
  return n;
}

void output_mandelbrot(double x_min,double x_max,double y_min,double y_max,int x_resolution,int y_resolution) {
  double a = y_min;
  double b = x_min;
  while(a < y_max) {
    b = x_min;    
    while(b < x_max) {
      std::complex<double> c(b,a);
      //cout << c << '\n';
       //M[i][j] = MAX_ITER - iters_till_convergence(c);
       cout << MAX_ITER - iters_till_convergence(c) << " ";
       b += (x_max - x_min)/x_resolution; 
    }
    a += (y_max - y_min)/y_resolution; 
    cout << '\n';
  }
}

int main() {
/*  double x_min = -0.65;
  double x_max = -0.37;
  double y_min = -0.732;
  double y_max = -0.5;
*/

  double x_min = -0.434;
  double x_max = -0.396;
  double y_min = -0.614;
  double y_max = -0.578;

/*
  double x_min = -0.4198868;
  double x_max = -0.4115724;
  double y_min = -0.594236;
  double y_max = -0.586827;
*/

/*  double x_min = -2;
  double x_max = 2;
  double y_min = -2;
  double y_max = 2;

*/  int x_resolution,y_resolution;
  x_resolution = 2000;
  y_resolution = 2000;

  output_mandelbrot(x_min,x_max,y_min,y_max,x_resolution,y_resolution);

  return 0;
}