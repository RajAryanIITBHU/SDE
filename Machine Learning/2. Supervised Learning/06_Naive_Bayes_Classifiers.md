# 6. Naïve Bayes Classifiers

## 1. Bayes' Theorem Formulation

$$P(y | X) = \frac{P(X | y) \cdot P(y)}{P(X)}$$

Where:
- $P(y | X)$: **Posterior Probability** (Probability of class $y$ given features $X$).
- $P(y)$: **Prior Probability** of class $y$.
- $P(X | y)$: **Likelihood** of features $X$ given class $y$.
- $P(X)$: **Evidence** / Marginal Probability.

---

## 2. The "Naïve" Conditional Independence Assumption

Naïve Bayes makes the strong assumption that **all features $x_1, x_2, \dots, x_n$ are mutually independent given the class $y$**:

$$P(x_1, x_2, \dots, x_n | y) = \prod_{i=1}^n P(x_i | y)$$

$$\hat{y} = \arg\max_y P(y) \prod_{i=1}^n P(x_i | y)$$

---

## 3. Naïve Bayes Variants

| Variant | Data Type Assumed | Classic Application |
| :--- | :--- | :--- |
| **Gaussian Naïve Bayes** | Continuous numerical features following a normal (Gaussian) distribution $\mathcal{N}(\mu_c, \sigma_c^2)$. | Sensor data, medical diagnosis. |
| **Multinomial Naïve Bayes** | Discrete feature counts (word frequencies / term frequencies). | **Spam classification, NLP text classification.** |
| **Bernoulli Naïve Bayes** | Binary boolean features (0 or 1, e.g., word present vs. absent). | Short text / tweet classification. |

---

## 4. Laplace Smoothing (Additive Smoothing)

If a word in the test set never appeared in a training class, $P(x_i | y) = 0$, causing the entire product $\prod P(x_i | y)$ to become **ZERO**!

- **Laplace Correction ($\alpha = 1$):**
  $$\hat{P}(x_i | y) = \frac{\text{Count}(x_i, y) + \alpha}{\text{Total Words in } y + \alpha \cdot |V|}$$
  *(Where $|V|$ is the total vocabulary size).*
