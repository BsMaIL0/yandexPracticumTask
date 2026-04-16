#include "car.h"

bool Car::IsSpeedValidForGear(int speed, Gear gear){
    if(gear==Gear::PARKED && speed==0){
        return true;
    }
    if(gear==Gear::DRIVE && speed>=0 && speed<=GetMaxSpeedForGear(gear)){
        return true;
    }
    if(gear==Gear::REVERSE && speed>=0 && speed<=GetMaxSpeedForGear(gear)){
        return true;
    }
    return false;
}

int Car::GetMaxSpeedForGear(Gear gear){
    if(gear==Gear::PARKED){
        return 0;
    }
    if(gear==Gear::DRIVE){
        return MAX_SPEED;
    }
    return MAX_REVERSE_SPEED;
 }

Direction Car::GetDirection(){
    if(GetGear()==Gear::DRIVE && GetSpeed()>0){
        return Direction::FORWARD;
    }
    if(GetGear()==Gear::PARKED || GetSpeed()==0){
        return Direction::STOPPED;
    }
    return Direction::BACKWARD;
}

void Car::TurnEngineOn(){
 engine_is_on_ = true;
}

bool Car::TurnEngineOff(){
    if(GetGear()==Gear::PARKED && GetSpeed()==0){
        engine_is_on_ = false;
        return true;
    }
    return false;
}

bool Car::IsEngineOn() {
    return engine_is_on_;
}

bool Car::SetGear(Gear new_gear) {
    if (gear_ == new_gear) {
        return true;
    }
    if (!engine_is_on_) {
        return false;
    }
    if (speed_ != 0) {
        return false;
    }
    gear_ = new_gear;
    return true;
}

Gear Car::GetGear() {
    return gear_;
}

int Car::GetSpeed() {
    return speed_;
}

bool Car::SetSpeed(int new_speed) {
    if (!engine_is_on_ || new_speed < 0) {
        return false;
    }
    if (speed_ == new_speed) {
        return true;
    }
    if (!IsSpeedValidForGear(new_speed, gear_)) {
        return false;
    }
    speed_ = new_speed;
    return true;
}