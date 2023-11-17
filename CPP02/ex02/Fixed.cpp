#include "Fixed.hpp"

Fixed::Fixed(void) : _n(0) {
    return;
}

Fixed::Fixed(int const n) : _n(n << _rawBits) {
    return;
}

Fixed::Fixed(float const f) : _n(static_cast<int>(f * (1 << _rawBits) + ((f < 0) ? -0.5f : 0.5f))) {
    return;
}

Fixed::Fixed(Fixed const &src) : _n(src._n) {
    *this = src;
    return;
}

Fixed::~Fixed(void) {
    return;
}

int Fixed::getRawBits(void) const {
    return this->_n;
}

void Fixed::setRawBits(int const raw) {
    this->_n = raw;
}

int Fixed::toInt(void) const {
    return this->_n >> (_rawBits - 1);
}

float Fixed::toFloat(void) const {
    return static_cast<float>(this->_n) / (1 << _rawBits);
}

std::ostream &operator<<(std::ostream &o, Fixed const &i) {
    o << i.toFloat();
    return o;
}

Fixed &Fixed::operator=(Fixed const &n) {
    this->_n = n.getRawBits();
    return *this;
}

Fixed Fixed::operator+(Fixed const &rhs) const {
    return Fixed(this->_n + rhs.toFloat() * (1 << _rawBits));
}

Fixed Fixed::operator-(Fixed const &rhs) const {
    return Fixed(this->_n - rhs.toFloat() * (1 << _rawBits));
}

Fixed Fixed::operator*(Fixed const &rhs) const {
    long long result = static_cast<long long>(this->_n) * rhs.getRawBits();
    result = (result + (1LL << (_rawBits - 1))) / (1LL << _rawBits);
    return Fixed(static_cast<float>(result) / (1 << _rawBits));
}


Fixed Fixed::operator/(Fixed const &rhs) const {
    return Fixed(static_cast<float>(this->_n) / rhs.getRawBits());
}

Fixed &Fixed::operator++() {
    ++this->_n;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    ++(*this);
    return temp;
}

Fixed Fixed::max(Fixed const &a, Fixed const &b) {
    return (a.toFloat() > b.toFloat()) ? a : b;
}