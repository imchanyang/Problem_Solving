#include <iostream>
#define endl "\n"
#define init ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main() {
    init
    int X;
    cin >> X;

    int count = 0;
    while(X > 0) {
        if(X % 2) {
            count++;
        }
        X = X >> 1;
    }

    cout << count << endl;
    return 0;
}
