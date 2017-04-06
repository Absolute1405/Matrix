#include "polygon.hpp"
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <cmath>

//FUNCTIONS

float line_length(float* p1, float* p2){
  float a,b,c;

  if (p2[0]*p1[0] >= 0) {
    a = std::abs(p2[0]) - std::abs(p1[0]);
  } else {
    a = p2[0] - p1[0];
  }
  a = a*a;

  if (p2[1]*p1[1] >= 0) {
    b = std::abs(p2[1]) - std::abs(p1[1]);
  } else {
    b = p2[1] - p1[1];
  }
  b = b*b;
  c = sqrt(a+b);

  return c;
}



//POLYGON METHODS

polygon::polygon(){
    dim = 5;
    coord = new float*[dim];
    for (int i=0; i<dim; ++i){
      coord[i] = new float[2];
    }
};


polygon::polygon(const polygon& rhs){
  dim = rhs.dim;
  coord = new float*[rhs.dim];
  for (int i=0; i<rhs.dim; ++i){
    coord[i] = new float[2];
    for (int j=0; j<2; ++j) {
      coord[i][j] = rhs.coord[i][j];
    }
  }
};

polygon& polygon::operator=(const polygon& rhs){
  if (this == &rhs) {
    return *this;
  }

  for (int i=0; i<dim; ++i){
    delete[] coord[i];
  }
  delete[] coord;

  dim = rhs.dim;
  coord = new float*[rhs.dim];
  for (int i=0; i<rhs.dim; ++i){
    coord[i] = new float[2];
    for (int j=0; j<2; ++j) {
      coord[i][j] = rhs.coord[i][j];
    }
  }
};


void polygon::set_coord(int *err){
  int new_dim;
  std::cout << "Input the dimension of polygon" << std::endl;
  std::cin >> new_dim;

  if (new_dim>2) {
    int i;
    int n;

    for (i=0; i<dim; ++i){
      delete[] coord[i];
    }
    delete[] coord;

    dim =  new_dim;
    coord = new float*[new_dim];

    for (i=0; i<new_dim; ++i){
      coord[i] = new float[2];
      n = i+1;

      std::cout << "Input the x for peek " << n << ": ";
      std::cin >> coord[i][0];

      std::cout << "Input the y for peek " << n << ": ";
      std::cin >> coord[i][1];
    }
  }
  else {
    std::cout << "Wrong dimension value" << std::endl;
    std::cout << "Aborting program" << std::endl;
    *err = 1;
  }
};


void polygon::show_coord(int *err){
  if (dim>2){
    int n;
    for (int i=0; i<dim; ++i) {
      n = i+1;
      std::cout << "Peek " << n << ":" << std::endl;
      std::cout << "x: " << coord[i][0] << " y: " << coord[i][1] <<std::endl;
    }
  }
  else {
    std::cout << "Can`t show uncreated polygon" << std::endl;
    std::cout << "Aborting program" << std::endl;
    *err = 1;
  }
};


float polygon::perimeter(int *err){
  if (dim>2) {
    int i=0;
    int n=1;
    float c=0;
    float P=0;

    for (i=0; i<dim; ++i){

      c = line_length(coord[n], coord[i]);
      P += c;
      ++n;

      if (n==dim) {
        i+=1;
        c = line_length(coord[0], coord[i]);
        P += c;
      }
    }
    return P;
  }
  else {
    std::cout << "Can`t count the perimeter of uncreated polygon" << std::endl;
    std::cout << "Aborting program" << std::endl;
    *err = 1;
  }
};


float polygon::height(int p1, int ph,int* err){
  if ((p1==ph)|((p1+1)==ph)|(p1>=dim)|(ph>=dim)|(p1<0)|(ph<0)) {
    std::cout << "Can`t count the height, wrong points" << std::endl;
    std::cout << "Aborting program" << std::endl;
    *err = 1;
  }
  else {
    int x1 = coord[p1][0];
    int x2 = coord[p1+1][0];
    int y1 = coord[p1][1];
    int y2 = coord[p1+1][1];
    int Mx = coord[ph][0];
    int My = coord[ph][1];

    float H;
    H = (std::abs((y1-y2)*Mx + (x2-x1)*My + (x1*y2 - x2*y1)))/(sqrt((y1-y2)*(y1-y2) + (x2-x1)*(x2-x1)));
    return H;
  }
};


void polygon::get_type(int* err){
  switch(dim) {
    case 3: {
      std::cout << "Triangle" << std::endl;
      break;
    }
    case 4: {
      std::cout << "Rectangle" << std::endl;
      break;
    }
    case 5: {
      std::cout << "Pentagon" << std::endl;
      break;
    }
    case 6: {
      std::cout << "Hexagon" << std::endl;
      break;
    }
    default: {
      if (dim>6) {
        std::cout << "Polygon of dimension " << dim << std::endl;
        break;
      }
      else {
        std::cout << "Wrong dimension value" << std::endl;
        std::cout << "Aborting program" << std::endl;
        *err = 1;
      }
    }
  }
};


