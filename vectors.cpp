#include <iostream>
#include <vector>
using namespace std;

struct Product
{
    int id;
    string name;
};

vector<Product> inventory;

void add_product(int id, const string& name) 
{
    Product newProduct = { id, name };
    inventory.push_back(newProduct);
}

void removeProduct(int id) 
{
    for (auto it = inventory.begin(); it != inventory.end(); ++it)
    {
        if (it->id == id)
        {
            inventory.erase(it);
            cout << "Product with ID " << id << " removed from inventory." << endl;
            return;
        }
    }
    cout << "Product with ID " << id << " not found in inventory." << endl;
}

int main() 
{
    
    add_product(1, "camera"); //instant insertion 
    add_product(2, "headphones");
    add_product(3, "watch");
    add_product(4, "mouse");
    removeProduct(1); // instant removal
    removeProduct(4);
    
    cout << "Current Inventory:" << endl;

    cout << "Names: " << endl;
    for (const auto& product : inventory) 
    {
        cout << product.name << endl;
    }
    return 0;
}
