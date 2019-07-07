#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>


#include "../utils/VectorUtils.hpp"
#include "../utils/PrintUtils.hpp"

// https://leetcode.com/problems/maximum-average-subarray-i/

// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        if (nums.size() < k) return 0;
        double sum = 0;
        for (int i = 0; i < k; ++i) {
            sum += nums[i];
        }
        double maxa = sum;
        for (int i = k; i < nums.size(); ++i) {
            sum += (nums[i] - nums[i-k]);
            maxa = max(maxa, sum);
        }
        return maxa / k;
    }
};

void test1() {
    vector<int> v1{1,12,-5,-6,50,3};

    cout << "12.75 ? " << Solution().findMaxAverage(v1, 4) << endl;
}

void test2() {

}

void test3() {

}