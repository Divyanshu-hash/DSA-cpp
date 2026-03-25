#include <bits/stdc++.h>
using namespace std;

bool checkValidString(string s) {
    int low = 0, high = 0;

    for (char c : s) {
        if (c == '(') {
            low++;
            high++;
        }
        else if (c == ')') {
            low--;
            high--;
        }
        else { // '*'
            low--;     // treat as ')'
            high++;    // treat as '('
        }

        if (high < 0) return false;
        if (low < 0) low = 0;
    }

    return low == 0;
}

int main() {
    string s;
    cin >> s;

    if (checkValidString(s)) {
        cout << "Valid" << endl;
    } else {
        cout << "Invalid" << endl;
    }

    return 0;
}