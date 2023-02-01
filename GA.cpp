//
// Created by 12514 on 2023/1/25.
//

#include "GA.h"
#include "cmath"
#include "random"

GA::GA() {
    this->number = 4;
    this->init();
}

GA::GA(int number) {
    int mid = number;
    if(number % 4 != 0){
        mid = number + 4 - number % 4;
    }
    this->number = mid;
    this->init();
}

void GA::init() {
    printf("------Init------\n");
    int sum = 0;
    for(int i = 0; i < number; i++){
        Chromosome par, chi;
        for (int j = 0; j < 6; ++j) {
            chi.gene[j] = randomInt(0, 1);
        }
        chi.fit = calculate(convert(chi.gene));
        sum += chi.fit;
        parent.insert(parent.begin() + parent.size(), par);
        child.insert(child.begin() + child.size(), chi);
    }
    show();
}

void GA::train(int epoch) {
    for (int i = 0; i < epoch; i++) {
        printf("\n#Epoch: %d\n", i);
        update();
        select();
        crossOver();
        mutation();
        show();
    }
}

void GA::update() {
    printf("------Update------\n");
    int sum = 0;
    for(int i = 0; i < number; i++){
        child[i].fit = calculate(convert(child[i].gene));
        sum += child[i].fit;
    }
    for (int i = 0; i < number; i++) {
        parent[i] = child[i];
    }
    printf("update finished\n");
}

void GA::select() {
    printf("------select------\n");
    quickSort();
    int i, j;
    Chromosome temp;
    for (i = 0; i < number - 1; i++) {
        for(j = 0; j < number - 1 - i; j++){
            if (parent[j + 1].fit > parent[j].fit){
                temp = parent[j + 1];
                parent[j + 1] = parent[j];
                parent[j] = temp;
            }
        }
    }
    for(i = 0; i < number; i++){
        child[i] = parent[i];
    }
    show();
}

void GA::crossOver() {
    printf("------CrossOver------\n");
    int i, j, mid;
    mid = randomInt(0, 5);
    printf("random = %d\n", mid);
    for(i = 0; i < number / 2; i++){
        for(j = 0; j < mid; j++){
            child[number / 2 + 2 * i].gene[j] = child[i * 2].gene[j];
            child[number / 2 + 2 * i + 1].gene[j] = child[i * 2 + 1].gene[j];
        }
        for(j = mid; j < 6; j++){
            child[number / 2 + 2 * i].gene[j] = child[i * 2 + 1].gene[j];
            child[number / 2 + 2 * i + 1].gene[j] = child[i * 2].gene[j];
        }
    }
    for(i = 0; i < number; i++){
        child[i].fit = calculate(convert(child[i].gene));
    }
//    show();
}

void GA::mutation() {
    printf("------Mutation------\n");
    int row, col, value;
    double mid;
    mid = random(0, 1);
    printf("random = %f\n", mid);
    if (mid > mutation_prob){
        col = randomInt(0, 5);
        row = randomInt(0, number - 1);
        child[row].gene[col] = (child[row].gene[col] + 1) % 2;
        child[row].fit = calculate(convert(child[row].gene));
        value = calculate(convert(child[row].gene));
        printf("value = %d, row = %d, col = %d\n", value, row, col);
//        show();
    }
}

void GA::setMutationProb(double prob) {
    mutation_prob = prob;
}

void GA::quickSort() {
    int i = 0, j = number - 1, flag = 0;
    Chromosome temp;
    while (i < j){
        if (flag == 0){
            if (child[i].fit < child[j].fit){
                temp = child[i];
                child[i] = child[j];
                child[j] = temp;
                i++;
                flag = 1;
            } else{
                j--;
            }
        } else{
            if (child[i].fit < child[j].fit){
                temp = child[i];
                child[i] = child[j];
                child[j] = temp;
                j--;
                flag = 0;
            } else{
                i++;
            }
        }
    }
}

double GA::random(double lower, double upper) {
    int mid = lower;
    if (upper < lower){
        lower = upper;
        upper = mid;
    }
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(lower, upper);
    return dist(mt);
}

int GA::randomInt(int lower, int upper) {
    int mid = lower;
    if (upper < lower){
        lower = upper;
        upper = mid;
    }
    int result = this->random(lower, upper + 1);
    return result;
}

int GA::convert(short *gene) {
    int result = 0;
    for(int i = 1; i < 6; i++){
        result = result * 2 + gene[i];
    }
    if (gene[5] == 1) result = - result;
    return result;
}

short* GA::convert(int value) {
    static short result[6];
    int mid;
    if (value >= 0){
        result[0] = 0;
        mid = value;
    } else{
        result[0] = 1;
        mid = - value;
    }
    for(int i = 5; i > 0; i--){
        result[i] = mid % 2;
        mid = mid / 2;
    }
    return result;
}

int GA::calculate(int x) {
    return - x * x + 2 * x + 1000;
}

void GA::show() {
//    for (int i = 0; i < number; i++) {
//        printf("parent[%d]: ", i);
//        for (int j = 0; j < 6; j++) {
//            printf("%d", parent[i].gene[j]);
//        }
//        printf(", fit = %d, rfit = %f, cfit = %f\n", parent[i].fit,
//               parent[i].rfit, parent[i].cfit);
//    }
    for(int i = 0; i < number; i++){
        printf("child[%d]: ", i);
        for (int j = 0; j < 6; j++) {
            printf("%d", child[i].gene[j]);
        }
        printf(", fit = %d\n", child[i].fit);
    }
}