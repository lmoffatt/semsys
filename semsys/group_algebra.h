#ifndef GROUP_ALGEBRA_H
#define GROUP_ALGEBRA_H
#include <type_traits>
#include <typeindex>
#include <string>
namespace conmutative_group
{





  template<class, class>
  struct index_in{};

  template<bool, int, class...>
  struct index_impl_compare{};

  template<int n,class T,template<class...> class S>
  struct index_impl_compare<false,n,T,S<>>
  {
     constexpr static std::size_t value=-1;
  };

  template<int n,class T,template<class...> class S, class... Ts>
  struct index_impl_compare<true,n,T,S<Ts...>>
  {
     constexpr static std::size_t value=n;
  };

  template<int n,class T,template<class...> class S, class T0,class... Ts>
  struct index_impl_compare<false,n,T,S<T0,Ts...>>
  {
     constexpr static std::size_t value=
         index_impl_compare<std::is_same<T,T0>::value,n+1,T,S<Ts...>>::value;
  };


  template<class T,template<class...> class S, class T0, class... Ts>
  struct index_in<T,S<T0,Ts...>>
  {
    constexpr static std::size_t value=
        index_impl_compare<std::is_same<T,T0>::value,0,T,S<Ts...>>::value;

  };





  template<class A, class B>
  struct Product{};

  template<class...>
  struct Product_impl{};



  template<
      template<class> class Def,
      template<class,int> class p,
      template<template<class> class,class...> class G,
      class...E0s, int...n0s,
      class E2, int n2>
  struct Product_impl<G<Def,p<E0s,n0s>...>,G<Def>,G<Def,p<E2,n2>>>
  {
    typedef G<Def,p<E0s,n0s>...,p<E2,n2>> type;
  };


  template<
      template<class> class Def,
      template<class,int> class p,
      template<template<class> class,class...> class G,
      class...E0s, int...n0s,
      class E1, class...E1s, int n1,int...n1s,
      class E2, int n2>
  struct Product_impl<G<Def,p<E0s,n0s>...>,G<Def,p<E1,n1>,p<E1s,n1s>...>,G<Def,p<E2,n2>>>
  {
    typedef
    std::conditional_t
    <
    std::is_same<E1,E2>::value,

    std::conditional_t
    <
    n1+n2==0,
    G<Def,p<E0s,n0s>...,p<E1s,n1s>...>,
    G<Def,p<E0s,n0s>...,p<E1,n1+n2>,p<E1s,n1s>...>
    >,
    std::conditional_t
    <
    Def<E2>::index < Def<E1>::index,
    std::conditional_t
    <
    n2==0,
    G<Def,p<E0s,n0s>...,p<E1,n1>,p<E1s,n1s>...>,
    G<Def,p<E0s,n0s>...,p<E2,n2>,p<E1,n1>,p<E1s,n1s>...>
    >,
    typename Product_impl
    <
    G<Def,p<E0s,n0s>...,p<E1,n1>>,G<Def,p<E1s,n1s>...>,G<Def,p<E2,n2>
    >
    >::type
    >
    > type;

  };



  template<
      template<class> class Def,
      template<class,int> class p,
      template<template<class> class,class...> class G,
      class E1, int n1
      >
  struct Product<G<Def>,G<Def,p<E1,n1>>>
  {
    typedef
    std::conditional_t<
    n1==0,
    G<Def>,
    G<Def,p<E1,n1>>
    >type;
  };
  template<
      template<class> class Def,
      template<class,int> class p,
      template<template<class> class,class...> class G,
      class E1, int n1
      >
  struct Product<G<Def,p<E1,n1>>,G<Def>>
  {
    typedef
    std::conditional_t<
    n1==0,
    G<Def>,
    G<Def,p<E1,n1>>
    > type;
  };

  template<
      template<class> class Def,
      template<template<class> class,class...> class G
      >
  struct Product<G<Def>,G<Def>>
  {
    typedef G<Def> type;
  };
  template<
      template<class> class Def,
      template<class,int> class p,
      template<template<class> class,class...> class G,
      class...E0s, int...n0s      >
  struct Product<G<Def,p<E0s,n0s>...>,G<Def>>
  {
    typedef G<Def,p<E0s,n0s>...> type;
  };



  template<
      template<class> class Def,
      template<class,int> class p,
      template<template<class> class,class...> class G,
      class...E0s, int...n0s,
      class E1, int n1,
      class...E1s, int...n1s
      >
  struct Product<G<Def,p<E0s,n0s>...>,G<Def,p<E1,n1>,p<E1s,n1s>...>>
  {
    typedef typename Product
    <
    typename Product_impl<G<Def>,G<Def,p<E0s,n0s>...>,G<Def,p<E1,n1>>>::type,
    G<Def,p<E1s,n1s>...>
    >
    ::type type;
  };

  template<class E, int n>
  struct Power_{};


  template<
      template<class> class Def,
      template<class,int> class p,
      template<template<class> class,class...> class G,
      class...E0s, int...n0s,
      int n1>
  struct Power_<G<Def,p<E0s,n0s>...>,n1>
  {
    typedef G<Def,p<E0s,n0s*n1>...> type;
  };

  template<class E, int n>
  using Power=typename Power_<E,n>::type;


  template <class...> struct Co{};

  template<
      template<class> class Def,
      template<template<class> class,class...> class G
      >
  std::string print_impl(std::string res,const Co<G<Def>>&, const std::string& )
  {
    return res;
  }


  template<
      template<class> class Def,
      template<template<class> class,class...> class G,
      class E,
      class...Es
      >
  std::string abbreviation_impl(std::string res,const Co<G<Def,E,Es...>>&,const std::string& sep)
  {
    return abbreviation_impl(res+sep+Def<E>::abbr,Co<Es...>(),sep);
  };

  template<
      template<class> class Def,
      template<template<class> class,class...> class G,
      class E,
      class...Es
      >
  std::string abbreviation(const Co<G<Def,E,Es...>>&,const std::string& sep)
  {
    return abbreviation_impl(Def<E>::abbr,Co<G<Def,Es...>>(), sep);
  }


  template<
      template<class> class Def,
      template<template<class> class,class...> class G
      >
  std::string abbreviation_impl(std::string res,const Co<G<Def>>&,  const std::string&, const std::string& )
  {
    return res;
  }


  template<
      template<class,int> class p,
      template<class> class Def,
      template<template<class> class,class...> class G,
      class...Es, int...ns,
      class E, int n>
  std::string abbreviation_impl(std::string res,const Co<G<Def,p<E,n>,p<Es,ns>...>>&,  const std::string& exp,const std::string& sep)
  {
    if (n!=1)
      return abbreviation_impl(res+sep+Def<E>::abbr+exp+std::to_string(n),Co<G<Def,p<Es,ns>...>>(),exp,sep);
    else
      return abbreviation_impl(res+sep+Def<E>::abbr,Co<G<Def,p<Es,ns>...>>(),exp,sep);

  }


  template<
      template<class,int> class p,
      template<class> class Def,
      template<template<class> class,class...> class G,
      class E, int n,
      class...Es, int...ns>
  std::string abbreviation(const Co<G<Def,p<E,n>,p<Es,ns>...>>&, const std::string& exp,const std::string& sep)
  {
    if (n!=1)
      return abbreviation_impl(Def<E>::abbr+exp+std::to_string(n),Co<G<Def,p<Es,ns>...>>(),exp,sep);
    else
      return abbreviation_impl(Def<E>::abbr,Co<G<Def,p<Es,ns>...>>(),exp,sep);
  }








};
#endif // GROUP_ALGEBRA_H
