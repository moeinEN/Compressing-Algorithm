#include <bits/stdc++.h>
#include "bwt.h"

using namespace std;


string bwt_encode(string data) {
    int n = data.size();

    std::vector<int> p(n), c(n), cnt(std::max(256, n), 0);

    for (int i = 0; i < n; i++)
        cnt[static_cast<uint8_t>(data[i])]++;
    for (int i = 1; i < 256; i++)
        cnt[i] += cnt[i - 1];
    for (int i = 0; i < n; i++)
        p[--cnt[static_cast<uint8_t>(data[i])]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (data[p[i]] != data[p[i - 1]])
            classes++;
        c[p[i]] = classes - 1;
    }

    std::vector<int> pn(n), cn(n);
    for (int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }
        cnt.assign(classes, 0);
        for (int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            std::pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            std::pair<int, int> prev = {c[p[i - 1]], c[(p[i - 1] + (1 << h)) % n]};
            if (cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }

    std::string bwt = "";
    size_t first;
    for (int i = 0; i < n; i++) {
        bwt += data[(p[i] + n - 1) % n];
        if (p[i] == 0)
            first = i;
    }

    string result(bwt);
    std::string serialized_first((char *) (&first), sizeof(first));
    result += serialized_first;
    return result;
}

string bwt_decode(string data) {
    size_t n = data.size() - sizeof(size_t);
    size_t first;
    std::memcpy(&first, &data[n], sizeof(size_t));

    std::string sortedBwt = data.substr(0, n);
    std::sort(sortedBwt.begin(), sortedBwt.end(), [](char a, char b) {
        return static_cast<uint8_t>(a) < static_cast<uint8_t>(b);
    });
    int lShift[n];

    int x = first;

    std::queue<int> arr[256];

    for (int i = 0; i < n; i++) {
        arr[static_cast<uint8_t>(data[i])].push(i);
    }

    for (int i = 0; i < n; i++) {
        lShift[i] = arr[static_cast<uint8_t>(sortedBwt[i])].front();
        arr[static_cast<uint8_t>(sortedBwt[i])].pop();
    }

    char decoded[n];
    for (int i = 0; i < n; i++) {
        x = lShift[x];
        decoded[n - 1 - i] = data[x];
    }
    std::string decodedStr(decoded, n);

    return string(std::string(decodedStr.rbegin(), decodedStr.rend()));
}