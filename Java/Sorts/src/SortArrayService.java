import java.security.InvalidParameterException;
import java.util.Random;
import java.util.function.BiPredicate;
import java.util.function.Function;

public class SortArrayService <T extends Comparable<T>>{

    public void shell_sort(T array[], int array_size, BiPredicate<T,T> criteria){
        int jump_ks[] = {23,19,17,13,11,7,5,3,2,1};
        for(int i = 0; i < jump_ks.length; i++){
            if(jump_ks[i] <= array_size){
                insertion_sort(array, array_size, criteria, jump_ks[i]);
            }
        }
    }

    /*
     * Only works when both arrays are already ordered
     */
    public void intercalateArrays(T array[], int beg1, int end1, int beg2, int end2, BiPredicate<T, T> criteria){

        if(beg1 > end1 || beg2 > end2 || beg1 > beg2 || end1 > end2){
            throw new InvalidParameterException("Some of the positions in the arrays are wrong");
        }

        if(end1 > beg2){
            throw new InvalidParameterException("Overlapping arrays");
        }

        int newArraySize = end1 - beg1 + 1 + end2 - beg2 + 1;
        T newArray[] = (T[])new Comparable[newArraySize];

        int controllerArray1 = beg1, controllerArray2 = beg2;
        int newArrayIndex = 0;

        while(controllerArray1 <= end1 && controllerArray2 <= end2){
            if(criteria.test(array[controllerArray1], array[controllerArray2])){
                newArray[newArrayIndex] = array[controllerArray1];
                controllerArray1++;
            }
            else{
                newArray[newArrayIndex] = array[controllerArray2];
                controllerArray2++;
            }
            newArrayIndex++;
        }

        if(controllerArray1 > end1){
            for(int i = controllerArray2; i <= end2; i++){
                newArray[newArrayIndex] = array[i];
                newArrayIndex++;
            }
        }
        else if(controllerArray2 > end2){
            for(int i = controllerArray1; i <= end1; i++){
                newArray[newArrayIndex] = array[i];
                newArrayIndex++;
            }
        }

        for(int i = 0; i < newArraySize; i++){
            array[beg1] = newArray[i];
            beg1++;
        }
    }

    public void mergeArrays(T array1[], T array2[], int array1Size, int array2Size, T destArray[]){
        int destArrayIndex = 0;
        for(int i = 0; i < array1Size; i++){
            destArray[destArrayIndex] = array1[i];
            destArrayIndex++;
        }

        for(int i = 0; i < array2Size; i++){
            destArray[destArrayIndex] = array2[i];
            destArrayIndex++;
        }
    }

    public void selection_sort(T array[], int arraySize, BiPredicate<T, T> criteria){
        int chosenIndex = 0;
        for(int i = 0; i < arraySize - 1; i++){
            chosenIndex = i;
            for(int j = i + 1; j < arraySize; j++){
                if(criteria.test(array[j], array[chosenIndex])){
                    chosenIndex = j;
                }
            }

            if(criteria.test(array[chosenIndex], array[i])){
                swap(array, chosenIndex, i);
            }
        }
    }

    public void merge_sort(T array[], int beginning, int end, BiPredicate<T,T> criteria){
        if(end <= beginning){
            return;
        }    

        int half = (beginning + end)/2;
        merge_sort(array, beginning, half, criteria);
        merge_sort(array, half + 1, end, criteria);
        intercalateArrays(array, beginning, half, half + 1, end, criteria);
    }

    public void insertion_sort(T array[], int arraySize, BiPredicate<T, T> criteria, int k_jump){
        T temp;
        int j = 0;
        for(int i = k_jump; i < arraySize; i++){
            temp = array[i];
            j = i - k_jump;
            while(j >= 0 && criteria.test(temp, array[j])){
                array[j + k_jump] = array[j]; 
                j -= k_jump;
            }
            array[j + k_jump] = temp;
        }
    }

    public void bubble_sort(T array[], int arraySize, BiPredicate<T, T> criteria){
        int i = arraySize - 1;
        boolean unordered = true;
        while(i >= 0 && unordered){
            unordered = false;
            for(int j = 0; j < i; j++){
                if(criteria.test(array[j], array[j + 1])){
                    swap(array, j, j + 1);
                    unordered = true;
                }
            }
            i--;
        }
    }

    private void swap(T[] array, int firstPosition, int secondPosition){
        T temp = array[firstPosition];
        array[firstPosition] = array[secondPosition];
        array[secondPosition] = temp;
    }

    public void generateRandomArray(T[] array, int arraySize, Function <Random, T> generator){
        Random random = new Random();
        random.setSeed(System.currentTimeMillis());

        for(int i = 0; i < arraySize; i++){
            array[i] = generator.apply(random);
        }
    }

    public void printArray(T[] array){
        int index = 0;
        for(T generic : array){
            System.out.println("[" + index + "] = " + generic);
            index++;
        }
    }
}
