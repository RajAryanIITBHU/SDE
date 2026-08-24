# 3. Model Evaluation Metrics in Machine Learning

## 1. Classification Metrics & Confusion Matrix

```
                      PREDICTED POSITIVE        PREDICTED NEGATIVE
ACTUAL POSITIVE      True Positive (TP)        False Negative (FN) [Type II Error]
ACTUAL NEGATIVE      False Positive (FP)       True Negative (TN)  [Type I Error]
```

### Core Classification Formulas:

$$\text{Accuracy} = \frac{\text{TP} + \text{TN}}{\text{TP} + \text{TN} + \text{FP} + \text{FN}}$$

$$\text{Precision} = \frac{\text{TP}}{\text{TP} + \text{FP}} \quad (\text{"Out of all predicted positives, how many were truly positive?" - Spam Detection})$$

$$\text{Recall (Sensitivity)} = \frac{\text{TP}}{\text{TP} + \text{FN}} \quad (\text{"Out of all actual positives, how many did we catch?" - Cancer Diagnosis})$$

$$\text{F1-Score} = 2 \times \frac{\text{Precision} \times \text{Recall}}{\text{Precision} + \text{Recall}} \quad (\text{Harmonic Mean - Best for Imbalanced Datasets})$$

$$\text{Specificity} = \frac{\text{TN}}{\text{TN} + \text{FP}}$$

---

## 2. The ROC-AUC Curve

- **Receiver Operating Characteristic (ROC) Curve:** Plots **True Positive Rate (TPR / Recall)** on the Y-axis against **False Positive Rate ($\text{FPR} = 1 - \text{Specificity}$)** on the X-axis across all classification probability thresholds ($0.0 \to 1.0$).
- **Area Under Curve (AUC):**
  - $\text{AUC} = 1.0$: Perfect classifier.
  - $\text{AUC} = 0.5$: Random guessing (Coin flip).
  - $\text{AUC} < 0.5$: Worse than random (invert predictions).

---

## 3. Regression Metrics

| Metric | Formula | Characteristic |
| :--- | :--- | :--- |
| **MAE** (Mean Absolute Error) | $\frac{1}{n} \sum |y_i - \hat{y}_i|$ | Robust to outliers; measured in target units |
| **MSE** (Mean Squared Error) | $\frac{1}{n} \sum (y_i - \hat{y}_i)^2$ | Heavily penalizes large errors/outliers |
| **RMSE** (Root Mean Squared Error) | $\sqrt{\text{MSE}}$ | Penalizes outliers while retaining original target units |
| **$R^2$ Score** (Coefficient of Determination) | $1 - \frac{\text{SS}_{\text{res}}}{\text{SS}_{\text{tot}}}$ | Proportion of variance explained by model (1.0 = perfect, $\le 0$ = worse than mean) |
| **Adjusted $R^2$** | $1 - \left[\frac{(1 - R^2)(n - 1)}{n - k - 1}\right]$ | Penalizes addition of useless predictor features ($k$) |
