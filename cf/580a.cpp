#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    int curr = 1;
    int ans = 1;

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] <= arr[i + 1]) {
            curr++;
        } else {
            curr = 1;
        }

        ans = max(ans, curr);
    }

    cout << ans << endl;
}