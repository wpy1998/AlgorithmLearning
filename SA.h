//
// Created by 12514 on 2022/12/31.
// 模拟退火算法
//

#ifndef GAME_SA_H
#define GAME_SA_H


class SA {
public:
    double delta = 0.98, Tmin = 1e-8;
    int k = 100;

    double getE(double x);
    double random(int begin, int last);
    double getSA(int begin, int last);
    void setK(int k){
        this->k = k;
    }
    void setDelta(double delta){
        this->delta = delta;
    }
};


#endif //GAME_SA_H
