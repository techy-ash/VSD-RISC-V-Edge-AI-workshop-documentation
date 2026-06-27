# Lab 3 — Quantized SVM for MNIST Digit Recognition

## Objective

Train a Support Vector Machine classifier, quantize the trained model, and deploy integer-based inference suitable for embedded RISC-V systems.

---

## Overview

This lab represented the transition from conventional machine learning to Embedded AI.

The trained floating-point SVM model was converted into an integer representation to reduce memory usage and computational cost while preserving classification performance. The generated parameters were exported as C header files and integrated into an Embedded C application for inference.

The embedded implementation performs input scaling, computes class scores using quantized weights, and predicts handwritten MNIST digits. :contentReference[oaicite:0]{index=0}

---

## Workflow

MNIST Dataset

↓

Train Floating Point SVM

↓

Feature Scaling

↓

Model Quantization

↓

Generate Header Files

↓

Embedded C Inference

↓

Prediction

---

## Repository Contents

- Embedded C inference source
- Floating-point model parameters
- Quantized model parameters
- Test dataset
- Feature scaling parameters
- Jupyter notebook implementation

---

## My Learning Journey

This lab provided valuable insight into how machine learning models are prepared for deployment on embedded hardware.

Rather than executing inference directly within Python, I learned how trained model parameters can be exported into C header files and integrated into firmware. I also explored feature scaling, integer arithmetic, and quantized inference, all of which are essential techniques for Edge AI systems with constrained memory and computational resources.

Understanding the relationship between floating-point training and integer inference significantly improved my understanding of embedded machine learning deployment.

---

## Challenges

Some of the largest generated parameter files contained thousands of values, making repository organization and documentation equally important as implementation. Structuring the project clearly helped improve maintainability.

---

## Key Takeaways

- Support Vector Machines
- Feature Scaling
- Quantization
- Embedded AI
- Integer Arithmetic
- Embedded C Integration
- Edge AI Deployment
