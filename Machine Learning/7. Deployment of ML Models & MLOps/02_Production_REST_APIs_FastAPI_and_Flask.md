# 2. Production REST APIs for ML Models: FastAPI & Flask

Serving a Machine Learning model as a REST API allows backend microservices, iOS/Android mobile apps, and web frontends to query predictions via standard JSON over HTTP.

---

## 1. Production High-Performance API: FastAPI + Pydantic (Industry Standard)

FastAPI provides asynchronous concurrency, automatic OpenAPI Swagger documentation (`/docs`), and automatic Pydantic request payload type validation.

```python
# main.py
from typing import List
from fastapi import FastAPI, HTTPException
from pydantic import BaseModel, Field
import uvicorn
import numpy as np

app = FastAPI(
    title="ML Model Inference API",
    description="Production-grade ML model serving endpoint",
    version="1.0.0"
)

# 1. Define Request Schema with Pydantic
class IrisRequest(BaseModel):
    sepal_length: float = Field(..., gt=0, description="Length of sepal in cm")
    sepal_width: float = Field(..., gt=0, description="Width of sepal in cm")
    petal_length: float = Field(..., gt=0, description="Length of petal in cm")
    petal_width: float = Field(..., gt=0, description="Width of petal in cm")

# 2. Define Response Schema
class PredictionResponse(BaseModel):
    prediction_class: int
    predicted_label: str
    confidence_score: float

CLASS_NAMES = ["setosa", "versicolor", "virginica"]

@app.get("/health")
def health_check():
    return {"status": "healthy", "service": "iris-inference"}

@app.post("/predict", response_model=PredictionResponse)
async def predict_iris(request: IrisRequest):
    try:
        # Extract features array
        input_data = np.array([[
            request.sepal_length,
            request.sepal_width,
            request.petal_length,
            request.petal_width
        ]])
        
        # Inference (Mocked model output)
        predicted_idx = 0
        confidence = 0.985
        
        return PredictionResponse(
            prediction_class=predicted_idx,
            predicted_label=CLASS_NAMES[predicted_idx],
            confidence_score=confidence
        )
    except Exception as e:
        raise HTTPException(status_code=500, detail=str(e))

if __name__ == "__main__":
    uvicorn.run(app, host="0.0.0.0", port=8000)
```

---

## 2. Flask REST API Implementation

```python
# app.py
from flask import Flask, request, jsonify

app = Flask(__name__)

@app.route("/predict", methods=["POST"])
def predict():
    data = request.get_json(force=True)
    features = data.get("features", [])
    if len(features) != 4:
        return jsonify({"error": "Invalid feature dimensions. Expected 4."}), 400
    
    # Mock inference
    return jsonify({"prediction": "Iris-Setosa", "class_id": 0})

if __name__ == "__main__":
    app.run(host="0.0.0.0", port=5000, debug=False)
```
