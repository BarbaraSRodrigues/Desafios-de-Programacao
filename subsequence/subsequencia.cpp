/* Nome: Barbara Silveira Rodrigues
   Materia: Desafios de Programação
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Function to count the number of distinct occurrences of Z in X
int subsequences(const string& X, const string& Z) {
    // Lengths of the strings X and Z
    int m = X.length();
    int n = Z.length();

    // Create a 2D array to store the count of subsequences
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Initialize the first row with 1 because an empty subsequence is present in any string
    for (int j = 0; j <= m; ++j)
        dp[0][j] = 1;

    // Dynamic programming
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (Z[i - 1] == X[j - 1]) {
                // If the current characters match, we have two choices:
                // Include the character in the subsequence and we have dp[i-1][j-1]
                // 2Exclude the character from the subsequence and we have dp[i][j-1]
                dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
            } else {
                // If the current characters dont match we can only exclude the character from X
                dp[i][j] = dp[i][j - 1];
            }
        }
    }
    return dp[n][m];
}

int main() {
    int numCases;
    cin >> numCases;

    while (numCases--) {
        string X, Z;
        cin >> X >> Z;
        int result = subsequences(X, Z);
        cout << result << endl;
    }

    return 0;
}
