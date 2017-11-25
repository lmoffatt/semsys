#ifndef DEFINITION_SYSTEM_H
#define DEFINITION_SYSTEM_H
#include <type_traits>
namespace definition_system
{
  template <class, class> struct Co{};

  template<
      class...> struct Full_impl{
  };

  template<bool,class...>
  struct Full_compare{};


  template<
      template<class> class Def,
      template<template<class> class,class...> class G,
      class...E0s
      >
  struct Full_impl<G<Def,E0s...>,G<Def>>
  {
      typedef G<Def,E0s...> type;
  };


  template<
      template<class> class Def,
      template<template<class> class,class...> class G,
      class...E0s,
      class E,class... Es>
  struct Full_impl<G<Def,E0s...>,G<Def,E,Es...>>
  {
      typedef typename Full_compare
    <
    std::is_same<G<Def,E>,typename Def<G<Def,E>>::type>::value,
    G<Def,E0s...>,Co<G<Def,E>,typename Def<G<Def,E>>::type>,G<Def,Es...>>::type type;
  };


  template<
      template<class> class Def,
      template<template<class> class,class...> class G,
      template<class, class> class Co,
      class...E0s,
      class E,
      class...Es,
      class... E1s>
  struct Full_compare<false,G<Def,E0s...>,Co<G<Def,E>,G<Def,Es...>>,G<Def,E1s...>>
  {
      typedef
    typename
    Full_impl<G<Def,E0s...>,G<Def,Es...,E1s...>>::type
        type;
  };

  template<
      template<class> class Def,
      template<template<class> class,class...> class G,
      template<class, class> class Co,
      class...E0s,
      class E,
      class... E1s>
  struct Full_compare<true,G<Def,E0s...>,Co<G<Def,E>,G<Def,E>>,G<Def,E1s...>>
  {
      typedef
    typename
    Full_impl<G<Def,E0s...,E>,G<Def,E1s...>>::type
        type;
  };


  template<
      template<class> class Def,
      template<template<class> class,class...> class G,
      class E,class... Es>
  struct Full_impl<G<Def,E,Es...>>
  {
      typedef typename Full_compare<
    std::is_same<G<Def,E>,typename Def<G<Def,E>>::type>::value,
    G<Def>,Co<G<Def,E>,typename Def<G<Def,E>>::type>,G<Def,Es...>>::type type;
  };

  template<class  G>
  using Full=typename Full_impl<G>::type;



}

#endif // DEFINITION_SYSTEM_H
