#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "romanos.hpp"


TEST_CASE( "Numeros romanos - algarismos �nicos", "[romanos]" ) {
    REQUIRE( romanos_para_decimal("I") == 1 );
    REQUIRE(romanos_para_decimal("V")==5);
    REQUIRE(romanos_para_decimal("X")==10);
    REQUIRE(romanos_para_decimal("L")==50);
    REQUIRE(romanos_para_decimal("C")==100);
    REQUIRE(romanos_para_decimal("D")==500);
    REQUIRE(romanos_para_decimal("M")==1000);
}
TEST_CASE( "Numeros romanos - algarismos inv�lidos", "[romanos]" ) {
    REQUIRE( romanos_para_decimal("G") == -1 );
    REQUIRE(romanos_para_decimal("IXI")==-1);
    REQUIRE(romanos_para_decimal("XVV")==-1);
    REQUIRE(romanos_para_decimal("MMIM")==-1);
    REQUIRE(romanos_para_decimal("XVIV")==-1);
}
TEST_CASE( "Numeros romanos - algarismos validos", "[romanos]" ){
    REQUIRE(romanos_para_decimal("XV")==15);
    REQUIRE(romanos_para_decimal("XIX")==19);
    REQUIRE(romanos_para_decimal("MMM")==3000);
    REQUIRE(romanos_para_decimal("CDXXVII")==427);
    REQUIRE(romanos_para_decimal("DCXXXVII")==637);
    REQUIRE(romanos_para_decimal("MMDI")==2501);
    

}

