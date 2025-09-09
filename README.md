<h1 align="center">🧾 Billing System 🧾</h1>

<h2 align="center">🍔 Web|Console-Based Restaurant Billing System</h2>

![C++](https://img.shields.io/badge/Language-C++-blue?style=flat-square) 
![License](https://img.shields.io/badge/License-MIT-green?style=flat-square) 
![Status](https://img.shields.io/badge/Status-Completed-success?style=flat-square)

---

### 🌟 OOP Concepts Demonstrated

- 🔒 **Encapsulation** → name and price are protected.
- 🌳 **Inheritance** → FoodItem and Beverage inherit from MenuItem.
- 🔄 **Polymorphism** → display() is virtual and overridden in derived classes.
- 🧠 **Dynamic Memory** → Menu items created with new and cleaned up with delete.

---

A simple web|console-based restaurant billing system implemented in C++ using Object-Oriented Programming (OOP) concepts.  
It allows users to view menu items, add items to a cart, and generate a detailed bill saved as a text file.

---

[![Live Preview](https://img.shields.io/badge/Live%20Preview-Visit-blue?style=for-the-badge&logo=netlify)](http://billingsystemexe.netlify.app)

---

## 🚀 Features

| Feature | Description |
|---------|-------------|
| Load Menu | Reads menu items from an external `menu.txt` file |
| Item Categories | Items categorized as **Food** or **Beverage** |
| Cart Management | Add items to cart with quantity |
| Bill Generation | Generates detailed bill with total amount |
| OOP Concepts | Demonstrates Encapsulation, Inheritance, Polymorphism, Dynamic Memory |
| File Handling | Saves bills to `bill.txt` for record keeping |

---

## 🛠️ Technologies Used
- **C++** (Core Language)  
- **STL**: `vector`, `pair` for dynamic arrays and cart storage  
- **File Handling**: `ifstream`, `ofstream` for reading/writing files 

---

## Getting Started

### Clone the repository
```bash
git clone https://github.com/yourusername/restaurant-billing-system.git
```
Compile the Program
```bash
g++ main.cpp -o BillingSystem
```
Run the Program
```bash
./BillingSystem   # Linux / Mac
BillingSystem.exe # Windows
```
Ensure `menu.txt` is in the same directory as the executable.

---

## 🍽️ Menu File Format
The program reads menu items from `menu.txt`.
Format:
```nginx
Category ItemName Price
```
Example :
```nginx
Food Burger 120
Beverage Coke 50
Food Pizza 250
```
Easily update the menu by editing this file without changing code.

---

## 🎮 Usage Instructions

- Show Menu – View all available items

- Add Item to Cart – Enter the item number and quantity

- Generate Bill – Display and save the bill to bill.txt

- Exit – Close the program

---

## 🖼️ Example Output

Menu Display:
```markdown
========= MENU =========
1. [FOOD] Burger - Rs120
2. [DRINK] Coke - Rs50
3. [FOOD] Pizza - Rs250
```

Adding to Cart & Generating Bill:
```yaml
Enter choice: 2
Enter item number: 1
Enter quantity: 2
Added 2 x Burger to cart.

Enter choice: 3
----- BILL -----
Burger x2 = Rs240
TOTAL = Rs240
Bill saved to bill.txt
```

---

## 🔮 Future Enhancements

- Add GUI interface for better usability

- Include taxes, discounts, and promotions

- Merge duplicate items automatically in the cart

- Integrate a database for large-scale restaurant management

- Multi-user support for restaurant staff

---

## 👤 Author

**ALPHA**

---

## License
```yaml
This project is licensed under the MIT License - see the LICENSE file for details.
```
---
