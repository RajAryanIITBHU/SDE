# 2. Logistic Regression & Classification

## 1. Why Linear Regression Fails for Classification
- Linear regression output is unbounded ($(-\infty, +\infty)$), making it unsuitable for probabilities $[0, 1]$.
- Sensitive to extreme outliers which shift the classification decision threshold.

---

## 2. Mathematical Formulation of Logistic Regression

Logistic Regression passes the linear combination $z = \theta^T X$ through the **Sigmoid (Logistic) Function** $\sigma(z)$:

$$\hat{p} = \sigma(z) = \frac{1}{1 + e^{-z}} = \frac{1}{1 + e^{-(\theta^T X)}}$$

```
Probability p
 1.0 +                      /-------
     |                     /
 0.5 + - - - - - - - - - -/ - - - - - - Threshold = 0.5 (z = 0)
     |                   /
 0.0 + -------/---------+------------> z = θ^T X
```

### Decision Boundary:
$$\text{Predict Class 1 if } \hat{p} \ge 0.5 \iff z \ge 0$$
$$\text{Predict Class 0 if } \hat{p} < 0.5 \iff z < 0$$

---

## 3. Cost Function: Binary Cross-Entropy (Log-Loss)

MSE produces a non-convex cost surface with local minima for logistic regression. Hence, **Log-Loss** (derived from Maximum Likelihood Estimation) is used:

$$J(\theta) = -\frac{1}{m} \sum_{i=1}^m \left[ y^{(i)} \log(\hat{p}^{(i)}) + (1 - y^{(i)}) \log(1 - \hat{p}^{(i)}) \right]$$

### Gradient Update:
$$\frac{\partial J(\theta)}{\partial \theta_j} = \frac{1}{m} \sum_{i=1}^m (\sigma(\theta^T X^{(i)}) - y^{(i)}) x_j^{(i)}$$

---

## 4. Python Implementation

```python
import numpy as np
from sklearn.datasets import load_breast_cancer
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import classification_report
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler

# Load dataset
X, y = load_breast_cancer(return_X_y=True)
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Scale features
scaler = StandardScaler()
X_train = scaler.fit_transform(X_train)
X_test = scaler.transform(X_test)

# Train Logistic Regression
clf = LogisticRegression(C=1.0, max_iter=1000)
clf.fit(X_train, y_train)

# Evaluate
y_pred = clf.predict(X_test)
print(classification_report(y_test, y_pred))
```
