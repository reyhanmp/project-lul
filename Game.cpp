#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;

bool alive;
char name[10];
const int ymax = 20;
const int xmax = 20;
int ekorX[100];
int ekorY[100];
int ekor;
int x , y;
int powerx , powery;
int score;
enum arah { stop = 0, kiri, kanan, atas, bawah};
arah dir;

void start(){
    alive = true;
    score = 0;
    x = xmax/2;
    y = ymax/2;
    powerx = rand() % xmax;
    powery = rand() % ymax;
    score = 0;
    ekor = 0;
    cout << "Nama uy : ";
    cin >> name;
}

void draw(){
    system("cls");
    cout << "Sneik 1.0" << endl;
    for (int i = 0 ; i < xmax+2 ; i++){
        cout << "#";
    }
    cout << endl;

    for (int i = 0; i < ymax; i ++){
        for (int j = 0; j < xmax+2; j++){
            if ((j == 0) || (j == xmax+1)){
                cout << "#";
            }
            else if((i == y) && (j == x)){
                cout << "O";
            }
            else if((i == powery) && (j == powerx)){
                cout << "P";
            }
            else{
                bool print = false;
                for (int k = 0 ; k < ekor ; k++){
                    if (ekorX[k] == j && ekorY[k] == i){
                        cout << 'o';
                        print = true;
                    }
                }
                if (!print){
                    cout << " ";
                }
            }
        }
        cout << endl;
    }

    for (int i = 0 ; i < xmax+2 ; i++){
        cout << "#";
    }
    cout << endl;
    cout << "Score : " << score << endl;
}

void press(){
    if (_kbhit()){
        switch(_getch()){
            case 'a':
                dir = kiri;
                break;
            case 'w':
                dir = atas;
                break;
            case 's':
                dir = bawah;
                break;
            case 'd':
                dir = kanan;
                break;
            case 'x':
                alive = false;
                break;
        }
    }
}

void rules(){
    int prevX = ekorX[0];
    int prevY = ekorY[0];
    int prev2X, prev2Y;
    ekorX[0] = x;
    ekorY[0] = y;
    for (int i = 1; i < ekor; i++){
        prev2X = ekorX[i];
        prev2Y = ekorY[i];
        ekorX[i] = prevX;
        ekorY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch(dir){
        case atas:
            y--;
            break;
        case bawah:
            y++;
            break;
        case kiri:
            x--;
            break;
        case kanan:
            x++;
            break;
    }

    for (int i = 0 ; i < ekor ; i++){
        if (x == ekorX[i] && y == ekorY[i]){
            alive = false;
        }
    }
    if (x == 0 || x == xmax+2){
        alive = false;
    }
    else if (y == -1 || y == ymax+1){
        alive = false;
    }
    if ((x == powerx) && (y == powery)){
        score = score + 10;
        powerx = rand() % xmax;
        powery = rand() % ymax;
        ekor++;
    }
}

int main(){
    start();
    while (alive){
        draw();
        press();
        rules();
        Sleep(100);
    }
    while (!alive){
        system("cls");
        cout << name <<  " cuma dapet : " << score << endl;
        cout << name << " cupu ah";
    }
    cout <<"empe"<< endl;

    return 0;
}
