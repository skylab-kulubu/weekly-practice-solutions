#include <iostream>
#include <vector>

template <typename Comparator>
const int inversions(const std::vector<int>& nums, Comparator cmp) {
    int inv{};
    
    const size_t n{ nums.size() };
    
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = i+1; j < n; ++j) {
            if (cmp(nums[i], nums[j])) {
                ++inv;
            }
        }
    }
    return inv;
}

const int solve(const std::vector<int>& nums) {
    const size_t n{ nums.size() };
    
    const int inv_asc{ inversions(nums, std::greater<>()) };
    const int inv_desc{ inversions(nums, std::less<>()) };
    
    return std::min(inv_asc, inv_desc);
}

int main() {
    size_t n{};
    std::cin >> n;
    
    std::vector<int> nums(n);
    for (size_t i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }
    std::cout << solve(nums) << '\n';
    
	return 0;
}
