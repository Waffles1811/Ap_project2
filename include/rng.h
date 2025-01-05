//
// Created by jensp on 29/11/2024.
//

#ifndef AP_RNG_H
#define AP_RNG_H
#include <cstdlib>
#include <chrono>
namespace dj {
class rng {
public:
    /*
     *
     * return: a random number between min and max-1
     *
     */
    int generateRandomint(int min, int max);

    rng() = default;
};
} // namespace dj
#endif // AP_RNG_H
