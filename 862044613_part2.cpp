#include <cpp.h>
#include <cmath>

facility_set *gas_pumps;

void car_gen();
const int MEAN = 50;
const int NUM_OF_PUMPS = 10;

using namespace std;

extern "C" void sim()
{
    reseed(NIL, 2);
    create("sim");
    gas_pumps = new facility_set("Gas Pump", 10);
    while (simtime() < 10000.0) {
        hold(-MEAN * log (uniform(0,1)));
        car_gen();
        }
    report();
}

void car_gen()
{
    create("Car");
    int i = 0;
    int pump_length[NUM_OF_PUMPS];
    int select = uniform(0,NUM_OF_PUMPS);
    double localLitresNeeded = 10 + uniform(0,1) * 50;
//    for (int j = 0; j < NUM_OF_PUMPS; j++)
//        pump_length[j] = (*gas_pumps)[j].qlength();
//        i++;
//    for (int j = 1; j < NUM_OF_PUMPS; j++)
//        if (pump_length[select] > pump_length[j])
//            select = j;
    if ((*gas_pumps)[select].qlength() > 0 && uniform(0,1) > (40 + localLitresNeeded) / 
(25 * (3 + (*gas_pumps)[select].qlength())))
        return;
    (*gas_pumps)[select].use(150 + 0.5 * localLitresNeeded + 30 * normal(0,1));
    //(*gas_pumps)[i].use(1);
}
