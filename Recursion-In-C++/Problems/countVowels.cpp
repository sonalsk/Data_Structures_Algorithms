#include <bits/stdc++.h>

using namespace std;

const set <char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'}; 

int totalVowels(string text, int len, int index) {
    if (index == len) {
        return 0;
    }
    if (vowels.find(text[index]) != vowels.end()) {
        return 1 + totalVowels(text, len, index + 1);
    }
    return totalVowels(text, len, index + 1);
} 

int test(string text, int len, int index){
    return totalVowels(text,len,index);
}

int main() {
    string text = "p";
    cout << test(text, text.length(), 0) << endl;
    return 0;
}