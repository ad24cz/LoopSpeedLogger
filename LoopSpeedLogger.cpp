#include "LoopSpeedLogger.h"
#include <Arduino.h>

unsigned long LoopSpeedLogger::lastRunStart,
    LoopSpeedLogger::thisRunStart,
    LoopSpeedLogger::minimalMillis = (unsigned long) UINT64_MAX,
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

unsigned long LoopSpeedLogger::thisRun() {
    return millis() - thisRunStart;
}

unsigned long LoopSpeedLogger::lastRun() {
    return thisRunStart - lastRunStart;
}

unsigned long LoopSpeedLogger::minimal() {
    return minimalMillis;
}

unsigned long LoopSpeedLogger::maximal() {
    return maximalMillis;
}

unsigned long LoopSpeedLogger::average() {
    return averageMillis;
}