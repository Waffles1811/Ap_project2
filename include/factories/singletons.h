//
// Created by jensp on 2/01/2025.
//

#ifndef AP_SINGLETONS_H
#define AP_SINGLETONS_H
#include "../rng.h"
#include "../stopwatch.h"
#include <memory>
namespace dj {
class rngFactory {
    static std::shared_ptr<dj::rng> generator;

public:
    /*
     * if the random number generator doesn't exist yet it will produce it then it will return a shared pointer to
     * it
     *
     * return: a shared pointer to the random number generator
     */
    std::shared_ptr<dj::rng> getRNG();

    rngFactory() = default;
};

class stopwatchFactory {
private:
    static std::shared_ptr<dj::stopwatch> chronometer;

public:
    /*
     * if the stopwatch doesn't exist yet it will produce it then it will return a shared pointer to it
     *
     * return: a shared pointer to the stopwatch
     */
    std::shared_ptr<dj::stopwatch> getStopwatch();

    stopwatchFactory() = default;
};
} // namespace dj

#endif // AP_SINGLETONS_H
