# 2. Attribute Closure & Finding Candidate Keys

## 1. What is Attribute Closure ($X^+$)?
The **Attribute Closure of $X$**, denoted as **$X^+$**, is the set of all attributes that can be **functionally determined by $X$** under a given set of functional dependencies $F$.

---

## Algorithm to Calculate Attribute Closure ($X^+$)

```
1. Initialize Result = X
2. Repeat until no more attributes can be added to Result:
     For each FD (A -> B) in F:
         If A ⊆ Result:
             Result = Result ∪ B
3. Return Result
```

---

## 2. Algorithm to Find Candidate Keys of a Relation

Given $R(A_1, A_2, \dots, A_n)$ and FD set $F$:

1. **Step 1:** Classify all attributes into 4 buckets based on where they appear in the FDs:
   - **Left-Only Attributes ($L$):** Attributes that appear ONLY on the left-hand side of FDs. *(Must be part of EVERY Candidate Key).*
   - **Right-Only Attributes ($R$):** Attributes that appear ONLY on the right-hand side. *(Can NEVER be part of any Candidate Key).*
   - **Both-Sides Attributes ($B$):** Appear on both left and right sides.
   - **Neither-Side Attributes ($N$):** Do not appear in any FD. *(Must be part of EVERY Candidate Key).*

2. **Step 2:** Form the **Core Attribute Set** = $L \cup N$.
3. **Step 3:** Calculate the closure $(L \cup N)^+$:
   - If $(L \cup N)^+$ contains **ALL attributes of $R$**, then $L \cup N$ is the **ONLY Candidate Key**.
   - If not, systematically combine attributes from bucket $B$ with $L \cup N$ to find all minimal sets whose closure equals all attributes of $R$.

---

## Complete Worked Example

Relation $R(A, B, C, D, E)$ with FDs:
- $A \to BC$
- $CD \to E$
- $B \to D$
- $E \to A$

1. Attributes on Left: $A, B, C, D, E$
2. Right-only: None. Left-only: None. All are in Both ($B$).
3. Test closures:
   - $A^+ = \{A\} \to \{A, B, C\} \to \{A, B, C, D\} \to \{A, B, C, D, E\} = R \implies \mathbf{A}$ **is a Candidate Key!**
   - $B^+ = \{B, D\}$ (Not all).
   - $(BC)^+ = \{B, C, D, E, A\} = R \implies \mathbf{BC}$ **is a Candidate Key!**
   - $E^+ = \{E, A, B, C, D\} = R \implies \mathbf{E}$ **is a Candidate Key!**
   - $(CD)^+ = \{C, D, E, A, B\} = R \implies \mathbf{CD}$ **is a Candidate Key!**
