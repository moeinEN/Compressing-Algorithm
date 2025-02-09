#include <bits/stdc++.h>
#include "runLength.h"
using namespace std;

string runLength(string s) {
    string res = "";
    int n = s.length();
    if (n == 0) return res;

    char temp = s.at(0);
    int cnt = 1;

    for (int i = 1; i < n; i++) {
        if (temp == '|') {
            res += "||";
            temp = s.at(i);
            cnt = 1;
            continue;
        }
        if (s.at(i) == temp) {
            cnt++;
        } else {
            res += "|x" + string(1, temp) + to_string(cnt);
            temp = s.at(i);
            cnt = 1;
        }
    }

    if (temp == '|') {
        res += "||";
    } else {
        res += "|x" + string(1, temp) + to_string(cnt);
    }

    return res;
}

string runLengthDecode(string encoded) {
    string decoded = "";
    int n = encoded.length();
    for (int i = 0; i < n; i++) {
        if (encoded[i] == '|') {
            if (i + 1 < n && encoded[i + 1] == '|') {
                decoded += '|';
                i++;
            } else if (i + 2 < n && encoded[i + 1] == 'x') {
                char ch = encoded[i + 2];
                i += 3;
                string countStr = "";
                while (i < n && isdigit(encoded[i])) {
                    countStr += encoded[i];
                    i++;
                }
                i--;
                int count = stoi(countStr);
                decoded += string(count, ch);
            }
        }
    }
    return decoded;
}



