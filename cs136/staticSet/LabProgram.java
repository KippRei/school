import java.util.*;
import java.io.PrintWriter;

// T = parameter type
// U = return type
interface Predicate<T, U> {
	U predicate(T x);
}

public class LabProgram {
	public static void main(String[] args) {
		PrintWriter testFeedback = new PrintWriter(System.out);

		// First test case tests binary operations: union, intersection, and
		// difference
		BinaryOpsTestCase<Integer> binaryOpsTestCase = new BinaryOpsTestCase<Integer>(
				new HashSet<Integer>(Arrays.asList(42, 63, 99, 32, 18, 77, 64, 50, 12)),
				new HashSet<Integer>(Arrays.asList(64, 16, 32, 8, 4, 1, 2)),
				new HashSet<Integer>(Arrays.asList(1, 2, 4, 8, 12, 16, 18, 32, 42, 50, 63, 64, 77, 99)),
				new HashSet<Integer>(Arrays.asList(32, 64)),
				new HashSet<Integer>(Arrays.asList(42, 63, 99, 18, 77, 50, 12)),
				new HashSet<Integer>(Arrays.asList(1, 2, 4, 8, 16)));
		int binaryTestCasePoints = binaryOpsTestCase.execute(testFeedback);
		testFeedback.flush();
		System.out.print("\n");

		Predicate<String, Integer> filterPredicate = (str) -> {
			return (str.length() <= 4) ? 1 : 0;
		};
		Predicate<String, Integer> mapMethod = (str) -> {
			return (int) str.length();
		};

		// Next test case tests unary operations: filter and map
		UnaryOpsTestCase<String, Integer> unaryOpsTestCase = new UnaryOpsTestCase<String, Integer>(
				new HashSet<String>(Arrays.asList("zero", "one", "two", "three", "four", "five", "six", "seven",
						"eight", "nine", "ten")),
				filterPredicate, mapMethod,
				new HashSet<String>(Arrays.asList("zero", "one", "two", "four", "five", "six", "nine", "ten")),
				new HashSet<Integer>(Arrays.asList(3, 4, 5)));
		int unaryTestCasePoints = unaryOpsTestCase.execute(testFeedback);
		testFeedback.flush();

		System.out.print("Binary operations score: ");
		System.out.print(binaryTestCasePoints);
		System.out.print(" out of 3");
		System.out.print("\n");
		System.out.print("Unary operations score: ");
		System.out.print(unaryTestCasePoints);
		System.out.print(" out of 2");
		System.out.print("\n");

		testFeedback.close();
	}
}
