# 1. K-Means Clustering, K-Means++ & Evaluation

## 1. What is K-Means Clustering?
**K-Means** is a centroid-based, iterative partitioning algorithm that divides an unlabelled dataset of $N$ points into $K$ non-overlapping clusters by minimizing the **Within-Cluster Sum of Squares (Inertia / WCSS)**:

$$\text{WCSS} = \sum_{k=1}^K \sum_{x \in C_k} \| x - \mu_k \|^2$$

---

## 2. The 4-Step K-Means Algorithm (Lloyd's Algorithm)

```
1. Initialize K cluster centroids (μ_1, μ_2, ... μ_K).
2. ASSIGNMENT STEP: Assign each data point x_i to the closest centroid:
      c^(i) = argmin_k || x_i - μ_k ||^2
3. UPDATE STEP: Recompute each centroid as the arithmetic mean of all points assigned to it:
      μ_k = (1 / |C_k|) * ∑_{x ∈ C_k} x
4. REPEAT Steps 2 & 3 until centroids converge (no points change clusters).
```

---

## 3. K-Means++ Initialization (Fixing Bad Local Minima)
Standard random centroid initialization can converge to poor local minima.
- **K-Means++:** Initializes the first centroid randomly, then chooses subsequent centroids with probability proportional to the **squared distance to the nearest existing centroid** ($P(x) \propto D(x)^2$).
- Spreads centroids far apart initially $\to$ Guaranteed $O(\log K)$ approximation bound!

---

## 4. How to Find Optimal $K$

1. **The Elbow Method:** Plot WCSS (Inertia) vs. $K$. Choose the point where the rate of decrease abruptly bends ("elbow").
2. **The Silhouette Score:**
   $$s(i) = \frac{b(i) - a(i)}{\max(a(i), b(i))} \quad \in [-1, +1]$$
   - $a(i)$: Mean intra-cluster distance.
   - $b(i)$: Mean nearest-cluster distance.
   - Score close to $+1.0$ indicates well-separated, dense clusters.

---

## 5. Other K-Means Variants
- **K-Modes:** Uses frequency modes and Hamming distance for **categorical datasets**.
- **Fuzzy C-Means (FCM):** Soft clustering where each point has a fractional membership degree $[0, 1]$ in every cluster ($\sum \mu_{ij} = 1$).
