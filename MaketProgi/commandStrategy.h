#pragma once
#include <iostream>
using namespace std;
class commandStrategy
{
    virtual void getCommand()
    {
        cout << "commandStrategy" << endl;
    }
};
