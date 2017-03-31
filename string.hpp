#ifndef STRING_STRING_HPP
#define STRING_STRING_HPP

class mstring {
public:
  mstring(int new_size);

  mstring& operator=(const mstring& rhs);
  mstring(const mstring& rhs);


  void set_string(int num, char* new_string);
  void set_arr(int *err);

  char* get_string(int num);
  void show_string(int num);
  void show_arr();

  mstring& concat(mstring& sum, mstring& rhs, int* err);
  void m_sort();
  mstring& allign(mstring& sum, mstring& rhs, int* err);



  ~mstring();

private:
  int msize;
  char** m_string;
};

#endif //STRING_STRING_HPP
