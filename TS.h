//
// Created by 12514 on 2023/1/29.
//

#ifndef ALGORITHMLEARNING_TS_H
#define ALGORITHMLEARNING_TS_H
#include "iostream"
#include "string"
#include "vector"
#include "time.h"

using namespace std;

class TS {
    class TabuElement{
    public:
        vector<int> path;
        int value, epoch;
        string name;
    };
public:
    TS();
    void init();
    void train();
    void show();
private:
    vector<vector<int>> cityMap;
    vector<TabuElement> tabuList;
    vector<vector<double>> delta;
    vector<bool> vis;
    void tabuSearch();
    int calculate(vector<int> path);
};


#endif //ALGORITHMLEARNING_TS_H
