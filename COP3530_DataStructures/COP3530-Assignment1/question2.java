public class question2
{
    public static int algorithm(int A[], int target_value) 
    {
        //Using binary search to find the first match
        int start_index = 0;
        int end_index = A.length - 1;
        int value_count = 0;
        int found_index;

        while (start_index <= end_index)
        {
            int middle = (start_index + end_index) / 2;

            if (target_value < A[middle])
            {
                end_index = middle - 1;
            }
            else if (target_value > A[middle])
            {
                start_index = middle + 1;
            }
            else 
            {
                //once the first match is found, the falue of the index is saved for later use
                found_index = middle;
                value_count++;

                //The while loop will count 1 by one the number times the target value is present above the found index by using middle as the position marker
                middle++;
                while (A[middle] == target_value)
                {
                    value_count++;
                    middle++;
                }

                //middle is set to the index before the first fount match, and then the number of matches below that index are counted
                middle = found_index - 1;
                while (A[middle] == target_value)
                {
                    value_count++;
                    middle--;
                }
                return value_count; //at the end the total count of target numbers is returned
            }
        }
        return value_count; //if the program does not enter the matching else condition the function will return 0
    }
    
    
    
    public static void main(String[] args) 
    {
        int test_array[] = {-1,2,3,5,6,6,6,9,10};
        int test_target = 4;

        int test_result = algorithm(test_array, test_target);

        System.out.println(test_result);
    }
}
