#ifndef LOOP_SPEED_LOGGER_H
#define LOOP_SPEED_LOGGER_H

class LoopSpeedLogger {
   public:
    static void measure();

    static int thisRun();

    static int lastRun();

    static int minimal();

    static int maximal();
    
    static int average();

   private:
    // make the class static
    LoopSpeedLogger() {}

    static int lastRunStart, thisRunStart, maximalMillis, minimalMillis, averageMillis, count, setupTime;
};

#endif