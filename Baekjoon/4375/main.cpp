#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    while(cin >> n)  {
        long long num = 1;
        int count = 1;
        while(1) {
            if(num % n == 0) {
                cout << count << "\n";
                break;
            }
            num %= n;
            num = num * 10 + 1;
            count++;
        }
    }
    return 0;
}
