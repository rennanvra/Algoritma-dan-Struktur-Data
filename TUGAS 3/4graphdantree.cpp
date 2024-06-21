#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int nilai;
    vector<Node*> anak;
    vector<Node*> tetangga; // untuk graph

    Node(int nilai) {
        this->nilai = nilai;
    }
};

class Tree {
private:
    Node* root;

public:
    Tree() {
        root = nullptr;
    }

    void tambahNode(int nilai) {
        if (root == nullptr) {
            root = new Node(nilai);
        } else {
            tambahNodeRekursif(root, nilai);
        }
    }

    void tambahNodeRekursif(Node* node, int nilai) {
        if (nilai < node->nilai) {
            if (node->anak.size() < 1) {
                node->anak.push_back(new Node(nilai));
            } else {
                tambahNodeRekursif(node->anak[0], nilai);
            }
        } else {
            if (node->anak.size() < 2) {
                if (node->anak.size() == 1) {
                    node->anak.push_back(new Node(nilai));
                } else {
                    node->anak.push_back(nullptr);
                    node->anak.push_back(new Node(nilai));
                }
            } else {
                tambahNodeRekursif(node->anak[1], nilai);
            }
        }
    }

    void tambahEdge(Node* node1, Node* node2) {
        node1->tetangga.push_back(node2);
        node2->tetangga.push_back(node1);
    }

    void cetakTree() {
        cetakTreeRekursif(root);
    }

    void cetakTreeRekursif(Node* node) {
        if (node != nullptr) {
            cout << node->nilai << " ";
            for (Node* child : node->anak) {
                cetakTreeRekursif(child);
            }
        }
    }

    void cetakGraph() {
        cetakGraphRekursif(root);
    }

    void cetakGraphRekursif(Node* node) {
        if (node != nullptr) {
            cout << "Node " << node->nilai << " terhubung dengan: ";
            for (Node* neighbor : node->tetangga) {
                cout << neighbor->nilai << " ";
            }
            cout << endl;
            for (Node* child : node->anak) {
                cetakGraphRekursif(child);
            }
        }
    }

    Node* findNode(int nilai) {
        return findNodeRekursif(root, nilai);
    }

    Node* findNodeRekursif(Node* node, int nilai) {
        if (node == nullptr) {
            return nullptr;
        }

        if (node->nilai == nilai) {
            return node;
        }

        for (Node* child : node->anak) {
            Node* found = findNodeRekursif(child, nilai);
            if (found != nullptr) {
                return found;
            }
        }

        return nullptr;
    }
};

int main() {
    Tree tree;

    tree.tambahNode(5);
    tree.tambahNode(3);
    tree.tambahNode(7);
    tree.tambahNode(2);
    tree.tambahNode(4);
    tree.tambahNode(6);
    tree.tambahNode(8);

    Node* node2 = tree.findNode(2);
    Node* node4 = tree.findNode(4);
    Node* node3 = tree.findNode(3);
    Node* node6 = tree.findNode(6);
    Node* node5 = tree.findNode(5);
    Node* node7 = tree.findNode(7);
    Node* node8 = tree.findNode(8);

    tree.tambahEdge(node2, node4);
    tree.tambahEdge(node3, node6);
    tree.tambahEdge(node5, node7);
    tree.tambahEdge(node7, node8);

    cout << "Tree: ";
    tree.cetakTree();
    cout << endl;

    cout << "Graph: " << endl;
    tree.cetakGraph();

    return 0;
}
