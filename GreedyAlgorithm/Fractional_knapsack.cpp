#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value, weight;
};

bool cmp(Item a, Item b) {
    return (double)a.value / a.weight > (double)b.value / b.weight;
}

int main() {
    int W = 50;

    vector<Item> arr = {
        {60, 10},
        {100, 20},
        {120, 30}
    };

    sort(arr.begin(), arr.end(), cmp);

    double totalValue = 0.0;

    for (auto item : arr) {
        if (item.weight <= W) {
            totalValue += item.value;
            W -= item.weight;
        } else {
            totalValue += (double)item.value * (W / (double)item.weight);
            break;
        }
    }

    cout << totalValue << endl;

    return 0;
}