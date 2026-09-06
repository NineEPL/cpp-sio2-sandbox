#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    string DNA1, DNA2;
    cin >> DNA1 >> DNA2;

    int max_len = 0;
    int curr_len = 0;

    for (int i = 0; i < n; i++) {
        if (DNA1[i] == DNA2[i]) {
            curr_len = curr_len + 1;
            if (curr_len > max_len)
                max_len = curr_len;
        } else {
            curr_len = 0;
        }
    }

    cout << max_len << "\n";
    return 0;
}
