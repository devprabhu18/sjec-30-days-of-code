#include <iostream>
#include <vector>

using namespace std;

int max_cherries(vector<int> cherries, int m) {
    // Initialize maximum number of cherries picked and current sum of cherries picked
    int max_cherries_picked = 0, curr_cherries_picked = 0;

    // Add up the cherries from the first m trees
    for (int i = 0; i < m; i++) {
        curr_cherries_picked += cherries[i];
    }

    // Update the maximum number of cherries picked
    max_cherries_picked = max(max_cherries_picked, curr_cherries_picked);

    // Slide the window to the right by one tree at a time
    for (int i = m; i < cherries.size(); i++) {
        curr_cherries_picked = curr_cherries_picked - cherries[i-m] + cherries[i];
        max_cherries_picked = max(max_cherries_picked, curr_cherries_picked);
    }

    return max_cherries_picked;
}

int main() {
    int n, m;
    cout << "Enter the number of cherry trees: ";
    cin >> n;

    cout << "Enter the number of consecutive trees to pick cherries from: ";
    cin >> m;

    vector<int> cherries(n);
    cout << "Enter the number of cherries in each tree: ";
    for (int i = 0; i < n; i++) {
        cin >> cherries[i];
    }

    cout << "Maximum number of cherries picked: " << max_cherries(cherries, m) << endl;

    return 0;
}
