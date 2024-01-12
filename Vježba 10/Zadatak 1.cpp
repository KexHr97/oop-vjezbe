//vjezba 10.
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<iterator>
#include<string>

bool containsSubstring(const std::string& str, const std::string& substring) {
    return str.find(substring) != std::string::npos;
}

void toUpperCase(std::string& str) {
    std::transform(str.begin(), str.end(), str.begin(), std::toupper());
}

void processFile(const std::string& filename, const std::string& targetWord, const std::string& targetSubstring) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    std::istream_iterator<std::string> fileIterator(file);
    std::istream_iterator<std::string> endOfFile;
    std::vector<std::string> words(fileIterator, endOfFile);
    file.close();

    std::vector<int> positions;
    auto p = std::find(words.begin(), words.end(), targetWord);
    while (p != words.end()) {
        positions.push_back(std::distance(words.begin(), p));
        p = std::find(std::next(p), words.end(), targetWord);
    }

    auto newEnd = std::remove_if(words.begin(), words.end(),
        [targetSubstring](const std::string& str) {
            return containsSubstring(str, targetSubstring);
        });
    words.erase(newEnd, words.end());

    std::for_each(words.begin(), words.end(), toUpperCase);


    std::cout << "Stringovi nakon operacija:" << std::endl;
    std::copy(words.begin(), words.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
}

int main() {
    const std::string filename = "words.txt";
    const std::string targetWord = "target";
    const std::string targetSubstring = "substring";

    processFile(filename, targetWord, targetSubstring);

    return 0;
}