#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;


double f1(int x)
{
    return pow(x, 4) - 3 * x - 20;
}

bool Check(int a) {
    for (int i = 1; i <= a; i++) { if (a == i * (i + 1) / 2) return true; }
    return false;
}

int _Menu(int vbr) {

    cout << "=========================" << endl;

    if (vbr == 1) {
        cout << "1) Задание 1!" << endl;
        cout << "2) Задание 2!" << endl;
    }

    if (vbr == 2) {

    }

    cout << "=========================" << endl;

    cin >> vbr;
    return vbr;
}


void _Proverka(int a) {
    int sum = 0, schet = 0;
    for (int i = 1; i <= a; i++)
    {
        if (Check(i) == true && schet <= 3 && (sum + i * (i + 1) / 2) <= a) {
            sum += i * (i + 1) / 2;
            schet++;
        }
    }
    if (schet == 3 && sum == a) cout << "Число выполняет условие!" << endl;
    else cout << "Число условие не выполняет!";
}


int _findF1(int a, int b, int ep) {
    int touch;
    while ((b - a) / 2 > ep) {
        touch = (a + b) / 2;
        if ((f1(a) * f1(touch)) > 0) a = touch;
        else b = touch;
    }
    return touch;
}

void _Graf(int N, int M) {

        int const length = M-N; //абцисса (x)

        int const width = 23;  //ордината (y)

        char** scene = new char*[length*2]; // оси ординат делаем в 2 раза больше (под отрицательные значения)
        for (int i = 0; i < length * 2; i++) scene[i] = new char[width * 2];  //создание матрицы
        
            
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
                scene[x + length / 2][(int)round(y + width)] = '*'; // ставим точку

        }

        //вывод на экран
        for (int y = width * 2-1; y >= 0; y--) {
            for (int x = 0; x < length; x++) {
                if(x == length / 2) cout << abs(y - width);
                cout << scene[x][y];
            }
            cout << endl;
        }
}




int main()
{
    setlocale(LC_CTYPE, "Rus");
    int menu = _Menu(1);
    system("cls");
    int x = 0;
   
    switch (menu)
    {
    case 1: {

        int a, b; // интервал от a до b
        cin >> a >> b;

        int ep; // эпсилент
        cin >> ep; 

        int touch = _findF1(a, b, ep);  //Точка 

        cout << touch << endl;

        for (int i = 0; i < b; i++)cout << "="; //Красиииивое
        cout << endl;
        _Graf(a, b);
        break;
    }
    case 2: {
        int a;
        cin >> a;
        _Proverka(a);
        break;
    }
    default:
        cout << "неверный символ!";
        break;
    }

    

}
