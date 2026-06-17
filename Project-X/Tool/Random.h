#pragma once
#include <random>

class Random {
private:
    static Random* myInstance;
    Random() = default;
public:
    ~Random() = default;
    
    static Random* getInstance();
    
    int getRandomInt(int min, int max);
};
