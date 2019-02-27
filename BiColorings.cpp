#include <iostream>
#define mod(i) i%998244353
using namespace std;
int main() {
    int n,k;
    cin >> n >> k;
    static long long int dp[1004][2009][4] = {};
    dp[1][1][0] = 1;dp[1][1][3] = 1; dp[1][2][1] = 1; dp[1][2][2] = 1;
    for(int i = 2; i < n+1; i++){
        for(int j = 1; j < (i*2)+1 ;j++){

            dp[i][j][0] = (dp[i-1][j][0] + dp[i-1][j][1] + dp[i-1][j][2] + dp[i-1][j-1][3]) % 998244353;

            dp[i][j][1] =
                        (dp[i - 1][j - 1][0] + dp[i - 1][j][1] + dp[i - 1][j - 2][2] + dp[i - 1][j - 1][3]) % 998244353;
            dp[i][j][2] =
                        (dp[i - 1][j - 1][0] + dp[i - 1][j - 2][1] + dp[i - 1][j][2] + dp[i - 1][j - 1][3]) % 998244353;

            dp[i][j][3] = (dp[i-1][j-1][0] + dp[i-1][j][1] + dp[i-1][j][2] + dp[i-1][j][3])  %998244353;
        }
    }

    cout << ((dp[n][k][0])+(dp[n][k][1])+(dp[n][k][2])+(dp[n][k][3]))% 998244353;;
    return 0;
}
//https://codeforces.com/problemset/problem/1051/D
