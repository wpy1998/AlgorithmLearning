//
// Created by 12514 on 2023/2/1.
// 粒子群算法
//

#ifndef ALGORITHMLEARNING_PSO_H
#define ALGORITHMLEARNING_PSO_H
#include "iostream"
#include "string"
#include "vector"
#include "random"

using namespace std;

class PSO {
    class Particle{
    public:
        double x, y, velocity, partialBest;
    };
public:
    PSO();
    PSO(int particleNumber);
    void setParticleNumber(int particleNumber);
    void setEpoch(int epoch);
    void setC1(double c1);
    void setC2(double c2);
    void train();
private:
    int particleNumber, epoch = 1;
    double c1 = 2, c2 = 2, velocityMax, globalBest;
    vector<Particle> particles;

    void init();
    double select();
    double calculate(double x);
    double random(double begin, double last);
    double getMax(double a, double b);
};


#endif //ALGORITHMLEARNING_PSO_H
