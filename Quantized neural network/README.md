# Lab 5 — Deployment of a Quantized Neural Network

## Objective

The objective of this lab was to train a neural network, quantize the trained model, and prepare it for deployment on a RISC-V based embedded platform.

This exercise was intended to bridge the gap between machine learning model development and deployment on resource-constrained edge devices.

---

## Overview

In this lab, I worked through the complete workflow of developing a neural network suitable for embedded inference. The process involved training the model using PyTorch, preparing the trained weights for quantization, and generating deployment-ready artifacts.

Unlike the previous SVM deployment exercise, this lab focused on neural networks, introducing a more complex inference pipeline and demonstrating how quantization enables deployment on systems with limited computational and memory resources.

---

## Workflow

Dataset

↓

Train Neural Network

↓

Evaluate Accuracy

↓

Quantize Model

↓

Export Model Parameters

↓

Deploy on Embedded Target

---

## My Learning Journey

This lab helped me understand the complete deployment workflow for neural networks on embedded hardware.

During the training phase, I successfully trained the neural network and explored the quantization process used to reduce model size while maintaining acceptable prediction accuracy.

While attempting to export the trained model for deployment, I encountered an issue in the deployment pipeline related to the project directory configuration. The training process completed successfully, but the deployment stage could not proceed because the required output directory for saving the trained model had not been created.

Rather than stopping at the error, I investigated the traceback to understand how PyTorch serializes trained models and how deployment scripts organize exported model artifacts.

This experience reinforced the importance of proper project structure and deployment pipelines in embedded AI development.

---

## Issue Encountered

During model export, the deployment script produced the following runtime error:

```
RuntimeError:
Parent directory modeldata does not exist.
```

The deployment script attempted to save the trained model using:

```python
torch.save(model.state_dict(), f"modeldata/{runname}.pth")
```

Since the `modeldata` directory had not been created beforehand, the serialization step failed before the model could be exported.

---

## Resolution

The issue can be resolved by creating the required output directory before saving the model.

For example:

```python
import os

os.makedirs("modeldata", exist_ok=True)

torch.save(model.state_dict(), f"modeldata/{runname}.pth")
```

This allows the trained model to be successfully serialized for later deployment.

---

## Key Learnings

- Neural network training using PyTorch
- Model serialization using `state_dict()`
- Quantization workflow
- Deployment preparation for embedded systems
- Importance of project directory organization
- Debugging deployment pipelines

---

## Challenges

Although the neural network training completed successfully, the deployment stage was interrupted due to a missing output directory. Debugging this issue provided insight into the model export process and highlighted the practical challenges involved in transitioning from model development to embedded deployment.

---

## Future Work

- Successfully export the trained model.
- Complete deployment on the RISC-V platform.
- Benchmark inference latency.
- Compare floating-point and quantized inference performance.
- Evaluate memory usage after deployment.

---

## Conclusion

This lab demonstrated that deploying machine learning models involves more than model training alone. It requires careful management of project structure, serialization, deployment artifacts, and embedded software integration. Even though the final deployment could not be completed during the lab, the exercise provided valuable experience in understanding the end-to-end Edge AI workflow.
