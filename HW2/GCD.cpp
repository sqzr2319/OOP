#include"GCD.hpp"

long long GCD::calculate(long long a, long long b){
    if(b == 0){
        return a;
    }
    return calculate(b, a % b);
}