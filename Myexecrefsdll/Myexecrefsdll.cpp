#include <iostream>
#include "Mathfuncsdll.h"

using namespace std;

int main() 
{
    cout << "=== Testing the ModelWindow class with DLL ===\n\n";

    Mathfuncs::ModelWindow win("Main Window", 10, 20, 800, 600, "White", true, true);

    cout << "Initial window state:\n";
    win.Display();

    cout << "\nChanging window position\n";
    win.MoveHorizontal(50);
    win.MoveVertical(100);

    cout << "\nChanging window size\n";
    win.Resize(1024, 768);

    cout << "\nUpdated window state:\n";
    win.Display();

    return 0;
}