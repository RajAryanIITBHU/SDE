# 2. ARIMA, SARIMA & Exponential Smoothing Models

## 1. ARIMA($p, d, q$) Model (AutoRegressive Integrated Moving Average)

Combines three fundamental modeling components:

```
                  ARIMA(p, d, q)
                        |
      +-----------------+-----------------+
      |                 |                 |
      v                 v                 v
AR(p)             I(d)              MA(q)
AutoRegressive    Integrated        Moving Average
(Past values)     (Differencing)    (Past shock errors)
```

$$\underbrace{Y'_t}_{\text{Differenced } d\text{ times}} = c + \underbrace{\sum_{i=1}^p \phi_i Y'_{t-i}}_{\text{AR}(p)} + \underbrace{\sum_{j=1}^q \theta_j \epsilon_{t-j}}_{\text{MA}(q)} + \epsilon_t$$

- **$p$ (Lag Order):** Number of autoregressive lag observations.
- **$d$ (Degree of Differencing):** Number of times the raw series is differenced to achieve stationarity.
- **$q$ (Moving Average Order):** Size of the moving average forecast error window.

---

## 2. SARIMA($p, d, q$)($P, D, Q, s$) (Seasonal ARIMA)
Adds seasonal autoregressive ($P$), seasonal differencing ($D$), and seasonal moving average ($Q$) terms for periodicity $s$ (e.g., $s = 12$ for monthly data).

---

## 3. Exponential Smoothing (Holt-Winters Method)

| Model | Components Modeled | Best For |
| :--- | :--- | :--- |
| **Simple Exponential Smoothing (SES)** | Level ($\alpha$) | Stationary series without trend or seasonality |
| **Holt's Linear Trend** | Level ($\alpha$) + Trend ($\beta$) | Data with linear trend, no seasonality |
| **Holt-Winters Seasonal** | Level ($\alpha$) + Trend ($\beta$) + Seasonality ($\gamma$) | Data with both trend and seasonal oscillations |

---

## 4. Python Implementation (`statsmodels`)

```python
import numpy as np
import pandas as pd
from statsmodels.tsa.arima.model import ARIMA

# Generate sample time-series data
np.random.seed(42)
dates = pd.date_range(start="2026-01-01", periods=100, freq="D")
values = np.sin(np.linspace(0, 20, 100)) + np.random.normal(0, 0.1, 100)
ts = pd.Series(values, index=dates)

# Fit ARIMA(1, 1, 1) model
model = ARIMA(ts, order=(1, 1, 1))
fitted_model = model.fit()

# Forecast next 7 days
forecast = fitted_model.forecast(steps=7)
print("7-Day Forecast:\n", forecast)
```
