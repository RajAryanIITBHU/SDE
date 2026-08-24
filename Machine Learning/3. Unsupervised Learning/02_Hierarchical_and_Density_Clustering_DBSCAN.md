# 2. Hierarchical Clustering & DBSCAN (Density-Based Clustering)

## 1. Hierarchical Clustering (Agglomerative vs. Divisive)

```
        DENDROGRAM (Tree Diagram)
             +---------------+
             |               |
         +---+---+       +---+---+
         |       |       |       |
       [ A ]   [ B ]   [ C ]   [ D ]
```

- **Agglomerative (Bottom-Up - Standard):** Starts with every data point in its own single cluster; iteratively merges the closest pair of clusters until one single root cluster remains.
- **Divisive (Top-Down):** Starts with all points in 1 cluster and recursively splits.
- **Linkage Criteria:**
  1. **Single Linkage:** $\min d(x, y)$ (Minimum distance between any two points in clusters).
  2. **Complete Linkage:** $\max d(x, y)$ (Maximum distance).
  3. **Average Linkage:** Average pairwise distance between all points.
  4. **Ward's Linkage:** Minimizes the total within-cluster variance increase (Most popular).

---

## 2. DBSCAN (Density-Based Spatial Clustering of Applications with Noise)

### Why DBSCAN is Revolutionary:
- **Does NOT require specifying the number of clusters $K$ in advance.**
- Can discover clusters of **arbitrary non-spherical shapes** (rings, concentric moons).
- Automatically detects and isolates **outliers / noise points**!

### Two Core Parameters:
1. **$\epsilon$ (Eps / Epsilon):** Maximum radius neighborhood around a point.
2. **$\text{MinPts}$:** Minimum number of data points required within the $\epsilon$-neighborhood to form a dense region.

### 3 Point Classifications:
1. **Core Point:** Has at least $\text{MinPts}$ within its $\epsilon$-neighborhood.
2. **Border Point:** Has fewer than $\text{MinPts}$, but falls within the $\epsilon$-neighborhood of a Core Point.
3. **Noise Point (Outlier):** Neither a Core nor a Border point (assigned cluster label `-1`).

---

## 3. Python Implementation

```python
from sklearn.datasets import make_moons
from sklearn.cluster import DBSCAN
import numpy as np

X, _ = make_moons(n_samples=300, noise=0.08, random_state=42)

# DBSCAN identifies non-linear moons easily!
dbscan = DBSCAN(eps=0.2, min_samples=5)
labels = dbscan.fit_predict(X)

n_clusters = len(set(labels)) - (1 if -1 in labels else 0)
n_noise = list(labels).count(-1)

print(f"Discovered Clusters: {n_clusters}, Noise Outliers: {n_noise}")
```