float polygon::get_square(int* err){
  float S;
  if (dim>2) {
    return S;
  }
  else {
    std::cout << "Can`t count the perimeter of uncreated polygon" << std::endl;
    std::cout << "Aborting program" << std::endl;
    *err = 1;
  }
};



polygon::~polygon(){
  for (int i=0; i<dim; ++i){
    delete[] coord[i];
  }
  delete[] coord;
  dim =0;
};


//TRIANGLE METHODS

triangle::triangle(){
  dim = 3;
  coord = new float*[dim];
  for (int i=0; i<dim; ++i){
    coord[i] = new float[2];
  }
};


void triangle::set_coord(int *err){
    int i;
    int n;

    for (i=0; i<dim; ++i){
      delete[] coord[i];
    }
    delete[] coord;

    coord = new float*[dim];

    for (i=0; i<dim; ++i){
      coord[i] = new float[2];
      n = i+1;

      std::cout << "Input the x for peek " << n << ": ";
      std::cin >> coord[i][0];

      std::cout << "Input the y for peek " << n << ": ";
      std::cin >> coord[i][1];
    }
};


void triangle::get_type(int* err){
  if (dim==3){
    std::cout << "Triangle" << std::endl;
  } else {
    std::cout << "Current object is not a triangle" << std::endl;
    std::cout << "Aborting program" << std::endl;
    *err = 1;
  }
};


float triangle::get_square(int* err){
  if (dim==3){
    float S;
    float H;

    H = this->height(0,2, err);
    if (*err==1) {
      std::cout << "Height function error" << std::endl;
    } else {

      float c;
      c = line_length(coord[1], coord[0]);
      S = (c*H)/2;
      return S;

    }
  } else {
    std::cout << "Current object is not a triangle" << std::endl;
    std::cout << "Aborting program" << std::endl;
    *err = 1;
  }
};


void triangle::median_point(){
  float a;
  float center_p[1][2];
  float x,y;

  a = (coord[1][0] - coord[0][0]);
  if (a<0) {
    a = std::abs(a);
    a = a/2 + coord[1][0];
  } else {
    a = a/2 + coord[0][0];
  }
  center_p[0][0] = a;

  a = (coord[1][1] - coord[0][1]);
  if (a<0) {
    a = std::abs(a);
    a = a/2 + coord[1][1];
  } else {
    a = a/2 + coord[0][1];
  }
  center_p[0][1] = a;

  float x1 = coord[2][0];
  float x2 = center_p[0][0];
  float y1 = coord[2][1];
  float y2 = center_p[0][1];

  a = (coord[2][0] - coord[1][0]);
  if (a<0) {
    a = std::abs(a);
    a = a/2 + coord[2][0];
  } else {
    a = a/2 + coord[1][0];
  }
  center_p[0][0] = a;

  a = (coord[2][1] - coord[1][1]);
  if (a<0) {
    a = std::abs(a);
    a = a/2 + coord[2][1];
  } else {
    a = a/2 + coord[1][1];
  }
  center_p[0][1] = a;

  float x3 = coord[0][0];
  float x4 = center_p[0][0];
  float y3 = coord[0][1];
  float y4 = center_p[0][1];

  x = (((x3*y4 - x4*y3)*(x2-x1)) - ((x1*y2 - x2*y1)*(x4-x3)))/(((y1-y2)*(x4-x3)) - ((y3-y4)*(x2-x1)));
  y =  ((x1*y2 - x2*y1) + (x*(y1-y2)))/(x2-x1);
  std::cout << "Median intersection point: " << std::endl;
  std::cout << "x: " << x << " y: " << y << std::endl;
};


