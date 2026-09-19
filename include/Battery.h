#ifndef BATTERY_H
#define BATTERY_H

class Battery {
public:
    Battery(double maxCharge, double currentCharge);

    double getMaxCharge() const;
    double getCurrentCharge() const;

    void changeCurrentCharge(double change);

private:
    double maxCharge_;
    double currentCharge_;
};

#endif // BATTERY_H