#include <iostream>
#include <climits>
using namespace std;

#define inf INT_MAX

int f(int n) {
    if (n == 1) return 0;
    if (n == 2) return 1;
    if (n == 3) return 1;

    int ans1 = f(n - 1);
    int ans2 = (n % 2 == 0) ? f(n / 2) : inf;
    int ans3 = (n % 3 == 0) ? f(n / 3) : inf;

    return 1 + min(ans1, min(ans2, ans3));  // ✅ use nested min()
}
vector<int> dp();
int f(int n) {
    if (n == 1) return 0;
    if (n == 2) return 1;
    if (n == 3) return 1;
    if(dp[n])
    int ans1 = f(n - 1);
    int ans2 = (n % 2 == 0) ? f(n / 2) : inf;
    int ans3 = (n % 3 == 0) ? f(n / 3) : inf;

    return 1 + min(ans1, min(ans2, ans3));  // ✅ use nested min()
}

int main() {
    int n = 10;
    dp.clear();
    dp.resize(n,-1);
    cout << f(n) << endl;
    return 0;
}
