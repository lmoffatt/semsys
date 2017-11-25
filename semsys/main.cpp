#include <iostream>

#include "units.h"
#include "variables.h"
#include "SI.h"
using SI::pw;

int main()
{
  variables::Var<SI::SI,pw<SI::m,1>>  f1{5};
  variables::Var<SI::SI,pw<SI::m,1>,pw<SI::kg,1>,pw<SI::s,-2>>  f2{5};


  variables::Var<SI::SI,pw<SI::V,1>> v{10};
  variables::Var<SI::SI,pw<SI::A,1>> i{10};
  variables::Var<SI::SI,pw<SI::W,1>> pot{10};
  std::cout<<v<<std::endl;
  std::cout<<v*i+pot<<std::endl;


  variables::Var<SI::SI,pw<SI::N,1>> force{100};
  std::cout << f1 << std::endl;
  std::cout << f2*f2 + force*force << std::endl;
  std::cout<< force+force<<std::endl;

  return 0;
}
