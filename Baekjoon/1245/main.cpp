#include <iostream>

#define endl "\n"
#define init ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int farm[100][70];
bool visited[100][70] {false, };
bool flag = true;

int x[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int y[8] = {0, 1, -1, 1, -1, 0, 1, -1};

int N, M;

void DFS(int i, int j) {
    visited[i][j] = true;

    for(int k = 0; k < 8; k++) {
        int i_ = i + y[k];
        int j_ = j + x[k];

        if(i_ < 0 || j_ < 0 || i_ >= N || j_ >= M) {
            continue;
        }

        if(farm[i][j] < farm[i_][j_]) {
            flag = false;
        }

        if(visited[i_][j_] == true) {
            continue;
        }

        if (farm[i][j] != farm[i_][j_]) {
            continue;
        }

        if(farm[i][j] == farm[i_][j_]) {
            DFS(i_, j_);
        }
    }
}

int main() {
    init
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            int data;
            cin >> data;
            farm[i][j] = data;
        }
    }

    int sum = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0 ; j < M; j++) {
            if(visited[i][j] == false) {
                flag = true;
                DFS(i, j);
                if(flag == true) {
                    sum++;
                }
            }
        }
    }
    cout << sum << endl;
    return 0;
}
