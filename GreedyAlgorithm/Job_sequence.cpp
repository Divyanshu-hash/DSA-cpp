#include <bits/stdc++.h>
using namespace std;

struct Job {
    int id, dead, profit;
};

bool cmp(Job a, Job b) {
    return a.profit > b.profit;
}

int main() {
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;

    vector<Job> jobs(n);

    cout << "Enter job id, deadline and profit:\n";
    for (int i = 0; i < n; i++) {
        cin >> jobs[i].id >> jobs[i].dead >> jobs[i].profit;
    }

    // Step 1: Sort by profit
    sort(jobs.begin(), jobs.end(), cmp);

    // Step 2: Find max deadline
    int maxDead = 0;
    for (auto job : jobs) {
        maxDead = max(maxDead, job.dead);
    }

    // Step 3: Create slots
    vector<int> slot(maxDead + 1, -1);

    int count = 0, totalProfit = 0;

    // Step 4: Assign jobs
    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].dead; j > 0; j--) {
            if (slot[j] == -1) {
                slot[j] = jobs[i].id;
                count++;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    cout << "Number of jobs done: " << count << endl;
    cout << "Total profit: " << totalProfit << endl;

    return 0;
}