# 6. Association Rule Mining: Apriori & FP-Growth

## 1. What is Association Rule Mining?
Used primarily in **Market Basket Analysis** to discover co-occurrence relationships and customer purchasing patterns (e.g., *"If a customer buys Bread and Butter, they are 80% likely to also buy Milk"*).

$$\text{Rule Format: } X \implies Y \quad (\text{Antecedent } X \implies \text{Consequent } Y)$$

---

## 2. 3 Fundamental Evaluation Metrics

### A. Support (Popularity / Frequency)
$$\text{Support}(X \implies Y) = \frac{\text{Transactions containing both } X \text{ and } Y}{\text{Total Number of Transactions } N}$$

### B. Confidence (Reliability / Conditional Probability)
$$\text{Confidence}(X \implies Y) = \frac{\text{Support}(X \cup Y)}{\text{Support}(X)} = P(Y | X)$$

### C. Lift (Strength / Independence Ratio)
$$\text{Lift}(X \implies Y) = \frac{\text{Confidence}(X \implies Y)}{\text{Support}(Y)} = \frac{P(X \cap Y)}{P(X) \cdot P(Y)}$$

- **$\text{Lift} > 1.0$:** Positive association ($X$ and $Y$ boost each other's purchase).
- **$\text{Lift} = 1.0$:** Independent (Random coincidence).
- **$\text{Lift} < 1.0$:** Negative association (Buying $X$ makes buying $Y$ less likely).

---

## 3. Apriori vs. FP-Growth (Frequent Pattern Growth)

- **The Apriori Property:** All non-empty subsets of a frequent itemset must also be frequent. If an itemset is infrequent, all its supersets are pruned immediately.
  - *Downside:* Multiple expensive passes scanning the entire database to generate candidate pairs.
- **FP-Growth Algorithm:** Builds a compact in-memory **FP-Tree (Frequent Pattern Tree)** with only **2 database scans**, eliminating candidate generation entirely ($10\times$ to $100\times$ faster than Apriori).
