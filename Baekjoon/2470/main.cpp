#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution;

void findValue() {
    int sum = 2000000000;
    int size = solution.size();
    int answer[2];

int i = 0;
int j = size - 1;

    while (i < j) {
        int tempSum = solution[i] + solution[j];

        if(abs(sum) > abs(tempSum)) {
            sum = tempSum;
            answer[0] = solution[i];
            answer[1] = solution[j];
            if(sum == 0 ){
                break;
            }
        }

        if(tempSum < 0) {
            i++;
        }
        else {
            j--;
        }
    }
    cout << answer[0] << " " << answer[1];
    }

int main() {
    int N;
    cin >> N;

    while(N--) {
        int value;
        cin >> value;

        solution.push_back(value);
    }
    sort(solution.begin(), solution.end());
    findValue();
    return 0;
}
