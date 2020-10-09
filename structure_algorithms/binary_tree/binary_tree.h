#pragma once
#include "structure_algorithms/my_exceptions.h"
#include "structure_algorithms/queue/queue.h"

template <typename T>
struct binaryTreeNode {
  T element;
  binaryTreeNode<T> *leftChild, rightChild;
  binaryTreeNode() {
    leftChild = nullptr;
    rightChild = nullptr;
  }
  binaryTreeNode(const T& theElement) {
    element = theElement;
    leftChild = nullptr;
    rightChild = nullptr;
  }
  binaryTreeNode(const T& theElement, binaryTreeNode<T>* theLeftChild,
                 binaryTreeNode<T>* theRightChild) {
    element = theElement;
    leftChild = theLeftChild;
    rightChild = theRightChild;
  }
};

// abstract class
template <typename T>
class BinaryTree {
 public:
  virtual ~BinaryTree() = default;
  virtual bool empty() const = 0;
  virtual int size() const = 0;
  virtual void preOrder(void (*)(T*)) = 0;
  virtual void inOrder(void (*)(T*)) = 0;
  virtual void postOrder(void (*)(T*)) = 0;
  virtual void levelOrder(void (*)(T*)) = 0;
};

template <typename E>
class LinkedBinaryTree : public BinaryTree<binaryTreeNode<E>> {
 public:
  LinkedBinaryTree() {
    root = nullptr;
    treeSize = 0;
  }
  ~LinkedBinaryTree() { erase(); }

  bool empty() const { return treeSize == 0; }
  int size() const { return treeSize; }
  E* rootElement() const;
  void makeTree(const E& element, LinkedBinaryTree<E>&, LinkedBinaryTree<E>&);
  LinkedBinaryTree<E>& removeLeftSubTree();
  LinkedBinaryTree<E>& removeRightSubTree();
  void preOrder(void (*theVisit)(binaryTreeNode<E>*)) {
    visit = theVisit;
    preOrder(root);
  }
  void inOrder(void (*theVisit)(binaryTreeNode<E>*)) {
    visit = theVisit;
    inOrder(root);
  }
  void postOrder(void (*theVisit)(binaryTreeNode<E>*)) {
    visit = theVisit;
    postOrder(root);
  }
  void levelOrder(void (*)(binaryTreeNode<E>*));
  void preOrderOutput() {
    preOrder(output);
    std::cout << std::endl;
  }
  void inOrderOutput() {
    inOrder(output);
    std::cout << std::endl;
  }
  void postOrderOutput() {
    postOrder(output);
    std::cout << std::endl;
  }
  void levelOrderOutput() {
    levelOrder(output);
    std::cout << std::endl;
  }
  void erase() {
    postOrder(dispose);
    root = nullptr;
    treeSize = 0;
  }
  int height() const { return height(root); }

 private:
  binaryTreeNode<E>* root;
  int treeSize;
  static int count;
  static void (*visit)(binaryTreeNode<E>*);
  static void preOrder(binaryTreeNode<E>* t);
  static void inOrder(binaryTreeNode<E>* t);
  static void postOrder(binaryTreeNode<E>* t);
  static void countNodes(binaryTreeNode<E>* t) {
    visit = addToCount;
    count = 0;
    preOrder(t);
  }

  static void dispose(binaryTreeNode<E>* t) { delete t; }
  static void output(binaryTreeNode<E>* t) { std::cout << t->element << ' '; }
  static void addToCount(binaryTreeNode<E>* t) { count++; }

  static int height(binaryTreeNode<E>* t);
};

template <typename E>
void LinkedBinaryTree<E>::preOrder(binaryTreeNode<E>* t) {
  if (t) {
    LinkedBinaryTree<E>::visit(t);
    preOrder(t->leftChild);
    preOrder(t->rightChild);
  }
}
template <typename E>
void LinkedBinaryTree<E>::inOrder(binaryTreeNode<E>* t) {
  if (t) {
    LinkedBinaryTree<E>::visit(t);
    inOrder(t->leftChild);
    inOrder(t->rightChild);
  }
}
template <typename E>
void LinkedBinaryTree<E>::postOrder(binaryTreeNode<E>* t) {
  if (t) {
    LinkedBinaryTree<E>::visit(t);
    postOrder(t->leftChild);
    postOrder(t->rightChild);
  }
}

template <typename E>
void LinkedBinaryTree<E>::levelOrder(void (*theVisit)(binaryTreeNode<E>*)) {
  ArrayQueue<binaryTreeNode<E>*> q;
  binaryTreeNode<E>* t = root;
  while (t) {
    theVisit(t);
    // put its children in queue
    if (t->leftChild) {
      q.push(t->leftChild);
    }
    if (t->rightChild) {
      q.push(t->rightChild);
    }
    // get next node to visit
    try {
      t = q.front();
    } catch (QueueEmpty) {
      return;
    }
    q.pop();
  }
}

template <typename E>
int LinkedBinaryTree<E>::height(binaryTreeNode<E>* t) {
  // return height of tree rooted by *t
  if (t == nullptr) {
    return 0;
  }
  int hl = height(t->leftChild);
  int hr = height(t->rightChild);
  if (hl > hr) {
    return ++hl;
  } else {
    return ++hr;
  }
}

template <typename E>
E* LinkedBinaryTree<E>::rootElement() const {
  if (root == nullptr) {
    return nullptr;
  }
  return &root->element;
}

template <typename E>
void LinkedBinaryTree<E>::makeTree(const E& element, LinkedBinaryTree<E>& left,
                                   LinkedBinaryTree<E>& right) {
  // Combine left and right, and element to make new tree
  // left, right and this must be different trees.
  // create combined tree
  root = new binaryTreeNode<E>(element, left.root, right.root);
  treeSize = 1 + left.treeSize + right.treeSize;

  // deny access from left and right trees
  left.root = right.root = nullptr;
  left.treeSize = right.treeSize = 0;
}

template <typename E>
LinkedBinaryTree<E>& LinkedBinaryTree<E>::removeLeftSubTree() {
  // remove and return left subtree
  // check if empty
  if (root->leftChild == nullptr) {
    throw EmptyTree();
  }
  LinkedBinaryTree<E> leftSubTree;
  leftSubTree.root = root->leftChild;
  leftSubTree.treeSize = countNodes(leftSubTree->root);
  root->leftChild = nullptr;
  treeSize -= leftSubTree.treeSize;
  return leftSubTree;
}

template <typename E>
LinkedBinaryTree<E>& LinkedBinaryTree<E>::removeRightSubTree() {
  // remove and return right subtree
  // check if empty
  if (root->rightChild == nullptr) {
    throw EmptyTree();
  }
  LinkedBinaryTree<E> rightSubTree;
  rightSubTree.root = root->leftChild;
  rightSubTree.treeSize = countNodes(rightSubTree->root);
  root->rightChild = nullptr;
  treeSize -= rightSubTree.treeSize;
  return rightSubTree;
}
