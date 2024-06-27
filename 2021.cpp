#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Item {
    int size;
    int value;
    string name;
};

int main() {
    int maxSpace;
    int n;

    cin >> maxSpace >> n;

    vector<Item> items(n);
    for (int i = 0; i < n; ++i) {
        cin >> items[i].size >> items[i].value >> items[i].name;
    }

    vector<int> dp(maxSpace + 1, 0);
    vector<int> itemChoice(maxSpace + 1, -1);

    for (int w = 1; w <= maxSpace; ++w) {
        for (int i = 0; i < n; ++i) {
            if (items[i].size <= w && dp[w] < dp[w - items[i].size] + items[i].value) {
                dp[w] = dp[w - items[i].size] + items[i].value;
                itemChoice[w] = i;
            }
        }
    }

    int totalValue = dp[maxSpace];
    vector<int> itemCounts(n, 0);
    int w = maxSpace;

    while (w > 0 && itemChoice[w] != -1) {
        int itemIndex = itemChoice[w];
        itemCounts[itemIndex]++;
        w -= items[itemIndex].size;
    }

    cout << "Total: " << totalValue << ", including";
    for (int i = 0; i < n; ++i) {
        if (itemCounts[i] > 0) {
            cout << " " << itemCounts[i] << " " << items[i].name;
        }
    }
    cout << "\n";

    return 0;
}
