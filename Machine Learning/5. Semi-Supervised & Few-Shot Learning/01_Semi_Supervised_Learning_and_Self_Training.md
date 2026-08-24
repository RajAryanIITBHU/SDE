# 1. Semi-Supervised Learning & Self-Training (Pseudo-Labeling)

## What is Semi-Supervised Learning?
Semi-Supervised Learning combines a **small amount of labeled data** with a **massive amount of unlabeled data** ($D = D_{\text{labeled}} \cup D_{\text{unlabeled}}$).
- Essential in domains where manual data labeling is prohibitively expensive (e.g., Medical Imaging CT scans, Drug Discovery).

---

## 1. Self-Training / Pseudo-Labeling Algorithm

```
1. TRAIN BASE MODEL: Train classifier f_θ on small labeled dataset D_labeled.
2. PREDICT: Run f_θ on unlabeled dataset D_unlabeled to generate probability predictions.
3. PSEUDO-LABEL: Select high-confidence predictions (e.g. max probability > 0.95)
   and assign them as ground-truth "pseudo-labels".
4. AUGMENT: Add high-confidence pseudo-labeled data into D_labeled.
5. RETRAIN: Retrain f_θ on expanded labeled dataset.
6. REPEAT steps 2-5 until convergence.
```

---

## 2. Label Propagation & Graph-Based Methods
- Constructs an undirected graph where nodes are data points and edges represent pairwise similarity weights $W_{ij} = \exp(-\gamma \|x_i - x_j\|^2)$.
- Iteratively diffuses known labels from labeled nodes across edges to adjacent unlabeled nodes until equilibrium is reached.

---

## 3. Python Implementation (Scikit-Learn `SelfTrainingClassifier`)

```python
import numpy as np
from sklearn.datasets import load_iris
from sklearn.semi_supervised import SelfTrainingClassifier
from sklearn.svm import SVC

X, y = load_iris(return_X_y=True)

# Simulate 80% Unlabeled Data by setting labels to -1
rng = np.random.RandomState(42)
unlabeled_mask = rng.rand(len(y)) < 0.8
y_semi = y.copy()
y_semi[unlabeled_mask] = -1

# Base Classifier with probability calibration
base_svc = SVC(probability=True, gamma="auto", random_state=42)

# Self-Training Wrapper
self_trainer = SelfTrainingClassifier(base_svc, threshold=0.8, max_iter=10)
self_trainer.fit(X, y_semi)

print(f"Total labeled iterations completed: {self_trainer.n_iter_}")
print(f"Accuracy on original full dataset: {self_trainer.score(X, y):.4f}")
```
