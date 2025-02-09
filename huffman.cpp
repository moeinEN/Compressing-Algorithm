#include <bits/stdc++.h>
#include "huffman.h"

using namespace std;


unordered_map<char, int> buildFrequencyTable(const string& text) {
    unordered_map<char, int> freqTable;
    for (char c : text) freqTable[c]++;
    return freqTable;
}

Node* buildHuffmanTree(const unordered_map<char, int>& freqTable) {
    priority_queue<Node*, vector<Node*>, Compare> minHeap;
    for (auto& entry : freqTable) {
        minHeap.push(new Node(entry.first, entry.second));
    }

    while (minHeap.size() > 1) {
        Node* left = minHeap.top(); minHeap.pop();
        Node* right = minHeap.top(); minHeap.pop();

        Node* merged = new Node('\0', left->freq + right->freq);
        merged->left = left;
        merged->right = right;

        minHeap.push(merged);
    }

    return minHeap.top();
}

void generateCodes(Node* root, const string& path, unordered_map<char, string>& codes) {
    if (!root) return;

    if (!root->left && !root->right) {
        codes[root->ch] = path;
    }

    generateCodes(root->left, path + "0", codes);
    generateCodes(root->right, path + "1", codes);
}

string encode(const string& text, unordered_map<char, string>& codes) {
    string result;
    for (char c : text) {
        result += codes[c];
    }
    return result;
}

string decode(const string& encoded, Node* root) {
    string decoded;
    Node* current = root;
    for (char bit : encoded) {
        current = (bit == '0') ? current->left : current->right;

        if (!current->left && !current->right) {
            decoded += current->ch;
            current = root;
        }
    }
    return decoded;
}

string huffmanEncode(const string& text) {
    unordered_map<char, int> freqTable = buildFrequencyTable(text);
    Node* root = buildHuffmanTree(freqTable);
    unordered_map<char, string> huffmanCodes;
    generateCodes(root, "", huffmanCodes);

    return encode(text, huffmanCodes);
}

string huffmanDecode(const string& encoded, const string& text) {
    unordered_map<char, int> freqTable = buildFrequencyTable(text);
    Node* root = buildHuffmanTree(freqTable);

    return decode(encoded, root);
}
