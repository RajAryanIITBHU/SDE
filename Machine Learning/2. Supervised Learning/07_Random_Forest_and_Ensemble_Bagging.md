# 7. Random Forest & Ensemble Learning (Bagging)

## 1. What is Ensemble Learning?
**Ensemble Learning** combines multiple base models (weak learners) to build a single superior predictive model with **lower variance and higher accuracy**.

```
                +------------------------------------+
                |         ENSEMBLE LEARNING          |
                +------------------------------------+
                                   |
                +------------------+------------------+
                |                                     |
                v                                     v
       BAGGING (PARALLEL)                    BOOSTING (SEQUENTIAL)
   - Bootstrap Aggregating                - Sequential Error Correction
   - Reduces VARIANCE                     - Reduces BIAS
   - e.g. Random Forest                   - e.g. XGBoost, AdaBoost, LightGBM
```

---

## 2. Bagging (Bootstrap Aggregating)
1. **Bootstrapping:** Create $B$ random subsets of the training dataset with replacement (each containing $\approx 63.2\%$ unique samples).
2. **Train in Parallel:** Train an independent base model on each bootstrap sample.
3. **Aggregation:** Combine predictions via **Majority Voting** (Classification) or **Averaging** (Regression).

---

## 3. Random Forest (Double Randomization)
Random Forest enhances bagging by introducing **Feature Randomness (Random Subspace Method)**:
- At every decision tree node split, it selects only a **random subset of $\sqrt{D}$ features** (instead of evaluating all $D$ features).
- **Why?** De-correlates individual decision trees so their average has significantly lower variance!

---

## 4. Out-of-Bag (OOB) Evaluation
- Approximately **$36.8\%$ of data samples** are never picked in any given bootstrap sample (Out-of-Bag samples).
- **OOB Score:** The model is evaluated on samples it never saw during training, providing an **unbiased validation score without needing a separate validation set**!

---

## 5. Python Implementation

```python
from sklearn.datasets import load_breast_cancer
from sklearn.ensemble import RandomForestClassifier
from sklearn.model_selection import train_test_split

X, y = load_breast_cancer(return_X_y=True)
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

rf = RandomForestClassifier(
    n_estimators=100,
    max_features="sqrt",
    oob_score=True,
    random_state=42
)
rf.fit(X_train, y_train)

print(f"OOB Validation Accuracy: {rf.oob_score_:.4f}")
print(f"Test Set Accuracy: {rf.score(X_test, y_test):.4f}")
```
