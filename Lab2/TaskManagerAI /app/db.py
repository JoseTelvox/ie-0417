"""
Database connection and setup module.
Simulates an in-memory database for tasks and users.
"""

tasks_db = []
users_db = []


def init_db():
    """
    Initializes mock databases.
    """
    global tasks_db, users_db
    tasks_db = []
    users_db = []
