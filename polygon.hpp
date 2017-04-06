#ifndef POLYGON_POLYGON_HPP
#define POLYGON_POLYGON_HPP

class polygon {
protected:
  int dim;
  float** coord;

public:
  polygon();
  polygon(const polygon& rhs);

  polygon& operator=(const polygon& rhs);

  void show_coord(int* err);
  float perimeter(int* err);
  float height(int p1, int ph,int* err);

  virtual void get_type(int* err);
  virtual float get_square(int* err);
  virtual void set_coord(int* err);



  ~polygon();
};

class triangle: public polygon {
  public:
  triangle();

  void get_type(int* err);
  void set_coord(int* err);
  float get_square(int* err);

  void median_point();
  void median_length();
  void bisector_length();
  void bisector_point();


};

class square: public polygon {
  public:
  square();

  void set_coord();
  void get_type(int* err);
  float get_square();

  void diagonals();

};


#endif //POLYGON_POLYGON_HPP
