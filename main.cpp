//------------------------------
//  DO NOT MODIFY NEXT LINE
//------------------------------
#include "catch.hpp"
//------------------------------

// Write the assignment code here
class Real{
protected:
  float realnum{0};
public:
  Real(float coefone){
    realnum = coefone;
  }
  float GetReal(){
    return realnum;
  }
  Real operator+(const float& b){
    realnum += b;
    return *this;
  }
};
class Complex: public Real{
protected:
  float compnum{0};
public:
  Complex(float coefone, float coeftwo): Real(coefone){
    compnum = coeftwo;
  }
  float GetImaginary(){
    return compnum;
  }
  Complex operator+(const float& c){
    compnum += c;
    realnum += c;
    return *this;
  }
};
class Surreal: public Complex{
  float surnum{0};
public:
  Surreal(float coefone, float coeftwo, float coefthree): Complex(coefone, coeftwo){
    surnum = coefthree;
  }
  float GetSurreal(){
    return surnum;
  }
  Surreal operator+(const float& d){
    surnum += d;
    realnum += d;
    compnum += d;
    return *this;
  }
};
//------------------------------
//   DO NOT MODIFY TEST CASES
//------------------------------
TEST_CASE( "Assignment" ) {
    SECTION( "c1" ) {
        Real n{10.0};
        REQUIRE( n.GetReal() == 10.0 );
    }
    SECTION( "c2" ) {
        Complex n{10.0, 20.0};
        REQUIRE( n.GetReal() == 10.0 );
        REQUIRE( n.GetImaginary() == 20.0 );
    }
    SECTION( "c3" ) {
        Surreal n{10.0, 20.0, 30.0};
        REQUIRE( n.GetReal() == 10.0 );
        REQUIRE( n.GetImaginary() == 20.0 );
        REQUIRE( n.GetSurreal() == 30.0 );
    }
    SECTION( "a1" ) {
        Real n{10.0};
        Real r = n + 2.0;
        REQUIRE( r.GetReal() == 12.0 );
    }
    SECTION( "a2" ) {
        Complex n{10.0, 20.0};
        Complex r = n + 2.0;
        REQUIRE( r.GetReal() == 12.0 );
        REQUIRE( r.GetImaginary() == 22.0 );
    }
    SECTION( "a3" ) {
        Surreal n{10.0, 20.0, 30.0};
        Surreal r = n + 2.0;
        REQUIRE( r.GetReal() == 12.0 );
        REQUIRE( r.GetImaginary() == 22.0 );
        REQUIRE( r.GetSurreal() == 32.0 );
    }
}
//------------------------------
