#include <cassert> // Включаем для запуска юнит-тестов.
#include <iostream>

const int MIN_CHANNEL = 1;
const int MAX_CHANNEL = 99;

/* Допишите класс в соответствии с требованиями задания. */
class TV {
public:
    // Включает телевизор.
    void TurnOn() {
        tv_on = true;
    }

    // Выключает телевизор.
    void TurnOff() {
        tv_on = false;
    }

    // Возвращает true, если телевизор включён, и false, если телевизор выключен.
    bool IsTurnedOn() {
        if (tv_on) {
            return true;
        }
        return false;
    }

    // Возвращает номер текущего канала либо 0, если телевизор был выключен.
    // Номер канала не сбрасывается при выключении и повторном включении.
    // При первом включении телевизор показывает канал № 1.
    int GetCurrentChannel() {
        if (tv_on) {
            return channel;
        }
        return 0;
    }

    // Выбирает канал с указанным номером. Номер канала должен быть в диапазоне [1..99].
    // Если указан недопустимый номер канала или телевизор выключен, возвращает false и не меняет
    // текущий канал. В противном случае возвращает true.
    bool SelectChannel(int neded_channel) {
        if (neded_channel >= 1 && neded_channel <= 99 && tv_on) {
            channel = neded_channel;
            return true;
        }
        return false;
    }
private:
    bool tv_on = false;
    int channel = 1;
};

int main() {
    {
        TV tv;
        assert(!tv.IsTurnedOn());
    }
    {
        TV tv;
        assert(!tv.IsTurnedOn());
        tv.TurnOn();
        assert(tv.IsTurnedOn());
        tv.TurnOff();
        assert(!tv.IsTurnedOn());
    }
    {
        TV tv;
        assert(!tv.IsTurnedOn());
        assert(tv.GetCurrentChannel() == 0);
        tv.TurnOn();
        assert(tv.GetCurrentChannel() == 1);
        tv.TurnOff();
        assert(tv.GetCurrentChannel() == 0);
    }
    {
        TV tv;
        tv.TurnOn();
        for (auto i = 0; i < 10; ++i) {
            int channel = (71 * i) % MAX_CHANNEL + 1;
            assert(tv.SelectChannel(channel));
            assert(tv.GetCurrentChannel() == channel);
        }
    }
    {
        TV tv;
        tv.TurnOff();
        int channel = 50;
        assert(!tv.SelectChannel(channel));
        assert(tv.GetCurrentChannel() == 0);
    }
    {
        TV tv;
        tv.TurnOn();
        for (auto i = 0; i < 10; ++i) {
            int channel = (641 * i) % MAX_CHANNEL + 1;
            assert(tv.SelectChannel(channel));
            assert(tv.GetCurrentChannel() == channel);
            tv.TurnOff();
            assert(!tv.IsTurnedOn());
            assert(tv.GetCurrentChannel() == 0);
            tv.TurnOn();
            assert(tv.GetCurrentChannel() == channel);
        }
    }
    std::cout << "Program testing OK" << std::endl;
}