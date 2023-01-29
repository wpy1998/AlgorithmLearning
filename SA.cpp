//
// Created by 12514 on 2022/12/31.
//

#include "SA.h"
#include "cmath"
#include "random"

double SA::getE(double x) {
    return 6 * pow(x, 7) + 8 * pow(x, 6) + 7 * pow(x, 3) +
    5 * pow(x, 2) - x * 13;
}

double SA::random(int begin, int last) {
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

double SA::getSA(int begin, int last) {
    int mid = begin;
    if (last < begin){
        begin = last;
        last = mid;
    }
    double result = 1.7976931348623157E308, t = last, x[k];
    for (int i = 0; i < k; i++) {
        x[i] = random(begin, last);
    }
    while (t > Tmin){
        for(int i = 0; i < k; i++){
            double funTmp = getE(x[i]);
            double x_new = x[i] + (random(0, 1) * 2 - 1) * t;
            if (x_new >= begin && x_new <= last){
//                printf("x[%d] = %f, FunTmp = %f, x_new = %f\n",
//                       i, x[i], funTmp, x_new);
                double funTmp_new = getE(x_new);
                if (funTmp_new - funTmp < 0){
                    x[i] = x_new;
                }else{
                    double p = 1 / (1 + exp(- (funTmp_new - funTmp) / last));
                    double rp = random(0, 1);
//                    printf("funTmp_new - funTmp = %f, rp = %f, p = %f\n",
//                           (funTmp_new - funTmp) / last, rp, p);
                    if (rp < p){
                        x[i] = x_new;
                    }
                }
            }
        }
//        system("Pause");
        t = t * delta;
    }
    for (int i = 0; i < k; i++) {
        result = std::min(result, getE(x[i]));
    }
    printf("result = %f\n", result);
}