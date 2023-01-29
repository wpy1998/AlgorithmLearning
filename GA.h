//
// Created by 12514 on 2023/1/25.
//

#ifndef ALGORITHMLEARNING_GA_H
#define ALGORITHMLEARNING_GA_H


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
    Chromosome parent[4], child[4];
    void init();
    void popSort();
    void crossOver();
    void mutation();
    void update();
    int convert(short gene[]);
    short* convert(int value);
    double random(double lower, double upper);
    int randomInt(int lower, int upper);
    int calculate(int x);
    void train(int epoch);
    void show();
private:
    int number = 4;
};


#endif //ALGORITHMLEARNING_GA_H
