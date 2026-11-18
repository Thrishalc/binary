
#include <iostream>
#include "BST.hpp"

using namespace std;

int main() {

    BST<int> tree;

    int choice, value;

    do {

        cout << "\n===== BINARY SEARCH TREE =====\n";

        cout << "1. Insert Node\n";
        cout << "2. Search Node\n";
        cout << "3. Delete Node\n";
        cout << "4. In-Order Traversal\n";
        cout << "5. Pre-Order Traversal\n";
        cout << "6. Post-Order Traversal\n";
        cout << "7. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "Enter value to insert: ";
                cin >> value;

                tree.Insert(value);

                cout << "Node inserted successfully!\n";
                break;

            case 2:
                cout << "Enter value to search: ";
                cin >> value;

                if (tree.Search(value)) {
                    cout << "Element found in BST!\n";
                }
                else {
                    cout << "Element not found!\n";
                }
                break;

            case 3:
                cout << "Enter value to delete: ";
                cin >> value;

                if (tree.Search(value)) {
                    tree.Delete(value);
                    cout << "Node deleted successfully!\n";
                }
                else {
                    cout << "Element not found!\n";
                }
                break;

            case 4:
                cout << "In-Order Traversal: ";
                tree.InOrder();
                break;

            case 5:
                cout << "Pre-Order Traversal: ";
                tree.PreOrder();
                break;

            case 6:
                cout << "Post-Order Traversal: ";
                tree.PostOrder();
                break;

            case 7:
                cout << "Exiting BST Program...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 7);

    return 0;
}
