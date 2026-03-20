from flask import Flask, render_template, jsonify
import subprocess

app = Flask(__name__)


@app.route('/')
def mainpage():
    return render_template('index.html')


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


if __name__ == '__main__':
    app.run(debug=False, port=5000)