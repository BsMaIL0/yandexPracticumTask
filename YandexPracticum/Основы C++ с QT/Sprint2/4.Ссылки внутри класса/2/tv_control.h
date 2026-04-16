#pragma once
#include "tv.h"

class TVControl {
public:
    TVControl(TV& tv);
    // Конструктор TVControl должен принять ссылку
    // на телевизор и сохранить её в поле класса.
    // Объявите его здесь, а определите в файле tv_control.cpp

    // Метод ReadAndApplyCommand больше не статический.
    bool ReadAndApplyCommand() const;
    void TurnOn() const;
    void TurnOff() const;
    void SelectChannel(int n) const;

private:
    TV& tv_;

private:
    // Приватные методы класса не должны быть статическими и не должны принимать ссылку на tv.*/
    void Info() const;
};