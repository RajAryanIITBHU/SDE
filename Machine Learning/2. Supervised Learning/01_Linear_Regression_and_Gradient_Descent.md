# 1. Linear Regression & Gradient Descent

## 1. Mathematical Formulation

Linear Regression models the relationship between continuous target $y$ and features $X$:

$$\hat{y} = \theta_0 + \theta_1 x_1 + \theta_2 x_2 + \dots + \theta_n x_n = \theta^T X$$

### Cost Function: Mean Squared Error (MSE / Residual Sum of Squares)

$$J(\theta) = \frac{1}{2m} \sum_{i=1}^m (\hat{y}^{(i)} - y^{(i)})^2 = \frac{1}{2m} \| X\theta - y \|_2^2$$

---

## 2. Solving Linear Regression

### Method A: Analytical Closed-Form Solution (The Normal Equation)

$$\theta = (X^T X)^{-1} X^T y$$

- **Pros:** No learning rate tuning, exact $1$-step solution.
- **Cons:** Inverting $X^T X$ matrix takes $O(n^3)$ time (slow for $> 10,000$ features).

---

### Method B: Gradient Descent Optimization

Iteratively update weights in the direction opposite to the gradient of the loss:

$$\theta_j := \theta_j - \alpha \frac{\partial J(\theta)}{\partial \theta_j} = \theta_j - \frac{\alpha}{m} \sum_{i=1}^m (\hat{y}^{(i)} - y^{(i)}) x_j^{(i)}$$

Where $\alpha$ is the **Learning Rate**.

```
3 Types of Gradient Descent:
1. Batch Gradient Descent:      Uses ALL m training samples per step (Accurate, but slow for huge data).
2. Stochastic GD (SGD):         Uses 1 random sample per step (Very fast, but noisy oscillations).
3. Mini-Batch Gradient Descent: Uses a mini-batch (e.g. 32, 64, 128 samples) (Industry Standard!).
```

---

## 3. Python Implementation from Scratch (NumPy) & Scikit-Learn

```python
import numpy as np
from sklearn.linear_model import LinearRegression


# Scratch Gradient Descent Implementation
class LinearRegressionGD:
    def __init__(self, lr=0.01, epochs=1000):
        self.lr = lr
        self.epochs = epochs

    def fit(self, X, y):
        m, n = X.shape
        self.weights = np.zeros(n)
        self.bias = 0

        for _ in range(self.epochs):
            y_pred = np.dot(X, self.weights) + self.bias
            # Compute Gradients
            dw = (1 / m) * np.dot(X.T, (y_pred - y))
            db = (1 / m) * np.sum(y_pred - y)
            # Update parameters
            self.weights -= self.lr * dw
            self.bias -= self.lr * db

    def predict(self, X):
        return np.dot(X, self.weights) + self.bias


if __name__ == "__main__":
    X = np.array([[1], [2], [3], [4], [5]])
    y = np.array([2, 4, 6, 8, 10])

    model = LinearRegressionGD(lr=0.05, epochs=500)
    model.fit(X, y)
    print("Predicted for x=6 (Scratch):", model.predict(np.array([[6]])))  # ~12.0
```
