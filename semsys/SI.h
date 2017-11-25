#ifndef SI_H
#define SI_H
#include "units.h"

namespace SI
{
  using units::pw;

  using units::U;
  template <class U>
  struct SI{
    constexpr static const int index=U::index;
    constexpr static const char* abbr=U::abbr;

  };


  template<
      template<class,int> class p,
      template<template<class> class,class...> class G,
      class U, int n>
  struct SI<G<SI,p<U,n>>>
  {
    typedef conmutative_group::Power<typename U::type ,n> type;
    constexpr static const int index=U::index;
    constexpr static const char* abbr=U::abbr;
  };
  struct m
  {
    constexpr static const char* name="metre";
    constexpr static const char* abbr="m";
    constexpr static const int index=0;
    constexpr static const char* quantity="Lenght";
    typedef units::U<SI,pw<m,1>> type;

  };
  struct s
  {
    constexpr static const char* name="second";
    constexpr static const char* abbr="s";
    constexpr static const int index=1;
    constexpr static const char* quantity="Time";
    typedef U<SI,pw<s,1>> type;

  };


  struct kg
  {
    constexpr static const char* unit="kilogram";
    constexpr static const char* abbr="kg";
    constexpr static const int index=-1;
    constexpr static const char* quantity="Mass";
    typedef U<SI,pw<kg,1>> type;
  };

  struct A
  {
    constexpr static const char* unit="ampere";
    constexpr static const char* abbr="A";
    constexpr static const int index=kg::index-1;
    constexpr static const char* quantity="Electric_Current";
    typedef U<SI,pw<A,1>> type;
  };

  struct K
  {
    constexpr static const char* unit="kelvin";
    constexpr static const char* abbr="K";
    constexpr static const int index=2;
    constexpr static const char* quantity="Thermodynamic_Temperature";
    typedef U<SI,pw<K,1>> type;
  };

  struct mol
  {
    constexpr static const char* unit="mole";
    constexpr static const char* abbr="mol";
    constexpr static const int index=3;
    constexpr static const char* quantity="amount_of_substance";
    typedef U<SI,pw<mol,1>> type;
  };

  struct cd
  {
    constexpr static const char* unit="candela";
    constexpr static const char* abbr="cd";
    constexpr static const int index=A::index-1;
    constexpr static const char* quantity="luminous_intensity";
    typedef U<SI,pw<cd,1>> type;
  };

  struct rad
  {
    constexpr static const char* unit="radian";
    constexpr static const char* abbr="rad";
    constexpr static const int index=cd::index-1;
    constexpr static const char* quantity="angle";
    typedef units::U<SI,pw<m,1>,pw<m,-1>> type;
  };

  struct sr
  {
    constexpr static const char* unit="steradian";
    constexpr static const char* abbr="sr";
    constexpr static const int index=rad::index-1;;
    constexpr static const char* quantity="solid angle";
    typedef units::U<SI,pw<m,2>,pw<m,-2>> type;
  };

  struct Hz
  {
    constexpr static const char* unit="hertz";
    constexpr static const char* abbr="Hz";
    constexpr static const int index=sr::index-1;;
    constexpr static const char* quantity="frequency";
    typedef units::U<SI,pw<s,-1>> type;
  };

  struct N
  {
    constexpr static const char* unit="newton";
    constexpr static const char* abbr="N";
    constexpr static const int index=Hz::index-1;
    constexpr static const char* quantity="force";
    typedef units::U<SI,pw<kg,1>,pw<m,1>,pw<s,-2>> type;
  };

  struct Pa
  {
    constexpr static const char* unit="pascal";
    constexpr static const char* abbr="Pa";
    constexpr static const int index=N::index-1;;
    constexpr static const char* quantity="pressure";
    typedef units::U<SI,pw<N,1>,pw<m,-2>> type;
  };

  struct J
  {
    constexpr static const char* unit="joule";
    constexpr static const char* abbr="J";
    constexpr static const int index=Pa::index-1;
    constexpr static const char* quantity="energy";
    typedef units::U<SI,pw<N,1>,pw<m,1>> type;
  };

  struct W
  {
    constexpr static const char* unit="watt";
    constexpr static const char* abbr="W";
    constexpr static const int index=J::index-1;
    constexpr static const char* quantity="power";
    typedef units::U<SI,pw<J,1>,pw<s,-1>> type;
  };

