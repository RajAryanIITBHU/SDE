/*
 * ============================================================================
 * Concept: Boyer-Moore Majority Vote Algorithm
 * Subtopic: Arrays, Hashing & Prefix Sum
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Boyer-Moore Voting Algorithm finds the majority element in an array (an element that appears more than N/2 or N/K times) in O(N) time and O(1) space.
It uses a candidate and a counter. Increment count when element matches candidate, decrement when it differs. Reset candidate when count hits 0.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(N) - 1 or 2 linear passes.
 * - Space Complexity: O(1) - constant extra space.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Finding element occurring > N/2 times or > N/K times.
- Requires O(1) space constraints (hash map is O(N) space).
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Majority Element (> N/2 times) - 1 Candidate.
2. Majority Element II (> N/3 times) - 2 Candidates and 2 Counters.
3. Majority Element (> N/K times) - K-1 Candidates and K-1 Counters.
4. Verification Pass: If majority element is not guaranteed to exist, run a 2nd pass to count candidate frequency.
 */

#include <iostream>
#include <vector>

using namespace std;

// Find Majority Element (> N/2 times)
int majorityElement(const vector<int>& nums) {
    int candidate = 0, count = 0;
    for (int num : nums) {
        if (count == 0) candidate = num;
        count += (num == candidate) ? 1 : -1;
    }
    return candidate;
}

// Find Majority Elements (> N/3 times)
vector<int> majorityElementII(const vector<int>& nums) {
    int cand1 = 0, cand2 = 0, count1 = 0, count2 = 0;
    for (int num : nums) {
        if (num == cand1) count1++;
        else if (num == cand2) count2++;
        else if (count1 == 0) { cand1 = num; count1 = 1; }
        else if (count2 == 0) { cand2 = num; count2 = 1; }
        else { count1--; count2--; }
    }

    // Verification pass
    count1 = 0; count2 = 0;
    for (int num : nums) {
        if (num == cand1) count1++;
        else if (num == cand2) count2++;
    }

    vector<int> result;
    int n = nums.size();
    if (count1 > n / 3) result.push_back(cand1);
    if (count2 > n / 3 && cand1 != cand2) result.push_back(cand2);
    return result;
}

int main() {
    vector<int> nums = {3, 2, 3};
    cout << "Majority Element (>N/2): " << majorityElement(nums) << "\n";
    vector<int> nums2 = {1, 1, 1, 3, 3, 2, 2, 2};
    auto res = majorityElementII(nums2);
    cout << "Majority Elements (>N/3): ";
    for (int x : res) cout << x << " ";
    cout << "\n";
    return 0;
}
