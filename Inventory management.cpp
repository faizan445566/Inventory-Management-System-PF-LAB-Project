#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// Structure to store product details
struct Product {
    int id;
    string name;
    int quantity;
    double price;
};

// Global inventory
vector<Product> inventory;

// Function prototypes
void addProduct();
void showInventory();
void saveToFile();
void loadFromFile();

// Helper functions for parsing
int parseInt(const string& str);
double parseDouble(const string& str);

int main() {
    loadFromFile(); // Load existing inventory

    int choice;
    do {
        cout << "\n===== Simple Inventory Management =====\n";
        cout << "1. Add New Product\n";
        cout << "2. Show All Products\n";
        cout << "3. Save and Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addProduct(); break;
            case 2: showInventory(); break;
            case 3: saveToFile(); break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 3);

    return 0;
}

void addProduct() {
    Product p;
    cout << "Enter product ID: ";
    cin >> p.id;
    cout << "Enter product name: ";
    cin.ignore();
    getline(cin, p.name);
    cout << "Enter product quantity: ";
    cin >> p.quantity;
    cout << "Enter product price: ";
    cin >> p.price;

    inventory.push_back(p);
    cout << "Product added successfully.\n";
}