void triangle::median_length(){
  float m,a;
  float center_p[1][2];

  a = (coord[1][0] - coord[0][0]);
  if (a<0) {
    a = std::abs(a);
    a = a/2 + coord[1][0];
  } else {
    a = a/2 + coord[0][0];
  }
  center_p[0][0] = a;

  a = (coord[1][1] - coord[0][1]);
  if (a<0) {
    a = std::abs(a);
    a = a/2 + coord[1][1];
  } else {
    a = a/2 + coord[0][1];
  }
  center_p[0][1] = a;

  m = line_length(coord[2], center_p[0]);
  std::cout << "Median 1 length: " << m << std::endl;

  a = (coord[2][0] - coord[1][0]);
  if (a<0) {
    a = std::abs(a);
    a = a/2 + coord[2][0];
  } else {
    a = a/2 + coord[1][0];
  }
  center_p[0][0] = a;

  a = (coord[2][1] - coord[1][1]);
  if (a<0) {
    a = std::abs(a);
    a = a/2 + coord[2][1];
  } else {
    a = a/2 + coord[1][1];
  }
  center_p[0][1] = a;

  m = line_length(coord[0], center_p[0]);
  std::cout << "Median 2 length: " << m << std::endl;


  a = (coord[0][0] - coord[2][0]);
  if (a<0) {
    a = std::abs(a);
    a = a/2 + coord[0][0];
  } else {
    a = a/2 + coord[2][0];
  }
  center_p[0][0] = a;

  a = (coord[0][1] - coord[2][1]);
  if (a<0) {
    a = std::abs(a);
    a = a/2 + coord[0][1];
  } else {
    a = a/2 + coord[2][1];
  }
  center_p[0][1] = a;

  m = line_length(coord[1], center_p[0]);
  std::cout << "Median 3 length: " << m << std::endl;
};


void triangle::bisector_length(){
    float L;
    float a,b,c;

    a = line_length(coord[0], coord[1]);
    b = line_length(coord[1], coord[2]);
    c = line_length(coord[2], coord[0]);

    L = sqrt(a*b*(a+b+c)*(a+b-c))/(a+b);
    std::cout << "Bisector 1 length: " << L << std::endl;

    a = line_length(coord[2], coord[0]);
    b = line_length(coord[1], coord[2]);
    c = line_length(coord[0], coord[1]);

    L = sqrt(a*b*(a+b+c)*(a+b-c))/(a+b);
    std::cout << "Bisector 2 length: " << L << std::endl;

    a = line_length(coord[0], coord[1]);
    b = line_length(coord[2], coord[0]);
    c = line_length(coord[1], coord[2]);

    L = sqrt(a*b*(a+b+c)*(a+b-c))/(a+b);
    std::cout << "Bisector 3 length: " << L << std::endl;
};


void triangle::bisector_point(){
    float x,y;
    float r;
    float p,S;
    float A1,A2,A,B1,B2,C1,C2,Sq;
    int err = 0;

    float x1 = coord[2][0];
    float x2 = coord[1][0];
    float y1 = coord[2][1];
    float y2 = coord[1][1];

    float x3 = coord[0][0];
    float x4 = coord[2][0];
    float y3 = coord[0][1];
    float y4 = coord[2][1];

    A1 = (y2-y1);
    A2 = (y3-y4);
    A = A1/(A1-A2);

    B1 = (x2-x1);
    B2 = (x4-x3);

    C1 = (x1*y2 - x2*y1);
    C2 = (x3*y4 - x4*y3);

    p = this->perimeter(&err);
    p = p/2;
    S = this->get_square(&err);
    r = S/p;

    Sq = sqrt((y1 - y2)*(y1 - y2) + (x2 - x1)*(x2 - x1));

    y = (r*Sq - C1 - A*(C1 - C2))/(A*(B2 - B1) + B1);
    x = (C2 - C1 + y*(B2 - B1))/(A1 - A2);

    std::cout << "Bisectors intersection point: " << std::endl;
    std::cout << "x: " << x << " y: " << y << std::endl;

};


//SQUARE METHODS

square::square(){
  dim = 4;
  coord = new float*[dim];
  for (int i=0; i<dim; ++i){
    coord[i] = new float[2];
  }
};


void square::set_coord(){
  int i;
  int n;

  for (i=0; i<dim; ++i){
    delete[] coord[i];
  }
  delete[] coord;

  coord = new float*[dim];

  for (i=0; i<dim; ++i){
    coord[i] = new float[2];
    n = i+1;

    std::cout << "Input the x for peek " << n << ": ";
    std::cin >> coord[i][0];

    std::cout << "Input the y for peek " << n << ": ";
    std::cin >> coord[i][1];
  }
};


void square::get_type(int* err){
  float l, cl;
  int k=0;
  int n = 2;
  cl = line_length(coord[1], coord[0]);

  for (int i=1; i<dim; ++i){
    l = line_length(coord[n], coord[i]);
    if (cl!=l) {
      k=1;
    }
    ++n;

    if (n==dim) {
      i+=1;
      l = line_length(coord[0], coord[i]);
      if (cl!=l) {
        k=1;
      }
    }
  }


  if ((dim==4)&&(k==0)){
      std::cout << "Square" << std::endl;
  } else {
    std::cout << "Current object is not a square" << std::endl;
    std::cout << "Aborting program" << std::endl;
    *err = 1;
  }

};


float square::get_square(){
    float S;
    S = line_length(coord[1], coord[0]);
    S = S*S;

    return S;

};


void square::diagonals(){


    float a,d;
    a = line_length(coord[1], coord[0]);
    d = a/0.7;

    std::cout << "Diagonal length: " << d << std::endl;

};
