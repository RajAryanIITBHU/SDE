# 4. Principal Component Analysis (PCA)

## 1. What is PCA?
**Principal Component Analysis (PCA)** is an unsupervised linear dimensionality reduction technique that projects high-dimensional data onto orthogonal axes of **maximum variance** (**Principal Components**), while minimizing reconstruction error.

---

## 2. Mathematical Derivation (Step-by-Step)

```
1. STANDARDIZATION: Center features to zero mean and unit variance:
      X_std = (X - μ) / σ

2. COVARIANCE MATRIX: Compute D x D symmetric covariance matrix:
      Σ = (1 / (m - 1)) * X_std^T X_std

3. EIGEN DECOMPOSITION: Compute eigenvalues λ and eigenvectors v of Σ:
      Σ v = λ v

4. SORT & SELECT: Sort eigenvectors in descending order of their eigenvalues λ.
   Select top k eigenvectors forming projection matrix W (D x k).

5. TRANSFORM: Project original data onto k-dimensional subspace:
      X_projected = X_std * W
```

- **Explained Variance Ratio:** The percentage of variance captured by the $i$-th principal component is $\frac{\lambda_i}{\sum \lambda_j}$.

---

## 3. Python Implementation (NumPy & Scikit-Learn)

```python
import numpy as np
from sklearn.datasets import load_iris
from sklearn.decomposition import PCA
from sklearn.preprocessing import StandardScaler

X, y = load_iris(return_X_y=True)

# 1. Standardize (Mandatory before PCA!)
X_scaled = StandardScaler().fit_transform(X)

# 2. Fit PCA retaining 95% of total variance
pca = PCA(n_components=0.95)
X_pca = pca.fit_transform(X_scaled)

print(f"Original shape: {X.shape} -> Reduced shape: {X_pca.shape}")
print("Explained Variance Ratio per Component:", pca.explained_variance_ratio_)
```
