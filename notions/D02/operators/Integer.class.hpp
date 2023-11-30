#pragma once

#include <iostream>

class Integer {

public:
    Integer( int const n );
    ~Integer( void );

    int getValue( void ) const;

    Integer &   operator=( Integer const & rhs); //right hand side
    Integer     operator+( Integer const & rhs) const;

private:

    int _n;
};

std::ostream & operator <<( std::ostream & o, Integer const & rhs );

