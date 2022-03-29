#pragma once

#include <random>

namespace util {

class Random
{
public:
    Random() = delete;

    static std::uint64_t rand(const std::size_t size)
    {
        std::mt19937 generator(std::random_device{}());
        std::uniform_int_distribution<std::uint64_t> dist(0, size - 1);
        return dist(generator);
    }
};

} // namespace util