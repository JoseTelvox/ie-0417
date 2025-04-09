"""
Authentication module for TaskManagerAI.
Handles user login, registration, and token generation.
"""

from fastapi import APIRouter, HTTPException
from pydantic import BaseModel

router = APIRouter(prefix="/auth", tags=["auth"])


class User(BaseModel):
    """
    User schema for registration and login.
    """
    username: str
    password: str


@router.post("/register")
def register_user(user: User):
    """
    Registers a new user.

    :param user: The user data.
    :type user: User
    :returns: Confirmation message.
    :rtype: dict
    """
    # Here you would interact with db
    return {"message": f"User {user.username} registered successfully"}


@router.post("/login")
def login(user: User):
    """
    Logs in a user and returns a token.

    :param user: The user credentials.
    :type user: User
    :returns: A fake JWT token (simulated).
    :rtype: dict
    """
    if user.username == "admin" and user.password == "admin":
        return {"token": "fake-jwt-token"}
    raise HTTPException(status_code=401, detail="Invalid credentials")
