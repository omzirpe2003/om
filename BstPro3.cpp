#include<iostream>
using namespace std;

class BST {
    int data;
    BST *left, *right;

public:
    BST() {
        data = 0;
        left = right = NULL;
    }

    BST(int value) {
        data = value;
        left = right = NULL;
    }

    BST* insert(BST*, int);
    void inorder(BST*);
    BST* search(BST*, int);
    void minvalue(BST*);
    void mirror(BST*);
    int height(BST*);
};

BST* BST::insert(BST* root, int value) {
    if (!root) {
        // Insert node, if root is NULL.
        return new BST(value);
    }
    if (value > root->data) {
        root->right = insert(root->right, value);
    } else if (value < root->data) {
        root->left = insert(root->left, value);
    }
    return root;
}

void BST::inorder(BST* root) {
    if (!root) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Updated search function to work even after mirroring
BST* BST::search(BST* root, int key) {
    if (!root) return NULL;

    if (root->data == key)
        return root;

    BST* found = search(root->left, key);
    if (found) return found;

    return search(root->right, key);
}

void BST::minvalue(BST* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    cout << "Minimum Value = " << root->data << endl;
}

void BST::mirror(BST* root) {
    if (root == NULL)
        return;

    // Recursively mirror left and right subtrees
    mirror(root->left);
    mirror(root->right);

    // Swap left and right pointers
    BST* temp = root->left;
    root->left = root->right;
    root->right = temp;
}

int BST::height(BST* root) {
    if (root == NULL)
        return 0;

    return (max(height(root->left), height(root->right)) + 1);
}

int main() {
    BST b, *root = NULL;
    int ch, n, value, key;

    while (ch != 8) {
        cout << "\n\n 1) Create BST \n 2) Insert new node \n 3) Number of nodes in longest path \n 4) Minimum Value \n 5) Mirror \n 6) Search \n 7) Display (Inorder) \n 8) Exit" << endl;
        cout << "\n Enter your choice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            cout << "ENTER number of elements in the BST: ";
            cin >> n;
            for (int i = 0; i < n; i++) {
                cout << "NUMBER = ";
                cin >> value;
                root = b.insert(root, value);
            }

            cout << "\nINORDER Traversal: " << endl;
            b.inorder(root);
            break;

        case 2:
            cout << "NUMBER = ";
            cin >> value;
            root = b.insert(root, value);

            cout << "\nINORDER Traversal: " << endl;
            b.inorder(root);
            break;

        case 3:
            cout << "\n Number of nodes in longest path: " << b.height(root);
            break;

        case 4:
            b.minvalue(root);
            break;

        case 5:
            cout << "\n Inorder traversal: ";
            b.inorder(root);
            b.mirror(root);
            cout << "\n The mirror of tree is: ";
            b.inorder(root);
            break;

        case 6:
            cout << "\nEnter key to search: ";
            cin >> key;
            if (b.search(root, key) == NULL)
                cout << key << " not found" << endl;
            else
                cout << key << " found" << endl;
            break;

        case 7:
            cout << "\nINORDER Traversal: " << endl;
            b.inorder(root);
            break;

        case 8:
            exit(0);
        }
    }
    return 0;
}
