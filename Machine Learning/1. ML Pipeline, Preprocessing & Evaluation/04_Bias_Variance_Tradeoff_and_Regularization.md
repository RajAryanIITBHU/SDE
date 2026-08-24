# 4. Bias-Variance Tradeoff & Regularization (L1 Lasso, L2 Ridge, ElasticNet)

## 1. The Bias-Variance Tradeoff

$$\text{Total Expected Error} = \text{Bias}^2 + \text{Variance} + \text{Irreducible Noise } (\sigma^2)$$

```
ERROR
  ^               Total Error
  |                  \   /
  |    High Bias      \ /       High Variance
  |   (Underfitting)   v        (Overfitting)
  |                  Optimal
  +---------------------------------------------> Model Complexity
```

- **High Bias (Underfitting):** Model is too simple (e.g., linear line for non-linear data); performs poorly on **both train and test sets**.
- **High Variance (Overfitting):** Model is overly complex and memorizes noise; performs great on training data but **generalizes terribly on test data**.

---

## 2. Regularization Techniques (L1 vs. L2 vs. ElasticNet)

Regularization penalizes large weight coefficients to prevent overfitting.

$$\text{Loss}_{\text{Regularized}} = \text{MSE} + \lambda \times \text{Penalty}$$

```
+-----------------------------------------------------------------------------------+
| REGULARIZATION | PENALTY TERM                       | KEY BENEFIT                 |
+----------------+------------------------------------+-----------------------------+
| L1 (Lasso)     | $\lambda \sum |\beta_j|$           | Sparsity: Forces useless    |
|                |                                    | weights to EXACTLY ZERO     |
|                |                                    | (Built-in feature selection)|
+----------------+------------------------------------+-----------------------------+
| L2 (Ridge)     | $\lambda \sum \beta_j^2$           | Shrinkage: Shrinks weights  |
|                |                                    | close to zero (handles      |
|                |                                    | multicollinearity)          |
+----------------+------------------------------------+-----------------------------+
| ElasticNet     | $\alpha L_1 + (1 - \alpha) L_2$    | Combines feature selection  |
|                |                                    | with correlated feature     |
|                |                                    | stability                   |
+----------------+------------------------------------+-----------------------------+
```

### Python Implementation:

```python
from sklearn.linear_model import ElasticNet, Lasso, LinearRegression, Ridge

# Baseline Linear Regression (No Regularization)
lr = LinearRegression()

# L1 Lasso Regularization (Promotes Sparsity / Feature Selection)
lasso = Lasso(alpha=0.1)

# L2 Ridge Regularization (Prevents Overfitting from Collinear Features)
ridge = Ridge(alpha=1.0)

# ElasticNet Combination
elastic_net = ElasticNet(alpha=0.1, l1_ratio=0.5)
```
