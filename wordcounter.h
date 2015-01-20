#ifndef WORDCOUNTER_H
#define WORDCOUNTER_H

#include <string>
#include <istream>

class WordCounter {
public:
    WordCounter(const std::string& reference) : reference(reference) {
    }

    int operator()(std::istream& stream) const;

private:
    const std::string reference;
};

#endif // WORDCOUNTER_H
