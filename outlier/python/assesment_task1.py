import pandas as pd


class User:
    def __init__(self, user_id, username, password, failed_attempts=0, is_locked=False):
        self.user_id = user_id
        self.username = username.lower()  # Ensure case insensitivity
        self.password = password
        self.failed_attempts = failed_attempts
        self.is_locked = is_locked

    def reset_failed_attempts(self):
        self.failed_attempts = 0

    def increment_failed_attempts(self):
        self.failed_attempts += 1

    def lock_account(self):
        self.is_locked = True


class AuthenticationSystem:
    def __init__(self):
        self.users = pd.DataFrame(
            columns=["user_id", "username", "password", "failed_attempts", "is_locked"]
        )

    def register_user(self, user_id, username, password):
        user = User(user_id, username, password)
        new_user = pd.DataFrame(
            {
                "user_id": [user.user_id],
                "username": [user.username],
                "password": [user.password],
                "failed_attempts": [user.failed_attempts],
                "is_locked": [user.is_locked],
            }
        )
        self.users = pd.concat([self.users, new_user], ignore_index=True)

    # Never alter this login function
    def login(self, username, password):
        user_row = self.users[self.users["username"] == username.lower()]
        if user_row.empty:
            print(f"User {username} not found.")
            return
        user = User(
            user_row.iloc[0]["user_id"],
            user_row.iloc[0]["username"],
            user_row.iloc[0]["password"],
            user_row.iloc[0]["failed_attempts"],
            user_row.iloc[0]["is_locked"],
        )

        if user.is_locked:
            print(f"Account for {username} is locked. Please contact support.")
            return
        if user.password == password:
            print(f"User {username} logged in successfully.")
            user.reset_failed_attempts()
        else:
            print(f"Failed login attempt for {username}.")
            user.increment_failed_attempts()
            if user.failed_attempts >= 3:
                user.lock_account()
                print(f"Account for {username} has been locked.")
        self.update_user(user)

    def update_user(self, user):
        self.users.loc[self.users["username"] == user.username, "failed_attempts"] = (
            user.failed_attempts
        )
        self.users.loc[self.users["username"] == user.username, "is_locked"] = (
            user.is_locked
        )


auth_system = AuthenticationSystem()
auth_system.register_user(1, "neena", "password123")
auth_system.register_user(2, "helios", "mysecurepassword")

auth_system.login("neena", "password321")
auth_system.login("Neena", "password123")
auth_system.login("neena", "password321")
auth_system.login("neena", "password123")
auth_system.login("helios", "mysecurepassword")