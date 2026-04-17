#include "tv_control.h"

#include <iostream>
#include <string>

using namespace std::literals;

TVControl::TVControl(TV& tv) : tv_(tv){};

void TVControl::TurnOn() const{
    tv_.TurnOn();
    std::cout<<"Turning on"<<std::endl;
}

void TVControl::TurnOff() const{
    tv_.TurnOff();
    std::cout<<"TV is turned off"<<std::endl;
}

void TVControl::SelectChannel(int n) const{
    if(!tv_.IsTurnedOn()){
        std::cout<<"TV is not turned on"<<std::endl;
        return;
    }
    if(n<1 || n > 99){
        std::cout<<"Invalid channel"<<std::endl;
        return;
    }
    tv_.SelectChannel(n);
    std::cout<<"Channel selected"<<std::endl;
}

bool TVControl::ReadAndApplyCommand() const {
    std::string action;
    if (!(std::cin >> action)) {
        std::cout << "Invalid command"s << std::endl;
        return false;
    }

    // Реализуйте обработку оставшихся команд.
    if (action == "Exit"s) {
        return false;
    } else if (action == "Info"s) {
        Info();
    }else if (action == "TurnOn"s) {
        TurnOn();
    }else if (action == "TurnOff"s) {
        TurnOff();
    }else if (action == "SelectChannel"s) {
        int n;
        std::cin>>n;
        SelectChannel(n);
    } else {
        std::cout << "Unknown command"s << std::endl;
    }
    return true;
}

void TVControl::Info() const {
    if (!tv_.IsTurnedOn()) {
        std::cout << "TV is turned off"s << std::endl;
        return;
    }
    std::cout << "TV is turned on. Channel is "s << tv_.GetCurrentChannel() << std::endl;
}