#include "checksum.h"

uint32_t checksum(std::istream &stream) {
    int32_t dword = 0;
    uint32_t checksum = 0;

    while (stream.read((char*)&dword, sizeof(dword))) {
        checksum += dword;
    }

    return checksum;
}
