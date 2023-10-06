#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

struct HuffmanNode {
    char data;
    int frequency;
    HuffmanNode *left, *right;

    HuffmanNode(char data, int frequency) : data(data), frequency(frequency), left(nullptr), right(nullptr) {}
};


struct CompareNodes {
    bool operator()(HuffmanNode* a, HuffmanNode* b) {
        return a->frequency > b->frequency;
    }
};


HuffmanNode* buildHuffmanTree(const unordered_map<char, int>& frequencies) {
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, CompareNodes> pq;

    for (const auto& pair : frequencies) {
        pq.push(new HuffmanNode(pair.first, pair.second));
    }

    while (pq.size() > 1) {
        HuffmanNode* left = pq.top();
        pq.pop();
        HuffmanNode* right = pq.top();
        pq.pop();

        HuffmanNode* newNode = new HuffmanNode('$', left->frequency + right->frequency);
        newNode->left = left;
        newNode->right = right;


        pq.push(newNode);
    }

    return pq.top();
}


void printHuffmanCodes(HuffmanNode* root, string code, unordered_map<char, string>& huffmanCodes) {
    if (!root)
        return;

    if (root->data != '$') {
        cout << root->data << ": " << code << endl;
        huffmanCodes[root->data] = code;
    }

    printHuffmanCodes(root->left, code + "0", huffmanCodes);
    printHuffmanCodes(root->right, code + "1", huffmanCodes);
}

int main() {
    string input;
    cout << "Enter the input string: ";
    cin >> input;

    unordered_map<char, int> frequencies;

    for (char c : input) {
        frequencies[c]++;
    }

    HuffmanNode* root = buildHuffmanTree(frequencies);

    unordered_map<char, string> huffmanCodes;
    printHuffmanCodes(root, "", huffmanCodes);

    cout << "Huffman Codes:" << endl;
    for (const auto& pair : huffmanCodes) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}
