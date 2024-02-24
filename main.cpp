#include <iostream>
#include <cstring>

// https://www.geeksforgeeks.org/cpp-stl-heap/ - used for an idea of how to make and use heaps

using namespace std;
int getParent_I(int);
int getLeft_CI(int);
int getRight_CI(int);
int* add_Heap(int, int*);
int* remove_Heap(int*);
int* check_adjust(int*, int);
int* clear(int*);
int getLast(int*);

void print(int*, int);

int main() {
  int running = 0;
  char choice[80];
  char add_choice[80];
  while(running == 0) {
    cout << "Do you want to A: add, D: delete, DA: delete all, P: print, Q: quit" << endl;
    cin >> choice;
    if(strcmp(choice, "A") == 0) {
      cout << "Do you want to Y: add yourself, or F: add from file" << endl;
      cin >> add_choice;
      if(strcmp(add_choice, "Y") == 0) {
	//add yourself
      }
      else if(strcmp(add_choice, "F") == 0) {
	//add from file
      }
    }
    else if(strcmp(choice, "D") == 0) {
      //delete num
    }
    else if(strcmp(choice, "DA") == 0) {
      //delete all
    }
    else if(strcmp(choice, "P") == 0) {
      //print
    }
    else if(strcmp(choice, "Q") == 0) {
      running = 1;
    }
  }

}

void print(int* tree, int index, int depth = 0) {
  if (tree[index] == -1 || index > 100) {
    return;
  }
  if (getRight_CI(index) <= 100) {
    print(tree, getRight_CI(index), depth + 1);
  }
  for (int i = 0; i < depth; i++) {
    cout << "\t";
  }
  cout << tree[index] << endl;
  if (getLeft_CI(index) <= 100) {
    print(tree, getLeft_CI(index), depth + 1);
  }
}

int* remove_Heap(int* tree) {
  int left_child = tree[getLeft_CI(1)];
  int right_child = tree[getRight_CI(1)];
  int greatest_child = (left_child > right_child) ? left_child : right_child;
  tree[1] = greatest_child;
  if (greatest_child == -1) {
    return tree;
  }
  int index = getLeft_CI(1);
  if (left_child < right_child) {
    index = getRight_CI(1);
  }
  check_adjust(tree, index);
  return tree;
}


int* check_adjust(int* tree, int index) {
  int parent = getParent_I(index);
  if (index == 1 || tree[parent] > tree[index]) {
    return tree;
  }
  else {
    int temp = tree[parent];
    tree[parent] = tree[index];
    tree[index] = temp;
    check_adjust(tree, parent);
  }
}

int getLast(int* tree) {
  int i = 1;
  while (true) {
    if (tree[i] == -1) {
      return i;
     }
    i++;
  }
  cout << "ERROR: Tree is full" << endl;
  return -1;
}

int* add_Heap(int num, int* tree) {
  int index = getLast(tree);
  if (index == 100) {
    return tree;
  }
  tree[index] = num;
  check_adjust(tree, index);
  return tree;
}

int getLeft_CI(int i) {
  return 2 * i;
}

int getRight_CI(int i) {
  return 2 * i + 1;
}

int getParent_I(int i) {
  if (i % 2 == 0) {
    return i / 2;
  }
  else {
    return (i - 1) / 2;
  }
}

int* clear(int* tree) {
  for (int i = 0; i <= 201; i++) {
    tree[i] = -1;
  }
  tree[0] = -2;
  return tree;
}
