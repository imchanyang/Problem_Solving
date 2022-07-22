#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    // 참가 선수 및 완주 선수 정렬
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    // 중간에 답을 찾았는지 확인하는 Flag
    bool flag = false;

    // 참가 선수와 완주 선수 정렬 후, 비교
    for(int i = 0; i < completion.size(); i++) {
        if(completion[i] != participant[i]) {
            answer = participant[i];
            flag = true;
            break;
        }
    }

    // 위 for문에서 못찾았다면 participant의 마지막 원소가 정답
    if(flag == false) {
        int lastIndex = participant.size() - 1;
        answer = participant[lastIndex];
    }

    return answer;
}