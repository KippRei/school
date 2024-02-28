import java.io.*;
import java.util.*;

public class BinarySearch {	
	public static void main(String[] args) {
		// Perform sample searches with strings
		String[] sortedFruits = { "Apple", "Apricot", "Banana", "Blueberry", 
				"Cherry", "Grape", "Grapefruit", "Guava", "Lemon", "Lime", 
				"Orange", "Peach", "Pear", "Pineapple", "Raspberry", "Strawberry"
				};	
		int sortedFruitsSize = sortedFruits.length;
		String[] fruitSearches = { "Nectarine", "Mango", "Guava", "Strawberry", 
				"Kiwi", "Apple", "Raspberry", "Carrot", "Lemon", "Bread"
				};
		int fruitSearchesSize = fruitSearches.length;
		int[] expectedFruitSearchResults = { -1, -1, 7, 15, -1, 0, 14, -1, 8, -1
				};
		StringComparer stringComparer = new StringComparer();
		PrintSearches<String> stringResults = new PrintSearches<String>();
		stringResults.print(sortedFruits, sortedFruitsSize, fruitSearches, 
				fruitSearchesSize, stringComparer, expectedFruitSearchResults, true);
		
		// Perform sample searches with integers
		Integer[] integers = { 11, 21, 27, 34, 42, 58, 66, 71, 72, 85, 88, 91, 98
				};
		Integer[] integerSearches = { 
				42, 23, 11, 19, 87, 98, 54, 66, 92, 1, 14, 21, 66, 87, 83
				};
		int[] expectedIntegerSearchResults = { 
				4, -1, 0, -1, -1, 12, -1, 6, -1, -1, -1, 1, 6, -1, -1
				};
		IntComparer intComparer = new IntComparer();
		PrintSearches<Integer> integerResults = new PrintSearches<Integer>();
		integerResults.print(integers, integers.length, integerSearches, 
				integerSearches.length, intComparer, expectedIntegerSearchResults, 
				false);
	}
}