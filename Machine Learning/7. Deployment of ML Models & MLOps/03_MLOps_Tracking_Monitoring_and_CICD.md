# 3. MLOps: Experiment Tracking, Monitoring & CI/CD Pipelines

## What is MLOps (Machine Learning Operations)?
**MLOps** is the practice of combining Machine Learning, DevOps, and Data Engineering to deploy, track, monitor, and maintain ML models reliably in production.

```
       +-----------------------------------------------------------+
       |                     THE MLOps LIFECYCLE                   |
       +-----------------------------------------------------------+
                                     |
       [ Data Versioning (DVC) ] ---> [ Experiment Tracking (MLflow) ]
                                                     |
       [ Model Registry ] <--------------------------+
               |
               v
       [ Containerization (Docker) ] ---> [ Automated CI/CD (GitHub Actions) ]
                                                     |
       [ Real-Time Monitoring (Data Drift / Evidently AI) ] <----+
```

---

## 1. Experiment Tracking & Model Registry (MLflow)

```python
import mlflow
import mlflow.sklearn
from sklearn.ensemble import RandomForestClassifier

mlflow.set_experiment("Customer_Churn_Prediction")

with mlflow.start_run():
    # 1. Log Hyperparameters
    n_trees = 150
    max_d = 5
    mlflow.log_param("n_estimators", n_trees)
    mlflow.log_param("max_depth", max_d)

    # 2. Train Model
    model = RandomForestClassifier(n_estimators=n_trees, max_depth=max_d)
    model.fit(X_train, y_train)

    # 3. Log Metrics
    acc = model.score(X_test, y_test)
    mlflow.log_metric("accuracy", acc)

    # 4. Save & Register Artifact in Model Registry
    mlflow.sklearn.log_model(model, "random_forest_model")
```

---

## 2. Production Model Monitoring: Data Drift vs. Concept Drift

| Drift Type | What Changes? | Cause | Detection Method |
| :--- | :--- | :--- | :--- |
| **Data Drift (Covariate Shift)** | Input data distribution $P(X)$ changes, but relationship $P(Y|X)$ remains constant. | New customer demographics, seasonal weather shifts. | Kolmogorov-Smirnov (KS) test, Population Stability Index (PSI). |
| **Concept Drift** | The true mathematical relationship between inputs and targets $P(Y|X)$ changes. | Macro-economic recession, sudden changes in consumer purchasing behavior. | Monitoring live ground-truth metrics (F1-score degradation over time). |

---

## 3. Containerization for ML Deployment (Dockerfile)

```dockerfile
# Dockerfile
FROM python:3.11-slim

WORKDIR /app

# Install dependencies
COPY requirements.txt .
RUN pip install --no-cache-dir -r requirements.txt

# Copy model artifacts and API code
COPY main.py .
COPY model.pkl .

EXPOSE 8000

# Run FastAPI with Uvicorn
CMD ["uvicorn", "main:app", "--host", "0.0.0.0", "--port", "8000"]
```
