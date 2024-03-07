import java.io.PrintWriter;
public class NaturalMergeSorter {
	PrintWriter p = new PrintWriter(System.out);
	//Returns number of items in list that are sorted
	public int getSortedRunLength(int[] array, int arrayLength, 
	   int startIndex) {
	  int count = 0;
	  if (startIndex >= arrayLength) {
		return count;
	  }
	  else if (startIndex == arrayLength - 1) {
		return 1;
	  }
	  
	  while (array[startIndex] <= array[startIndex + 1]) {
		count++;
		startIndex++;
		if (startIndex == arrayLength - 1) {
			break;
		}
	  }
	  return count + 1;
	}

	public void naturalMergeSort(int[] array, int arrayLength) {
	   int leftStart = 0, leftLength, leftEnd, rightLength, rightEnd;
	   while (true) {
		leftLength = getSortedRunLength(array, arrayLength, leftStart);
		if (leftLength == arrayLength) {
			break;
		}
		leftEnd = leftStart + leftLength - 1;
		if (leftEnd == arrayLength - 1 || leftLength == 0) {
			leftStart = 0;
			continue;
		}
		rightLength = getSortedRunLength(array, arrayLength, leftEnd + 1);
		if (rightLength == 0) {
			leftStart = 0;
			continue;
		}
		else {
			rightEnd = leftEnd + rightLength;
		}
		merge(array, leftStart, leftEnd, rightEnd);
		leftStart = rightEnd + 1;
	   }
	}
	
	public void merge(int[] numbers, int leftFirst, int leftLast, 
	   int rightLast) {
		int mergedSize = rightLast - leftFirst + 1;
		int[] mergedNumbers = new int[mergedSize];
		int mergePos = 0;
		int leftPos = leftFirst;
		int rightPos = leftLast + 1;
      // Add smallest element from left or right partition to merged numbers
		while (leftPos <= leftLast && rightPos <= rightLast) {
			if (numbers[leftPos] <= numbers[rightPos]) {
				mergedNumbers[mergePos] = numbers[leftPos];
				leftPos++;
			}
			else {
				mergedNumbers[mergePos] = numbers[rightPos];
				rightPos++;
			}
			mergePos++;
		}
      
      // If left partition isn't empty, add remaining elements to mergedNumbers
		while (leftPos <= leftLast) {
			mergedNumbers[mergePos] = numbers[leftPos];
			leftPos++;
			mergePos++;
		}
      
      // If right partition isn't empty, add remaining elements to mergedNumbers
		while (rightPos <= rightLast) {
			mergedNumbers[mergePos] = numbers[rightPos];
			rightPos++;
			mergePos++;
		}
      
      // Copy merged numbers back to numbers
		for (mergePos = 0; mergePos < mergedSize; mergePos++) {
			numbers[leftFirst + mergePos] = mergedNumbers[mergePos];
		}

      // Free temporary array
		mergedNumbers = null;
	}
}