#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> a(20);

int solver(int i, int res) {
    if (res == 0) return 1;
    if (i >= n) return 0;
    return solver(i + 1, res) || solver(i + 1, res - a.at(i));
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int q;
        cin >> q;
        if (solver(0, q)) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }
}
