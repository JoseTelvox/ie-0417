"""
Main entry point for TaskManagerAI.

This file launches the FastAPI server and includes routers and middleware setup.
"""

from fastapi import FastAPI
from app import auth, crud, tasks, db

app = FastAPI(title="TaskManagerAI", version="1.0.0")


@app.get("/")
def read_root():
    """
    Root endpoint.
    
    :returns: Greeting message.
    :rtype: dict
    """
    return {"message": "Welcome to TaskManagerAI!"}


@app.on_event("startup")
def startup_event():
    """
    Event triggered on server startup.
    
    Initializes the database connection.
    """
    db.init_db()


# Include routers
app.include_router(auth.router)
app.include_router(crud.router)
