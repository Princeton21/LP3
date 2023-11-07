#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    char data;
    int freq;
    Node* left;
    Node* right;

    Node(char d, int f) {
        data = d;
        freq = f;
        left = right = nullptr;
    }

    ~Node() {
        delete left;
        delete right;
    }
};

class Compare {
public:
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

Node* root = nullptr; 
map<char, string> codes;

Node* buildHuffmanTree(map<char, int>& freqMap) {
    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (auto pair : freqMap) {
        Node* newNode = new Node(pair.first, pair.second);
        pq.push(newNode);
    }
    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();

        Node* internalNode = new Node('$', left->freq + right->freq);
        internalNode->left = left;
        internalNode->right = right;

        pq.push(internalNode);
    }

    return pq.top();
}

void generateCodes(Node* root, string code, map<char, string>& codes) {
    if (root->left == nullptr && root->right == nullptr) {
        codes[root->data] = code;
        return;
    }
    generateCodes(root->left, code + "0", codes);
    generateCodes(root->right, code + "1", codes);
}

string huffmanEncode(string input) {
    map<char, int> freqMap;
    for (char c : input) freqMap[c]++;
    root = buildHuffmanTree(freqMap); 
    generateCodes(root, "", codes);
    string encodedString;
    for (char c : input) encodedString += codes[c];
    return encodedString; 
}

string huffmanDecode(string encodedString) { 
    string decodedString;
    string currentCode;
    Node* current = root; 

    for (char bit : encodedString) {
        if (bit == '0') {
            current = current->left;
        } else {
            current = current->right;
        }

        if (current->left == nullptr && current->right == nullptr) {
            decodedString += current->data;
            current = root; 
        }
    }

    return decodedString;
}

int main() {
    string input;
    getline(cin, input);
    string encodedString = huffmanEncode(input);
    cout << "Encoded string: " << encodedString << endl;
    
    string decodedString = huffmanDecode(encodedString);
    cout << "Decoded string: " << decodedString << endl;

    delete root;
}

// TC - O(nlogn)
// SC - O(n)
/*
-Princeton likes watching anime!!

freqMap
  3
! 3
P 1
a 2
c 2
e 3
g 1
h 1
i 4
k 1
l 1
m 1
n 4
o 1
r 1
s 1
t 2
w 1

Encoded string: 10000110010100011101111010101100000111110110101001100111010010111110011011110101101101110100011000111110111001010101101110000000000
Decoded string: Princeton likes watching anime!!!
*/