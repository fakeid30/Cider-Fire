#include <iostream>
#include "Screen.h"

using namespace std;
using namespace ciderFireNamespace;

int main() {

    Screen screen;

    if (screen.init() == false) {
        cout << "Error" << endl;
    }


    while (true) {
//        Update particles
//        Draw particles

        if (screen.processEvents() == false) {
            break;
        }
    }

    screen.close();

    return 0;
}
