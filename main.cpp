#include <iostream>
#include <string>
#include <windows.h>

using namespace std;
#define delay 0
bool result = false;
const std::string tittle = "*** BAI 2.1 : BAI TOAN MA DI TUAN ***\n";

// di theo chieu kim dong ho
// int a[8] = { 2, 2, 1, -1, -2, -2, -1, 1 };
// int b[8] = { 1, -1, -2, -2, -1, 1, 2, 2 };
// di theo chieu nguoc chieu kim dong ho
int a[8] = {2, 2, 1, -1, -2, -2, -1, 1};
int b[8] = {1, -1, -2, -2, -1, 1, 2, 2};

void getinput(int&, int&, int&);
void initChessBoard(int**, int, int, int);
void drawchessboard(int);
void moveknight(int**, int, int, int, int);
void gotoxy(int, int);
void settextcolor(int);

int main()
{
    settextcolor(6);
    cout << tittle;
    int sizeOfChessBoard, xPosition, yPosition;

    getinput(sizeOfChessBoard, xPosition, yPosition);

    int** chessBoard = new int*[sizeOfChessBoard + 1];
    initChessBoard(chessBoard, sizeOfChessBoard, xPosition, yPosition);
    drawchessboard(sizeOfChessBoard);

    gotoxy(2 + sizeOfChessBoard * 4, 6);
    cout << "Buoc di hien tai cua quan ma la :";
    gotoxy(0, 4);
    cout << "Quan ma dang di chuyen...";
    settextcolor(14);
    moveknight(chessBoard, xPosition - 3, yPosition - 2, 1, sizeOfChessBoard);
    gotoxy(0, 4);

    cout << "Quan ma da di chuyen xong\n";
    gotoxy(0, 7 + sizeOfChessBoard * 2);
    settextcolor(7);
    cout << "Ket qua: ";
    if (result == false)
    {
        settextcolor(12);
        cout << "Khong co cach di chuyen nao di het ban co\n";
    }
    else
    {
        settextcolor(10);
        cout << "Da di het " << sizeOfChessBoard * sizeOfChessBoard << " buoc\n\n";
    }

    delete[] chessBoard;
    settextcolor(7);
    system("pause");
    return 0;
}

/******************************************************************************************************/

void getinput(int& sizeOfChessBoard, int& xPosition, int& yPosition)
{
    bool accept = false;
    do
    {
        cout << "Nhap kich thuoc ban co: ";
        cin >> sizeOfChessBoard;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(32767, '\n');
        }

        if (sizeOfChessBoard > 10)
        {
            cout << "Canh bao: Kich thuoc ban co qua lon, co the lam cham chuong trinh\n"
                 << "Ban co chac chan muon tiep tuc khong? (Y/N): ";

            std::string choice;
            cin.ignore();
            getline(cin, choice);

            auto isYes = choice.find("Y") != std::string::npos || choice.find("y") != std::string::npos;

            if (!isYes)
            {
                cout << "Nhap lai kich thuoc ban co: ";
                cout << "\b";
                continue;
            }

            break;
        }

        if (sizeOfChessBoard < 1)
        {
            cout << "Kich thuoc ban co khong hop le\n";
        }

        accept = sizeOfChessBoard >= 1;
    } while (!accept);

    accept = false;
    do
    {
        cout << "Nhap toa do a, b de bat dau (a,b) : ";
        cin >> xPosition >> yPosition;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(32767, '\n');
        }
        accept = xPosition >= 1 && xPosition <= sizeOfChessBoard && yPosition >= 1 && yPosition <= sizeOfChessBoard;
        if (!accept)
        {
            cout << "Toa do khong hop le\n";
        }
    } while (!accept);
    system("cls");
}
void moveknight(int** chessBoard, int x, int y, int n, int N)
{
    for (int i = 0; i <= 7; i++)
    {
        int u = x + a[i];
        int v = y + b[i];
        if (u >= 0 && u < N && v >= 0 && v < N && chessBoard[u][v] == 0)
        {
            chessBoard[u][v] = n;
            gotoxy(1 + u * 4, 6 + v * 2);
            Sleep(delay);
            cout << n;
            gotoxy(36 + N * 4, 6);
            cout << n;
            if (n == N * N)
            {
                result = true;
            }
            if (result == false)
            {
                moveknight(chessBoard, u, v, n + 1, N);
            }
            if (result == true)
            {
                return;
            }
            chessBoard[u][v] = 0;
            gotoxy(1 + u * 4, 6 + v * 2);
            Sleep(delay);
            cout << "  ";
        }
    }
}

void settextcolor(int x)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
}

void gotoxy(int a, int b)
{
    COORD coord;
    coord.X = a;
    coord.Y = b;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void drawchessboard(int sizeOfChessBoard)
{
    gotoxy(0, 5);
    settextcolor(13);

    for (int i = 1; i <= sizeOfChessBoard; i++)
    {
        for (int j = 1; j <= sizeOfChessBoard; j++)
        {
            cout << "+---";
            if (j == sizeOfChessBoard)
                cout << "+\n";
        }
        for (int j = 1; j <= sizeOfChessBoard; j++)
        {
            cout << "|   ";
            if (j == sizeOfChessBoard)
                cout << "|\n";
        }
    }
    for (int i = 1; i <= sizeOfChessBoard; i++)
    {
        cout << "+---";
        if (i == sizeOfChessBoard)
            cout << "+\n";
    }
}

void initChessBoard(int** chessBoard, int sizeOfChessBoard, int xPosition, int yPosition)
{
    settextcolor(3);
    cout << "- Ban co co kich thuoc " << sizeOfChessBoard << "x" << sizeOfChessBoard << endl
         << "- Bat dau tu toa do (" << xPosition << "," << yPosition << ")\n"
         << "- Quan ma di chuyen voi do delay la " << delay << "ms\n";
    for (int i = 0; i < (sizeOfChessBoard + 1); i++)
    {
        chessBoard[i] = new int[sizeOfChessBoard];
        for (int j = 0; j < (sizeOfChessBoard + 1); j++)
        {
            chessBoard[i][j] = 0;
        }
    }
}