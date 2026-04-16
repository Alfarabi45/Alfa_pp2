import psycopg2

conn = psycopg2.connect(
    dbname="phonebook",
    user="postgres",
    password="1234",
    host="localhost",
    port="5432"
)

cur = conn.cursor()

cur.execute("CALL upsert_contact(%s, %s)", ("Ali", "87001112233"))

cur.execute("SELECT * FROM search_contacts(%s)", ("Ali",))
print(cur.fetchall())

cur.execute("SELECT * FROM get_contacts_paginated(%s, %s)", (5, 0))
print(cur.fetchall())

cur.execute("CALL delete_contact(%s)", ("Ali",))

conn.commit()
cur.close()
conn.close()