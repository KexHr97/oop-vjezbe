#include <iostream>
#include <string>

using namespace std;

bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

string pigLatinTranslation(string& word) {
    if (isVowel(word[0])) {
        return word + "hay";
    } else {
        return word.substr(1) + word[0] + "ay";
    }
}

string translateSentence(string& sentence) {
    string pigLatinSentence;
    string word;

    for (int i = 0; i < sentence.length(); i++) {
        if (isalpha(sentence[i])) {
            word += sentence[i];
        } else {
            pigLatinSentence += pigLatinTranslation(word) + sentence[i];
            word.clear();
        }
    }

    return pigLatinSentence;
}

int main() {
    string sentence = "I love computers!";
    string pigLatin = translateSentence(sentence);
    cout << "Originalna recenica: " << sentence << endl;
    cout << "Pig Latin prevod: " << pigLatin << endl;

    return 0;
}
