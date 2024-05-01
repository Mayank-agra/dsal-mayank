// NAME & ROLLNO.
//  DSAL EXPERIMENT
//  Problem Statement : A Dictionary stores keywords and its meanings. Provide facility for adding new keywords, deleting keywords, updating values of any entry. Provide facility to display whole data sorted in ascending/ Descending order. Also find how many maximum comparisons may require for finding any keyword. Use Binary Search Tree for implementation.
//  Code:
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class node {
public:
    node *left;
    char word[50], mean[50];
    node *right;
};

class BT {
public:
    node *root;

    BT() {
        root = NULL;
    }

    void create();
    node *insert(node *, node *);
    void inorder(node *);
    void preorder(node *);
    void postorder(node *);
    node *findSmallest(node *);
    node *findLargest(node *);
    void search(node *, char[]);
    void modify(node *, char[]);
    node *dlt(node *, char[]);
    node *findMin(node *);
};

void BT::create() {
    int op;
    node *temp;
    do {
        temp = new node;
        cout << "Enter a word: ";
        cin >> temp->word;
        cout << "Enter its meaning: ";
        cin >> temp->mean;
        temp->left = temp->right = NULL;
        if (root == NULL) {
            root = temp;
        } else {
            root = insert(root, temp);
        }
        cout << "Want to insert again? (1 for yes, 0 for no): ";
        cin >> op;
    } while (op == 1);
}

node *BT::insert(node *root, node *temp) {
    if (root == NULL) {
        return temp;
    }

    if (strcmp(temp->word, root->word) < 0) {
        root->left = insert(root->left, temp);
    } else {
        root->right = insert(root->right, temp);
    }
    
    return root;
}

void BT::inorder(node *temp) {
    if (temp != NULL) {
        inorder(temp->left);
        cout << temp->word << " " << temp->mean << endl;
        inorder(temp->right);
    }
}

// Implement other member functions...

int main() {
    BT b;
    int op;
    char src[100];
    while (1) {
        cout << "\n ";
        cout << "\n 1. Insert into Binary Search Tree ";
        cout << "\n 2. Display Inorder, Preorder, and Postorder ";
        cout << "\n 3. Search for a Word ";
        cout << "\n 4. Modify the Meaning of a Word ";
        cout << "\n 5. Delete a Word from the Dictionary ";
        cout << "\n 6. Find Largest and Smallest Nodes ";
        cout << "\n 7. Exit";
        cout << "\n Enter your choice: ";
        cin >> op;
        switch (op) {
            case 1:
                b.create();
                break;

            case 2:
                cout << "\n Inorder: ";
                b.inorder(b.root);
                // Additional traversal options can be added here
                break;

            // Implement other cases...

            case 7:
                exit(0);
                break;

            default:
                cout << "\n Invalid Option ";
                break;
        }
        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();
    }
    return 0;
}
