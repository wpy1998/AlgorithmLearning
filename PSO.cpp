//
// Created by 12514 on 2023/2/1.
//

#include "PSO.h"

PSO::PSO() {
    this->particleNumber = 2;
    init();
}

PSO::PSO(int particleNumber) {
    this->particleNumber = particleNumber;
    init();
}

void PSO::init() {
    particles.clear();
    velocityMax = 0.1;
    globalBest = - 100000;
    for(int i = 0; i < this->particleNumber; i++){
        Particle particle;
        particle.x = random(0, 2);
        particle.y = calculate(particle.x);
        particle.partialBest = particle.y;
        particle.velocity = random(0, 0.1);
        particles.insert(particles.begin() + particles.size(), particle);
    }
}

void PSO::train() {
    globalBest = select();
    for(int i = 0; i < epoch; i++){
        double w = 0.4, w1, w2;
        for(int j = 0; j < particleNumber; j++){
            w1 = random(0, 1);
            w2 = random(0, 1);
            particles[j].velocity = w * particles[j].velocity +
                    c1 * w1 * (particles[j].partialBest - particles[j].y) +
                    c2 * w2 * (globalBest - particles[j].y);
            if (particles[j].velocity > velocityMax){
                particles[j].velocity = velocityMax;
            }
            if (particles[j].velocity < - velocityMax){
                particles[j].velocity = - velocityMax;
            }
            particles[j].x += particles[j].velocity;
            if (particles[j].x > 2){
                particles[j].x = 2;
            }
            if (particles[j].x < 0){
                particles[j].x = 0;
            }
        }

        for (int j = 0; j < particleNumber; ++j) {
            particles[j].y = calculate(particles[j].x);
            particles[j].partialBest = getMax(particles[j].y, particles[j].partialBest);
            globalBest = getMax(globalBest, particles[j].partialBest);
        }
        printf("epoch: %d, best fitness = %f\n", i, globalBest);
    }
}

double PSO::random(double begin, double last) {
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

double PSO::select() {
    double result = particles[0].y;
    for (int i = 0; i < particleNumber; ++i) {
        if (particles[i].y > result){
            result = particles[i].y;
        }
    }
    return result;
}

void PSO::setParticleNumber(int particleNumber) {
    this->particleNumber = particleNumber;
}

void PSO::setC1(double c1) {
    this->c1 = c1;
}

void PSO::setC2(double c2) {
    this->c2 = c2;
}

void PSO::setEpoch(int epoch) {
    this->epoch = epoch;
}

double PSO::calculate(double x) {
    return x * x - x;
}

double PSO::getMax(double a, double b) {
    return a > b ? a : b;
}