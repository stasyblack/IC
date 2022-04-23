#pragma once
#include <iostream>
#include "commandStrategy.h"
using namespace std;
class ConsoleControler : public commandStrategy
{
public:
    void getCommand();
};