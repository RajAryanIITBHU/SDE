# 1. Time Series Basics, Decomposition & Stationarity

## 1. Components of a Time Series

$$Y_t = T_t + S_t + C_t + I_t \quad (\text{Additive Model}) \quad \text{or} \quad Y_t = T_t \times S_t \times C_t \times I_t \quad (\text{Multiplicative})$$

1. **Trend ($T_t$):** Long-term upward or downward movement over time.
2. **Seasonality ($S_t$):** Repeating patterns occurring at fixed, regular intervals (e.g., quarterly sales, diurnal spikes).
3. **Cyclicality ($C_t$):** Long-term economic waves (unfixed durations, multi-year business cycles).
4. **Irregular / Noise ($I_t$):** Residual random fluctuations.

---

## 2. Stationarity (The Foundation of Statistical Forecasting)

A time series is **Strictly / Weakly Stationary** if its statistical properties do not change over time:
1. **Constant Mean:** $\mathbb{E}[Y_t] = \mu$ for all $t$.
2. **Constant Variance:** $\text{Var}(Y_t) = \sigma^2$ for all $t$.
3. **Autocovariance depends only on lag $k$:** $\text{Cov}(Y_t, Y_{t-k}) = \gamma_k$ (independent of time $t$).

---

## 3. Testing for Stationarity: Augmented Dickey-Fuller (ADF) Test

- **Null Hypothesis ($H_0$):** The series has a unit root (is **NON-STATIONARY**).
- **Alternative Hypothesis ($H_1$):** The series has no unit root (is **STATIONARY**).
- **Decision Rule:** If $\mathbf{p\text{-value}} < 0.05 \implies$ Reject $H_0 \implies$ **Series is Stationary!**

### How to Make a Non-Stationary Series Stationary:
1. **Differencing:** $\Delta Y_t = Y_t - Y_{t-1}$ (Removes linear trend; $d$-order differencing).
2. **Log Transformation:** $\log(Y_t)$ (Stabilizes exponential variance growth).

---

## 4. ACF and PACF Plots

- **Autocorrelation Function (ACF):** Measures correlation between $Y_t$ and $Y_{t-k}$ across all intermediate lags $\implies$ Used to determine **$q$ (MA order)**.
- **Partial Autocorrelation Function (PACF):** Measures direct correlation between $Y_t$ and $Y_{t-k}$ removing intermediate lag effects $\implies$ Used to determine **$p$ (AR order)**.
