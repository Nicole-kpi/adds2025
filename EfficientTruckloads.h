#ifndef EFFICIENT_TRUCKLOADS_H
#define EFFICIENT_TRUCKLOADS_H

#include <unordered_map>
#include <cstdint>

class EfficientTruckloads {
public:
    int numTrucks(int numCrates, int loadSize);

private:
    static std::uint64_t makeKey(int numCrates, int loadSize) {
        return (static_cast<std::uint64_t>(static_cast<std::uint32_t>(numCrates)) << 32) |
               static_cast<std::uint32_t>(loadSize);
    }

    std::unordered_map<std::uint64_t, int> memo;
};

#endif // EFFICIENT_TRUCKLOADS_H
