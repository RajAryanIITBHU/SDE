# 1. ML Web App Prototyping: Streamlit & Gradio

## 1. Streamlit (Data Dashboard & Full Interactive Web Apps)

Streamlit turns data scripts into shareable web apps in pure Python with no HTML/CSS/JS needed.

```python
# app_streamlit.py
import joblib
import numpy as np
import streamlit as st

# Load Pre-trained Scikit-Learn Model
# model = joblib.load('iris_model.pkl')

st.set_page_config(page_title="Iris Flower Classifier", layout="centered")
st.title("🌸 Iris Flower Prediction App")

st.sidebar.header("User Input Parameters")
sepal_len = st.sidebar.slider("Sepal Length (cm)", 4.0, 8.0, 5.4)
sepal_wid = st.sidebar.slider("Sepal Width (cm)", 2.0, 5.0, 3.4)
petal_len = st.sidebar.slider("Petal Length (cm)", 1.0, 7.0, 1.5)
petal_wid = st.sidebar.slider("Petal Width (cm)", 0.1, 3.0, 0.2)

if st.button("Predict Species"):
    features = np.array([[sepal_len, sepal_wid, petal_len, petal_wid]])
    # prediction = model.predict(features)
    st.success("Predicted Iris Species: **Iris-Setosa**")
    st.balloons()
```

---

## 2. Gradio (Fast Prototyping for Deep Learning & Generative AI)

Gradio creates immediate UI interfaces for function calling with multimodal support (Audio, Images, Text).

```python
# app_gradio.py
import gradio as gr


def classify_text(text: str) -> dict:
    # Dummy sentiment classifier
    score = len(text) % 2
    return {"Positive": 0.85 if score else 0.15, "Negative": 0.15 if score else 0.85}


demo = gr.Interface(
    fn=classify_text,
    inputs=gr.Textbox(lines=2, placeholder="Enter review text here..."),
    outputs=gr.Label(num_top_classes=2),
    title="Customer Review Sentiment Analyzer",
)

if __name__ == "__main__":
    demo.launch()
```
