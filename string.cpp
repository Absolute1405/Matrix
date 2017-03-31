#include <iostream>
#include <cstring>
#include "string.hpp"
#include <stdio.h>
//CONSTRUCTORS
mstring::mstring(int new_size) {
  if (new_size) {
    int i;
    msize = new_size;
    m_string =  new char*[new_size];
    for (i=0; i<new_size; i++){
      m_string[i] = new char[1];
    }
  }
}


mstring& mstring::operator=(const mstring& rhs) {
  if (this == &rhs) {
    return *this;
  }

  int i;
  size_t l;
  for (i=0; i<msize; i++) {
    delete[] m_string[i];
  }
  delete[] m_string;

  msize = rhs.msize;
  m_string =  new char*[rhs.msize];
  for (i=0; i<rhs.msize; i++){
    l=sizeof(rhs.m_string[i]);
    m_string[i] = new char[l];
    memcpy(m_string[i], rhs.m_string[i], l );
  }
}



mstring::mstring(const mstring& rhs) {
  int i;
  size_t l;
  msize = rhs.msize;
  m_string =  new char*[rhs.msize];
  for (i=0; i<rhs.msize; i++){
    l=sizeof(rhs.m_string[i]);
    m_string[i] = new char[l];
    memcpy(m_string[i], rhs.m_string[i], l );
  }
}


//SETERS
void mstring::set_string(int num, char* new_string) {
  size_t size = sizeof(new_string);

  delete[] m_string[num];
  m_string[num] = new char[size];
  memcpy(m_string[num], new_string, size);
}


void mstring::set_arr(int *err) {
  int i;
  int size;
  char* _string = new char[1024];
  for (i=0; i<msize; i++) {
    delete[] m_string[i];
  }
  delete[] m_string;

  std::cout << "Input the size of array:" << std::endl;
  std::cin >> msize;

  m_string = new char*[msize];
  for (i=0; i<msize; i++) {
    printf("Size of string %d: ", (i+1));
    scanf("%3d", &size);
    m_string[i] = new char[size];

    printf("String %d: ", (i+1));
    std::cin >> m_string[i];
    if (strlen(m_string[i])>size) {
      printf("Out of string size. Aborting program\n");
      *err = 1;
      break;
    }
  }
}


//GETERS
char* mstring::get_string(int num) {
  if (num<msize) return m_string[num];
  else {
    std::cout << "Wrong number of string\n" << std::endl;
    return NULL;
  }
}


void mstring::show_string(int num){
  if (num<msize) {
  std::cout << "String " << num+1 << ":" << std::endl;
  for (int i=0; i<=strlen(m_string[num]); i++){
      std::cout << m_string[num][i];
  }
  std::cout << std::endl;
}
else printf("Wrong number of string\n");
}


void mstring::show_arr(){
  for (int i=0; i<msize; i++){
    std::cout << "String " << i+1 << ": ";
    for (int j=0; j<=strlen(m_string[i]); j++){
      std::cout << m_string[i][j];
    }
  std::cout << std::endl;
  }
}


//CONCAT
mstring& mstring::concat(mstring& sum, mstring& rhs, int* err) {
  if (this != &sum) {

  int i,j,k;
  int size;

  for (i=0; i<sum.msize; i++) {
    delete[] sum.m_string[i];
  }
  delete[] sum.m_string;


  if (msize>=rhs.msize) {
      sum.m_string = new char*[msize];
      for (i=0; i<rhs.msize; i++){
          size = sizeof(m_string[i])+sizeof(rhs.m_string[i])-1;
          sum.m_string[i] = new char[size];
          for (j=0; j<sizeof(m_string[i]); j++){
              sum.m_string[i][j] = m_string[i][j];
              }
          for (k=0; k<sizeof(rhs.m_string[i]); k++) {
              sum.m_string[i][j] = m_string[i][k];
              j++;
              }
          }
      for (k=i; k<msize; k++){
          sum.m_string[k] = m_string[k];
          }
      }

    else {
    sum.m_string = new char*[msize];
    for (i=0; i<msize; i++){
        size = sizeof(m_string[i])+sizeof(rhs.m_string[i])-1;
        sum.m_string[i] = new char[size];
        for (j=0; j<sizeof(m_string[i]); j++){
            sum.m_string[i][j] = m_string[i][j];
            }
        for (k=0; k<sizeof(rhs.m_string[i]); k++) {
            sum.m_string[i][j] = m_string[i][k];
            j++;
            }
        }
    for (k=i; k<rhs.msize; k++){
        sum.m_string[k] = m_string[k];
        }

      }
  return sum;

} else {
   printf("Can`t write in same array. Aborting program\n");
   *err = 1;
 }
}


//SORTING
int s_comparision(char* s1, char* s2){
  int i=0;
  int k=0;
  if (sizeof(s1)==sizeof(s2)){
    for (i=0; i<sizeof(s1); i++){
      if (s1[i] > s2[i]) {return 1;}
      else if (s1[i] < s2[i]) {return 2;}
    }
  }  else if (sizeof(s1) > sizeof(s2)) {
    for (i=0; i<sizeof(s2); i++){
      if (s1[i] > s2[i]) {return 1;}
      else if (s1[i] < s2[i]) {return 2;}
    }
    return 1;
  } else if (sizeof(s1) < sizeof(s2)) {
    for (i=0; i<sizeof(s1); i++){
      if (s1[i] > s2[i]) {return 1;}
      else if (s1[i] < s2[i]) {return 2;}
    }
    return 2;
  }
}


void mstring::m_sort() {
  int i,j;
  char* tmp = new char[1024];

  for (i=0; i<msize-1; i++){
    for (j=0; j<msize-1; j++){
      if (s_comparision(m_string[j], m_string[j+1])==1) {
          tmp = m_string[j+1];
          m_string[j+1] = m_string[j];
          m_string[j] = tmp;
        }
      }
    }
  delete[] tmp;
}


//ALLIGN
mstring& mstring::allign(mstring& sum, mstring& rhs, int* err) {
  if (this != &sum) {

  int i,j;
  int k=0;
  int ssize = msize + rhs.msize;
  int size;

  for (i=0; i<sum.msize; i++) {
    delete[] sum.m_string[i];
  }
  delete[] sum.m_string;



  sum.m_string = new char*[ssize];
  for (int i=0; i<msize; i++){
    size = sizeof(m_string[i]);
    sum.m_string[i] = new char[size];
    memcpy(sum.m_string[i], m_string[i], size);
  }

  for (int j=i; j< (i+rhs.msize); j++) { 
    size = sizeof(rhs.m_string[k]);
    sum.m_string[j] = new char[size];
    memcpy(sum.m_string[i], rhs.m_string[k], size);
    k++;
  }

} else {
   printf("Can`t write in same array. Aborting program\n");
   *err = 1;
 }

}


mstring::~mstring() {
  int i;
  for (i=0; i<msize; i++) {
    delete[] m_string[i];
  }
  delete[] m_string;
  msize=0;
}

