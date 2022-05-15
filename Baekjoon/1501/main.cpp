#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define endl "\n"
#define init ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main() {
    init
    int N,T;
    vector<string> dictionary;

    cin >> N;
    while(N--) {
        string word;
        cin >> word;
        if(word.length() > 3) {
            sort(word.begin()+1, word.end()-1);
        }
        dictionary.push_back(word);
    }

    cin >> T;
    cin.ignore();
    while(T--) {
        vector<string> stringInfo;
        string sentence;
        getline(cin, sentence);

        string word_ = "";
        for(int i = 0; i < sentence.length(); i++) {

            if(sentence[i] == ' ') {
                if(word_.length() > 3) {
                    sort(word_.begin()+1, word_.end()-1);
                }

                stringInfo.push_back(word_);
                word_ = "";
            }
            else if(i == sentence.length() - 1) {
                word_ += sentence[i];
                if(word_.length() > 3) {
                    sort(word_.begin()+1, word_.end()-1);
                }

                stringInfo.push_back(word_);
                word_ = "";
            }
            else {
                word_ += sentence[i];
            }
        }

        int mul = 1;
        for(int i = 0; i < stringInfo.size(); i++) {
            int count = 0;
            for(int j = 0; j < dictionary.size(); j++) {
                if(stringInfo[i] == dictionary[j]) {
                    count++;
                }
            }
            mul *= count;
        }
            cout << mul << endl;
    }
    return 0;
}