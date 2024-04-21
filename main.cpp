#include <iostream>
#include <iomanip>
#include <windows.h> 
using namespace std;
#define delay 0
bool q = false;

// di theo chieu kim dong ho
// int a[8] = { 2, 2, 1, -1, -2, -2, -1, 1 };
// int b[8] = { 1, -1, -2, -2, -1, 1, 2, 2 };
// di theo chieu nguoc chieu kim dong ho
int a[8] = { 2, 2, 1, -1, -2, -2, -1, 1 };
int b[8] = { 1, -1, -2, -2, -1, 1, 2, 2 };

void gotoxy(int, int);
void textcolor(int);
void Di(int**, int, int, int, int);
void VeBanCo(int);
void init(int**, int);

int main() {
    textcolor(6);
    cout << "*** BAI 2.1 : BAI TOAN MA DI TUAN ***\n";
    int N; cout << "Nhap kich thuoc ban co: ";
    cin >> N; system("cls");
    while (N < 1) {
        cout << "Kich thuoc khong hop le\n" << "Nhap lai kich thuoc ban co: ";
        cin >> N; system("cls");
    }

    int x_chon, y_chon; cout << "Nhap toa do a, b de bat dau (a,b) : ";
    cin >> x_chon >> y_chon; system("cls");
    while (x_chon < 1 || x_chon > N || y_chon < 1 || y_chon > N) {
        cout << "Tao do khong hop le\n" << "Nhap lai toa do a, b (a,b) : ";
        cin >> x_chon >> y_chon; system("cls");
    }

    int** BanCo = new int* [N + 1];
    init(BanCo, N);

    textcolor(3);
    cout << "- Ban co co kich thuoc " << N << "x" << N << endl
        << "- Bat dau tu toa do (" << x_chon << "," << y_chon << ")\n"
        << "- Quan ma di chuyen voi do delay la " << delay << "ms\n";
    gotoxy(0, 5);
    textcolor(13);
    VeBanCo(N);

    gotoxy(2 + N * 4, 6);
    cout << "Buoc di hien tai cua quan ma la :";

    gotoxy(0, 4); cout << "Quan ma dang di chuyen...";
    textcolor(14);
    Di(BanCo, x_chon - 3, y_chon - 2, 1, N);
    gotoxy(0, 4); cout << "Quan ma da di chuyen xong\n";

    gotoxy(0, 7 + N * 2);
    textcolor(7);
    cout << "Ket qua: ";
    if (q == false) {
        textcolor(12);
        cout << "Khong co cach di chuyen nao di het ban co\n";
    }
    else {
        textcolor(10);
        cout << "Da di het " << N * N << " buoc\n\n";
    }

    delete[] BanCo;
    textcolor(7);
    system("pause");
    return 0;
}


///////////////////////////////////////////////////////////////////////////////////////
void Di(int** BanCo, int x, int y, int n, int N) {
    int u, v;
    for (int i = 0; i <= 7; i++) {
        int u = x + a[i];
        int v = y + b[i];
        if (u >= 0 && u < N && v >= 0 && v < N && BanCo[u][v] == 0) {
            BanCo[u][v] = n;
            gotoxy(1 + u * 4, 6 + v * 2);
            Sleep(delay);
            cout << n;
            gotoxy(36 + N * 4, 6);
            cout << n;
            if (n == N * N) {
                q = true;
            }
            if (q == false) {
                Di(BanCo, u, v, n + 1, N);
            }
            if (q == true) {
                return;
            }
            BanCo[u][v] = 0;
            gotoxy(1 + u * 4, 6 + v * 2);
            Sleep(delay); cout << "  ";
        }
    }
}

void textcolor(int x) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
}

void gotoxy(int a, int b)
{
    COORD coord;
    coord.X = a;
    coord.Y = b;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void VeBanCo(int N) {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << "+---";
            if (j == N) cout << "+\n";
        }
        for (int j = 1; j <= N; j++) {
            cout << "|   ";
            if (j == N) cout << "|\n";
        }

    }
    for (int i = 1; i <= N; i++) {
        cout << "+---";
        if (i == N) cout << "+\n";
    }
}

void init(int** BanCo, int N) {
    for (int i = 0; i < (N + 1); i++) {
        BanCo[i] = new int[N];
        for (int j = 0; j < (N + 1); j++) {
            BanCo[i][j] = 0;
        }
    }
}