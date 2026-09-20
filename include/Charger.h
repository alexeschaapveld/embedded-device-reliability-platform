#ifndef CHARGER_H
#define CHARGER_H

class Charger {
public:
    Charger(double currentChargeRate);
    
    double getCurrentChargeRate() const;

    void setCurrentChargeRate(double currentChargeRate);

private:
    double currentChargeRate_;
};
#endif //CHARGER_H