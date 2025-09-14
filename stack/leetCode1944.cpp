#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int> st;
        vector<int> ans(heights.size(), 0);
        for (int i = heights.size() - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] < heights[i]) {
                st.pop();
                ans[i]++;
            }
            if (!st.empty())
                ans[i]++;
            st.push(i);
        }
        return ans; 
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> heights = {10, 6, 8, 5, 11, 9};

    // Call function
    vector<int> result = sol.canSeePersonsCount(heights);

    // Print output
    cout << "Result: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
