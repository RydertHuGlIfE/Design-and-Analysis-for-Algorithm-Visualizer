from flask import Flask, render_template, jsonify, request
from math import isfinite
import subprocess

app = Flask(__name__)

SORT_BINARIES = {
    'bubble': './bubble',
    'merge': './merge',
    'quick': './quick',
    'heap': './heap',
    'insertion': './insertion',
    'selection': './selection',
}


@app.route('/sort/<algo>')
def get_sort_steps(algo):
    binary = SORT_BINARIES.get(algo)
    if not binary:
        return jsonify({"error": "Unknown algorithm"}), 404
    n = request.args.get('n')
    cmd = [binary] + ([n] if n else [])
    process = subprocess.Popen(cmd, stdout=subprocess.PIPE, text=True)
    steps = []
    for line in process.stdout:
        steps.append(line.strip())
    return jsonify({"steps": steps})


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


@app.route('/mcm')
def get_mcm_steps():
    process = subprocess.Popen(['./mcm'], stdout=subprocess.PIPE, text=True)
    steps = []
    for line in process.stdout:
        steps.append(line.strip())
    return jsonify({"steps": steps})


@app.route('/huffman')
def get_huffman_steps():
    process = subprocess.Popen(['./huffman'], stdout=subprocess.PIPE, text=True)
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


def build_mst_trace(nodes=None, edges=None):
    if nodes is None:
        nodes = list('ABCDEFG')
    if edges is None:
        edges = [
            {"u": "A", "v": "B", "weight": 4},
            {"u": "A", "v": "C", "weight": 3},
            {"u": "B", "v": "C", "weight": 1},
            {"u": "B", "v": "D", "weight": 2},
            {"u": "C", "v": "D", "weight": 4},
            {"u": "C", "v": "E", "weight": 2},
            {"u": "D", "v": "E", "weight": 3},
            {"u": "D", "v": "F", "weight": 2},
            {"u": "E", "v": "F", "weight": 3},
            {"u": "E", "v": "G", "weight": 5},
            {"u": "F", "v": "G", "weight": 1},
        ]
    parent = {node: node for node in nodes}
    rank = {node: 0 for node in nodes}
    steps = []
    total_weight = 0
    selected_count = 0

    def find(node):
        if parent[node] != node:
            parent[node] = find(parent[node])
        steps.append({"type": "FIND", "node": node, "root": parent[node]})
        return parent[node]

    for edge in sorted(edges, key=lambda item: (item["weight"], item["u"], item["v"])):
        first, second, weight = edge["u"], edge["v"], edge["weight"]
        steps.append({"type": "CONSIDER", "u": first, "v": second, "weight": weight})
        first_root = find(first)
        second_root = find(second)

        if first_root == second_root:
            steps.append({"type": "REJECT", "u": first, "v": second, "weight": weight})
            continue

        steps.append({"type": "ACCEPT", "u": first, "v": second, "weight": weight})
        if rank[first_root] < rank[second_root]:
            first_root, second_root = second_root, first_root
        parent[second_root] = first_root
        steps.append({"type": "UNION", "firstRoot": first_root, "secondRoot": second_root})
        if rank[first_root] == rank[second_root]:
            rank[first_root] += 1
        total_weight += weight
        selected_count += 1

    steps.append({"type": "DONE", "weight": total_weight, "edgeCount": selected_count})
    return {"nodes": nodes, "edges": edges}, steps, total_weight


def validate_mst_graph(payload):
    if not isinstance(payload, dict):
        raise ValueError("Send a graph with nodes and edges.")

    nodes = payload.get("nodes")
    edges = payload.get("edges")
    if not isinstance(nodes, list) or not 2 <= len(nodes) <= 26:
        raise ValueError("A graph must have between 2 and 26 points.")
    if any(not isinstance(node, str) or len(node) != 1 or not "A" <= node <= "Z" for node in nodes):
        raise ValueError("Point labels must be unique letters from A to Z.")
    if len(set(nodes)) != len(nodes):
        raise ValueError("Point labels must be unique.")
    if not isinstance(edges, list) or len(edges) > 325:
        raise ValueError("Provide a valid list of weighted edges.")

    valid_edges = []
    seen_pairs = set()
    for edge in edges:
        if not isinstance(edge, dict):
            raise ValueError("Each edge needs two endpoints and a distance.")
        first, second, weight = edge.get("u"), edge.get("v"), edge.get("weight")
        if first not in nodes or second not in nodes or first == second:
            raise ValueError("Edges must connect two different points in the graph.")
        if isinstance(weight, bool) or not isinstance(weight, (int, float)) or not isfinite(weight) or weight < 0:
            raise ValueError("Edge distances must be finite, non-negative numbers.")
        pair = frozenset((first, second))
        if pair in seen_pairs:
            raise ValueError("Only one edge is allowed between each pair of points.")
        seen_pairs.add(pair)
        valid_edges.append({"u": first, "v": second, "weight": weight})

    return nodes, valid_edges


@app.route('/mst', methods=['GET', 'POST'])
def get_mst_steps():
    if request.method == 'POST':
        try:
            nodes, edges = validate_mst_graph(request.get_json(silent=True))
            graph, steps, total_weight = build_mst_trace(nodes, edges)
            if steps[-1]["edgeCount"] != len(nodes) - 1:
                return jsonify({"error": "The graph is disconnected. Connect every point before solving its minimum spanning tree."}), 400
        except ValueError as error:
            return jsonify({"error": str(error)}), 400
    else:
        graph, steps, total_weight = build_mst_trace()
    return jsonify({"graph": graph, "steps": steps, "totalWeight": total_weight})


if __name__ == '__main__':
    app.run(debug=False, port=5000)