import java.util.Arrays;

public class question1 {

    public static int[] moveAllNegativeOne(int[] arr) {
        int first_itr = 0, last_itr = arr.length - 1;

        // new array to sort
        int[] sort_array = new int[arr.length];
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == -1) {
                sort_array[last_itr] = -1; // Store at last place
                last_itr--;
            } else {
                sort_array[first_itr] = arr[i]; // Store in next place
                first_itr++;
            }
        }
        return sort_array;
    }

    public static void main(String[] args) {
        int[] input = {6, -1, 8, 2, 3, -1, 4, -1, 1};

        System.out.println("Array before sort: ");
        System.out.println(Arrays.toString(input));
        input = moveAllNegativeOne(input); 
        System.out.println("After: ");
        System.out.println(Arrays.toString(input));
    }
}
