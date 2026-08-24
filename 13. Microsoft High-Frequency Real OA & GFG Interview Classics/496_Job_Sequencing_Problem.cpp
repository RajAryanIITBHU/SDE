// Link: https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job {
    int id;
    int dead;
    int profit;
};

// ==========================================
// 1. OPTIMAL APPROACH (Greedy Profit Sorting + Disjoint Set / Slot Array)
// ==========================================
// Time Complexity  : O(n log n + n * maxDeadline)
// Space Complexity : O(maxDeadline)
/*
PSEUDOCODE:
1. Sort jobs by profit in descending order.
2. Find maxDeadline among all jobs.
3. slot array of size maxDeadline + 1 initialized to -1.
4. totalProfit = 0, jobCount = 0.
5. For each job:
     For d from min(n, job.dead) down to 1:
         if slot[d] == -1:
             slot[d] = job.id
             totalProfit += job.profit
             jobCount++
             break
6. Return {jobCount, totalProfit}.
*/

class Solution {
public:
    vector<int> JobScheduling(Job arr[], int n) {
        // Sort jobs in descending order of profit
        sort(arr, arr + n, [](const Job& a, const Job& b) {
            return a.profit > b.profit;
        });

        int maxDead = 0;
        for (int i = 0; i < n; i++) {
            maxDead = max(maxDead, arr[i].dead);
        }

        vector<int> slot(maxDead + 1, -1);
        int countJobs = 0;
        int maxProfit = 0;

        for (int i = 0; i < n; i++) {
            // Find a free slot from deadline down to 1
            for (int j = arr[i].dead; j > 0; j--) {
                if (slot[j] == -1) {
                    slot[j] = arr[i].id;
                    countJobs++;
                    maxProfit += arr[i].profit;
                    break;
                }
            }
        }

        return {countJobs, maxProfit};
    }
};
