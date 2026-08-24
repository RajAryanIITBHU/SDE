/*
 * ============================================================================
 * Concept: Search in a 2D Matrix
 * Subtopic: Binary Search & Search on Answer
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Search in row-wise / column-wise sorted 2D grid.
- Variant 1 (LC 74): Whole matrix is flattened sorted. Virtual 1D index `mid` maps to `(mid / cols, mid % cols)`.
- Variant 2 (LC 240): Rows and Cols sorted independently. Start at Top-Right `(0, cols-1)`, move Left if `val > target`, Down if `val < target`.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(log(M * N)) for LC 74, O(M + N) for LC 240.
 * - Space Complexity: O(1) space complexity.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Search target in sorted 2D matrix.
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Search a 2D Matrix I (LC 74).
2. Search a 2D Matrix II (LC 240 - Top-Right staircase walk).
 */

#include <iostream>
#include <vector>

using namespace std;

// Search 2D Matrix II (LC 240) - Staircase Search
bool searchMatrix(const vector<vector<int>>& matrix, int target) {
    if (matrix.empty()) return false;
    int r = 0, c = matrix[0].size() - 1;
    while (r < (int)matrix.size() && c >= 0) {
        if (matrix[r][c] == target) return true;
        else if (matrix[r][c] > target) c--;
        else r++;
    }
    return false;
}

int main() {
    vector<vector<int>> mat = {{1, 4, 7}, {2, 5, 8}, {3, 6, 9}};
    cout << "Found 5: " << (searchMatrix(mat, 5) ? "Yes" : "No") << "\n";
    return 0;
}
