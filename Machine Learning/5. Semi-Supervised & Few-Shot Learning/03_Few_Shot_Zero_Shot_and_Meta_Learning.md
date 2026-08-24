# 3. Few-Shot, Zero-Shot & Meta-Learning ("Learning to Learn")

## 1. The $N$-Way $K$-Shot Problem Formulation
- **$N$-Way:** Number of novel target classes to classify between.
- **$K$-Shot:** Number of labeled example instances provided per class ($K = 1 \implies$ **One-Shot Learning**).

---

## 2. Siamese Networks (Metric-Based Few-Shot)
- Twin neural networks sharing identical weights $W$ compute dense feature embedding vectors $f(x_1)$ and $f(x_2)$.
- **Contrastive Loss / Triplet Loss:**
  $$\mathcal{L}_{\text{Triplet}} = \max\left(0, \|f(A) - f(P)\|^2 - \|f(A) - f(N)\|^2 + \alpha\right)$$
  - $A$: Anchor
  - $P$: Positive (Same class as Anchor)
  - $N$: Negative (Different class)
  - $\alpha$: Margin distance constant

---

## 3. Prototypical Networks (Snell et al., 2017)
- Computes a single **Class Prototype Vector $\mathbf{c}_k$** as the centroid of support embeddings for class $k$:
  $$\mathbf{c}_k = \frac{1}{|S_k|} \sum_{(x_i, y_i) \in S_k} f_\theta(x_i)$$
- Assigns query point $x$ to the class whose prototype vector has the minimum Euclidean distance.

---

## 4. Zero-Shot Learning (CLIP & Prompting)
- **Zero-Shot Learning:** Classifies instances into categories **never seen during training**, by aligning multimodal semantics (e.g., OpenAI's **CLIP** aligns Image Embeddings with Natural Language Text Embeddings via contrastive pre-training).
