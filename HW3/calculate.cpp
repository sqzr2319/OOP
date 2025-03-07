#include"calculate.hpp"
#include<cmath>

double triangle::c(double a){
    return 3*a;
}

double triangle::s(double a){
    return a*a*sqrt(3)/4;
}

double square::c(double a){
    return 4*a;
}

double square::s(double a){
    return a*a;
}

double pentagon::c(double a){
    return 5*a;
}

double pentagon::s(double a){
    return 1.7204774*a*a;
}

double hexagon::c(double a){
    return 6*a;
}

double hexagon::s(double a){
    return 2.5980762*a*a;
}

double circle::c(double a){
    return 2*3.1415926*a;
}

double circle::s(double a){
    return 3.1415926*a*a;
}