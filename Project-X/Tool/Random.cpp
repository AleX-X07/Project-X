#include "Random.h"

Random* Random::myInstance = nullptr;

Random* Random::getInstance() {
    if (myInstance == nullptr) {
        myInstance = new Random();
    }
    return myInstance;
}

int Random::getRandomInt(int min, int max) {
    std::random_device m_rd;
    std::mt19937 m_gen(m_rd());

    std::uniform_int_distribution<int> dis(min, max);
    return dis(m_gen);
}
