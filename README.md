# DAA Visualizer

A high-performance Algorithm Visualizer for Design and Analysis of Algorithms (DAA). This project aims to provide a clear and interactive way to understand various sorting algorithms through real-time visualization.

## 🚀 Features

- **Interactive Sorting Visualization**: Watch algorithms in action with real-time bar animations.
- **Multiple Algorithms Supported**:
  - **Merge Sort**: $O(n \log n)$ - Stable
  - **Quick Sort**: $O(n \log n)$ - Unstable
  - **Heap Sort**: $O(n \log n)$ - Unstable
  - **Bubble Sort**: $O(n^2)$ - Stable
  - **Insertion Sort**: $O(n^2)$ - Stable
  - **Selection Sort**: $O(n^2)$ - Unstable
- **Dynamic Speed Control**: Adjust the animation delay (in milliseconds) using a slider.
- **Complexity Insights**: Displays time complexity and stability information for each algorithm.

## 🛠️ Tech Stack

- **Backend (Algorithms)**: C++ for efficient sorting logic and step generation.
- **Backend (Web)**: Python (Flask) as the interface between the core algorithms and the web interface.
- **Frontend**: HTML5, CSS3, and JavaScript for the interactive UI and animations.

## ⚙️ How It Works

1.  **Core Logic**: Each sorting algorithm is implemented in C++. When executed, these programs output a series of "steps" (e.g., `CMP` for comparison, `UPD` for value updates/swaps).
2.  **Web Interface**: The Flask backend serves the frontend and handles requests for specific sorting algorithms.
3.  **Bridge**: Flask uses `subprocess` to run the corresponding C++ binary and captures its standard output.
4.  **Visualization**: The frontend fetches these steps as a JSON object and animates the HTML elements (bars) to reflect the sorting process.

## 📦 Installation & Setup

### Prerequisites

- **GCC (G++)**: For compiling C++ files.
- **Python 3.x**: To run the Flask server.
- **Flask**: A micro web framework for Python.
  ```bash
  pip install flask
  ```

### Step 1: Compile the C++ Algorithms

Compile each C++ source file into a binary that the Flask app can execute. Navigate to the project root and run:

```bash
g++ bubble.cpp -o bubble
g++ heap.cpp -o heap
g++ insertion.cpp -o insertion
g++ merge.cpp -o merge
g++ quick.cpp -o quick
g++ selection.cpp -o selection
```

### Step 2: Run the Flask Server

Start the web application by running the `main.py` script:

```bash
python3 main.py
```

The application will be available at `http://127.0.0.1:5000/`.

## 📂 Project Structure

- `main.py`: The Flask application entry point.
- `templates/index.html`: The main web page and visualization logic.
- `static/style.css`: Styles for the visualizer.
- `*.cpp`: C++ source files for each sorting algorithm.
- `*` (binaries): Compiled algorithm executables (after following installation steps).

## 🎮 Usage

1. Open the application in your browser.
2. Select a sorting algorithm from the buttons at the top.
3. Adjust the **Animation Speed** slider to your preference.
4. Observe the visualization:
   - **Yellow**: Current comparison or update.
   - **Blue**: Original element state.
   - **Green**: Fully sorted state.

---
*Created as part of the Design and Analysis of Algorithms study.*
