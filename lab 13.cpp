#include <iostream>
using namespace std;

/* =========================
   BST Node Structure
   ========================= */
struct Node {
    int data;
    Node* left;
    Node* right;
};

/* =========================
   Create New Node
   ========================= */
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/* =========================
   Insert Node into BST
   ========================= */
Node* insert(Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

/* =========================
   Find Minimum Value Node
   ========================= */
Node* findMin(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

/* =========================
   Delete Node from BST
   ========================= */
Node* deleteNode(Node* root, int value) {
    if (root == NULL)
        return root;

    if (value < root->data)
        root->left = deleteNode(root->left, value);
    else if (value > root->data)
        root->right = deleteNode(root->right, value);
    else {
        // Case 1: No child
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        // Case 2: One child
        else if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Case 3: Two children
        else {
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

/* =========================
   Inorder Traversal
   ========================= */
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

/* =========================
   Preorder Traversal
   ========================= */
void preorder(Node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

/* =========================
   Postorder Traversal
   ========================= */
void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

/* =========================
   Main Function (Menu)
   ========================= */
int main() {
    Node* root = NULL;
    int choice, value;

    do {
        cout << "\n===== Binary Search Tree Menu =====\n";
        cout << "1. Insert Node\n";
        cout << "2. Delete Node\n";
        cout << "3. Inorder Traversal\n";
        cout << "4. Preorder Traversal\n";
        cout << "5. Postorder Traversal\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            root = insert(root, value);
            cout << "Value inserted successfully.\n";
            break;

        case 2:
            cout << "Enter value to delete: ";
            cin >> value;
            root = deleteNode(root, value);
            cout << "Value deleted successfully (if existed).\n";
            break;

        case 3:
            cout << "Inorder Traversal: ";
            inorder(root);
            cout << endl;
            break;

        case 4:
            cout << "Preorder Traversal: ";
            preorder(root);
            cout << endl;
            break;

        case 5:
            cout << "Postorder Traversal: ";
            postorder(root);
            cout << endl;
            break;

        case 0:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}