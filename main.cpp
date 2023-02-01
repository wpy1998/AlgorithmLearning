#include <iostream>
#include "SA.h"
#include "GA.h"
#include "TS.h"
#include "PSO.h"
using namespace std;

int main() {
//    SA sa;
//    int t = 100;
//    sa.getSA(0, t);

    GA ga = GA(6);
    ga.train(1);

//    TS ts;
//    ts.show();

//    PSO pso = PSO(5);
//    pso.train();
}
