/*
 * ============================================================================
 * Concept: Microsoft Real OA Simulations (Minimum Platforms & Meetings)
 * Subtopic: Microsoft High-Frequency Real OA & GFG Interview Classics
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Simulates real Microsoft OA scheduling & platform optimization tasks.
Minimum Platforms (GFG): Find min railway platforms needed so no train waits.
Strategy: Sort arrival and departure arrays independently. Use two pointers `i` (arrivals) and `j` (departures). If `arr[i] <= dep[j]`, platform_needed++, i++; else platform_needed--, j++.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(N log N) sorting time.
 * - Space Complexity: O(1) space after sorting.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Minimum Platforms (GFG).
- Meeting Rooms III (LC 2402).
- Activity Selection.
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Minimum Platforms (GFG Classic).
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findPlatform(vector<int>& arr, vector<int>& dep) {
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int n = arr.size();
    int plat_needed = 1, max_platforms = 1;
    int i = 1, j = 0;

    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            plat_needed++;
            i++;
        } else {
            plat_needed--;
            j++;
        }
        max_platforms = max(max_platforms, plat_needed);
    }
    return max_platforms;
}

int main() {
    vector<int> arr = {900, 940, 950, 1100, 1500, 1800};
    vector<int> dep = {910, 1200, 1120, 1130, 1900, 2000};
    cout << "Min Platforms Needed: " << findPlatform(arr, dep) << "\n"; // 3
    return 0;
}
