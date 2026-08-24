# 5. K-Nearest Neighbors (KNN)

## 1. What is KNN?
**K-Nearest Neighbors (KNN)** is a **non-parametric, instance-based "Lazy Learner"**:
- **Zero Training Time:** It does not build an explicit mathematical model during training; it simply stores the training instances.
- **Inference Time ($O(N \cdot D)$):** To classify a query point, it computes distances to all $N$ training samples, selects the $K$ closest neighbors, and takes a **majority vote** (or average for regression).

---

## 2. Distance Metrics

1. **Euclidean Distance ($L_2$ Norm):**
   $$d(p, q) = \sqrt{\sum_{i=1}^n (p_i - q_i)^2}$$
2. **Manhattan Distance ($L_1$ Norm / City Block):**
   $$d(p, q) = \sum_{i=1}^n |p_i - q_i|$$
3. **Minkowski Distance ($L_p$ Norm):**
   $$d(p, q) = \left( \sum_{i=1}^n |p_i - q_i|^p \right)^{1/p}$$
   *(When $p = 1 \to$ Manhattan, $p = 2 \to$ Euclidean).*

---

## 3. How to Choose the Optimal Value of $K$
- **Small $K$ (e.g., $K = 1$):** Highly flexible, captures fine patterns, but **extremely sensitive to noise and outliers (High Variance / Overfitting)**.
- **Large $K$ (e.g., $K = N$):** Smooth decision boundary, but washes out minority classes and predicts the global majority class **(High Bias / Underfitting)**.
- **Rule of Thumb:** $K = \sqrt{N}$ (Prefer an **odd number** for binary classification to prevent ties).

---

## 4. The Curse of Dimensionality
As the number of features (dimensions $D$) increases, the volume of the space grows exponentially, making all data points appear equidistant from one another, causing distance-based metrics in KNN to lose discriminative power.
- **Fix:** Apply PCA or Feature Selection before running KNN. Feature scaling is **mandatory** before KNN.
