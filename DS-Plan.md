+---------------------+----------------------+--------------------------------------------------------------+-----------------+
| Operation           | Data Structure Used  | Reason for Choosing the DS                                   | Assigned Member |
+---------------------+----------------------+--------------------------------------------------------------+-----------------+
| Add New Passenger   | Singly Linked List   | We chose a Linked List because the train has a dynamic       | Muneeb          |
|                     |                      | capacity. We can easily add a new node (passenger) at the    |                 |
|                     |                      | end without resizing a fixed array.                          |                 |
+---------------------+----------------------+--------------------------------------------------------------+-----------------+
| Cancel Ticket       | Singly Linked List   | Deletion is efficient in a Linked List. We simply adjust     | Iman            |
|                     |                      | the pointers to bypass the node to be deleted, avoiding the  |                 |
|                     |                      | need to shift all subsequent elements like in an array.      |                 |
+---------------------+----------------------+--------------------------------------------------------------+-----------------+
| Search Passenger    | Singly Linked List   | Since the passengers are not stored in an indexed format,    | Moosa           |
|                     |                      | we use linear traversal to check each node sequentially      |                 |
|                     |                      | until the Ticket ID is found.                                |                 |
+---------------------+----------------------+--------------------------------------------------------------+-----------------+
| Sort by Name        | Singly Linked List   | We can reorder the list by swapping data between nodes.      | Faisal          |
|                     |                      | While arrays are faster to sort, Linked Lists allow us to    |                 |
|                     |                      | maintain the dynamic nature of the data while sorting.       |                 |
+---------------------+----------------------+--------------------------------------------------------------+-----------------+
| Display All         | Singly Linked List   | The next pointer naturally leads from the head to the last   | Muneeb          |
|                     |                      | node, making it perfect for printing the manifest in order.  |                 |
+---------------------+----------------------+--------------------------------------------------------------+-----------------+
