#include <bits/stdc++.h>
#include "bwt.h"
#include "runLength.h"
#include "huffman.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    string word;
    getline(cin, word);


    string bwtEncode = bwt_encode(word);
    string runLengthEncoded = runLength(bwtEncode);
    string huffmanEncoded = huffmanEncode(word);

    string huffmanDecoded = huffmanDecode(huffmanEncoded, word);
    cout << huffmanDecoded << endl;
    string runLengthDecoded = runLengthDecode(runLengthEncoded);
    string bwtDecode = bwt_decode(runLengthDecoded);

    cout << bwtEncode << endl;
    cout << runLengthEncoded << endl;
    cout << huffmanEncoded << endl;

    cout << huffmanDecoded << endl;
    cout << runLengthDecoded << endl;
    cout << bwtDecode << endl;


    return 0;
}
