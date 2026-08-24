# 2. Feature Scaling, Engineering & Selection Techniques

## 1. Feature Scaling: Normalization vs. Standardization

| Feature | Standardization (`StandardScaler`) | Normalization (`MinMaxScaler`) |
| :--- | :--- | :--- |
| **Formula** | $z = \frac{x - \mu}{\sigma}$ | $x_{\text{scaled}} = \frac{x - x_{\min}}{x_{\max} - x_{\min}}$ |
| **Output Range** | $\mu = 0, \sigma = 1$ (Unbounded) | $[0, 1]$ (or custom range $[-1, 1]$) |
| **Outlier Sensitivity** | Robust to moderate outliers | Highly sensitive to outliers |
| **When to Use** | Algorithms assuming zero-mean Gaussian distribution (Linear Models, SVM, PCA, Neural Networks) | Distance-based models with bounded features (KNN, Image pixel scaling $[0, 255] \to [0, 1]$) |

> [!NOTE]
> **Tree-Based Models (Decision Trees, Random Forest, XGBoost) DO NOT require feature scaling** because tree splits are monotonic and scale-invariant.

---

## 2. Feature Selection Techniques

```
                         FEATURE SELECTION
                                 |
        +------------------------+------------------------+
        |                        |                        |
        v                        v                        v
  FILTER METHODS           WRAPPER METHODS         EMBEDDED METHODS
  - Variance Threshold     - Recursive Feature      - L1 Lasso Regularization
  - Correlation Matrix       Elimination (RFE)     - Tree Feature Importance
  - Chi-Square / ANOVA     - Forward / Backward       (Random Forest, XGBoost)
  - Mutual Information       Selection
```

### Python Implementation of Feature Selection Methods:

```python
import numpy as np
import pandas as pd
from sklearn.datasets import make_classification
from sklearn.ensemble import RandomForestClassifier
from sklearn.feature_selection import RFE, SelectKBest, VarianceThreshold, f_classif
from sklearn.linear_model import LogisticRegression

# Generate sample dataset
X, y = make_classification(n_samples=200, n_features=10, n_informative=5, random_state=42)

# 1. Filter Method: Remove Quasi-Constant Features (Variance < 0.01)
var_thresh = VarianceThreshold(threshold=0.01)
X_var = var_thresh.fit_transform(X)

# 2. Filter Method: Select top K features using ANOVA F-value
k_best = SelectKBest(score_func=f_classif, k=5)
X_kbest = k_best.fit_transform(X, y)

# 3. Wrapper Method: Recursive Feature Elimination (RFE)
model = LogisticRegression(max_iter=1000)
rfe = RFE(estimator=model, n_features_to_select=5)
rfe.fit(X, y)
print("RFE Selected Feature Mask:", rfe.support_)

# 4. Embedded Method: Feature Importance from Random Forest
rf = RandomForestClassifier(n_estimators=100, random_state=42)
rf.fit(X, y)
print("Tree Feature Importances:", rf.feature_importances_)
```
