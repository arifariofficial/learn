from dataclasses import dataclass, asdict


@dataclass
class User:
    id: int
    name: str
    email: str
    bio: str

    def update(self, data):
        self.name = data.get("name", self.name)
        self.email = data.get("email", self.email)
        self.bio = data.get("bio", self.bio)


# Mock database represented as a dictionary
users_db = dict()


# CRUD Functions
def create_user(id, name, email, bio):
    if id in users_db:
        raise ValueError(f"User with ID {id} already exists.")

    user = User(id, name, email, bio)
    users_db[id] = user
    return user


def get_user_by_id(user_id):
    return users_db.get(user_id)


def update_user(user_id, data):
    user = get_user_by_id(user_id)
    user.update(data)
    return user


def list_users():
    return list(users_db.values())


# Utility Functions
def seed_mock_db():
    create_user(0, "Alice Smith", "alice@example.com", "Software Developer from NY.")
    create_user(1, "Bob Johnson", "bob@example.com", "Graphic Designer from CA.")
    create_user(2, "Charlie Lee", "charlie@example.com", "Data Scientist from TX.")
