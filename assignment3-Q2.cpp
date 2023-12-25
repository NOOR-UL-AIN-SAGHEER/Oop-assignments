#include <iostream>
#include <string>

using namespace std;

// Product Class
class Product 
{
public:
    int productId;
    string productName;
    double price;
    Product(int id, const string& name, double p) 
    {
        productId = id; 
        productName = name;
        price = p;
    }
    void displayProductDetails() const 
    {
        cout << "Product ID: " << productId << endl;
        cout << "Name: " << productName << endl;
        cout<<"Price : " << price << endl;
    }
};

// ShoppingCart Class
class ShoppingCart 
{
private:
    static const int maxProducts = 10;  // Maximum products in the cart
    Product* products[maxProducts];
    int size;

public:
    
    ShoppingCart()
    {
        size = 0;
    }

    // Function to add a product to the cart
    void addProduct(Product* product) 
    {
        if (size < maxProducts)
        {
            products[size++] = product;
        }
        else
        {
            cout << "Cart is full "<<endl;
            cout<<"Cannot add more products." << endl;
        }
    }

    // Function to display all products in the cart
    void displayCart() const
    {
        cout << "Products in the Cart:" << endl;
        for (int i = 0; i < size; ++i) 
        {
            products[i]->displayProductDetails();
        }
    }

    // Function to calculate the total cost of products in the cart
    double calculateTotalCost() const 
    {
        double totalCost = 0.0;
        for (int i = 0; i < size; ++i)
        {
            totalCost += products[i]->price;
        }
        return totalCost;
    }
};

// User Class
class User {
public:
    int userId;
    ShoppingCart* cart;  // Aggregation, User aggregates a ShoppingCart

    User(int id) 
    {
        userId = id;
        cart = nullptr;
    }

    // Function to display user details
    void displayUserDetails() const 
    {
        cout << "User ID: " << userId << endl;
        if (cart != nullptr) {
            cout << "Shopping Cart Details:" << endl;
            cart->displayCart();
            cout << "Total Cost: " << cart->calculateTotalCost() << endl;
        }
        else 
        {
            cout << "No shopping cart associated with this user." << endl;
        }
    }
};

int main() {
    // Create products
    Product* product1 = new Product(1, "Laptop", 999.99);
    Product* product2 = new Product(2, "Headphones", 49.99);
    Product* product3 = new Product(3, "Mouse", 19.99);

    // Create a shopping cart and add products
    ShoppingCart* cart = new ShoppingCart();
    cart->addProduct(product1);
    cart->addProduct(product2);
    cart->addProduct(product3);

    // Create a user and associate the shopping cart
    User user1(101);
    user1.cart = cart;

    // Display user details
    user1.displayUserDetails();

    // Cleanup (delete dynamically allocated objects)
    delete product1;
    delete product2;
    delete product3;
    delete cart;

    return 0;
}
