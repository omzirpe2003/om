#include <iostream>
#include <string>
using namespace std;

class BST
{
    string word;
    string meaning;
    BST *left, *right;

public:
    BST()
    {
        word = "";
        meaning = "";
        left = right = NULL;
    }
    BST(string w, string m)
    {
        word = w;
        meaning = m;
        left = right = NULL;
    }
    BST *insert(BST *root, string w, string m)
    {
        if (root == NULL)
        {
            return new BST(w, m);
        }
        if (w > root->word)
        {
            root->right = insert(root->right, w, m);
        }
        else if (w < root->word)
        {
            root->left = insert(root->left, w, m);
        }
        return root;
    }
    void ascorder(BST *root)
    {
        if (root != NULL)
        {
            ascorder(root->left);
            cout << root->word << " - " << root->meaning << endl;
            ascorder(root->right);
        }
    }
    void descorder(BST *root)
    {
        if (root != NULL)
        {
            descorder(root->right);
            cout << root->word << " - " << root->meaning << endl;
            descorder(root->left);
        }
    }
    int search(BST *root, string key)
    {
        int c = 0;
        while (root != NULL)
        {
            c++;
            if (root->word == key)
            {
                cout << "\n Word found with comparisons: " << c;
                return 1;
            }
            if (key > root->word)
                root = root->right;
            else if (key < root->word)
                root = root->left;
        }
        return -1;
    }
    void update(BST *root, string key)
    {
        while (root != NULL)
        {
            if (root->word == key)
            {
                cout << "Enter new meaning of the word " << root->word << endl;
                cin >> root->meaning;
                return;
            }
            else if (key > root->word)
                root = root->right;
            else
                root = root->left;
        }
        cout << "\nWord not found";
    }
    BST *remove(BST *root, string w)
    {
        if (root == NULL)
            return root;
        if (w < root->word)
        {
            root->left = remove(root->left, w);
            return root;
        }
        else if (w > root->word)
        {
            root->right = remove(root->right, w);
            return root;
        }

        // If the node to be deleted has one or no child
        if (root->left == NULL)
        {
            BST *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            BST *temp = root->left;
            delete root;
            return temp;
        }

        // If the node to be deleted has two children
        BST *temp = minValNode(root->right);
        root->word = temp->word;
        root->meaning = temp->meaning;
        root->right = remove(root->right, temp->word);
        return root;
    }

    BST *minValNode(BST *node)
    {
        BST *current = node;
        while (current && current->left != NULL)
            current = current->left;
        return current;
    }
};

int main()
{
    BST b, *root = NULL;
    int ch, n, count = 0;
    string word, meaning, key;
    while (true)
    {
        cout << "\n\n 1) Create BST \n 2) Comparisons \n 3) Delete \n 4) Update \n 5) Ascending Order \n 6) Descending Order \n 7) Exit" << endl;
        cout << "\n Enter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "ENTER number of elements in the BST : ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                cout << "\n Enter word: ";
                cin >> word;
                cout << "\n Enter meaning: ";
                cin >> meaning;
                root = b.insert(root, word, meaning);
            }
            break;
        case 2:
            cout << "\nEnter word to search: ";
            cin >> word;
            if (b.search(root, word) == 1)
                cout << "\nKeyword Found";
            else
            {
                cout << "\nKeyword Not Found";
            }
            break;
        case 3:
            cout << "\nEnter word to delete: ";
            cin >> key;
            root = b.remove(root, key);
            cout << "\nWord deleted successfully";
            break;
        case 4:
            cout << "\nEnter word to update: ";
            cin >> key;
            b.update(root, key);
            break;
        case 5:
            cout << "\nAscending Order: " << endl;
            b.ascorder(root);
            break;
        case 6:
            cout << "\nDescending Order: " << endl;
            b.descorder(root);
            break;
        case 7:
            exit(0);
        }
    }
    return 0;
}

