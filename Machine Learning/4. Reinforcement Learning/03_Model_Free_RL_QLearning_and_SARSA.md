# 3. Model-Free Reinforcement Learning: Q-Learning & SARSA

When the environment dynamics $P(s'|s, a)$ are **unknown**, the agent must learn directly from trial-and-error experience using **Temporal Difference (TD) Learning**.

---

## 1. Q-Learning (Off-Policy TD Control)

- **Off-Policy:** Learns the optimal action-value function $Q^*$ regardless of the policy the agent is currently following to explore.
- **Update Rule:**
  $$Q(S_t, A_t) \leftarrow Q(S_t, A_t) + \alpha \left[ R_{t+1} + \gamma \max_{a} Q(S_{t+1}, a) - Q(S_t, A_t) \right]$$

---

## 2. SARSA (On-Policy TD Control)

- **On-Policy:** Learns action-values for the exact behavioral exploration policy (takes the actual action $A_{t+1}$ executed under $\epsilon$-greedy policy).
- **Tuple:** $(S_t, A_t, R_{t+1}, S_{t+1}, A_{t+1})$ $\to$ **S-A-R-S-A**.
- **Update Rule:**
  $$Q(S_t, A_t) \leftarrow Q(S_t, A_t) + \alpha \left[ R_{t+1} + \gamma Q(S_{t+1}, A_{t+1}) - Q(S_t, A_t) \right]$$

---

## Q-Learning vs. SARSA Comparison

| Feature | Q-Learning | SARSA |
| :--- | :--- | :--- |
| **Policy Type** | **Off-Policy** (Assumes greedy best next action $\max_a Q$) | **On-Policy** (Uses actual chosen action $A_{t+1}$) |
| **Risk Sensitivity**| Learns optimal shortest path (e.g. walks along cliff edge) | Learns safer, conservative path away from danger |
| **Exploration** | Decoupled from target policy | Tightly coupled with exploration policy |

---

## 3. Python Q-Learning Algorithm Implementation

```python
import numpy as np

# Q-Table Initialization: states x actions
n_states, n_actions = 16, 4
Q = np.zeros((n_states, n_actions))

alpha = 0.1     # Learning rate
gamma = 0.99    # Discount factor
epsilon = 0.1   # Exploration rate

def choose_action(state):
    if np.random.uniform(0, 1) < epsilon:
        return np.random.choice(n_actions) # Explore
    return np.argmax(Q[state, :])          # Exploit

def update_q_learning(state, action, reward, next_state):
    best_next_action_q = np.max(Q[next_state, :])
    td_target = reward + gamma * best_next_action_q
    td_error = td_target - Q[state, action]
    Q[state, action] += alpha * td_error
```
