#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct fileName{
    int order;
    string head;
    int number;
};

vector<fileName> f;

void setFileName(int o, string h, int n) {
    fileName fileName_;
    fileName_.order = o;
    fileName_.head = h;
    fileName_.number = n;

    f.push_back(fileName_);
}

bool compare(const fileName& f1, const fileName& f2) {
    if (f1.head == f2.head) {
        if (f1.number == f2.number) {
            return f1.order < f2.order;
        }
        else {
            return f1.number < f2.number;
        }
    }
    else {
        return f1.head < f2.head;
    }
}

bool isNumber(char c) {
    if('0'<= c && c <= '9') {
        return 1;
    }
    return 0;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;

    int size = files.size();
    for(int i = 0; i < size; i++) {
        string file = files[i];
        string head = "";
        string number = "";

        int index = 0;
        for(int j = 0; j < file.length(); j++) {
            if(!isNumber(file[j])) {
                head.push_back(tolower(file[j]));
            }
            else {
                index = j;
                break;
            }
        }
        for(int k = index; k < file.length(); k++) {
            if(isNumber(file[k])) {
                number.push_back(file[k]);
            }
            else {
                break;
            }
        }
        setFileName(i, head, stoi(number));
    }
    sort(f.begin(), f.end(), compare);

    for (int i = 0; i < f.size(); i++) {
        answer.push_back(files[f[i].order]);
    }

    return answer;
}