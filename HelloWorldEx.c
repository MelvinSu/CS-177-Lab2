#include <iostream>
#include "cpp.h"
#include <string>

using namespace std;

extern "C" void sim()
{
    int i;
    create("sim");
    for(i=1;i<10;i++)
    {
        cout << "Alice says hello " << i << " times." << endl;
    }
}
