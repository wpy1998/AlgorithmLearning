//
// Created by wpy on 23-2-6.
//

#include <random>
#include "BAS.h"

double BAS::random(int begin, int last) {
    int mid = begin;
    if (last < begin){
        begin = last;
        last = mid;
    }
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(begin, last);
    return dist(mt);
}