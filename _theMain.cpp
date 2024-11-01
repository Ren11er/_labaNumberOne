#include <cstdlib>
#include <iostream>
using namespace std;


int _Menu(int vbr) {

    cout << "=========================" << endl;

    if (vbr == 1) {
        cout << "1) Задание 1!" << endl;
        cout << "1) Задание 2!" << endl;
    }

    if (vbr == 2) {

    }

    cout << "=========================" << endl;

    cin >> vbr;
    return vbr;
}



int main()
{
    int menu = _Menu(1);
    system("cls");
}
