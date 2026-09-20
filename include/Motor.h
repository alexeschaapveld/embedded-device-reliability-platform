#ifndef MOTOR_H
#define MOTOR_H

class Motor {
public:
    Motor(double maxSpeed, double maxPower); 
    
    double getCurrentSpeed() const;
    double getMaxSpeed() const;
    double getMaxPower() const;
    double getLoad() const;
    bool isRunning() const;

    void increaseSpeed(double amount);
    void decreaseSpeed(double amount);
    void setLoad(double amount);
private:
    double currentSpeed_;
    double maxSpeed_;
    double maxPower_;
    double load_;
};

#endif //MOTOR_H