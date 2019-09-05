#ifndef LOOP_SPEED_LOGGER_H
#define LOOP_SPEED_LOGGER_H

class LoopSpeedLogger {
   public:
    static void measure();

    static unsigned long thisRun();

    static unsigned long lastRun();

    static unsigned long minimal();

    static unsigned long maximal();
    
    static unsigned long average();

   private:
    // make the class static
    LoopSpeedLogger() {}

    static unsigned long lastRunStart, thisRunStart, maximalMillis, minimalMillis, averageMillis, count, setupTime;
};

#endif