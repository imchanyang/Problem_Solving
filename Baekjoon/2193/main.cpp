#include <iostream>
#include <math.h>

using namespace std;
// table : number of pinary number
long long dp[91];
int N;

void dynamicPinary() {
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    for(int i = 3; i <= N; i++) {
        dp[i] = dp[i-2] + dp[i-1];
    }
    cout << dp[N] << "\n";
}

int main() {
    cin >> N;

    dynamicPinary();
    return 0;
}
