#include <cstring>
#include <fstream>
#include <iostream>
#include <cstdint>
#include "wordcounter.h"
#include "checksum.h"

using namespace std;

const char* HELP_MESSAGE = R"~(usage: test [-h] -f FILENAME  -m MODE [-v word]

arguments:
-h      show this message
-f      full or reative path to target file
-m      choose application mode. "checksum", "words" - are available modes
-v      required field if "words" mode was chosen. Will be ignored otherwise
)~";


int checksum_handler(istream& stream);
int words_handler(istream& stream, const string& word);


int main(int argc, char* argv[]) {
    try {
        string mode;
        string word;
        string filename;

        for (int i = 0; i < argc; ++i) {
            const char* arg = *(argv + i);

            if (!strncmp(arg, "-m", 3) && (i+1) < argc) {
                mode = *(argv + i + 1);
            } else if (!strncmp(arg, "-f", 3) && (i+1) < argc) {
                filename = *(argv + i + 1);
            } else if (!strncmp(arg, "-v", 3) && (i+1) < argc) {
                word = *(argv + i + 1);
            } else if (!strncmp(arg, "-h", 3)) {
                cout << HELP_MESSAGE;
                return 0;
            }
        }

        if (!filename.empty() && !mode.empty()) {
            ifstream stream(filename);
            if (!stream) {
                cerr << "can not open " << filename << " file" << endl;
                return 1;
            }

            if (mode == "words" && !word.empty()) {
                return words_handler(stream, word);
            } else if (mode == "checksum") {
                return checksum_handler(stream);
            }
        }
        cout << HELP_MESSAGE;

    } catch (const exception& ex) {
        cerr << "unhandled exception: " << ex.what() << endl;
    } catch (...) {
        cerr << "fatal error";
    }
    return 1;
}


int checksum_handler(istream& stream) {
    try {
        uint32_t cs = checksum(stream);
        cout << "checksum: " << cs << endl;
        return 0;

    } catch (const std::exception& ex) {
        cerr << "error: " << ex.what();
        return 1;
    }
}


int words_handler(istream& stream, const string& word) {
    try {
        int count = WordCounter(word)(stream);
        cout << "\"" << word << "\": " << count << endl;
        return 0;

    } catch (const std::exception& ex) {
        cerr << "error while counting words: " << ex.what();
        return 1;
    }
}
