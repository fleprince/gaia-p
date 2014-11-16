/*
 * main.cpp
 * Copyright (C) 2014 Florian Leprince <floleprince@gmail.com>
 *
 * Distributed under terms of the GNU GPL V2 license.
 */

#include <iostream>
#include "Planet.h"

// debug directives

using namespace std;
using namespace Gaia;

int main()
{
    Planet* earth = new Planet();
    cout << "earth contains " << earth->GetNPoints() << " points." << endl;
    return 0;
}
