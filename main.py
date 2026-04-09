from flask import Flask, render_template, jsonify
import subprocess

app = Flask(__name__)


@app.route('/')
def mainpage():
    return render_template('index.html')



@app.route('/tree/<traversal_type>')
def get_tree_steps(traversal_type):
    process = subprocess.Popen(['./tree', traversal_type], stdout=subprocess.PIPE, text=True)
    steps = []
    for line in process.stdout:
        steps.append(line.strip())
    return jsonify({"steps": steps})


@app.route('/knapsack')
def get_knapsack_steps():
    process = subprocess.Popen(['./knapsack'], stdout=subprocess.PIPE, text=True)
    steps = []
    for line in process.stdout:
        steps.append(line.strip())
    return jsonify({"steps": steps})



@app.route('/mergesort')
def get_merge_steps():
    process=subprocess.Popen(['./merge'], stdout=subprocess.PIPE, text=True)
    steps = []

    for line in process.stdout:
        steps.append(line.strip())
    return jsonify({"steps": steps})

@app.route('/quicksort')
def get_quick_steps():
    process = subprocess.Popen(['./quick'], stdout=subprocess.PIPE, text=True)
    steps = []

    for line in process.stdout:
        steps.append(line.strip())
    return jsonify({"steps": steps})


@app.route('/heapsort')
def get_heap_steps():
    process = subprocess.Popen(['./heap'], stdout=subprocess.PIPE, text=True)
    steps = []

    for line in process.stdout:
        steps.append(line.strip())
    return jsonify({"steps": steps})


@app.route('/insertionsort')
def get_inse_steps():
    process = subprocess.Popen(['./insertion'], stdout=subprocess.PIPE, text=True)
    steps = []

    for line in process.stdout:
        steps.append(line.strip())
    return jsonify({"steps": steps})

@app.route('/selectionsort')
def get_select_steps():
    process = subprocess.Popen(['./selection'], stdout=subprocess.PIPE, text=True)
    steps = []

    for line in process.stdout:
        steps.append(line.strip())
    return jsonify({"steps": steps})
    

@app.route('/bubblesort')
def get_bubble_steps():
    process = subprocess.Popen(['./bubble'], stdout=subprocess.PIPE, text=True)
    steps = []

    for line in process.stdout:
        steps.append(line.strip())
    return jsonify({"steps": steps})


if __name__ == '__main__':
    app.run(debug=False, port=5000)