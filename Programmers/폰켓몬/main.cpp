#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int N = nums.size();

    // set은 중복을 허용하지 않는 균형 이진 트리
    set<int> s;

    for(int i = 0; i < nums.size(); i++) {
        s.insert(nums[i]);
    }

    if(s.size() < (N/2)) {
        answer = s.size();
    }
    else {
        answer = N/2;
    }

    return answer;
}