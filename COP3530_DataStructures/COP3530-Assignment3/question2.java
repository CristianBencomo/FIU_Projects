import java.util.ArrayList;
import java.util.List;
import java.util.Arrays;

;

public class question2 {

    public static void radixsort(int arr[]) {
        final int RADIX = 10;

        List<Integer>[] bucket = new ArrayList[RADIX];

        for (int i = 0; i < bucket.length; i++)
            bucket[i] = new ArrayList<Integer>();

        //sorting
        boolean finalDigit = false;
        int tmp = -1, placeMultiplier = 1;
        while (!finalDigit) {
            finalDigit = true;

            // divide in buckets
            for (Integer i : arr) {
                if(i%2 != 0)
                {
                    System.out.println("***Abort*** the input has  at least one key with odd digits");
                    return;
                }
                tmp = i / placeMultiplier;
                bucket[tmp % RADIX].add(i);
                if (finalDigit && tmp > 0)
                    finalDigit = false;
            }

            // reformat array
            int a = 0;
            for (int b = 0; b < RADIX; b++) {
                for (Integer i : bucket[b]) {
                    arr[a++] = i;
                }
                bucket[b].clear();
            }

            // next digit
            placeMultiplier *= RADIX;
        }

        System.out.println("The sorted array is:");
        System.out.println(Arrays.toString(arr));
    }

    public static void main(String[] args) {

        int[] input1 = { 24, 12, 4, 366, 45, 66, 8, 14 };
        int[] input2 = { 24, 2, 4, 466, 48, 66, 8, 44 };

        System.out.println("Integer arrays before sorting");
        System.out.println(Arrays.toString(input1));
        System.out.println(Arrays.toString(input2));
        System.out.println();

        radixsort(input1);
        radixsort(input2);
    }
}

/*
    b) The running time complexxity of the algorithm is O(k * N) where k is the number of digits of the biggest number and N is the size of the array, since k will be a constant we can say that the time complexity is O(N) 
*/