"""
Utility functions for TaskManagerAI.
"""

def generate_task_id(current_ids):
    """
    Generates a unique task ID.

    :param current_ids: List of existing IDs.
    :type current_ids: list[int]
    :returns: New unique ID.
    :rtype: int
    """
    return max(current_ids, default=0) + 1
