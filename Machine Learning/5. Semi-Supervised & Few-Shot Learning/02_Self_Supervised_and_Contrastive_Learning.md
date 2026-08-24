# 2. Self-Supervised & Contrastive Learning

## What is Self-Supervised Learning (SSL)?
**Self-Supervised Learning** trains models on **100% unlabeled data** by automatically creating supervisory training signals from the inherent structure of the data itself (**Pretext Tasks**).
- The backbone of modern Foundation Models (BERT, GPT, CLIP, DINO).

---

## 1. Contrastive Learning (SimCLR / MoCo)

- **Intuition:** Pull representations of **augmented views of the same image (Positive Pairs)** closer together in embedding space, while pushing **different images (Negative Pairs)** far apart!

```
                  +--- Augmentation 1 ---> [ View x_i ] ---> [ Encoder ] ---> [ z_i ]
                  |                                                              ^
[ Original Image ]                                                        Pull   | (InfoNCE Loss)
                  |                                                       Close  v
                  +--- Augmentation 2 ---> [ View x_j ] ---> [ Encoder ] ---> [ z_j ]
                                                                                 ^
                                                                          Push   |
[ Other Image k  ] ---------------------> [ View x_k ] ---> [ Encoder ] ---> [ z_k ]
```

### The InfoNCE Loss Function (Normalized Temperature Cross-Entropy):
$$\mathcal{L}_{i, j} = -\log \frac{\exp\left(\text{sim}(z_i, z_j) / \tau\right)}{\sum_{k=1}^{2N} \mathbb{I}_{[k \neq i]} \exp\left(\text{sim}(z_i, z_k) / \tau\right)}$$

---

## 2. Masked Modeling (BERT & Masked Autoencoders - MAE)
- Mask out $15\%$ of text tokens (or $75\%$ of image pixel patches) and train a deep Transformer encoder-decoder to reconstruct the missing components.
