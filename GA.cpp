//
// Created by 12514 on 2023/1/25.
//

#include "GA.h"
#include "cmath"
#include "random"

GA::GA() {
    this->init();
}

void GA::train(int epoch) {
    for (int i = 0; i < epoch; ++i) {
        printf("\n#Epoch: %d\n", i);
        update();
        popSort();
        crossOver();
        mutation();
    }
}

void GA::init() {
    printf("------Init------\n");
    int sum = 0;
    for(int i = 0; i < number; i++){
        for (int j = 0; j < 6; ++j) {
            child[i].gene[j] = randomInt(0, 1);
        }
        child[i].fit = calculate(convert(child[i].gene));
        sum += child[i].fit;
    }
    for (int i = 0; i < number; ++i) {
        child[i].rfit = 1.0 * child[i].fit / sum;
        child[i].cfit = 0.0;
    }
    show();
}

void GA::update() {
    printf("------Update------\n");
    for (int i = 0; i < number; ++i) {
        parent[i] = child[i];
    }
    printf("update finished\n");
}

void GA::popSort() {
    printf("------PopSort------\n");
    int i, j;
    Chromosome temp;
    for (i = 0; i < 3; ++i) {
        for(j = 0; j < 3 - i; j++){
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
    int i, mid;
    mid = randomInt(0, 5);
    printf("random = %d\n", mid);
    for(i = 0; i < mid; i++){
        child[2].gene[i] = child[0].gene[i];
        child[3].gene[i] = child[1].gene[i];
    }
    for(i = mid; i < 6; i++){
        child[2].gene[i] = child[1].gene[i];
        child[3].gene[i] = child[0].gene[i];
    }
    for(i = 0; i < number; i++){
        child[i].fit = calculate(convert(child[i].gene));
    }
    show();
}

void GA::mutation() {
    printf("------Mutation------\n");
    int row, col, value, mid;
    mid = randomInt(0, 50);
    printf("random = %d\n", mid);
    if (mid == 25){
        col = randomInt(0, 5);
        row = randomInt(0, 3);
        child[row].gene[col] = (child[row].gene[col] + 1) % 2;
        child[row].fit = calculate(convert(child[row].gene));
        value = calculate(convert(child[row].gene));
        printf("value = %d, row = %d, col = %d\n", value, row, col);
        show();
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
    return - x * x + 1000;
}

void GA::show() {
    for (int i = 0; i < number; ++i) {
        printf("parent[%d]: ", i);
        for (int j = 0; j < 6; ++j) {
            printf("%d", parent[i].gene[j]);
        }
        printf(", fit = %d, rfit = %f, cfit = %f\n", parent[i].fit,
               parent[i].rfit, parent[i].cfit);
    }
    for(int i = 0; i < number; i++){
        printf("child[%d]: ", i);
        for (int j = 0; j < 6; ++j) {
            printf("%d", child[i].gene[j]);
        }
        printf(", fit = %d, rfit = %f, cfit = %f\n", child[i].fit,
               child[i].rfit, child[i].cfit);
    }
}