// Maket.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>
using namespace std;


class Camera
{
    int x, y;
public:
    enum State{track, sendKor, waiting, appearRob, clean, dirty, noTrack};
    int track();
    void sendKor();
    int waiting();
    int appearRob();
    int clean();
    int dirty();
    void noTrack();
};

int Camera::track()
{
    int s = 0;
    int x_y;
    if (s == 0)
        track;
    else
    {
        sendKor();
        waiting();
    }
}

void Camera::sendKor()
{
    

}

int Camera::waiting()
{
    int robot = 0;
    if (robot == 0)
        waiting();
    else
        appearRob();
}

int Camera::appearRob()
{
    int graf = 0;

    if (graf == 0)
        clean();
    else
        dirty();
}

int Camera::clean()
{
    track();
}

int Camera::dirty()
{
    sendKor();
}

void Camera::noTrack()
{
    char b;
    cout << "Включить камеру?(д/н)" << endl;
    cin >> b;
    if (b == 'д')
        track();
    else
        noTrack();
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Camera kor;
    char a;
    cout << "Включить камеру?(д/н)" << endl;
    cin >> a;
    if (a == 'д')
        kor.track();
    else
        kor.noTrack();

}

