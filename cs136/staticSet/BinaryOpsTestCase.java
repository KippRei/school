import java.util.*;
import java.io.PrintWriter;

// BinaryOpsTestCase represents an executable test case for the StaticSet's
// union(), intersection(), and difference() methods
public class BinaryOpsTestCase<T> extends StaticSetTestCase {
	private HashSet<T> setA = new HashSet<T>();
	private HashSet<T> setB = new HashSet<T>();
	private HashSet<T> expectedUnion = new HashSet<T>();
	private HashSet<T> expectedIntersection = new HashSet<T>();
	private HashSet<T> expectedAMinusB = new HashSet<T>();
	private HashSet<T> expectedBMinusA = new HashSet<T>();

	public BinaryOpsTestCase(HashSet<T> setA, HashSet<T> setB, HashSet<T> expectedUnion,
			HashSet<T> expectedIntersection, HashSet<T> expectedAMinusB, HashSet<T> expectedBMinusA) {
		this.setA = new HashSet<T>(setA);
		this.setB = new HashSet<T>(setB);
		this.expectedUnion = new HashSet<T>(expectedUnion);
		this.expectedIntersection = new HashSet<T>(expectedIntersection);
		this.expectedAMinusB = new HashSet<T>(expectedAMinusB);
		this.expectedBMinusA = new HashSet<T>(expectedBMinusA);
	}

	@Override
	public int execute(PrintWriter testFeedback) {
		// Print sets A and B first
		StaticSetTestCase.<HashSet<T>, T>print(testFeedback, setA, ", ", "A = {", "}\n");
		StaticSetTestCase.<HashSet<T>, T>print(testFeedback, setB, ", ", "B = {", "}\n");

		// Create the two StaticSet objects from the HashSet objects
		StaticSet<T> staticSetA = new StaticSet<T>(setA);
		StaticSet<T> staticSetB = new StaticSet<T>(setB);

		// Create the union, intersection, and differences
		StaticSet<T> actualUnion = staticSetA.union(staticSetB);
		StaticSet<T> actualIntersection = staticSetA.intersection(staticSetB);
		StaticSet<T> actualAMinusB = staticSetA.difference(staticSetB);
		StaticSet<T> actualBMinusA = staticSetB.difference(staticSetA);

		// Verify that performing operations didn't change either StaticSet's size
		ArrayList<Tuple<StaticSet<T>, HashSet<T>, String>> sizeChecks = new ArrayList<Tuple<StaticSet<T>, HashSet<T>, String>>() {
			{
				add(new Tuple<StaticSet<T>, HashSet<T>, String>(staticSetA, setA, "A"));
				add(new Tuple<StaticSet<T>, HashSet<T>, String>(staticSetB, setB, "B"));
			}
		};

		for (var sizeCheckTuple : sizeChecks) {
			StaticSet<T> staticSet = sizeCheckTuple.getVar0();
			HashSet<T> unorderedSet = sizeCheckTuple.getVar1();
			String staticSetName = sizeCheckTuple.getVar2();
			if (staticSet.getSize() != (int) unorderedSet.size()) {
				testFeedback.write("FAIL: Creating the union/intersection/difference ");
				testFeedback.write(" of StaticSets A and B changed set ");
				testFeedback.write(staticSetName + "'s size from ");
				testFeedback.write(unorderedSet.size());
				testFeedback.write(" to " + staticSetA.getSize() + "\n");
				return (int) 0.0;
			}
		}

		// Compare actual vs. expected sets
		double totalPoints = 0.0;
		totalPoints += StaticSetTestCase.<T>compareSets(testFeedback, actualUnion, expectedUnion, "Union operation",
				1.0);
		totalPoints += StaticSetTestCase.<T>compareSets(testFeedback, actualIntersection, expectedIntersection,
				"Intersection operation", 1.0);
		totalPoints += StaticSetTestCase.<T>compareSets(testFeedback, actualAMinusB, expectedAMinusB,
				"A \\ B operation", 0.5);
		totalPoints += StaticSetTestCase.<T>compareSets(testFeedback, actualBMinusA, expectedBMinusA,
				"B \\ A operation", 0.5);

		return (int) totalPoints;
	}
}
