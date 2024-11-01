#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;


double f1(int x)
{
    return pow(x,4) - 3*x - 20;
}




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

int x = 1;

void _Graf() {

        int const length = 30; //абцисса (x)

        int const width = 30;  //ордината (y)

        char scene[length*2][width * 2]; // оси ординат делаем в 2 раза больше (под отрицательные значения)

        //Создание графика и его прорисовка
        for (int x = 0; x < length; x++) {
            for (int y = 0; y < width * 2; y++)
                scene[x][y] = '.';
            scene[x][width] = '-'; // это будет линия x
        }

        //Прорисовка функции на графике
        for (int x = 0 - length; x < length; x++) {
            double y = f1(x); // функция      
            if (abs(y) < width) // проверяем чтобы значение за пределы не выходило
                scene[x + length/2+1][(int)round(y - width)] = '*'; // ставим точку

        }

        //вывод на экран
        for (int y = width * 2; y >= 0; y--) {
            for (int x = 0; x < length; x++) {
                if(x == length / 2) cout << abs(y - width);
                cout << scene[x][y];
            }
            cout << endl;
        }
}




int main()
{
    int menu = _Menu(1);
    system("cls");
    int x = 0;
   
    cout << "====================" << endl;
    _Graf();
    cout << "====================" << endl;

}
