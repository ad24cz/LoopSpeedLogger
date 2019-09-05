#include "LoopSpeedLogger.h"
#include <Arduino.h>

int LoopSpeedLogger::lastRunStart,
    LoopSpeedLogger::thisRunStart,
    LoopSpeedLogger::minimalMillis = INT32_MAX,
    LoopSpeedLogger::maximalMillis,
    LoopSpeedLogger::averageMillis,
    LoopSpeedLogger::count,
    LoopSpeedLogger::setupTime;

void LoopSpeedLogger::measure() {
    lastRunStart = thisRunStart;
    thisRunStart = millis();
    
    if (thisRunStart - lastRunStart < minimalMillis)
        minimalMillis = thisRunStart - lastRunStart;
    
    if (count == 0) {
        setupTime = thisRunStart;
    } else {
        if (thisRunStart - lastRunStart > maximalMillis)
            maximalMillis = thisRunStart - lastRunStart;

        averageMillis = (thisRunStart - setupTime) / count;
    }
    
    count++;
}

int LoopSpeedLogger::thisRun() {
    return millis() - thisRunStart;
}

int LoopSpeedLogger::lastRun() {
    return thisRunStart - lastRunStart;
}

int LoopSpeedLogger::minimal() {
    return minimalMillis;
}

int LoopSpeedLogger::maximal() {
    return maximalMillis;
}

int LoopSpeedLogger::average() {
    return averageMillis;
}