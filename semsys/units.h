#ifndef UNITS_H
#define UNITS_H
#include <type_traits>
#include <typeindex>
#include <string>
#include "group_algebra.h"
#include "Definition_system.h"
namespace units
{

  template<class U, int i>
  struct pw{};

  template<template<class> class,class...> struct U_{};



  template<template<class> class SI,template<class,int> class p,class...Us, int...ns>
  struct U_<SI,p<Us,ns>...>
  {
     static std::string abbr()
     {
       return conmutative_group::abbreviation(conmutative_group::Co<U_<SI,pw<Us,ns>...>>(),"^",".");
     }
  };

  template<template<class> class,class...> struct U_impl{

  };

  template<
      template<class> class SI>
  struct U_impl<SI>
  {
       typedef U_<SI> type;
  };
  template<
      template<class> class SI,
      template<class,int> class p,
      class...Us,
      int...ns>
  struct U_impl<SI,p<Us,ns>...>
  {
       typedef typename conmutative_group::Product
    <U_<SI>,U_<SI,p<Us,ns>...>>::type type;
  };

  template<template<class>class SI,class...Us>
  using U=typename U_impl<SI,Us...>::type;

  template<class U0, class U1>
  using Product=typename conmutative_group::Product<U0,U1>::type;
  template<class> struct Full_{};

  template<template<class>class SI,class...Us>
  struct Full_<U_<SI,Us...>>
  {
     typedef
    typename conmutative_group::Product<U_<SI>,typename definition_system::Full<U_<SI,Us...>>>::type
    type;

  };

  template<class U>
  using Full=typename Full_<U>::type;

  template<class, class> class Sum_impl{};

  template<class G> struct Sum_impl<G,G>
  {
    typedef G type;
  };

  template<class, class> class Sum_{};

  template<
      template<class> class Def,
      template<template<class> class,class...> class G,
      class... E0, class... E1>
  struct Sum_<G<Def,E0...>,G<Def,E1...>>
  {
    typedef  typename Sum_impl<Full<G<Def,E0...>>,Full<G<Def,E1...>>>::type type;
  };

  template <class A, class B>
  using Sum=typename Sum_<A,B>::type;



};




#endif // UNITS_H
