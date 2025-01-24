#include <bits/stdc++.h>
using namespace std;


string shiftString(string s) {
    int len = s.length();
    string res = "";
    char c = s.at(0);
    for (int i = 1; i < len; i++) {
        res += s.at(i);
    }
    res += c;
    return res;
}

int compareRotations(const void* a, const void* b) {
    const char* str1 = *(const char**)a;
    const char* str2 = *(const char**)b;
    return strcmp(str1, str2);
}

vector<string> generateRotations(const string& s) {
    vector<string> rotations;
    int n = s.length();
    for (int i = 0; i < n; ++i) {
        rotations.push_back(s.substr(i) + s.substr(0, i));
    }
    return rotations;
}

vector<char> encodeWordBWT(string& word) {
    vector<string> rotations = generateRotations(word);

    const char** rotationArray = new const char*[rotations.size()];
    for (int i = 0; i < rotations.size(); ++i) {
        rotationArray[i] = rotations[i].c_str();
    }

    qsort(rotationArray, rotations.size(), sizeof(const char*), compareRotations);

    vector<char> decodedBWT;
    for (int i = 0; i < rotations.size(); ++i) {
        decodedBWT.push_back(rotationArray[i][rotations[i].length() - 1]);
    }

    delete[] rotationArray;


    return decodedBWT;
}

string decodeBWT(const string& bwt) {
    int n = bwt.size();
    vector<int> count(256, 0);
    vector<int> rank(n);

    for (int i = 0; i < n; i++) {
        rank[i] = count[bwt[i]];
        count[bwt[i]]++;
    }

    vector<int> first(256, 0);
    int pos = 0;
    for (int i = 0; i < 256; i++) {
        if (count[i] > 0) {
            first[i] = pos;
            pos += count[i];
        }
    }

    int index;
    for (int i = 0; i < n; i++) {
        if (bwt[i] == '$') {
            index = i;
            break;
        }
    }

    string original(n, ' ');
    int current = index;
    for (int i = n - 1; i >= 0; i--) {
        original[i] = bwt[current];
        current = first[bwt[current]] + rank[current];
    }

    return original;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    string word;
    cin >> word;
    word += "$";

    vector<char> encodedBWT = encodeWordBWT(word);
    for (int i = 0; i < word.length(); ++i) {
        cout << encodedBWT[i];
    }
    cout << endl;


    string encodedBWTString(encodedBWT.begin(), encodedBWT.end());
    string decodedBWT = decodeBWT(encodedBWTString);
    cout << decodedBWT << endl;

    return 0;
}