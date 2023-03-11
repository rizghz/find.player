#pragma once

#include <iostream>
#include <cmath>

template <typename T>
struct Vec {
    T x;
    T y;
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const Vec<T>& v) {
    out << "[" << v.x << ", " << v.y << "]";
    return out;
}

template <typename T>
bool operator==(const Vec<T> v, const Vec<T> w) {
    return (v.x == w.x and v.y == w.y);
}

template <typename T>
bool operator!=(const Vec<T> v, const Vec<T> w) {
    return (v.x != w.x and v.y != w.y);
}

template <typename T>
float norm(const Vec<T> v, const Vec<T> w) {
    return std::sqrt(std::pow(w.x - v.x, 2) + std::pow(w.y - v.y, 2));
}
