#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool isPalindrome(string s) {
    int j = s.length() - 1;
    for (int i = 0; i < s.length() / 2; i++) {
        if (s[i] != s[j]) {
            return false;
        }
        j--;
    }
    return true;
}

int main() {
    string palindrome;
    cin >> palindrome;
    int n = palindrome.length();
    if (!isPalindrome(palindrome)) {
        cout << "No" << endl;
    } else {
        string sub1 = palindrome.substr(0, ((n - 1) / 2));
        string sub2 = palindrome.substr(((n + 3) / 2) - 1, n - 1);
        if (isPalindrome(sub1) && isPalindrome(sub2)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
