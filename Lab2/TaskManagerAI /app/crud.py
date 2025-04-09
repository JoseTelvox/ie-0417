"""
CRUD operations for tasks.
"""

from fastapi import APIRouter
from app.models import Task
from app.db import tasks_db

router = APIRouter(prefix="/tasks", tags=["tasks"])


@router.post("/", response_model=Task)
def create_task(task: Task):
    """
    Creates a new task.

    :param task: The task object to be created.
    :type task: Task
    :returns: Created task.
    :rtype: Task
    """
    tasks_db.append(task)
    return task


@router.get("/", response_model=list[Task])
def list_tasks():
    """
    Lists all tasks.

    :returns: List of tasks.
    :rtype: list[Task]
    """
    return tasks_db
