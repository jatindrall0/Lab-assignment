#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Inventory Item ADT
struct InventoryItem
{
    int itemID;
    string itemName;
    int quantity;
    float price;
};

// Inventory Management System
class InventorySystem
{
private:
    vector<InventoryItem> itemArray;

public:
    // Insert a new item
    void insertItem()
    {
        InventoryItem item;
        cout << "Enter Item ID: ";
        cin >> item.itemID;
        cin.ignore();
        cout << "Enter Item Name: ";
        getline(cin, item.itemName);
        cout << "Enter Quantity: ";
        cin >> item.quantity;
        cout << "Enter Price: ";
        cin >> item.price;
        itemArray.push_back(item); // O(1) amortized
        cout << "Item added successfully.\n";
    }

    // Delete item by ID
    void deleteItem()
    {
        int id;
        cout << "Enter Item ID to delete: ";
        cin >> id;
        for (auto it = itemArray.begin(); it != itemArray.end(); ++it)
        {
            if (it->itemID == id)
            {
                itemArray.erase(it); // O(n)
                cout << "Item deleted.\n";
                return;
            }
        }
        cout << "Item not found.\n";
    }

    // Search item by ID or Name
    void searchItem()
    {
        string keyword;
        cout << "Enter Item ID or Name to search: ";
        cin.ignore();
        getline(cin, keyword);
        for (InventoryItem item : itemArray)
        {
            if (to_string(item.itemID) == keyword || item.itemName == keyword)
            {
                cout << "Found: " << item.itemName << " | Qty: " << item.quantity << " | Price: " << item.price << "\n";
                return;
            }
        }
        cout << "Item not found.\n";
    }

    // Display price and quantity table
    void displayPriceQuantityTable()
    {
        int choice;
        cout << "Choose format:\n1. Row-Major\n2. Column-Major\nEnter choice: ";
        cin >> choice;
        if (choice == 1)
        {
            cout << "\nRow-Major Format:\n";
            for (InventoryItem item : itemArray)
                cout << item.itemName << ": Price = " << item.price << ", Qty = " << item.quantity << "\n";
        }
        else
        {
            cout << "\nColumn-Major Format:\n";
            cout << "Item\tPrice\tQty\n";
            for (InventoryItem item : itemArray)
                cout << item.itemName << "\t" << item.price << "\t" << item.quantity << "\n";
        }
    }

    // Show sparse items (rarely restocked)
    void showSparseItems()
    {
        cout << "\nSparse Items (Qty <= 2):\n";
        for (InventoryItem item : itemArray)
        {
            if (item.quantity <= 2)
                cout << item.itemName << " | Qty: " << item.quantity << "\n";
        }
    }
};

int main()
{
    InventorySystem store;
    int choice;

    do
    {
        cout << "\n--- Grocery Store Inventory Menu ---\n";
        cout << "1. Add Item\n";
        cout << "2. Delete Item\n";
        cout << "3. Search Item\n";
        cout << "4. Display Price-Quantity Table\n";
        cout << "5. Show Sparse Items\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            store.insertItem();
            break;
        case 2:
            store.deleteItem();
            break;
        case 3:
            store.searchItem();
            break;
        case 4:
            store.displayPriceQuantityTable();
            break;
        case 5:
            store.showSparseItems();
            break;
        case 6:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}