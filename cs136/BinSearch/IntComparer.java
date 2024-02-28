import java.util.*;

// IntComparer inherits from Comparator<Integer> and so provides the
// ability to compare two integers.
public class IntComparer implements Comparator<Integer> {
	@Override
	public int compare(Integer a, Integer b) {
		return a - b;
	}
}