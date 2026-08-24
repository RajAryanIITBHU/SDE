# 5. Cross-Validation & Hyperparameter Tuning

## 1. Cross-Validation Strategies

```
 K-FOLD CROSS-VALIDATION (e.g., K = 5)
 Iteration 1: [ Test  ] [ Train ] [ Train ] [ Train ] [ Train ] -> Score 1
 Iteration 2: [ Train ] [ Test  ] [ Train ] [ Train ] [ Train ] -> Score 2
 Iteration 3: [ Train ] [ Train ] [ Test  ] [ Train ] [ Train ] -> Score 3
 Iteration 4: [ Train ] [ Train ] [ Train ] [ Test  ] [ Train ] -> Score 4
 Iteration 5: [ Train ] [ Train ] [ Train ] [ Train ] [ Test  ] -> Score 5
 Final Validation Score = Average(Score 1 .. 5)
```

| Cross-Validation Method | When to Use |
| :--- | :--- |
| **K-Fold CV** | General regression and balanced classification tasks. |
| **Stratified K-Fold CV** | **Imbalanced classification datasets** (ensures each fold has identical target class proportions). |
| **TimeSeriesSplit** | Time series data (prevents lookahead data leakage; only trains on past to predict future). |
| **Leave-One-Out (LOOCV)** | Very tiny datasets ($N < 50$); computationally expensive ($K = N$). |

---

## 2. Hyperparameter Tuning: GridSearch vs. RandomSearch vs. Optuna

- **GridSearchCV:** Exhaustively evaluates **all combinations** of parameter values (guaranteed to find the best in grid, but slow).
- **RandomizedSearchCV:** Samples random combinations from parameter distributions (significantly faster with comparable results).
- **Optuna / Bayesian Optimization:** Uses probabilistic modeling (Tree-structured Parzen Estimator) to guide subsequent parameter trials towards the most promising regions of the search space.

### Python Code Example:

```python
from sklearn.datasets import load_iris
from sklearn.ensemble import RandomForestClassifier
from sklearn.model_selection import GridSearchCV, StratifiedKFold

X, y = load_iris(return_X_y=True)

# Define Model and Parameter Grid
rf = RandomForestClassifier(random_state=42)
param_grid = {
    "n_estimators": [50, 100, 200],
    "max_depth": [3, 5, None],
    "min_samples_split": [2, 5],
}

# Stratified 5-Fold Cross-Validation
cv = StratifiedKFold(n_splits=5, shuffle=True, random_state=42)

# Grid Search Execution
grid_search = GridSearchCV(
    estimator=rf,
    param_grid=param_grid,
    cv=cv,
    scoring="accuracy",
    n_jobs=-1
)

grid_search.fit(X, y)

print("Best Parameters:", grid_search.best_params_)
print("Best CV Accuracy:", grid_search.best_score_)
```
