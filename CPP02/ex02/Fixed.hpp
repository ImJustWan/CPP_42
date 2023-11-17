#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
public:
    Fixed(void);
    Fixed(int const n);
    Fixed(float const f);
    Fixed(Fixed const &src);
    ~Fixed(void);

    Fixed &operator=(Fixed const &rhs);

    Fixed operator+(Fixed const &rhs) const;
    Fixed operator-(Fixed const &rhs) const;
    Fixed operator*(Fixed const &rhs) const;
    Fixed operator/(Fixed const &rhs) const;

    Fixed &operator++();       // prefix increment
    Fixed operator++(int);     // postfix increment

    int getRawBits(void) const;
    void setRawBits(int const raw);
    int toInt(void) const;
    float toFloat(void) const;

    static Fixed max(Fixed const &a, Fixed const &b);

private:
    int _n;
    static const int _rawBits = 8;
};
std::ostream &operator<<(std::ostream &o, Fixed const &i);


#endif