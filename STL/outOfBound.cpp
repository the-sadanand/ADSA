#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {10,20,30,40,50};

    try {
        cout << arr.at(10);
    }
    catch (const out_of_range &e) {
        cout << "Exception: " << e.what() << endl;
    }

    cout << "Program continues..." << endl;

    return 0;
}