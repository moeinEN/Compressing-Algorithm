#include <bits/stdc++.h>

using namespace std;

#ifndef HUFFMAN_H
#define HUFFMAN_H


struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;
    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};
struct Compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

unordered_map<char, int> buildFrequencyTable(const string& text);
Node* buildHuffmanTree(const unordered_map<char, int>& freqTable);
void generateCodes(Node* root, const string& path, unordered_map<char, string>& codes);
string encode(const string& text, unordered_map<char, string>& codes);
string decode(const string& encoded, Node* root);
string huffmanEncode(const string& text);
string huffmanDecode(const string& encoded, const string& text);


#endif //HUFFMAN_H
