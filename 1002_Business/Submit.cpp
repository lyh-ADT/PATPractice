#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

static const auto disable_sync = []() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

struct Project {
    long profit;
    long lasting;
    long deadline;
    void read() { cin >> profit >> lasting >> deadline; }
    bool operator<(const Project &r) { return deadline < r.deadline; }
};

int main() {
    long N;
    cin >> N;
    vector<Project> projects(N + 1);
    long maxDeadline = 0;
    long maxProfit = 0;
    for (long i = 1; i <= N; ++i) {
        projects[i].read();
        maxDeadline = max(projects[i].deadline, maxDeadline);
        maxProfit = max(projects[i].profit, maxProfit);
    }
    sort(projects.begin(), projects.end());
    vector<vector<long>> dp(N + 1, vector<long>(maxDeadline + 1));
    for (long i = 1; i <= N; ++i) {
        for (long j = 1; j <= maxDeadline; ++j) {
            if (j <= projects[i].deadline) {
                if (j - projects[i].lasting >= 0 &&
                    dp[i - 1][j] < projects[i].profit + dp[i - 1][j - projects[i].lasting]) {
                    dp[i][j] = projects[i].profit + dp[i - 1][j - projects[i].lasting];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
            maxProfit = max(maxProfit, dp[i][j]);
        }
    }
    // for (long i = 1; i <= N; ++i) {
    //     for (long j = 1; j <= maxDeadline; ++j) {
    //         cout << dp[i][j] << "  ";
    //     }
    //     cout << endl;
    // }

    cout << maxProfit;

    return 0;
}