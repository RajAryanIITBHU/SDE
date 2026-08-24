# 4. Support Vector Machines (SVM) & Kernel Trick

## 1. What is a Support Vector Machine?
An **SVM** is a powerful classifier that finds the **Optimal Maximum-Margin Hyperplane** that maximizes the geometric distance (margin) between the closest data points of distinct classes (**Support Vectors**).

```
          Class +1         / (Margin Boundary: w^T x + b = +1)
             +            /
             +   [SV]    /  <-- Support Vector
                        /
                       /  <-- Optimal Separating Hyperplane (w^T x + b = 0)
                      /
            [SV]     /
              -     / (Margin Boundary: w^T x + b = -1)
          Class -1 /
             <---- 2 / ||w|| ----> (Total Margin Width)
```

---

## 2. Hard Margin vs. Soft Margin ($C$ Hyperparameter)

$$\min_{w, b, \xi} \frac{1}{2} \|w\|^2 + C \sum_{i=1}^m \xi_i$$

- **Hard Margin ($C = \infty$):** Requires 100% linear separability with zero misclassifications (fails if noise exists).
- **Soft Margin ($C$ parameter):** Allows some margin violations ($\xi_i > 0$).
  - **Large $C$:** Strictly penalizes errors $\to$ smaller margin, risk of **overfitting**.
  - **Small $C$:** Tolerates more errors $\to$ wider margin, smoother decision boundary, risk of **underfitting**.

---

## 3. The Kernel Trick (Non-Linear SVM)

When data is not linearly separable in low dimensions, the **Kernel Trick** implicitly maps data into a higher-dimensional space where it becomes linearly separable, **without ever physically computing coordinates in the high-dimensional space**!

$$K(x, z) = \langle \phi(x), \phi(z) \rangle$$

### Popular Kernels:
1. **Linear Kernel:** $K(x, z) = x^T z$
2. **Polynomial Kernel:** $K(x, z) = (\gamma x^T z + r)^d$
3. **Radial Basis Function (RBF / Gaussian Kernel):**
   $$K(x, z) = \exp(-\gamma \|x - z\|^2)$$
   - **$\gamma$ (Gamma) Parameter:** Controls the radius of influence of individual support vectors (Large $\gamma \to$ tight, complex boundary $\to$ overfitting).

---

## 4. Python Implementation

```python
from sklearn.datasets import make_moons
from sklearn.model_selection import GridSearchCV
from sklearn.svm import SVC

X, y = make_moons(n_samples=200, noise=0.2, random_state=42)

# Non-linear RBF SVM with GridSearch
param_grid = {
    "C": [0.1, 1.0, 10.0],
    "gamma": ["scale", 0.1, 1.0, 10.0]
}

grid = GridSearchCV(SVC(kernel="rbf"), param_grid, cv=5)
grid.fit(X, y)

print("Best Parameters:", grid.best_params_)
```
