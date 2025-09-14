#pragma once
struct Color{
    unsigned char r = 0, g = 0, b = 0;
    Color() : r(0), g(0), b(0){}
    Color(unsigned char new_r, unsigned char new_g, unsigned char new_b) : r(new_r), g(new_g), b(new_b) {} 
};