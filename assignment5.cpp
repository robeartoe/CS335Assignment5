#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

struct treeNode
{
    string name;
    treeNode *left,*right;
};
struct queueNode
{
    string name;
    queueNode *next;
};


// 1: Insert data in array months to a BST:
struct treeNode *newNode(string month){
    struct treeNode *temp =  (struct treeNode *)malloc(sizeof(struct treeNode));
    temp->name = month;
    temp->left = temp->right = NULL;
    return temp;
}
struct treeNode *insert(struct treeNode* t,string month){
    if (t == NULL) {
        return newNode(month);
    }
    if (month < t->name)
        t->left  = insert(t->left, month);
    else if (month > t->name)
        t->right = insert(t->right, month);
    return t;
}

// 2: Display Months in Alphabetical Order:
void displayAlphabetical(struct treeNode* t){
    if (t != NULL) {
        displayAlphabetical(t->left);
        std::cout << t->name << ' ';
        displayAlphabetical(t->right);
    }
}

// 3: Display tree sideway:
void displaySideway(struct treeNode* t,int sp){
    if (t != NULL) {
        displaySideway(t->right,sp +=5);
        std::cout << setw(sp) << t->name<<endl;
        displaySideway(t->left,sp);
    }
}

// 4: Find and Display the height of the tree:
int displayHeight(struct treeNode* t){
    if (t == NULL) return -1;
    else return 1 + max(displayHeight(t->left),displayHeight(t->right));
}

// 6: Count and Display the number of nodes in the left and right subtrees:
// 7: Display the descendants of Mar:

// 8: Display the ancestors of Sep:
// 9: Make the mirror image of this tree and display it.
struct treeNode *makeMirror(struct treeNode* m,struct treeNode* t){
    if (m == NULL) {
        return newNode(t->name);
    }
        m->left  = makeMirror(m->left, t->right);
        m->right = makeMirror(m->right, t->left);
    return t;
}


// 10: Visit the original tree and the mirror tree level by level (data at each level must be reverse of each other) display the result of each visitations.
void displayTreesAllLevels(struct treeNode* t, struct treeNode* m)
{
    int h = displayHeight(t);
    for (int i = 1; i<=h; i ++)
    displayTreesAtLevel(t, m, i);

}
void displayTreesAtLevel(struct treeNode* t, struct treeNode* m, int level)
{
     if (t == NULL) return;
     if (level == 1)
     {
         std::cout<< t->name << " " << m->name;
     }
     else if(level>1)
     {
        displayTreesAtLevel(t->left, m->right, level-1);
        displayTreesAtLevel(t->right, m->left, level-1);
    }
}


int main() {
    struct treeNode *t = NULL;
    struct treeNode *m = NULL;
    string months[12]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sept","Oct","Nov","Dec"};

    // 1:
    std::cout << "Inserting the Months ... "<<'\n';
    std::cout << '\n';
    for (int i = 0; i < 12; i++) {
        t = insert(t,months[i]);
    }

    // 2:
    std::cout << "Months in Alphabetical Order: "<<'\n';
    displayAlphabetical(t);

    // 3:
    std::cout << '\n' << "Displaying Tree Sideways: "<<'\n';
    displaySideway(t,0);
    std::cout << '\n';

    // 4:
    int disHeight = displayHeight(t);
    std::cout << "The Height of the Tree is: " << disHeight <<'\n';

    // 5:
    std::pair<int,int> subtreeHeight;
    // Simply treat the subtrees on the left and right as their own trees.
    // The child to the orginal root become the parents in the subtrees.
    subtreeHeight.first = displayHeight(t->left);
    subtreeHeight.second = displayHeight(t->right);
    std::cout << "The Height of SubTree Left is: "<< subtreeHeight.first << '\n';
    std::cout << "The Height of SubTree Right is: "<< subtreeHeight.second << '\n';

    //TODO: 6-10:


    //9:
    m = makeMirror(m,t);
    return 0;
}
