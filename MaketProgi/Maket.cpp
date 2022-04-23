#include <iostream>
#include "commandStrategy.h"
#include "Header.h"
//#include <Windows.h>
using namespace std;


enum CameraState {
    on, off, track, sendKor, waiting, appearRob, clean, dirty, noTrack
};


enum Event {
    nothing,
    pressOn
};



class NetController : public commandStrategy
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
    commandStrategy* cont;
public:
    Camera(commandStrategy*control)
    {
        state = CameraState::off;
        cont = control;
    }
    Event get()
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
    void run();
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

void Camera::run()
{
    Camera kor(new ConsoleControler);
    while (1) 
    {
        Event ev = kor.get();
        kor.processEvent(ev);
    }
}

Event getEvent() 
{
    return Event::pressOn;
}


int main()
{
    Camera kor(new ConsoleControler);
    kor.run();
    return 0;
}
