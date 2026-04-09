#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

struct HNode {
    int id, freq, left, right;
    char ch;
    HNode(int i, char c, int f): id(i), freq(f), left(-1), right(-1), ch(c) {}
    HNode(int i, int f, int l, int r): id(i), freq(f), left(l), right(r), ch('\0') {}
};

vector<HNode> nodes;

void outputTree(int id, int pid, char dir) {
    if (id < 0) return;
    string lbl = (nodes[id].ch != '\0') ? string(1, nodes[id].ch) : "*";
    cout << "TNODE " << id << " " << pid << " " << dir << " " << nodes[id].freq << " " << lbl << endl;
    if (nodes[id].left  != -1) outputTree(nodes[id].left,  id, 'L');
    if (nodes[id].right != -1) outputTree(nodes[id].right, id, 'R');
}

void genCodes(int id, const string& code) {
    if (nodes[id].ch != '\0') { cout << "CODE " << nodes[id].ch << " " << code << endl; return; }
    genCodes(nodes[id].left,  code + "0");
    genCodes(nodes[id].right, code + "1");
}

int main() {
    vector<pair<char,int>> chars = {{'A',5},{'B',9},{'C',12},{'D',13},{'E',16},{'F',45}};
    int n = chars.size();
    cout << "CONFIG " << n << endl;

    auto cmp = [](int a, int b){ return nodes[a].freq > nodes[b].freq; };
    priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);

    for (auto& [ch, fr] : chars) {
        int id = nodes.size();
        nodes.push_back(HNode(id, ch, fr));
        cout << "LEAF " << id << " " << ch << " " << fr << endl;
        pq.push(id);
    }

    while (pq.size() > 1) {
        int l = pq.top(); pq.pop();
        int r = pq.top(); pq.pop();
        int id = nodes.size();
        nodes.push_back(HNode(id, nodes[l].freq + nodes[r].freq, l, r));
        cout << "MERGE " << l << " " << r << " " << id << " " << nodes[id].freq << endl;
        pq.push(id);
    }

    int root = pq.top();
    outputTree(root, -1, 'N');
    genCodes(root, "");
    cout << "DONE" << endl;
    return 0;
}
