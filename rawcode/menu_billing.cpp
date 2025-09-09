#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

// ---------------- Base Class ----------------
class MenuItem {
protected:   // Encapsulation
    string name;
    double price;
public:
    MenuItem(string n = "", double p = 0.0) : name(n), price(p) {}

    virtual void display() {   // Polymorphism
        cout << name << " - Rs" << price << endl;
    }

    string getName() { return name; }
    double getPrice() { return price; }
};

// ---------------- Derived Classes ----------------
class FoodItem : public MenuItem {
public:
    FoodItem(string n = "", double p = 0.0) : MenuItem(n, p) {}
    void display() override {   // Polymorphism
        cout << "[FOOD] " << name << " - Rs" << price << endl;
    }
};

class Beverage : public MenuItem {
public:
    Beverage(string n = "", double p = 0.0) : MenuItem(n, p) {}
    void display() override {   // Polymorphism
        cout << "[DRINK] " << name << " - Rs" << price << endl;
    }
};

// ---------------- Billing System ----------------
class BillingSystem {
private:
    vector<MenuItem*> menu;
    vector<pair<MenuItem*, int>> cart; // item + quantity
public:
    void loadMenuFromFile(string filename) {
        ifstream file(filename);
        if (!file) {
            cout << "Menu file not found!" << endl;
            return;
        }
        string category, name;
        double price;
        while (file >> category >> name >> price) {
            if (category == "Food")
                menu.push_back(new FoodItem(name, price));
            else if (category == "Beverage")
                menu.push_back(new Beverage(name, price));
        }
        file.close();
    }

    void showMenu() {
        cout << "\n------ MENU CARD ------" << endl;
        for (size_t i = 0; i < menu.size(); i++) {
            cout << i + 1 << ". ";
            menu[i]->display();
        }
    }

    void addToCart(int index, int qty) {
        if (index > 0 && index <= (int)menu.size()) {
            cart.push_back({menu[index - 1], qty});
            cout << "Added " << qty << " x " << menu[index - 1]->getName() << " to cart.\n";
        } else {
            cout << "Invalid item selection!" << endl;
        }
    }

    void generateBill(string filename = "bill.txt") {
        if (cart.empty()) {
            cout << "Cart is empty. Add items first.\n";
            return;
        }

        ofstream file(filename);
        double total = 0;
        file << "----- BILL -----\n";
        cout << "\n----- BILL -----" << endl;

        for (auto &entry : cart) {
            MenuItem* item = entry.first;
            int qty = entry.second;
            double amount = item->getPrice() * qty;
            file << item->getName() << " x" << qty << " = Rs" << amount << endl;
            cout << item->getName() << " x" << qty << " = Rs" << amount << endl;
            total += amount;
        }
        file << "TOTAL = Rs" << total << endl;
        cout << "TOTAL = Rs" << total << endl;
        file.close();

        cout << "Bill saved to " << filename << endl;
    }

    ~BillingSystem() {
        for (auto item : menu) delete item; // Free memory
    }
};

// ---------------- Main Program ----------------
int main() {
    BillingSystem system;
    system.loadMenuFromFile("menu.txt");

    int choice;
    while (true) {
        cout << "\n========= MENU =========" << endl;
        cout << "1. Show Menu" << endl;
        cout << "2. Add Item to Cart" << endl;
        cout << "3. Generate Bill" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // Handle invalid input
        if (!cin) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Try again.\n";
            continue;
        }

        if (choice == 1) {
            system.showMenu();
        }
        else if (choice == 2) {
            int itemNo, qty;
            system.showMenu();
            cout << "Enter item number: ";
            cin >> itemNo;
            cout << "Enter quantity: ";
            cin >> qty;
            system.addToCart(itemNo, qty);
        }
        else if (choice == 3) {
            system.generateBill();
        }
        else if (choice == 4) {
            cout << "Exiting... Thank you!" << endl;
            break;
        }
        else {
            cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}
