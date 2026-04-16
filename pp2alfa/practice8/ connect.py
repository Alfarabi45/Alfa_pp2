import psycopg2
from config import host, database, user, password, port


def connect():
    conn = psycopg2.connect(
        host=host,
        dbname=database,
        user=user,
        password=0,
        port=5432
    )
    return conn