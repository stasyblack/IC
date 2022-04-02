#include <iostream>
//#include <Windows.h>
using namespace std;




enum CameraState {
    on, off, track, sendKor, waiting, appearRob, clean, dirty, noTrack
};


enum Event {
    nothing,
    pressOn
};


class Camera
{
    CameraState state;
    int x, y;
public:
    Camera() {
        state = CameraState::off;
    }


    int track();
    void sendKor();
    int waiting();
    int appearRob();
    int clean();
    int dirty();
    void noTrack();

    void processEvent(Event event) {
        switch (state) {
            CameraState::off;
            if (event == Event::pressOn) {
                state = CameraState::on;
                track();
            }
            break;
        }
    }

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
    cout << "Turn camera on?(y/n)" << endl;
    cin >> b;
    if (b == 'y')
        track();
    else
        noTrack();
}

Event getEvent() {
    // std::cin >> ...
    // if ...
    return Event::pressOn;
}


int main()
{
    //    SetConsoleCP(1251);
    //    SetConsoleOutputCP(1251);
    Camera kor;
    /*    char a;
        cout << "Turn camera on?(y/n)" << endl;
        cin >> a;
        if (a == 'y')
            kor.track();
        else
            kor.noTrack();
    */
    while (1) {
        Event ev = getEvent();
        kor.processEvent(ev);
    }
}
