import java.util.*;

public class LabProgram {
	public static void main(String[] args) {
		// Get user input
		Scanner reader = new Scanner(System.in);
		String userInput = reader.nextLine();

		userInput = "(20, (10, (8), (21)), (30, (29), (31)))";

		// Parse into a binary tree
		Node userRoot = Node.parse(userInput);
		userRoot.right = userRoot;
		if (userRoot != null) {
			Node badNode = BSTChecker.checkBSTValidity(userRoot);
			if (badNode != null) {
				System.out.print(String.valueOf(badNode.key));
				System.out.print("\n");
			} 
			else {
				System.out.print("No violation");
				System.out.print("\n");
			}
		} 
		else {
			System.out.print("Failed to parse input tree");
			System.out.print("\n");
		}
      
      reader.close();
	}
}