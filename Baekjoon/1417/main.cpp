#include <cstdio>
#include <queue>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    int dasom;
    scanf("%d", &dasom);

    priority_queue<int> pq;
    for(int i = 0; i < N-1; i++) {
        int vote;
        scanf("%d", &vote);
        pq.push(vote);
    }

    int count = 0;
    while(N != 1) {
        if(dasom <= pq.top()) {
            int max = pq.top();
            pq.pop();
            max--;
            dasom++;
            pq.push(max);

            count++;
        }
        else {
            break;
        }
    }
    printf("%d\n", count);
    return 0;
}