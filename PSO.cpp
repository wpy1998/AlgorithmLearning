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
    for(int i = 0; i < this->particleNumber; i++){
        Particle particle;
        particle.x = random(0, 2);
        particle.y = calculate(particle.x);
        particle.velocity = 0.01 * ((i + 1) % 10);
        particles.insert(particles.begin() + particles.size(), particle);
    }
}

void PSO::train() {
    quickSort();
    for(int i = 0; i < particles.size(); i++){
        printf("x = %f, y = %f, velocity = %f\n", particles[i].x, particles[i].y, particles[i].velocity);
    }
}

void PSO::setParticleNumber(int particleNumber) {
    this->particleNumber = particleNumber;
}

double PSO::calculate(double x) {
    return x * x - x;
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

void PSO::quickSort() {
    int i, j, flag;
    i = 0;
    j = particles.size() - 1;
    flag = 0;
    while (i <= j){
        if (flag == 0){
            if (particles[i].y < particles[j].y){
                Particle temp = particles[i];
                particles[i] = particles[j];
                particles[j] = temp;
                i++;
                flag = 1;
            } else{
                j--;
            }
        } else{
            if (particles[i].y < particles[j].y){
                Particle temp = particles[i];
                particles[i] = particles[j];
                particles[j] = temp;
                j--;
                flag = 0;
            } else{
                i++;
            }
        }
    }
}