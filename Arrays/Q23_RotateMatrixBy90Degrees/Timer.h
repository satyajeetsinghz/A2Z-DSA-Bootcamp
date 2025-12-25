#ifndef TIMER_H
#define TIMER_H

#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

class Timer
{
private:
    high_resolution_clock::time_point start_time;

public:
    // Start timer
    void start()
    {
        start_time = high_resolution_clock::now();
    }

    // Stop timer and print duration
    void stop(const string &message = "Execution Time")
    {
        auto end_time = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end_time - start_time);
        cout << message << ": " << duration.count() << " microseconds" << endl;
    }
};

#endif
