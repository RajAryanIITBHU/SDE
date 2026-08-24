# 4. Deep Q-Networks (DQN) & Policy Gradient Methods

When the state space is continuous or massive (e.g., video game raw pixels), tabular Q-Learning fails. **Deep Reinforcement Learning (Deep RL)** uses Deep Neural Networks as function approximators.

---

## 1. Deep Q-Networks (DQN)

A neural network $Q(s, a; \theta)$ approximates Q-values. Standard neural Q-learning diverges; DeepMind stabilized DQN using **two innovations**:

1. **Experience Replay Buffer:** Stores transitions $(s, a, r, s')$ in a cyclic memory buffer; samples random mini-batches for training. **Breaks temporal correlations** and stabilizes gradient descent.
2. **Target Network ($\theta^-$):** Maintains a separate, frozen set of target network weights updated periodically. Prevents moving-target oscillations during loss calculation:
   $$\mathcal{L}(\theta) = \mathbb{E} \left[ \left( r + \gamma \max_{a'} Q(s', a'; \theta^-) - Q(s, a; \theta) \right)^2 \right]$$

---

## 2. Policy Gradient Methods & REINFORCE

Instead of estimating action-values $Q(s, a)$ and selecting $\arg\max$, **Policy Gradient methods directly optimize the policy parameters $\theta$** to maximize expected cumulative reward $J(\theta) = \mathbb{E}_{\pi_\theta}[G]$:

$$\nabla_\theta J(\theta) = \mathbb{E}_{\pi_\theta} \left[ \nabla_\theta \log \pi_\theta(a | s) \cdot G_t \right]$$

### REINFORCE Algorithm (Monte Carlo Policy Gradient):
- Sample full episode trajectories under policy $\pi_\theta$.
- Increase probability of actions that resulted in positive returns $G_t > 0$; decrease probability of actions with negative returns.

---

## 3. Actor-Critic Architectures (A2C & A3C)

Combines Value-based and Policy-based RL:

```
                  +-----------------------------------+
                  |           ACTOR (Policy)          | ---> Action Selection
                  |         π_θ(a|s) Network          |
                  +-----------------------------------+
                                   ^
                                   | Advantage A(s,a) = Q(s,a) - V(s)
                                   |
                  +-----------------------------------+
                  |          CRITIC (Value)           | ---> Evaluates how good
                  |          V_w(s) Network           |      the state is
                  +-----------------------------------+
```

- **A2C (Advantage Actor-Critic):** Synchronous, deterministic updates.
- **A3C (Asynchronous Advantage Actor-Critic):** Multiple parallel CPU worker agents explore asynchronous copies of the environment simultaneously.
