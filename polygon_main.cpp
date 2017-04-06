#include "polygon.hpp"
#include <iostream>

int main(){
  int err = 0;
  int ph,p1;
  float p,s;
  polygon pentagon;
  triangle triangle1;
  square square1;

  polygon* polygons[3];
  polygons[0] = new polygon;
  polygons[1] = new triangle;
  polygons[2] = new square;

  //POLYGON METHODS
  std::cout << "Polygon methods: polygon." << std::endl;

  polygons[0]->set_coord(&err);
  polygons[0]->get_type(&err);
  polygons[0]->show_coord(&err);
  p = polygons[0]->perimeter(&err);
  std::cout << "Perimeter: " << p << std::endl;

  std::cout << "Polygon methods: triangle." << std::endl;

  polygons[1]->set_coord(&err);
  polygons[1]->get_type(&err);
  polygons[1]->show_coord(&err);
  p = polygons[1]->perimeter(&err);
  std::cout << "Perimeter: " << p << std::endl;
  s = polygons[1]->get_square();
  std::cout << "Square: " << s << std::endl;

  std::cout << "Polygon methods: square." << std::endl;

  polygons[2]->set_coord(&err);
  polygons[2]->get_type(&err);
  polygons[2]->show_coord(&err);
  p = polygons[2]->perimeter(&err);
  std::cout << "Perimeter: " << p << std::endl;
  s = polygons[2]->get_square();
  std::cout << "Square: " << s << std::endl;

  //TRIANGLE METHODS

  std::cout << "Triangle methods: " << std::endl;

  std::cout << "Please, input:" << std::endl;
  std::cout << "Peek where height begins on: ";
  std::cin >> ph;
  std::cout << "Peek which belongs to line height lands on: ";
  std::cin >> p1;
  polygons[1]->height(p1,ph,&err);

  polygons[1]->median_point();
  polygons[1]->median_length();
  polygons[1]->bisector_length();
  polygons[1]->bisector_point();

  //SQUARE METHODS

  std::cout << "Square methods: " << std::endl;

  polygons[2]->diagonals();


  delete polygons[0];
  delete polygons[1];
  delete polygons[2];

  return 0;
}

/*
1)Поставить проверку методов от типа
2)Заполнить виртуальный метод площади*/
