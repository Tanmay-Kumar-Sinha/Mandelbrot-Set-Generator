#include<iostream>
#include<complex>
#include<stdio.h>

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


void output_mandelbrot(double x_min,double x_max,double y_min,double y_max,int x_resolution,int y_resolution,char filename[]) {
  double a = y_min;
  double M[1005][1005];
  double b = x_min;
  int i = 0;
  int j = 0;
  double  delta_x = (x_max - x_min)/(1.0*x_resolution);
  double  delta_y = (y_max - y_min)/(1.0*y_resolution);
  while(a < y_max) {
    b = x_min;    
    i = 0;
    while(b < x_max) {
      std::complex<double> c(b,a);
       // cout << MAX_ITER - iters_till_convergence(c) << " ";
       M[i][j] =iters_till_convergence(c);
       i++;
       b += delta_x; 
    }
    a += delta_y;
    j++; 
  }
  save_image(M,x_resolution,y_resolution,filename);
}

int main(int argc, char **argv) {
  if(argc < 2) {
    cout << "Please give output filename" << endl;
    return 0;
  }

/*  double x_min = -0.65;
  double x_max = -0.37;
  double y_min = -0.732;
  double y_max = -0.5;
*/

  // double x_min = -0.434;
  // double x_max = -0.396;
  // double y_min = -0.614;
  // double y_max = -0.578;


  // double x_min = -0.4198868;
  // double x_max = -0.4115724;
  // double y_min = -0.594236;
  // double y_max = -0.586827;


  double x_min = -2;
  double x_max = 0.5;
  double y_min = -1.25;
  double y_max = 1.25;

  
  int x_resolution,y_resolution;
  x_resolution = 1000;
  y_resolution = 1000;
  // cout << argv[1] << endl;
  output_mandelbrot(x_min,x_max,y_min,y_max,x_resolution,y_resolution,argv[1]);

  return 0;
}