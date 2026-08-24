# 2. Bellman Equations & Dynamic Programming (Value & Policy Iteration)

## 1. The Bellman Equation (Recursive Decomposition)

The value of a state equals the **immediate reward** plus the **discounted value of the next state**:

### Bellman Expectation Equation for $V(s)$:
$$V^\pi(s) = \sum_{a \in A} \pi(a|s) \sum_{s' \in S} P(s'|s, a) \left[ R(s, a, s') + \gamma V^\pi(s') \right]$$

### Bellman Optimality Equation:
$$V^*(s) = \max_{a \in A} \sum_{s' \in S} P(s'|s, a) \left[ R(s, a, s') + \gamma V^*(s') \right]$$

$$Q^*(s, a) = \sum_{s' \in S} P(s'|s, a) \left[ R(s, a, s') + \gamma \max_{a'} Q^*(s', a') \right]$$

---

## 2. Model-Based Dynamic Programming Algorithms

When transition probabilities $P(s'|s, a)$ and reward function $R$ are fully known:

### A. Value Iteration (Iterative Optimality Update)
- Repeatedly updates state values using Bellman Optimality until convergence:
  $$V_{k+1}(s) \leftarrow \max_{a} \sum_{s'} P(s'|s,a) [R + \gamma V_k(s')]$$
- Once converged, extract optimal greedy policy: $\pi^*(s) = \arg\max_a \sum_{s'} P [R + \gamma V(s')]$.

### B. Policy Iteration (Two-Step Evaluation & Improvement)
1. **Policy Evaluation:** Compute exact $V^\pi(s)$ for current policy $\pi$.
2. **Policy Improvement:** Greedily update policy $\pi_{\text{new}}(s) = \arg\max_a Q^\pi(s, a)$.
3. Repeat until policy stops changing.
