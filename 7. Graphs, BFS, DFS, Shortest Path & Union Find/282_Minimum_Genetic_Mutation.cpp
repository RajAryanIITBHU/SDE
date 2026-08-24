// Link: https://leetcode.com/problems/minimum-genetic-mutation/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (BFS Gene Transformation)
// ==========================================
// Time Complexity  : O(N * 8 * 4) = O(32 * N), where N is bank size
// Space Complexity : O(N)
/*
PSEUDOCODE:
1. Store bank in unordered_set bankSet.
2. If endGene not in bankSet return -1.
3. char choices = {'A', 'C', 'G', 'T'}.
4. Initialize queue<string> q, push startGene, mutations = 0.
5. While !q.empty():
     levelSize = q.size()
     For i from 0 to levelSize - 1:
         gene = q.front(), q.pop()
         if gene == endGene return mutations
         For j from 0 to 7:
             origChar = gene[j]
             For c in choices:
                 gene[j] = c
                 if bankSet.count(gene):
                     bankSet.erase(gene)
                     q.push(gene)
             gene[j] = origChar
     mutations++
6. Return -1.
*/

class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> bankSet(bank.begin(), bank.end());
        if (bankSet.find(endGene) == bankSet.end()) return -1;

        vector<char> choices = {'A', 'C', 'G', 'T'};
        queue<string> q;
        q.push(startGene);
        int mutations = 0;

        while (!q.empty()) {
            int sz = q.size();

            for (int i = 0; i < sz; i++) {
                string gene = q.front();
                q.pop();

                if (gene == endGene) {
                    return mutations;
                }

                for (int j = 0; j < (int)gene.length(); j++) {
                    char orig = gene[j];

                    for (char c : choices) {
                        gene[j] = c;

                        if (bankSet.find(gene) != bankSet.end()) {
                            bankSet.erase(gene); // Mark visited
                            q.push(gene);
                        }
                    }

                    gene[j] = orig;
                }
            }

            mutations++;
        }

        return -1;
    }
};
