# Fourier Epicycle Drawing

A visualization of **Fourier series** using rotating circles (epicycles) to reconstruct drawings.

This project demonstrates how any 2D shape can be decomposed into a sum of rotating vectors using the  **Discrete Fourier Transform (DFT)** . When these vectors are chained together, their endpoints trace the original drawing.

The result is a mesmerizing animation where complex drawings emerge from a set of rotating circles.

---

## Demo

Each circle represents a complex exponential term of the Fourier series:

[
f(t) = \sum_{n=-\infty}^{\infty} c_n e^{i n t}
]

The radius of each circle corresponds to the magnitude of a Fourier coefficient, and its angular velocity corresponds to its frequency.

---

## Features

* Fourier decomposition of arbitrary drawings
* Epicycle animation showing frequency components
* Real-time reconstruction of shapes
* Visualization of complex Fourier coefficients
* Written in **modern C++ (C++17)**

---

## How It Works

1. A path (set of 2D points) is sampled.
2. The **Discrete Fourier Transform (DFT)** is applied to convert the signal into frequency components.
3. Each Fourier coefficient becomes an  **epicycle** :
   * Radius = coefficient magnitude
   * Rotation speed = frequency
4. The tip of the last vector traces the reconstructed drawing.

This is essentially representing a signal as a sum of rotating complex vectors.

---

## Building

This project uses  **CMake** .

```bash
git clone https://github.com/YOUR_USERNAME/fourier_epicycle.git
cd fourier_epicycle

cmake -S . -B build
cmake --build build
```

Run:

```bash
./build/fourier_draw
```

---

## Project Structure

```
fourier_epicycle/
│
├── src/           # source files
├── include/       # headers
├── CMakeLists.txt
└── README.md
```

---

## Why This Is Interesting

Fourier analysis appears everywhere:

* signal processing
* image compression
* audio synthesis
* quantum mechanics
* machine learning

This project provides an **intuitive geometric visualization** of Fourier series that makes the mathematics much easier to understand.

---

## Inspiration

Inspired by visual explanations of Fourier series and epicycles often used in mathematical visualization projects.

---

## Future Improvements

* SVG input for arbitrary drawings
* interactive drawing mode
* adjustable number of Fourier terms
* real-time frequency filtering
* GPU rendering
