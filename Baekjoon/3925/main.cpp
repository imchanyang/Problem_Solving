#include <cstdio>
#include <iostream>
#include <math.h>
using namespace std;
unsigned long long add(unsigned long long a, unsigned long long b) {
    if (b == 0) {
        return a;
    }
    else if(a == 0) {
        return b;
    }

    unsigned long long sum = a ^ b;
    unsigned long long carry = (a & b) << 1;

    return add(sum, carry);
}

int main() {
    cout << add(1024, 123) << endl;
    int T;
    scanf("%d", &T);

    while(T--) {
        unsigned long long arr[9];
        for(int i = 0; i < 9; i++) {
            int M;
            scanf("%x", &M);
            arr[i] = M;
        }

//            unsigned long long sum = arr[0];
//            unsigned long long carry =0;
//            for(int i = 1; i < 8; i++) {
//                sum = add(sum,arr[i]);
//            }


//            unsigned long long temp = sum;
//            for(int i = 0; i < 8; i++) {
//                carry &= (arr[i]);
//                temp = add(temp ,carry);
//            }

            bool arrK[32];
            unsigned long long x = 2;
            for(int j = 0; j < 32; j++) {
                unsigned long long sum = 0;
                for(int i = 0; i < 8; i++) {
                    sum += arr[i]%x;
                    arr[i] -= arr[i]%x;
                }
                if(arr[8]%x == sum) {
                    arrK[j] = 0;
                }
                else {
                    arrK[j] = 1;
                }
                x *= 2;
            }

            unsigned long long anwser = 0;
            x = 1;
            for(int j = 0; j < 32; j++) {
                anwser += arrK[j]*x;
                x *=2;
            }




//            unsigned long long K = sum%(4294967296) ^ arr[8];
            printf("%x\n", anwser);

    }
    return 0;
}

//  N ^ K = M  => N ^ M = K
// N1 ^ M1 = N2 ^ M2 = N3 ^ M3 = N9 ^ M9 = K
// (N1 ^ K) + (N2 ^ K) + ---- + (N8 ^ K) = M9 = N9 ^ K

110000
101110
\

// 1.  N ^ M = K
// 2. 각 비트끼리...
