public class NaturalMergeSorter {

	//Returns number of items in list that are sorted
	public int getSortedRunLength(int[] array, int arrayLength, 
	   int startIndex) {
	  int count = 0;
	  if (arrayLength <= startIndex) {
		return count;
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
	   int i = 0, leftFirst = 0, leftLast, rightLast;
	   while (i < arrayLength) {
		leftLast = getSortedRunLength(array, arrayLength, i);
		i = leftLast;
		if (i == arrayLength || i == 0) {
			break;
		}
		rightLast = getSortedRunLength(array, arrayLength, i);
		i = rightLast;
		merge(array, leftFirst, leftLast, rightLast);
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