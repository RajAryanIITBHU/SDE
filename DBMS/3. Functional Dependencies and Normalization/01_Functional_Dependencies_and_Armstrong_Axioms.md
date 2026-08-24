# 1. Functional Dependencies & Armstrong's Axioms

## What is a Functional Dependency (FD)?
Given a relation $R$, a **Functional Dependency $X \to Y$** (read: *"X functionally determines Y"*) is a constraint stating that if two tuples agree on attribute set $X$, they **MUST also agree on attribute set $Y$**.

$$\forall t_1, t_2 \in R: \quad \text{if } t_1[X] = t_2[X] \implies t_1[Y] = t_2[Y]$$

- $X$ is called the **Determinant**.
- $Y$ is called the **Dependent**.

---

## Types of Functional Dependencies

1. **Trivial Functional Dependency:** $X \to Y$ is trivial if $Y \subseteq X$ (e.g., $\{A, B\} \to A$). Always true.
2. **Non-Trivial Functional Dependency:** $X \to Y$ is non-trivial if $X \cap Y = \emptyset$ (e.g., $A \to B$).
3. **Semi-Trivial Functional Dependency:** $X \to Y$ where $Y \not\subseteq X$ and $X \cap Y \neq \emptyset$ (e.g., $\{A, B\} \to \{B, C\}$).

---

## Armstrong's Axioms (Inference Rules)

Armstrong's Axioms are a set of rules used to infer all valid functional dependencies from a given set $F$:

### Primary Axioms (Sound and Complete):
1. **Reflexivity Rule:** If $Y \subseteq X$, then $X \to Y$.
2. **Augmentation Rule:** If $X \to Y$, then $XZ \to YZ$ for any attribute set $Z$.
3. **Transitivity Rule:** If $X \to Y$ and $Y \to Z$, then $X \to Z$.

### Secondary Derived Rules:
4. **Union Rule:** If $X \to Y$ and $X \to Z$, then $X \to YZ$.
5. **Decomposition Rule:** If $X \to YZ$, then $X \to Y$ and $X \to Z$.
6. **Pseudo-Transitivity Rule:** If $X \to Y$ and $WY \to Z$, then $WX \to Z$.
