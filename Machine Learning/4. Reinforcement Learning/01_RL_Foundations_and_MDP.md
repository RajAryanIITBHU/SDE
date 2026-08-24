# 1. Reinforcement Learning Foundations & Markov Decision Processes (MDP)

## 1. The Agent-Environment Interaction Cycle

```
                    +-------------------+
                    |       AGENT       |
                    +-------------------+
                      /               ^
             Action  /                 \  Reward R_t,
              A_t   /                   \ New State S_{t+1}
                   v                     \
            +-----------------------------------+
            |            ENVIRONMENT            |
            +-----------------------------------+
```

---

## 2. Core Reinforcement Learning Terminology

| Component | Notation | Description |
| :--- | :---: | :--- |
| **State** | $S$ | Current situation/observation of the environment. |
| **Action** | $A$ | Decision/movement made by the Agent. |
| **Reward** | $R_t$ | Scalar feedback signal from environment ($+10$ for goal, $-100$ for crash). |
| **Policy** | $\pi(a | s)$ | The Agent's strategy mapping state $s$ to action probability distribution. |
| **Return (Discounted)** | $G_t$ | Cumulative future rewards: $G_t = \sum_{k=0}^\infty \gamma^k R_{t+k+1}$ (where discount factor $\gamma \in [0, 1)$). |
| **State-Value Function** | $V^\pi(s)$ | Expected return starting from state $s$ following policy $\pi$: $\mathbb{E}_\pi[G_t | S_t = s]$. |
| **Action-Value Function**| $Q^\pi(s, a)$| Expected return starting from state $s$, taking action $a$, and then following $\pi$: $\mathbb{E}_\pi[G_t | S_t = s, A_t = a]$. |

---

## 3. Markov Decision Process (MDP)

An MDP formalizes the environment using the **Markov Property**:

> *"The future is independent of the past given the present."*  
> $$P(S_{t+1} | S_t, A_t, S_{t-1}, A_{t-1}, \dots) = P(S_{t+1} | S_t, A_t)$$

An MDP is defined as a 5-tuple: $(S, A, P, R, \gamma)$:
1. $S$: Set of states.
2. $A$: Set of actions.
3. $P(s' | s, a)$: State Transition Probability Function.
4. $R(s, a, s')$: Reward Function.
5. $\gamma$: Discount factor ($0 \le \gamma < 1$).
