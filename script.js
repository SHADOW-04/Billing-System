// Menu Data
const menuItems = [
  { name: "Pizza", price: 150 },
  { name: "Burger", price: 100 },
  { name: "Pasta", price: 120 },
  { name: "Coke", price: 50 },
  { name: "Coffee", price: 80 }
];

let cart = [];

// Render Menu
const menuDiv = document.getElementById("menuItems");
menuItems.forEach(item => {
  const btn = document.createElement("button");
  btn.textContent = `${item.name} - Rs${item.price}`;
  btn.onclick = () => addToCart(item);
  menuDiv.appendChild(btn);
});

// Add to Cart
function addToCart(item) {
  const existing = cart.find(ci => ci.name === item.name);
  if (existing) {
    existing.quantity++;
  } else {
    cart.push({ ...item, quantity: 1 });
  }
  renderCart();
}

// Render Cart
function renderCart() {
  const cartUl = document.getElementById("cartItems");
  const totalSpan = document.getElementById("total");
  cartUl.innerHTML = "";

  let total = 0;
  cart.forEach(ci => {
    total += ci.price * ci.quantity;
    const li = document.createElement("li");
    li.textContent = `${ci.name} × ${ci.quantity} = Rs${ci.price * ci.quantity}`;
    cartUl.appendChild(li);
  });

  totalSpan.textContent = total;
}

// Checkout Button
document.getElementById("checkoutBtn").onclick = () => {
  if (cart.length === 0) {
    alert("Cart is empty!");
  } else {
    alert("✅ Order placed successfully!");
    cart = [];
    renderCart();
  }
};
fetch("menu.json")
  .then(res => res.json())
  .then(data => {
    menuItems = data;
    renderMenu();
  });
  function downloadBill() {
  let content = "----- BILL -----\n";
  let total = 0;
  cart.forEach(ci => {
    const amount = ci.price * ci.quantity;
    content += `${ci.name} × ${ci.quantity} = Rs${amount}\n`;
    total += amount;
  });
  content += `TOTAL = Rs${total}\n`;

  // Create downloadable file
  const blob = new Blob([content], { type: "text/plain" });
  const link = document.createElement("a");
  link.href = URL.createObjectURL(blob);
  link.download = "bill.txt";
  link.click();
}

document.getElementById("checkoutBtn").onclick = () => {
  if (cart.length === 0) {
    alert("Cart is empty!");
  } else {
    downloadBill();
    cart = [];
    renderCart();
  }
};

