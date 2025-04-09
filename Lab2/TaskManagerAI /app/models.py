"""
Defines data models for TaskManagerAI.
"""

from pydantic import BaseModel
from typing import Optional


class Task(BaseModel):
    """
    Task schema used for creation and retrieval.

    :param id: Unique identifier.
    :param title: Title of the task.
    :param description: Optional description.
    :param completed: Task completion status.
    """
    id: int
    title: str
    description: Optional[str] = None
    completed: bool = False
