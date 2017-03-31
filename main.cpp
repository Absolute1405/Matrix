#include <iostream>
#include <cstring>
#include "string.hpp"
#include <stdio.h>

mstring& func(mstring& lhs, mstring& rhs, mstring& result, int *err) {

  lhs.allign(result, rhs, err);
  if (*err != 1 ){
    result.m_sort();
  }
  return result;
}

int main (){
  return 0;
}

