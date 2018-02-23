#include <iostream>
#include <string>
using namespace std;

struct treeNode
{
  string name;
  treeNode; *left,*right;
}
struct queueNode
{
  string name;
  queueNode *next;
}

// 1:
void insert(struct treeNode* t,string month){}

// 2:
void displayAlphabetical(struct treeNode* t){}

//3:
void displaySideway(struct treeNode* t){}

// 4:
void displayHeight(struct treeNode* t){}


int main() {
  struct treeNode t = NULL;
  string months[12]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sept","Oct","Nov","Dec"};

  return 0;
}
