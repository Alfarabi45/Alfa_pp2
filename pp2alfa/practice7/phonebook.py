import csv
from connect import get_connection


# ✅ Создание таблицы
def create_table():
    conn = get_connection()
    cur = conn.cursor()

    cur.execute("""
        CREATE TABLE IF NOT EXISTS phonebook (
            id SERIAL PRIMARY KEY,
            username VARCHAR(50) UNIQUE NOT NULL,
            phone VARCHAR(20) NOT NULL
        );
    """)

    conn.commit()
    cur.close()
    conn.close()


# ✅ Вставка из CSV
def insert_from_csv(filename):
    conn = get_connection()
    cur = conn.cursor()

    with open(filename, newline='', encoding='utf-8') as file:
        reader = csv.reader(file)
        for row in reader:
            cur.execute(
                "INSERT INTO phonebook (username, phone) VALUES (%s, %s) ON CONFLICT DO NOTHING",
                (row[0], row[1])
            )

    conn.commit()
    cur.close()
    conn.close()


# ✅ Вставка с консоли
def insert_from_console():
    username = input("Enter name: ")
    phone = input("Enter phone: ")

    conn = get_connection()
    cur = conn.cursor()

    cur.execute(
        "INSERT INTO phonebook (username, phone) VALUES (%s, %s)",
        (username, phone)
    )

    conn.commit()
    cur.close()
    conn.close()


# ✅ Обновление
def update_contact():
    username = input("Enter username to update: ")
    new_name = input("New name (leave blank to skip): ")
    new_phone = input("New phone (leave blank to skip): ")

    conn = get_connection()
    cur = conn.cursor()

    if new_name:
        cur.execute("UPDATE phonebook SET username=%s WHERE username=%s", (new_name, username))

    if new_phone:
        cur.execute("UPDATE phonebook SET phone=%s WHERE username=%s", (new_phone, username))

    conn.commit()
    cur.close()
    conn.close()


# ✅ Поиск
def query_contacts():
    print("1 - Show all")
    print("2 - Search by name")
    print("3 - Search by phone prefix")

    choice = input("Choose option: ")

    conn = get_connection()
    cur = conn.cursor()

    if choice == "1":
        cur.execute("SELECT * FROM phonebook")

    elif choice == "2":
        name = input("Enter name: ")
        cur.execute("SELECT * FROM phonebook WHERE username ILIKE %s", ('%' + name + '%',))

    elif choice == "3":
        prefix = input("Enter prefix: ")
        cur.execute("SELECT * FROM phonebook WHERE phone LIKE %s", (prefix + '%',))

    rows = cur.fetchall()

    for row in rows:
        print(row)

    cur.close()
    conn.close()


# ✅ Удаление
def delete_contact():
    print("1 - Delete by username")
    print("2 - Delete by phone")

    choice = input("Choose: ")

    conn = get_connection()
    cur = conn.cursor()

    if choice == "1":
        username = input("Enter username: ")
        cur.execute("DELETE FROM phonebook WHERE username=%s", (username,))

    elif choice == "2":
        phone = input("Enter phone: ")
        cur.execute("DELETE FROM phonebook WHERE phone=%s", (phone,))

    conn.commit()
    cur.close()
    conn.close()


# ✅ Меню
def menu():
    while True:
        print("\n--- PHONEBOOK MENU ---")
        print("1. Create table")
        print("2. Insert from CSV")
        print("3. Insert from console")
        print("4. Update contact")
        print("5. Query contacts")
        print("6. Delete contact")
        print("0. Exit")

        choice = input("Select: ")

        if choice == "1":
            create_table()
        elif choice == "2":
            insert_from_csv("contacts.csv")
        elif choice == "3":
            insert_from_console()
        elif choice == "4":
            update_contact()
        elif choice == "5":
            query_contacts()
        elif choice == "6":
            delete_contact()
        elif choice == "0":
            break


if __name__ == "__main__":
    menu()