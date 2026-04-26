import re
import json

# -------------------- LOAD FILE --------------------
with open("raw.txt", "r", encoding="utf-8") as file:
    text = file.read()

# -------------------- CLEAN TEXT --------------------
# убираем пробелы в числах типа "1 526,00" -> "1526,00"
text_clean = re.sub(r"(\d)\s(\d{3})", r"\1\2", text)

# заменяем запятую на точку для float
text_clean = text_clean.replace(",", ".")

# -------------------- EXTRACT PRICES --------------------
# берём все цены вида 154.00, 1526.00 и т.д.
prices = re.findall(r"\d+\.\d{2}", text_clean)
prices = [float(p) for p in prices]

# -------------------- EXTRACT PRODUCT NAMES --------------------
# берём строки перед количеством "1. ... имя"
products = re.findall(r"\d+\.\s(.+)", text)
products = [p.strip() for p in products]

# -------------------- TOTAL --------------------
total_match = re.search(r"ИТОГО:\s*([\d\s]+,\d{2})", text)
total = total_match.group(1).replace(" ", "").replace(",", ".") if total_match else sum(prices)

# -------------------- DATE & TIME --------------------
date = re.findall(r"\d{2}\.\d{2}\.\d{4}", text)
time = re.findall(r"\d{2}:\d{2}:\d{2}", text)

# -------------------- PAYMENT METHOD --------------------
payment = "CARD" if "Банковская карта" in text else "CASH"

# -------------------- RECEIPT STRUCTURE --------------------
receipt = {
    "products": products,
    "prices": prices,
    "total": float(total),
    "date": date[0] if date else None,
    "time": time[0] if time else None,
    "payment_method": payment
}

# -------------------- OUTPUT --------------------
print("\n===== PARSED RECEIPT =====")
print(json.dumps(receipt, indent=4, ensure_ascii=False))