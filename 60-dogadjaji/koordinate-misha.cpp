#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;

int main()
{
    INPUT_RECORD rec;
    DWORD evk;
    HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);
    int x_pos, y_pos;

    while (true)
    {
        SetConsoleMode(hIn, ENABLE_MOUSE_INPUT);
        ReadConsoleInput(hIn, &rec, 1, &evk);
        system("cls");

        if (rec.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
            cout << "Levo dugme pritisnuto";
            continue;
        }

        if (rec.Event.MouseEvent.dwButtonState == FROM_LEFT_2ND_BUTTON_PRESSED) {
            cout << "Srednje dugme pritisnuto";
            continue;
        }

        x_pos = rec.Event.MouseEvent.dwMousePosition.X;
        y_pos = rec.Event.MouseEvent.dwMousePosition.Y;
        cout << x_pos << " " << y_pos;
    }
}
