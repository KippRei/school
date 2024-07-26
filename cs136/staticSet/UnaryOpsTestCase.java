import java.util.*;
import java.io.PrintWriter;

// UnaryOpsTestCase represents an executable test case for the StaticSet's
// filter() and map() methods
public class UnaryOpsTestCase<T, MappedItemType> extends StaticSetTestCase {
	private HashSet<T> sourceSet = new HashSet<T>();
	private Predicate<T, Integer> filterPredicate;
	private Predicate<T, MappedItemType> mapMethod;
	private HashSet<T> expectedFiltered = new HashSet<T>();
	private HashSet<MappedItemType> expectedMapped = new HashSet<MappedItemType>();

	public UnaryOpsTestCase(HashSet<T> sourceSet, Predicate<T, Integer> filterPredicate,
			Predicate<T, MappedItemType> mapMethod, HashSet<T> expectedFiltered,
			HashSet<MappedItemType> expectedMapped) {
		this.sourceSet = new HashSet<T>(sourceSet);
		this.filterPredicate = filterPredicate;
		this.mapMethod = mapMethod;
		this.expectedFiltered = new HashSet<T>(expectedFiltered);
		this.expectedMapped = new HashSet<MappedItemType>(expectedMapped);
	}

	@Override
	public int execute(PrintWriter testFeedback) {

		// Print the source set first
		StaticSetTestCase.<HashSet<T>, T>print(testFeedback, sourceSet, ", ", "Set = {", "}\n");

		// Create the StaticSet object from the HashSet source
		StaticSet<T> staticSet = new StaticSet<T>(sourceSet);

		// Create the filtered and mapped sets
		StaticSet<T> actualFiltered = staticSet.filter(filterPredicate);
		StaticSet<MappedItemType> actualMapped = staticSet.map(mapMethod);

		// Verify that performing operations didn't staticSetA's size
		if (staticSet.getSize() != (int) sourceSet.size()) {
			testFeedback.write("FAIL: Filtering and/or mapping StaticSet S changed ");
			testFeedback.write("S's size from " + sourceSet.size());
			testFeedback.write(" to " + staticSet.getSize() + "\n");
			return (int) 0.0;
		}

		// Compare actual vs. expected sets
		double totalPoints = 0.0;
		totalPoints += StaticSetTestCase.<T>compareSets(testFeedback, actualFiltered, expectedFiltered,
				"Filter operation", 1.0);
		totalPoints += StaticSetTestCase.<MappedItemType>compareSets(testFeedback, actualMapped, expectedMapped,
				"Map operation", 1.0);

		return (int) totalPoints;
	}
}
