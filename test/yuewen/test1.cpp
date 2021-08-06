#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int push(int value) {
    int size = sizeof(*array) / (sizeof(int));
    if (len < size) {
      array[len++] = value;
    } else {
      size *= 2;
      int * arraycopy = new int[size];
      for (int i = 0; i < len; i++) {
        arraycopy[i] = array[i];
      }
      delete array;
      array = arraycopy;
      arraycopy = nullptr;
      len++;
      array[len] = value;
    }
  }
  int pop() {
    int size = sizeof(*array) / (sizeof(int));
    if (len - 1 < size / 4) {
      int * arraycopy = new int[size / 2];
      for (int i = 0; i < len - 1; i++) {
        arraycopy[i] = array[i];
      }
      delete array;
      array = arraycopy;
      arraycopy = nullptr;
      len--;
    }
  }
  int get() {
    return array[len];
  }
 private:
  int *array = new int[1];
  int len = 0;
};
int main() {

}