import java.util.*;

public class Searcher<T> {
	// Returns the index of the key in the sorted array, or -1 if the 
	// key is not found.
	public static <T> int binarySearch(T[] array, int arraySize, T key, 
			Comparator<T> comparer) {
			   
		// Your code here
		int low = 0;
		int high = arraySize - 1;
		int mid = 0;

		do {
			mid = (high + low) / 2;
			if (comparer.compare(key, array[mid]) > 0) {
				low = mid + 1;
			}
			else if (comparer.compare(key, array[mid]) < 0) {
				high = mid - 1;
			}
			else {
				return mid;
			}
		} while (high >= low);

		return -1;
	}
}