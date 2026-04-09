# DAA Visualizer

A high-performance Algorithm Visualizer for Design and Analysis of Algorithms (DAA). This project aims to provide a clear and interactive way to understand various sorting algorithms through real-time visualization.

## 🚀 Features

- **Interactive Sorting Visualization**: Watch algorithms in action with real-time bar animations.
- **Multiple Algorithms Supported**:
  - **Sorting**: Merge Sort, Quick Sort, Heap Sort, Bubble Sort, Insertion Sort, Selection Sort.
  - **Trees**: Binary Search Tree (Build, Inorder, Preorder, Postorder).
  - **Dynamic Programming**: 0/1 Knapsack, Matrix Chain Multiplication.
  - **Greedy Algorithms**: Huffman Coding.
- **Dynamic Speed Control**: Adjust the animation delay (in milliseconds) using a slider.
- **Complexity Insights**: Displays time complexity and stability information for each algorithm.

## 🛠️ Tech Stack

- **Backend (Algorithms)**: C++ for efficient logic and step generation.
- **Backend (Web)**: Python (Flask) with `subprocess` for binary execution.
- **Frontend**: HTML5, CSS3 (Vanilla), and JavaScript for interactive SVG and Table animations.

## ⚙️ How It Works

1.  **Core Logic**: Algorithms are implemented in C++. When executed, they output a series of "steps" (e.g., `CMP` for comparison, `NODE` for tree building, `CELL` for DP table update).
2.  **Web Interface**: The Flask backend serves the frontend and handles requests for specific algorithms.
3.  **Bridge**: Flask runs the corresponding C++ binary and captures its standard output.
4.  **Visualization**: The frontend fetches these steps and animates the UI (Bars, SVG Trees, or DP Tables) to reflect the process.

## 📦 Installation & Setup

### Prerequisites

- **GCC (G++)**: For compiling C++ files.
- **Python 3.x**: To run the Flask server.
- **Flask**: `pip install flask`

### Step 1: Compile the C++ Algorithms

Run theFollowing to compile all core components:

```bash
g++ bubble.cpp -o bubble
g++ heap.cpp -o heap
g++ insertion.cpp -o insertion
g++ merge.cpp -o merge
g++ quick.cpp -o quick
g++ selection.cpp -o selection
g++ tree.cpp -o tree
g++ knapsack.cpp -o knapsack
g++ mcm.cpp -o mcm
g++ huffman.cpp -o huffman
```

### Step 2: Run the Flask Server

```bash
python3 main.py
```

The application will be available at `http://127.0.0.1:5000/`.

## 📂 Project Structure

- `main.py`: Flask application entry point.
- `templates/index.html`: Main web page with visualization logic (D3-like SVG and Table animations).
- `static/style.css`: Modern glassmorphic styles.
- `*.cpp`: C++ source files for algorithm logic.
- `*` (binaries): Compiled algorithm executables.

## 🎮 Usage

1. Open the application in your browser.
2. Select an algorithm category (Sorting, Tree, DP, Greedy).
3. Adjust the **Animation Speed** slider.
4. Observe the visualization:
   - **Sorting**: Bars moving and changing colors.
   - **BST**: Tree building and traversal highlights.
   - **DP**: Table cells filling with optimal value tracking.
   - **Greedy**: Huffman tree construction and priority queue updates.

---
*Created as part of the Design and Analysis of Algorithms study.*
