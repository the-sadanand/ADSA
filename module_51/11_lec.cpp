#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        int n = intervals.size();

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        ans.push_back(intervals[0]);

        for (int i = 1; i < n; i++) {

            if (ans.back()[1] >= intervals[i][0]) {

                ans.back()[0] = min(ans.back()[0], intervals[i][0]);

                ans.back()[1] = max(ans.back()[1], intervals[i][1]);

            } else {

                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};

int main() {

    Solution s;

    vector<vector<int>> v = {{1,3}, {2,5}, {8,10}, {9,12}};

    vector<vector<int>> ans = s.merge(v);

    for (auto &it : ans) {
        cout << "[" << it[0] << ", " << it[1] << "]\n";
    }

    return 0;
}