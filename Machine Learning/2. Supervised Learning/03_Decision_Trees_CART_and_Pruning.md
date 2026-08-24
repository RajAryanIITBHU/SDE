# 3. Decision Trees, Splitting Criteria & Pruning

## 1. How Decision Trees Work (CART Algorithm)
A **Decision Tree** is a non-parametric model that recursively partitions the feature space into orthogonal rectangular regions by choosing the split that maximizes **Node Purity**.

---

## 2. Splitting Criteria Formulas

### A. Entropy & Information Gain (ID3 / C4.5)
$$\text{Entropy}(S) = -\sum_{i=1}^C p_i \log_2(p_i)$$

$$\text{Information Gain}(S, A) = \text{Entropy}(S) - \sum_{v \in \text{Values}(A)} \frac{|S_v|}{|S|} \text{Entropy}(S_v)$$

### B. Gini Impurity (CART - Default in Scikit-Learn)
$$\text{Gini}(S) = 1 - \sum_{i=1}^C p_i^2$$

- **Gini vs. Entropy:** Gini is computationally faster (no logarithm calculations); produces nearly identical trees in practice.

### C. Variance Reduction (For Decision Tree Regression)
$$\text{MSE Split} = \sum_{i \in \text{Left}} (y_i - \bar{y}_{\text{Left}})^2 + \sum_{i \in \text{Right}} (y_i - \bar{y}_{\text{Right}})^2$$

---

## 3. Preventing Overfitting: Pruning Techniques

Decision trees have a natural tendency to overfit down to 100% training accuracy.

- **Pre-Pruning (Early Stopping):**
  - Set `max_depth` (e.g., 3 to 10).
  - Set `min_samples_split` (minimum samples required to split a node).
  - Set `min_samples_leaf` (minimum samples required in a leaf node).
- **Post-Pruning (Cost-Complexity Pruning / Minimal Cost-Complexity $\alpha$):**
  - Grow the full tree, then prune subtrees that minimize:
    $$R_\alpha(T) = R(T) + \alpha |T|$$

---

## 4. Python Implementation

```python
from sklearn.datasets import load_iris
from sklearn.tree import DecisionTreeClassifier, export_text

X, y = load_iris(return_X_y=True)

# Pre-pruned Decision Tree
tree_clf = DecisionTreeClassifier(
    criterion="gini",
    max_depth=3,
    min_samples_leaf=5,
    random_state=42
)
tree_clf.fit(X, y)

# Print human-readable decision rules
rules = export_text(tree_clf, feature_names=load_iris().feature_names)
print(rules)
```
