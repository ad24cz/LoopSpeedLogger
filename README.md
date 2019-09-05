# LoopSpeedLogger
This is an Arduino library that outputs the speed of main loop() as well as maximal, minimal, average values. On top of that it gives you the free memory reading... might make debugging easier

# Usage
The library provides a simple static class `LoopSpeedLogger`. At the beginning of each loop, you use `LoopSpeedLogger::measure()`. Then you can use functions described below. Everything is measured in milliseconds.

### `int LoopSpeedLogger::thisRun()`
Returns the elapsed time since the last call of `LoopSpeedLogger::measure()`.

### `int LoopSpeedLogger::lastRun()`
Returns the time of the last loop.

### `int LoopSpeedLogger::minimal()`
Returns the time of the fastest loop.

### `int LoopSpeedLogger::maximal()`
Returns the time of the slowest loop.

### `int LoopSpeedLogger::average()`
Returns the average time of all the loops.

# Example
```cpp
#include <Arduino.h>
#include "LoopSpeedLogger.h"

void setup() {
    Serial.begin(115200);
    delay(2000);
    Serial.println("last\tthis\tmin\tmax\tavg");
}

void loop() {
    LoopSpeedLogger::measure();
    delay(random(1000));
    Serial.println(String(LoopSpeedLogger::lastRun()) + "\t" +
                   String(LoopSpeedLogger::thisRun()) + "\t" +
                   String(LoopSpeedLogger::minimal()) + "\t" +
                   String(LoopSpeedLogger::maximal()) + "\t" +
                   String(LoopSpeedLogger::average()));
}
```