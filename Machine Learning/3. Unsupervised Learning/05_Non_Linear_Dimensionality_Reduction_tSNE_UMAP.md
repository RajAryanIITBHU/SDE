# 5. Non-Linear Dimensionality Reduction: t-SNE, UMAP, LDA & ICA

## 1. t-SNE (t-Distributed Stochastic Neighbor Embedding)
- **Nature:** Non-linear, probabilistic technique primarily used for **2D/3D high-dimensional data visualization**.
- **Mechanism:**
  - Converts pairwise Euclidean distances in high-dimensional space into Gaussian conditional probabilities $p_{j|i}$.
  - Defines similar probabilities in low-dimensional map using a **Student-t distribution** (heavy tails resolve the "crowding problem").
  - Minimizes the **Kullback-Leibler (KL) Divergence** between high-D and low-D distributions using gradient descent:
    $$KL(P \,||\, Q) = \sum_i \sum_j p_{ij} \log \frac{p_{ij}}{q_{ij}}$$
- **Rule:** **t-SNE preserves LOCAL neighborhood structure** (distances between distant clusters are meaningless).

---

## 2. UMAP (Uniform Manifold Approximation and Projection)
- **Advantage over t-SNE:** Faster computational speed, scales to massive datasets, and **preserves both LOCAL and GLOBAL manifold structure**.

---

## 3. Comparison of All Major Dimensionality Reduction Techniques

| Algorithm | Type | Supervised? | Global vs. Local Structure | Primary Use Case |
| :--- | :--- | :---: | :--- | :--- |
| **PCA** | Linear | Unsupervised | Preserves Global Variance | Feature reduction for ML models |
| **LDA** | Linear | **Supervised** | Maximizes Between-Class / Within-Class ratio | Dimensionality reduction for Classification |
| **t-SNE** | Non-Linear | Unsupervised | Preserves **Local** Neighborhoods | 2D/3D Data Visualization |
| **UMAP** | Non-Linear | Both | Preserves **Local & Global** | Visualization & general feature reduction |
| **ICA** | Linear | Unsupervised | Separates statistically independent signals | Blind source separation (Cocktail party problem) |
