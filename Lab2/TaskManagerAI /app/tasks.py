"""
Background task processing logic.
"""

import threading
import time


def execute_background_task(task_id: int, duration: int):
    """
    Simulates a long-running task.

    :param task_id: The ID of the task to process.
    :param duration: Duration in seconds.
    """
    def background():
        print(f"Task {task_id} started")
        time.sleep(duration)
        print(f"Task {task_id} completed")

    thread = threading.Thread(target=background)
    thread.start()
