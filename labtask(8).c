
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Huffman Tree Node
struct Node {
    int freq;
    struct Node *left, *right;
};

// Create new node
struct Node* newNode(int freq) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

// Swap two heap nodes
void swap(struct Node** a, struct Node** b) {
    struct Node* t = *a;
    *a = *b;
    *b = t;
}

// Min-heapify
void minHeapify(struct Node* heap[], int size, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < size && heap[left]->freq < heap[smallest]->freq)
        smallest = left;
    if (right < size && heap[right]->freq < heap[smallest]->freq)
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        minHeapify(heap, size, smallest);
    }
}

// Extract min node
struct Node* extractMin(struct Node* heap[], int *size) {
    struct Node* min = heap[0];
    heap[0] = heap[*size - 1];
    (*size)--;
    minHeapify(heap, *size, 0);
    return min;
}

// Insert node into heap
void insertHeap(struct Node* heap[], int *size, struct Node* node) {
    int i = (*size)++;
    heap[i] = node;

    while (i && heap[i]->freq < heap[(i-1)/2]->freq) {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

// Preorder traversal to print Huffman codes
void preOrder(struct Node* root, char code[], int depth) {
    if (root == NULL) return;

    // Leaf node
    if (root->left == NULL && root->right == NULL) {
        code[depth] = '\0';
        printf("%s ", code);
        return;
    }

    code[depth] = '0';
    preOrder(root->left, code, depth + 1);

    code[depth] = '1';
    preOrder(root->right, code, depth + 1);
}

// Build Huffman Tree and print codes
void huffmanCodes(char s[], int freq[], int n) {
    struct Node* heap[100];
    int size = 0;

    // Initialize heap
    for (int i = 0; i < n; i++) {
        heap[i] = newNode(freq[i]);
    }
    size = n;

    // Build min heap
    for (int i = (size-1)/2; i >= 0; i--)
        minHeapify(heap, size, i);

    // Construct Huffman tree
    while (size >= 2) {
        struct Node* l = extractMin(heap, &size);
        struct Node* r = extractMin(heap, &size);

        struct Node* parent = newNode(l->freq + r->freq);
        parent->left = l;
        parent->right = r;

        insertHeap(heap, &size, parent);
    }

    // Root of tree
    struct Node* root = heap[0];

    // Print codes
    char code[100];
    preOrder(root, code, 0);
}

int main() {
    char s[] = "acdeomstu";
    int freq[] = {20, 11, 2, 10, 15, 8, 10,22,2};
    int n = strlen(s);

    huffmanCodes(s, freq, n);

    return 0;
}
