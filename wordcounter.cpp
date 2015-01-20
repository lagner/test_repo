#include "wordcounter.h"

using namespace std;

int WordCounter::operator ()(istream& stream) const {
    int counter = 0;
    string word;

    while (stream >> word) {
        if (word == reference)
            ++counter;
    }
    return counter;
}
