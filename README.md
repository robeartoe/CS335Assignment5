Given String:
``` c++
string months[12]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sept","Oct","Nov","Dec"};
```
and the following declarations:
``` c++
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
```

Write and run a program to do the following:

1. Insert data in array months to a BST:
2. Display Months in Alphabetical Order:
3. Display tree sideway:
4. Find and Display the height of the tree:
5. Find and display the height of the left and right subtrees.
6. Count and Display the number of nodes in the left and right subtrees:
7. Display the descendants of Mar:
8. Display the ancestors of Sep:
9. Make the mirror image of this tree and display it.
10. Visit the original tree and the mirror tree level by level (data at each level must be reverse of each other) display the result of each visitations.
