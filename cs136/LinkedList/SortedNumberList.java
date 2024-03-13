
public class SortedNumberList {
	public Node head;
	public Node tail;

	public SortedNumberList() {
		head = null;
		tail = null;
	}
   
	// Inserts the number into the list in the correct position such that the
	// list remains sorted in ascending order.
	public void insert(double number) {
	   // Your code here
	   Node newNode = new Node(number);
	   Node currNode = head;
	   
	   if (head == null) {
		head = newNode;
		tail = newNode;
	   }
	   else {
		while (currNode != null) {
			if (currNode.getData() > newNode.getData()) {
				break;
			}
			currNode = currNode.getNext();
		}

		if (currNode == head) {
			currNode.setPrevious(newNode);
			newNode.setNext(currNode);
			head = newNode;
		}
		else if (currNode == null) {
			tail.setNext(newNode);
			newNode.setPrevious(tail);
			tail = newNode;
		}
		else {
			currNode.getPrevious().setNext(newNode);
			newNode.setPrevious(currNode.getPrevious());
			newNode.setNext(currNode);
			currNode.setPrevious(newNode);
		}
	   }
	}

	// Removes the node with the specified number value from the list. Returns
	// true if the node is found and removed, false otherwise.
	public boolean remove(double number) {
	   // Your code here
	   if (head == null) {
		return false;
	   }
	   Node currNode = head;
	   Node prevNode = currNode.getPrevious();
	   Node nextNode = currNode.getNext();
	   while (currNode != null) {
	      if (currNode.getData() == number) {

	         prevNode = currNode.getPrevious();
	         nextNode = currNode.getNext();
			 if (prevNode == null && nextNode == null) {
				head = null;
				tail = null;
			 }
	         else if (prevNode == null) {
	            nextNode.setPrevious(prevNode);
	            head = nextNode;
	         }
	         else if (nextNode == null) {
	            prevNode.setNext(nextNode);
	            tail = prevNode;
	         }
	         else {
	            prevNode.setNext(nextNode);
	            nextNode.setPrevious(prevNode);
	         }
			 return true;
	      }
		  currNode = currNode.getNext();
	   }
	   return false;
	}
}