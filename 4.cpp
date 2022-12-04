#include "utils.hpp"

using namespace std;

int main() {
    string line;
    vector<int> nums;
    int sum=0, sum2=0;
    auto is_full_subset = [&](const vector<int> nums) {
        return ((nums[0] >= nums[2] && nums[1] <= nums[3]) || (nums[0] <= nums[2] && nums[1] >= nums[3]));
    };
    auto is_union = [&](const vector<int> nums) {
        return is_full_subset(nums) || (nums[0] <= nums[2] && nums[2] <= nums[1]) || (nums[2] <= nums[0] && nums[0] <= nums[3]);
    };
    while (cin >> line) {
        nums = splitString<int>(line, ",-");
        if (is_full_subset(nums)) sum++;
        if (is_union(nums)) sum2++;
    }
    cout << sum << endl;
    cout << sum2 << endl;
}