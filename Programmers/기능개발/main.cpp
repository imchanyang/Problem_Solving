#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int size = progresses.size();

    // 작업 완료 수
    int count = 0;

    // 작업이 모두 완료되면 종료
    while(count < size) {

        // 배포 기능 수 초기화
        int n = 0;

        // 작업 진도 나가기
        for(int i = count; i < size; i++) {
            progresses[i] += speeds[i];
        }

        // 조건에 맞게 완료된 작업이 있으면 배포 준비
        while(count < size && progresses[count] >= 100) {
            n++;
            count++;
        }

        // 배포 가능한 기능이 있으면 배포
        if(n != 0) {
            answer.push_back(n);
            continue;
        }
    }
    return answer;
}