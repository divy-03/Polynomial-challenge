# **Polynomial Reconstruction from Mixed-Base Encoded Inputs**

This project solves a mathematical/algorithmic challenge where the goal is to **reconstruct a polynomial** from a set of points — except the inputs are encoded in **different number bases**.

Given a JSON file containing:

* `keys.n` → number of points
* `keys.k` → number of roots (polynomial degree = k-1)
* Several entries where each key represents **x**, and each value represents **y** encoded in arbitrary bases

The program decodes all values, then uses **Lagrange Interpolation** to compute the polynomial coefficients.

---

## 🚀 **Features**

* Decode numbers from **any base (2–36)** into decimal
* Parse dynamic JSON input using `nlohmann/json`
* Compute polynomial coefficients using **Lagrange Interpolation**
* Handle arbitrary key/value structures
* Fully implemented in C++ (AI-assisted reasoning, self-implemented code)

---

## 📌 **Problem Overview**

The input looks like:

```json
{
    "keys": { "n": 4, "k": 3 },
    "1": { "base": "10", "value": "4" },
    "2": { "base": "2", "value": "111" },
    "3": { "base": "10", "value": "12" },
    "6": { "base": "4", "value": "213" }
}
```

Each entry represents a point:

```
x = key
y = value (decoded using the given base)
```

Since `k = 3`, the polynomial degree is **2** (quadratic).
Using the given points, the program reconstructs the polynomial:

```
aX² + bX + c
```

---

## 🧠 **Approach**

### **1. Decode Mixed-Base Values**

A custom function converts each encoded number into decimal:

* Supports digits + letters
* Validates base correctness
* Computes decimal value manually

### **2. Apply Lagrange Interpolation**

Lagrange Interpolation computes the polynomial coefficients directly from point sets without solving linear systems.

This approach was inspired by referencing AI/GPT explanations for the math, but the **full implementation was written independently**.

---

## 🛠 **Tech Stack**

* **C++17**
* **nlohmann/json** for JSON parsing
* Standard Template Library (STL)

---

## 📁 **Project Structure**

```
|-- main.cpp
|-- input.json
|-- README.md
```

---

## ▶️ **How to Run**

### **1. Install Dependencies**

Ubuntu/Debian:

```bash
sudo apt install g++ nlohmann-json3-dev
```

### **2. Compile**

```bash
g++ main.cpp -o poly -std=c++17
```

### **3. Run**

```bash
./poly
```

Make sure `input.json` is present in the working directory.

---

## 📤 **Output**

The program prints the highest-degree coefficient of the reconstructed polynomial.

You can modify the final line to print the full coefficient vector for debugging.

---

## 🧪 Example

Given the sample input, the interpolation will generate coefficients

```text
[a0, a1, a2]
```

forming a polynomial:

```
P(x) = a2*x² + a1*x + a0
```