  struct C
  {
    constexpr static const char* unit="coulomb";
    constexpr static const char* abbr="C";
    constexpr static const int index=W::index-1;
    constexpr static const char* quantity="electric_charge";
    typedef units::U<SI,pw<s,1>,pw<A,1>> type;
  };

  struct V
  {
    constexpr static const char* unit="volt";
    constexpr static const char* abbr="V";
    constexpr static const int index=C::index-1;
    constexpr static const char* quantity="voltage";
    typedef units::U<SI,pw<W,1>,pw<A,-1>> type;
  };

  struct F
  {
    constexpr static const char* unit="farad";
    constexpr static const char* abbr="F";
    constexpr static const int index=V::index-1;
    constexpr static const char* quantity="capacitance";
    typedef units::U<SI,pw<C,1>,pw<V,-1>> type;
  };

  struct Ohm
  {
    constexpr static const char* unit="Ohm";
    constexpr static const char* abbr="Ohm";
    constexpr static const int index=F::index-1;
    constexpr static const char* quantity="electrical_resistance";
    typedef units::U<SI,pw<V,1>,pw<A,-1>> type;
  };

  struct S
  {
    constexpr static const char* unit="siemens";
    constexpr static const char* abbr="S";
    constexpr static const int index=Ohm::index-1;
    constexpr static const char* quantity="electrical_conductance";
    typedef units::U<SI,pw<Ohm,-1>> type;
  };

  struct Wb
  {
    constexpr static const char* unit="weber";
    constexpr static const char* abbr="Wb";
    constexpr static const int index=S::index-1;
    constexpr static const char* quantity="magnetic_flux";
    typedef units::U<SI,pw<V,1>,pw<s,1>> type;
  };

  struct T
  {
    constexpr static const char* unit="tesla";
    constexpr static const char* abbr="T";
    constexpr static const int index=Wb::index-1;
    constexpr static const char* quantity="magnetic_flux_density";
    typedef units::U<SI,pw<Wb,1>,pw<m,-2>> type;
  };

  struct H
  {
    constexpr static const char* unit="henry";
    constexpr static const char* abbr="H";
    constexpr static const int index=T::index-1;
    constexpr static const char* quantity="inductance";
    typedef units::U<SI,pw<Wb,1>,pw<A,-1>> type;
  };

  struct Celsius
  {
    constexpr static const char* unit="degree_Celsius";
    constexpr static const char* abbr="ºC";
    constexpr static const int index=H::index-1;
    constexpr static const char* quantity="Celsius_temperature";
    typedef units::U<SI,pw<K,1>> type;
  };

  struct lm
  {
    constexpr static const char* unit="lumen";
    constexpr static const char* abbr="lm";
    constexpr static const int index=Celsius::index-1;
    constexpr static const char* quantity="luminous_flux";
    typedef units::U<SI,pw<cd,1>,pw<sr,1>> type;
  };

  struct lx
  {
    constexpr static const char* unit="lux";
    constexpr static const char* abbr="lx";
    constexpr static const int index=lm::index-1;
    constexpr static const char* quantity="iluminance";
    typedef units::U<SI,pw<m,1>,pw<m,-2>> type;
  };

  struct Bq
  {
    constexpr static const char* unit="becquerel";
    constexpr static const char* abbr="Bq";
    constexpr static const int index=lx::index-1;
    constexpr static const char* quantity="radioactivity";
    typedef units::U<SI,pw<s,-1>> type;
  };

  struct Gy
  {
    constexpr static const char* unit="gray";
    constexpr static const char* abbr="Gy";
    constexpr static const int index=Bq::index-1;
    constexpr static const char* quantity="absorbed_dose_of_radiation";
    typedef units::U<SI,pw<J,1>,pw<kg,-1>> type;
  };

  struct Sv
  {
    constexpr static const char* unit="siervert";
    constexpr static const char* abbr="Sv";
    constexpr static const int index=Gy::index-1;
    constexpr static const char* quantity="equivalent_dose_of_radiation";
    typedef units::U<SI,pw<J,1>,pw<kg,-1>> type;
  };

  struct kat
  {
    constexpr static const char* unit="katal";
    constexpr static const char* abbr="kat";
    constexpr static const int index=Sv::index-1;
    constexpr static const char* quantity="catalytic_activity";
    typedef units::U<SI,pw<mol,1>,pw<s,-1>> type;
  };
};
#endif // SI_H
