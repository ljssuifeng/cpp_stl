#pragma once
#include <iostream>
#include <string>

// illegal parameter value
class IllegalParameterValue {
 public:
  IllegalParameterValue(std::string theMessage = "Illegal parameter value.") {
    message = theMessage;
  }
  void outputMessage() { std::cout << message << std::endl; }

 private:
  std::string message;
};

// illegal input data
class IllegalInputData {
 public:
  IllegalInputData(std::string theMessage = "Illegal input data.") {
    message = theMessage;
  }
  void outputMessage() { std::cout << message << std::endl; }

 private:
  std::string message;
};

// Matrix index out of bounds
class MatrixIndexOutOfBounds {
 public:
  MatrixIndexOutOfBounds(
      std::string theMessage = "Matrix index out of bounds.") {
    message = theMessage;
  }
  void outputMessage() { std::cout << message << std::endl; }

 private:
  std::string message;
};

// Matrix size dismatch
class MatrixSizeMismatch {
 public:
  MatrixSizeMismatch(std::string theMessage = "Matrix size mismatch.") {
    message = theMessage;
  }
  void outputMessage() { std::cout << message << std::endl; }

 private:
  std::string message;
};

// stack is empty
class StackEmpty {
 public:
  StackEmpty(std::string theMessage = "stack empty.") { message = theMessage; }
  void outputMessage() { std::cout << message << std::endl; }

 private:
  std::string message;
};

// queue is empty
class QueueEmpty {
 public:
  QueueEmpty(std::string theMessage = "queue empty.") { message = theMessage; }
  void outputMessage() { std::cout << message << std::endl; }

 private:
  std::string message;
};

// tree is empty
class EmptyTree {
 public:
  EmptyTree(std::string theMessage = "empty tree.") { message = theMessage; }
  void outputMessage() { std::cout << message << std::endl; }

 private:
  std::string message;
};

// hash table full
class HashTableFull {
 public:
  HashTableFull(std::string theMessage = "hash table full.") {
    message = theMessage;
  }
  void outputMessage() { std::cout << message << std::endl; }

 private:
  std::string message;
};

// edge weight undefined
class UndefinedEdgeWeight {
 public:
  UndefinedEdgeWeight(std::string theMessage = "No edge weight defined.") {
    message = theMessage;
  }
  void outputMessage() { std::cout << message << std::endl; }

 private:
  std::string message;
};

// method undefined
class UndefinedMethod {
 public:
  UndefinedMethod(std::string theMessage = "this method is undefined.") {
    message = theMessage;
  }
  void outputMessage() { std::cout << message << std::endl; }

 private:
  std::string message;
};
