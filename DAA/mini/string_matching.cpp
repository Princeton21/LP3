#include <bits/stdc++.h>
using namespace std;

// naive approach
// TC - O((n-m+1)*m)
// SC - O(1)
vector<int> naiveStringMatching(const string& text, const string& pattern) {
	vector<int> occurrences;
	int textLen = text.length();
	int patternLen = pattern.length();

	for (int i = 0; i <= textLen - patternLen; i++) {
		int j = 0;
		while (j < patternLen && text[i + j] == pattern[j]) j++;
		if (j == patternLen) occurrences.push_back(i);
	}

	return occurrences;
}

// rabinkarp approach
// TC - O(n+m)
// SC - O(1)
vector<int> rabinKarpStringMatching(const string& text, const string& pattern) {
    vector<int> occurrences;
    int textLen = text.length();
    int patternLen = pattern.length();
    const int prime = 101;
    int patternHash = 0;
    int textHash = 0;
    int h = 1;
    for (int i = 0; i < patternLen - 1; i++) {
        h = (h * 256) % prime;
    }
    for (int i = 0; i < patternLen; i++) {
        patternHash = (patternHash * 256 + pattern[i]) % prime;
        textHash = (textHash * 256 + text[i]) % prime;
    }
    for (int i = 0; i <= textLen - patternLen; i++) {
        if (patternHash == textHash) {
            int j = 0;
            while (j < patternLen && text[i + j] == pattern[j]) {
                j++;
            }
            if (j == patternLen) {
                occurrences.push_back(i);
            }
        }
        if (i < textLen - patternLen) {
            textHash = (256 * (textHash - text[i] * h) + text[i + patternLen]) % prime;
            if (textHash < 0) {
                textHash += prime;
            }
        }
    }
    return occurrences;
}

int main() {
    string text, pattern;
    cout << "Enter the text: ";
    getline(cin, text);
    cout << "Enter the pattern: ";
    getline(cin, pattern);
    vector<int> naiveOccurrences = naiveStringMatching(text, pattern);
    cout << "Naive Algorithm - Occurrences found at indices: ";
    for (int idx : naiveOccurrences) cout << idx << " ";
    cout << endl;
    vector<int> rkOccurrences = rabinKarpStringMatching(text, pattern);
    cout << "Rabin-Karp Algorithm - Occurrences found at indices: ";
    for (int idx : rkOccurrences) cout << idx << " ";
    cout << endl;
    return 0;
}