import java.util.*;

// StringComparer inherits from Comparator<String> and so provides the 
// ability to compare two String objects.
public class StringComparer implements Comparator<String> {
	@Override
	public int compare(String a, String b) {
		return a.compareTo(b);
	}
}