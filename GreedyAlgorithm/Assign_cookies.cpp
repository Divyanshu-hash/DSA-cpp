#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    
    cout << "Enter number of children: ";
    cin >> n;

    vector<int> g(n);
    cout << "Enter greed factors:\n";
    for (int i = 0; i < n; i++) cin >> g[i];

    cout << "Enter number of cookies: ";
    cin >> m;

    vector<int> s(m);
    cout << "Enter cookie sizes:\n";
    for (int i = 0; i < m; i++) cin >> s[i];

    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int i = 0, j = 0;

    while (i < n && j < m) {
        if (s[j] >= g[i]) {
            i++;
        }
        j++;
    }

    cout << "Maximum satisfied children: " << i << endl;

    return 0;
}