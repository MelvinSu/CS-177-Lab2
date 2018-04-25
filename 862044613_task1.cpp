//melvin Su
//862044613

#include <cpp.h>

facility *f;

void customer();

extern "C" void sim() //creator
{
    create("sim");
    f = new facility("Joe");
    reseed(NIL,15);

    while(simtime() < 480) {
        hold(uniform(12,23));
        customer();
        }
    report();
}

void customer() //customer
{
    create("customer");
    f->use(uniform(12, 19));
}
