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
        double x, y, velocity;
    };
public:
    PSO();
    PSO(int particleNumber);
    void setParticleNumber(int particleNumber);
    void train();
private:
    int particleNumber;
    vector<Particle> particles;
    void init();
    void quickSort();
    double calculate(double x);
    double random(double begin, double last);
};


#endif //ALGORITHMLEARNING_PSO_H
