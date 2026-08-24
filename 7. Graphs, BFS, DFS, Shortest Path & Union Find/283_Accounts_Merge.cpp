// Link: https://leetcode.com/problems/accounts-merge/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <numeric>
#include <algorithm>

using namespace std;

// Disjoint Set Union (DSU)
class DSU {
public:
    vector<int> parent;

    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }

    void unite(int i, int j) {
        int rootI = find(i);
        int rootJ = find(j);
        if (rootI != rootJ) {
            parent[rootI] = rootJ;
        }
    }
};

// ==========================================
// 1. OPTIMAL APPROACH (Union-Find on Account Indices)
// ==========================================
// Time Complexity  : O(N * K * log(N * K)), where N is accounts, K is max emails
// Space Complexity : O(N * K)
/*
PSEUDOCODE:
1. emailToAcc: email -> accountIndex.
2. Initialize DSU for n accounts.
3. For i from 0 to n-1:
     For j from 1 to accounts[i].size() - 1:
         email = accounts[i][j]
         if email in emailToAcc:
             dsu.unite(i, emailToAcc[email])
         else:
             emailToAcc[email] = i
4. Group emails by root parent account index: mergedEmails[rootParent].
5. Format and sort emails for each merged account:
     ans.push_back({accounts[rootParent][0], sorted_emails...})
6. Return ans.
*/

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DSU dsu(n);
        unordered_map<string, int> emailToAcc;

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < (int)accounts[i].size(); j++) {
                string email = accounts[i][j];

                if (emailToAcc.find(email) != emailToAcc.end()) {
                    dsu.unite(i, emailToAcc[email]);
                } else {
                    emailToAcc[email] = i;
                }
            }
        }

        // Group emails by component root
        unordered_map<int, vector<string>> merged;
        for (auto& p : emailToAcc) {
            string email = p.first;
            int rootAcc = dsu.find(p.second);
            merged[rootAcc].push_back(email);
        }

        vector<vector<string>> ans;
        for (auto& p : merged) {
            int rootAcc = p.first;
            vector<string> emails = p.second;
            sort(emails.begin(), emails.end());

            vector<string> acc = {accounts[rootAcc][0]}; // Account Name
            acc.insert(acc.end(), emails.begin(), emails.end());
            ans.push_back(acc);
        }

        return ans;
    }
};
