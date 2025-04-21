# Project Requirements

This project requires the following external libraries and tools in order to compile and run correctly.

---

## 1. [doctest](https://github.com/doctest/doctest) – Unit Testing Framework

- **Type**: Header-only  
- **Purpose**: Used to write and run unit tests (`#include "doctest.h"`)  
- **Installation**:  
  - Download the file `doctest.h` from the [official repository](https://github.com/doctest/doctest/blob/master/doctest/doctest.h)  
  - Place it in the `external/` or `include/` folder of your project

<pre><code>mkdir -p external
curl -o external/doctest.h https://raw.githubusercontent.com/doctest/doctest/master/doctest/doctest.h
</code></pre>

---

## 2. [sciplot](https://github.com/sciplot/sciplot) – Plotting Library

- **Type**: Header-only (C++ wrapper around gnuplot)  
- **Purpose**: Used for plotting scientific graphs (`#include &lt;sciplot/sciplot.hpp&gt;`)  
- **Installation**:  
  - Download `sciplot.hpp` from the [official GitHub repository](https://github.com/sciplot/sciplot)  
  - Place it in a folder like `external/sciplot/`

<pre><code>mkdir -p external/sciplot
curl -o external/sciplot/sciplot.hpp https://raw.githubusercontent.com/sciplot/sciplot/master/include/sciplot/sciplot.hpp
</code></pre>

---

## 3. [gnuplot](http://www.gnuplot.info/) – External Tool (Required by sciplot)

- **Type**: System dependency  
- **Purpose**: Required runtime tool for generating plots  
- **Installation**:
  - **Ubuntu/Debian**:  
    <code>sudo apt install gnuplot</code>
  - **macOS (Homebrew)**:  
    <code>brew install gnuplot</code>
  - **Windows**:  
    Download the installer from [gnuplot.info](http://www.gnuplot.info/)

Make sure `gnuplot` is accessible from your system's `PATH`.
