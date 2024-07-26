import java.util.*;
import java.io.PrintWriter;

public abstract class StaticSetTestCase {
	public static <T> double compareSets(PrintWriter testFeedback, StaticSet<T> actual, HashSet<T> expected,
			String title, double points) {
		boolean pass = true;

		// Compare actual vs. expected sets
		if (actual.getSize() != (int) expected.size()) {
			pass = false;
		} else {
			// Expected and actual have equal sizes, so compare contents
			for (T item : expected) {
				if (!actual.contains(item)) {
					pass = false;
				}
			}
		}

		// Print the pass or fail message with expected and actual sets
		testFeedback.write((pass ? "PASS: " : "FAIL: "));
		testFeedback.write(title + "\n");
		StaticSetTestCase.<HashSet<T>, T>print(testFeedback, expected, ", ", "  Expected: {", "}\n");
		actual.print(testFeedback, ", ", "  Actual:   {", "}\n");

		return pass ? points : 0.0;
	}

	public static <ContainerType, ItemType> void print(PrintWriter output, HashSet<ItemType> iterable, String separator,
			String prefix, String suffix) {
		// Print the prefix first
		output.write(prefix);

		boolean firstItem = true;
		for (ItemType item : iterable) {
			if (firstItem) {
				// Print first item without separator
				output.write(item.toString());
				firstItem = false;
			} else {
				// Print item preceded by separator
				output.write(separator + item.toString());
			}
		}

		// Print the suffix last
		output.write(suffix);
	}

	public abstract int execute(PrintWriter testFeedback);
}

// Basic Tuple class for test cases
class Tuple<T, U, V> {
	public T var0;
	public U var1;
	public V var2;

	public Tuple(T x, U y, V z) {
		var0 = x;
		var1 = y;
		var2 = z;
	}

	public T getVar0() {
		return var0;
	}

	public U getVar1() {
		return var1;
	}

	public V getVar2() {
		return var2;
	}
}
