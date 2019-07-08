#pragma once
#include "thread.hpp"
namespace distance
{
class Constants
{
public:
    // Intervals (millis)
    static const unsigned long TRIG_PIN_LOW_INTERVAL = 2UL;
    static const unsigned long TRIG_PIN_HIGH_INTERVAL = 1UL;
    static const unsigned long SPEED_UPDATE_INTERVAL = 250UL;
    static const unsigned long MEASURE_DISTANCE_INTERVAL = 35UL;

    // Counts
    static const unsigned int TRIG_PIN_LOW_MAX_COUNTS = 2U;
    static const unsigned int TRIG_PIN_HIGH_MAX_COUNTS = 10U;
};
class Distance
{
public:
    Distance(unsigned char t_trigPin, unsigned char t_echoPin);
    double getDistance() const;
    double getSpeed() const;
    void measureDistance();
    void measureSpeed();
    void trigPinHigh();
    void trigPinLow();

private:
    double m_getDistance();

    double m_lastDistance;
    double m_currentDistance;

    // cm/sec
    double m_speed;
    const unsigned char m_echoPin;
    const unsigned char m_trigPin;
    unsigned int m_trigPinLowCounter;
    unsigned int m_trigPinHighCounter;
};
} // namespace distance