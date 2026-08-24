# 8. Boosting Algorithms: AdaBoost, Gradient Boosting & XGBoost

## 1. What is Boosting?
Unlike Bagging (which trains trees independently in parallel), **Boosting trains models sequentially**: each new base learner is trained to **correct the specific prediction errors (residuals) made by previous models**.

---

## 2. The 3 Major Boosting Algorithms Compared

```
+-----------------------------------------------------------------------------------+
| ALGORITHM        | CORE MECHANISM                       | REGULARIZATION / SPEED  |
+------------------+--------------------------------------+-------------------------+
| **AdaBoost**     | Re-weights misclassified data points | Weak (Sensitive to      |
|                  | exponentially higher at each round   | outliers)               |
+------------------+--------------------------------------+-------------------------+
| **Gradient       | Fits new trees directly to the       | Slower sequential tree  |
| Boosting (GBM)** | **Pseudo-Residuals (Gradients)** of  | building                |
|                  | the loss function                    |                         |
+------------------+--------------------------------------+-------------------------+
| **XGBoost**      | Uses **2nd-Order Taylor expansion**  | Built-in L1/L2 weights, |
| (Extreme Grad)** | (Hessians + Gradients) + Exact split | parallel histogram tree |
|                  | search algorithm                     | construction            |
+------------------+--------------------------------------+-------------------------+
```

---

## 3. Mathematical Intuition of Gradient Boosting

Let $F_0(x) = \arg\min_\gamma \sum L(y_i, \gamma)$ be the initial constant prediction (mean of $y$).

At each iteration $m = 1, 2, \dots, M$:
1. Compute the **Residual (Negative Gradient)** for each sample:
   $$r_{im} = -\left[ \frac{\partial L(y_i, F(x_i))}{\partial F(x_i)} \right]_{F(x) = F_{m-1}(x)}$$
2. Train a small regression tree $h_m(x)$ to predict the residuals $r_{im}$.
3. Update the ensemble model with learning rate (shrinkage) $\eta$:
   $$F_m(x) = F_{m-1}(x) + \eta \cdot h_m(x)$$

---

## 4. Python Implementation (XGBoost / LightGBM)

```python
from sklearn.datasets import make_classification
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score
import xgboost as xgb

X, y = make_classification(n_samples=1000, n_features=20, random_state=42)
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Instantiate and train XGBoost
model = xgb.XGBClassifier(
    n_estimators=100,
    learning_rate=0.05,
    max_depth=4,
    subsample=0.8,
    colsample_bytree=0.8,
    random_state=42
)
model.fit(X_train, y_train)

y_pred = model.predict(X_test)
print(f"XGBoost Test Accuracy: {accuracy_score(y_test, y_pred):.4f}")
```
