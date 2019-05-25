#include <bits/stdc++.h>

using namespace std;

class Node {
  Node *l, *r;
  int val;

public:
  Node *createLeft() {
    return l = new Node();
  }

  Node *createRight() {
    return r = new Node();
  }

  Node *getLeft() {
    if (l == NULL) createLeft();
    printf("L");
    return l;
  }

  Node *getRight() {
    if (r == NULL) createRight();
    printf("R");
    return r;
  }

  void setValue(int n) {
    printf("*\n");
    val = n;
  }

  int getValue() {
    return val;
  }
};

class Tree {
  Node *root;
public:
  void insert(int n) {
    if (root == NULL) {
      root = new Node();
      root->setValue(n);
    } else {
      Node *node = root;
      int val;
      while (true) {
        val = node->getValue();
        if (val == 0) {
          node->setValue(n);
          break;
        } else if (val > n) {
          node = node->getLeft();
        } else {
          node = node->getRight();
        }
      }
    }
  }
};

int main() {
  int N, i, tmp;
  Tree *tree = new Tree();
  scanf("%d", &N);
  for (i = 0; i < N; ++i) {
    scanf("%d", &tmp);
    tree->insert(tmp);
  }
  return 0;
}
