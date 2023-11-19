#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Product {
private:
    string name;
    double price;
    bool onPromotion;
public:
    Product(const string& productName, double productPrice) {
        this->name = productName;
        this->price = productPrice;
        this->onPromotion = false;
    }
    const string& getName() const {
        return name;
    }

    double getPrice() const {
        return price;
    }

    bool isOnPromotion() const {
        return onPromotion;
    }

    void setOnPromotion(bool promotionStatus) {
        onPromotion = promotionStatus;
    }

    void setPrice(double newPrice) {
        price = newPrice;
    }
};

class Category {
private:
    string name;
    vector<Product> products;

public:
    Category(const std::string& categoryName) {
        this->name = categoryName;
    }


    const string& getName() const {
        return name;
    }

    const vector<Product>& getProducts() const {
        return products;
    }

    void addProduct(const Product& product) {
        products.push_back(product);
    }

    void removeProduct(const string& productName) {
        auto it = remove_if(products.begin(), products.end(),
            [productName](const Product& product) {
                return product.getName() == productName;
            });
        products.erase(it, products.end());
    }

    void updateProduct(const string& productName, double newPrice, bool onPromotion) {
        for (auto& product : products) {
            if (product.getName() == productName) {
                product.setPrice(newPrice);
                product.setOnPromotion(onPromotion);
                break;
            }
        }
    }
};

class OnlineShop {
private:
    vector<Category> categories;

public:
    const vector<Category>& getCategories() const {
        return categories;
    }

    void addCategory(const Category& category) {
        categories.push_back(category);
    }

    void removeCategory(const string& categoryName) {
        auto it = remove_if(categories.begin(), categories.end(),
            [categoryName](const Category& category) {
                return category.getName() == categoryName;
            });
        categories.erase(it, categories.end());
    }

    void displayAllProducts() const {
        cout << "All Products in the Shop:\n";
        for (const auto& category : categories) {
            cout << "Category: " << category.getName() << "\n";
            for (const auto& product : category.getProducts()) {
                cout << "  - " << product.getName() << " - $" << product.getPrice() << "\n";
            }
        }
    }

    void displayPromotionalProducts() const {
        cout << "Promotional Products in the Shop:\n";
        for (const auto& category : categories) {
            for (const auto& product : category.getProducts()) {
                if (product.isOnPromotion()) {
                    cout << "  - " << product.getName() << " - $" << product.getPrice() << "\n";
                }
            }
        }
    }

    void searchProductsByName(const string& productName) const {
        cout << "Search for '" << productName << "' in the Shop:\n";
        for (const auto& category : categories) {
            for (const auto& product : category.getProducts()) {
                if (product.getName() == productName) {
                    cout << "  - " << product.getName() << " - $" << product.getPrice() << "\n";
                }
            }
        }
    }

    void searchProductsByPrice(double targetPrice) const {
        cout << "Search for products under $" << targetPrice << " in the Shop:\n";
        for (const auto& category : categories) {
            for (const auto& product : category.getProducts()) {
                if (product.getPrice() < targetPrice) {
                    cout << "  - " << product.getName() << " - $" << product.getPrice() << "\n";
                }
            }
        }
    }

    void searchProductsByCategory(const string& categoryName) const {
        cout << "Search for products in the '" << categoryName << "' category:\n";
        for (const auto& category : categories) {
            if (category.getName() == categoryName) {
                for (const auto& product : category.getProducts()) {
                    cout << "  - " << product.getName() << " - $" << product.getPrice() << "\n";
                }
                break;
            }
        }
    }
};




int main() {
    Product product1("Laptop", 999.99);
    Product product2("Smartphone", 499.99);
    Category electronics("Electronics");
    electronics.addProduct(product1);
    electronics.addProduct(product2);
    OnlineShop myShop;

    myShop.addCategory(electronics);

    myShop.displayAllProducts();

    myShop.displayPromotionalProducts();

    myShop.searchProductsByName("Laptop");

    myShop.searchProductsByPrice(600.0);

    myShop.searchProductsByCategory("Electronics");

    return 0;
}
