#include <iostream>
#include "repoSTL.h"
#include "ui.h"
#include "teste.h"
using namespace std;
int main()
{
    TestServiceTemplate ts;
    ts.runTests();
    UI ui;
    ui.run();
    return 0;
}