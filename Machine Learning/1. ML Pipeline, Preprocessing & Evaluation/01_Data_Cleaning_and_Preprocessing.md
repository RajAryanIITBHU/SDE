# 1. Data Cleaning & Preprocessing in Machine Learning

## The Machine Learning Pipeline Workflow

```
[ Raw Data ] ---> [ Data Cleaning ] ---> [ Feature Engineering ] ---> [ Train/Test Split ]
                                                                             |
[ Deployment / MLOps ] <--- [ Model Evaluation ] <--- [ Model Training ] <---+
```

---

## 1. Handling Missing Data (Imputation Techniques)

| Strategy | When to Use | Scikit-Learn Class |
| :--- | :--- | :--- |
| **Mean / Median Imputation** | Numerical features (Median preferred for skewed data with outliers) | `SimpleImputer(strategy='median')` |
| **Mode Imputation** | Categorical features | `SimpleImputer(strategy='most_frequent')` |
| **KNN Imputation** | Imputes missing value based on $K$ most similar rows | `KNNImputer(n_neighbors=5)` |
| **Iterative / MICE Imputation** | Models each feature with missing values as a function of other features | `IterativeImputer()` |

```python
import numpy as np
import pandas as pd
from sklearn.impute import KNNImputer, SimpleImputer

# Sample Data with Missing Values
df = pd.DataFrame({
    "Age": [25, np.nan, 28, 35, 40],
    "Salary": [50000, 54000, np.nan, 80000, 110000],
    "Department": ["IT", "HR", "IT", np.nan, "Finance"],
})

# 1. Numeric Median Imputation
num_imputer = SimpleImputer(strategy="median")
df[["Age", "Salary"]] = num_imputer.fit_transform(df[["Age", "Salary"]])

# 2. Categorical Mode Imputation
cat_imputer = SimpleImputer(strategy="most_frequent")
df[["Department"]] = cat_imputer.fit_transform(df[["Department"]])

print("Cleaned DataFrame:\n", df)
```

---

## 2. Outlier Detection and Treatment

### A. Interquartile Range (IQR) Method
- Data points outside $[Q_1 - 1.5 \times \text{IQR}, \quad Q_3 + 1.5 \times \text{IQR}]$ are considered outliers.

```python
def remove_outliers_iqr(df, column):
    Q1 = df[column].quantile(0.25)
    Q3 = df[column].quantile(0.75)
    IQR = Q3 - Q1
    lower_bound = Q1 - 1.5 * IQR
    upper_bound = Q3 + 1.5 * IQR
    return df[(df[column] >= lower_bound) & (df[column] <= upper_bound)]
```

### B. Z-Score Method (Assumes Gaussian Distribution)
$$Z = \frac{x - \mu}{\sigma} \quad (\text{Flag if } |Z| > 3)$$

---

## 3. Categorical Encoding

1. **One-Hot Encoding (`OneHotEncoder` / `pd.get_dummies`):** For nominal categories with no natural order (e.g., `City: [Delhi, Mumbai, Bangalore]`). Avoid high-cardinality columns (prevents curse of dimensionality).
2. **Ordinal Encoding (`OrdinalEncoder`):** For ordered categories (e.g., `Education: [High School, Bachelor, Master, PhD]`).
3. **Target / Mean Encoding:** Replaces each categorical level with the mean of the target variable (must be cross-validated to avoid data leakage).
