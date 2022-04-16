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


class Controler
{
public:
    virtual void getCommand()
    {
        cout << "Controler"<<endl;
    }
};

class ConsoleControler: public Controler
{
public:
    void getCommand()
    {
        cout << "ConsoleControler"<<endl;
    }
};

class NetController : public Controler
{
public:
    void getCommand()
    {
        cout << "NetController"<<endl;
    }
};


class Camera
{
    CameraState state;
    Controler* cont;
public:
    Camera(Controler *control) 
    {
        state = CameraState::off;
        cont = control;
    }
    void get()
    {
        cont->getCommand();
    }

    void track();
    void sendKor();
    void waiting();
    void appearRob();
    void clean();
    void dirty();
    void noTrack();

    void processEvent(Event event) 
    {
        switch (state) 
        {
            CameraState::off;
            if (event == Event::pressOn) 
            {
                state = CameraState::on;
                track();
            }
            break;
        }
    }

};


void Camera::track()
{
    int s = 1;
    int x_y;
    if (s == 0)
        track();
    else
    {
        sendKor();
        waiting();
    }
}

void Camera::sendKor()
{
    cout << "sendKor"<<endl;

}

void Camera::waiting()
{
    int robot = 1;
    cout << "waiting"<<endl;
    if (robot == 0)
        waiting();
    else
        appearRob();
}

void Camera::appearRob()
{
    int graf = 0;
    cout << "appearRob"<<endl;
    if (graf == 0)
        clean();
    else
        dirty();
}

void Camera::clean()
{
    cout << "clean" << endl;
    track();
}

void Camera::dirty()
{
    cout << "dirty" << endl;
    sendKor();
}

void Camera::noTrack()
{
    cout << "noTrack" << endl;
}

Event getEvent() 
{
    return Event::pressOn;
}


int main()
{
    Camera kor(new ConsoleControler);
    while (1) {
        Event ev = getEvent();
        kor.processEvent(ev);
    }
    return 0;
}
