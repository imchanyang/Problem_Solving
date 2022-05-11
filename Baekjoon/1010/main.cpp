#include <iostream>
using namespace std;

int main() {
    int T,N,M;
    int dp[31][31];

    for(int i = 0; i < 31; i++) {
        for(int j = 1; j < 31; j++) {
            // 파스칼 삼각형 오른쪽 변 값 1로 초기화
            if(i == j) {
                dp[i][j] = 1;
            }
            // 파스칼 삼각형 왼쪽 변 값 1로 초기화
            else if(i == 0) {
                dp[i][j] = 1;
            }
            else {
                dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
            }
        }
    }
    scanf("%d", &T);

    while(T--) {
        scanf("%d %d", &N, &M);
        printf("%d\n", dp[N][M]);
    }
    return 0;
}
