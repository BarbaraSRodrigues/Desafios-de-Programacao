/*
    Nome: Barbara Silveira Rodrigues
    Materia: Desafios de Programacao
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 9;
double circle[MAXN], ans, x[MAXN];
int n;

// Calculates the horizontal distance between the centers of two touching circles aa and bb when both circles are sitting on the bottom
double GetDis(int c1, int c2) {
    double a = circle[c1] + circle[c2];
    double b = abs(circle[c1] - circle[c2]);
    return sqrt(a * a - b * b);
}

// Permutate and calculate the rectangle
void solve() {
    do {
        memset(x, -1, sizeof(x));
        x[0] = circle[0];

        for (int i = 1; i < n; i++) {
            double x_ = circle[i];
            for (int j = 0; j < i; j++) {
                x_ = max(x_, x[j] + GetDis(i, j));
            }
            x[i] = x_;
        }

        double tmp = -1;
        for (int i = 0; i < n; i++) {
            tmp = max(tmp, x[i] + circle[i]);
        }

        // Get the smallest
        ans = min(ans, tmp);
    } while (next_permutation(circle, circle + n));
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> circle[i];
        }

        ans = 1e9;  // Initialize with a large value
        sort(circle, circle + n);
        solve();
        cout << fixed << setprecision(3) << ans << endl;
    }
    return 0;
}
