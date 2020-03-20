#include<iostream>
#include<complex>

using namespace std;

// int M[10005][100005];
int MAX_ITER = 500;
float max_val = 2;
double M[2004][2004];

void save_image(int x_resolution,int y_resolution,char filename[]) {
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
  fprintf(pgmimg, "510\n");  
  int count = 0; 
  for (i = 0; i < height; i++) { 
      for (j = 0; j < width; j++) { 
          double temp = 10*M[j][i]; 
          fprintf(pgmimg, "%d ", (int)temp); 
      } 
      fprintf(pgmimg, "\n"); 
  } 
  fclose(pgmimg); 
}


void output_buddhabrot(double x_min,double x_max,double y_min,double y_max,int x_resolution,int y_resolution) {
  double a = y_min;
  double b = x_min;
  double delta_x = (x_max - x_min)/(1.0*x_resolution);
  double delta_y = (y_max - y_min)/(1.0*y_resolution);
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
          if(i < x_resolution && j < y_resolution && i >= 0 && j >= 0) M[i][j] += 1.0;
        }  
      }
      b += delta_x;
    }
    a += delta_y;

  }
}

int main(int argc, char **argv) {
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

  if(argc < 2) {
    cout << "Please give output filename" << endl;
  }
  int x_resolution,y_resolution;
  x_resolution = 2000;
  y_resolution = 2000;
  for(int i=0;i<x_resolution;i++) {
    for(int j=0;j<y_resolution;j++) {
      M[i][j] = 0;
    }
  }
  output_buddhabrot(x_min,x_max,y_min,y_max,x_resolution,y_resolution);
  save_image(x_resolution,y_resolution,argv[1]);  

  return 0;
}