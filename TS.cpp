//
// Created by 12514 on 2023/1/29.
//

#include "TS.h"

TS::TS() {
    init();
}

void TS::init() {
    cityMap = {
            {0, 10, 15, 6, 2},
            {10, 0, 8, 13, 9},
            {15, 8, 0, 20, 15},
            {6, 13, 20, 0, 5},
            {2, 9, 15, 5, 0}
    };
    TabuElement tabuElement;
    tabuElement.path = {0, 1, 2, 3, 4};
    tabuElement.value = calculate(tabuElement.path);
    tabuElement.name = "01234";
    tabuElement.epoch = 1;
    tabuList.insert(tabuList.begin() + tabuList.size(), tabuElement);
}

void TS::train() {}

int TS::calculate(vector<int> path) {
    int result = 0;
    for(int i = 0; i < path.size() - 1; i++){
        int front = i, next = i + 1;
        result += cityMap[front][next];
    }
    return result;
}

void TS::tabuSearch() {}

void TS::show() {
    for(int i = 0; i < cityMap.size(); i++){
        for(int j = 0; j < cityMap[i].size(); j++){
            printf("%4d", cityMap[i][j]);
        }
        printf("\n");
    }
    for(int i = 0; i < tabuList.size(); i++){
        printf("value = %d\n", tabuList[i].value);
    }
}