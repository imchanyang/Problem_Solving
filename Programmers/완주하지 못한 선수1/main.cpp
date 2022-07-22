#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    unordered_map<string, int> m;
    // 참가 선수
    for(int i = 0; i < participant.size(); i++) {
        if(m.find(participant[i]) == m.end()) {
            m.insert(make_pair(participant[i],1));
        }
        else {
            m[participant[i]]++;
        }
    }

    // 완주한 선수
    for(int i = 0; i < completion.size(); i++) {
        m[completion[i]]--;
    }

    // 완주하지 못한 선수
    for(int i = 0; i < participant.size(); i++) {
        if(m[participant[i]] > 0) {
            answer = participant[i];
        }
    }

    return answer;
}