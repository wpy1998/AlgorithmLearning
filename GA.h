//
// Created by 12514 on 2023/1/25.
//

#ifndef ALGORITHMLEARNING_GA_H
#define ALGORITHMLEARNING_GA_H
#include "vector"
#include "iostream"

using namespace std;

class GA {
    class Chromosome{
    public:
        short gene[6];
        int fit;
        double rfit;
        double cfit;
    };
public:
    GA();
    GA(int number);
    void train(int epoch);
    void setMutationProb(double prob);
    void show();
private:
    int number = 4;
    double mutation_prob = 0.2;
    vector<Chromosome> parent, child;
    void init();
    void update();
    void select();
    void crossOver();
    void mutation();

    double random(double lower, double upper);
    int randomInt(int lower, int upper);
    int calculate(int x);
    void quickSort();
    int convert(short gene[]);
    short* convert(int value);
};


#endif //ALGORITHMLEARNING_GA_H
