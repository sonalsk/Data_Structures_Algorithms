#include <iostream>
#include <string>
using namespace std;

int isPalindrome(string text, int front, int back) {  
    if (front >= back) {
        return 1;
    }
    if (text[front] != text[back]) {
        return 0;
    }
    return isPalindrome(text, front + 1, back - 1);
}

int test(string text) {
  
  int answer= isPalindrome(text,0,text.length()-1);
  if (answer)
  {cout<< "Yes" <<endl;}
  else
  {cout<< "No" <<endl;}
  return answer;
}

int main() {
    string s = "madam";
    test(s);
    return 0;
}