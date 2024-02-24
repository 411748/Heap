#include <iostream>
#include <cstring>

using namespace std;

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
