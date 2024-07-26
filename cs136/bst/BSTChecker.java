import java.util.*;

public class BSTChecker {
	public static Node badNode = null;

	public static Node checkBSTValidity(Node rootNode) {
		ArrayList<Node> currNodeList = new ArrayList<Node>();
		ArrayList<Node> nodeOrderList = new ArrayList<Node>();

		checkForInvalidLink(rootNode, currNodeList);
		if (badNode == null) {
			nodesInOrder(rootNode, nodeOrderList);
			badNode = checkNodes(rootNode, nodeOrderList);
		}

		return badNode;
	}

	private static void checkForInvalidLink(Node currNode, ArrayList<Node> currNodeList) {
		if (currNode == null) {return;}
		if (currNode.left == null && currNode.right == null) {return;}
		currNodeList.add(currNode);
		for (Node n: currNodeList) {
			if (currNode.left == n || currNode.right == n) {
				badNode = currNode;
				return;
			}
		}
		checkForInvalidLink(currNode.left, currNodeList);
		checkForInvalidLink(currNode.right, currNodeList);
	}

	private static void nodesInOrder(Node currNode, ArrayList<Node> nodeOrderList) {
		if (currNode == null) {return;}

		nodesInOrder(currNode.left, nodeOrderList);
		nodeOrderList.add(currNode);
		nodesInOrder(currNode.right, nodeOrderList);
	}

	private static Node checkNodes(Node root, ArrayList<Node> nodeOrderList) {
		int rootIndex = -1;
		for (int i = 0; i < nodeOrderList.size(); i++) {
			if (nodeOrderList.get(i).key == root.key) {
				rootIndex = i;
			}
		}
		if (rootIndex == -1) {return null;}

		if (rootIndex > 0) {
			// Check left side
			int currNodeIndex = rootIndex - 1;
			Node prevNode = nodeOrderList.get(rootIndex);
			Node currNode = nodeOrderList.get(currNodeIndex);
			while (currNodeIndex >= 0) {
				currNode = nodeOrderList.get(currNodeIndex);
				if (currNode.key > prevNode.key) {
					return currNode;
				}
				prevNode = currNode;
				currNodeIndex -= 1;
			}
		}

		if (rootIndex < nodeOrderList.size() - 2) {
			// Check right side
			int currNodeIndex = rootIndex + 1;
			Node prevNode = nodeOrderList.get(rootIndex);
			Node currNode = nodeOrderList.get(currNodeIndex);
			while (currNodeIndex < nodeOrderList.size()) {
				currNode = nodeOrderList.get(currNodeIndex);
				if (currNode.key < prevNode.key) {
					return currNode;
				}
				prevNode = currNode;
				currNodeIndex += 1;
			}
		}
	
		return null;
	}
}