#include <iostream>
#include "SA.h"
#include "GA.h"
#include <vector>
using namespace std;

int main() {
//    SA sa;
//    int t = 100;
//    sa.getSA(0, t);
    GA ga = GA(14);
    ga.train(10);
}
