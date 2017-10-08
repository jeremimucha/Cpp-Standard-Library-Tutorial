// Chapter 17 Numerics
#include <random>
#include <iostream>
#include <sstream>


void printNumbers( std::default_random_engine& dre )
{
    for( int i=0; i<6; ++i ){
        std::cout << dre() << " ";
    }
    std::cout << std::endl;
}


int main()
{
    // create engine and generate numbers
    std::default_random_engine dre;
    printNumbers( dre );

    // create equal engine and generate numbers
    std::default_random_engine dre2;    // same initial state as dre
    printNumbers( dre2 );

    // create engine with initial state specified by a seed
    std::default_random_engine dre3( 42 );
    printNumbers( dre3 );

    // save state of engine dre
    std::stringstream engineState;
    engineState << dre;

    // generate numbers acording to current state of dre
    printNumbers( dre );

    // restore saved state of engine dre and create numbers again
    engineState >> dre;
    printNumbers( dre );

    // restore saved state of engine dre, skip 2 numbers and create numbers
    engineState.clear();        // clear EOF bit
    engineState.seekg(0);       // and move read position to the beginning
    engineState >> dre;
    dre.discard(2);
    printNumbers(dre);
}
