import java.util.Stack;

public class question4 
{
    static int leader(int[] A)
    {
        //Stack size is used as a counter, each index is of the current leader being tested is pushed into the stack
        Stack<Integer> leaderCount = new Stack<>();

        for(int i=0; i< A.length; i++)
        {
            if (leaderCount.size() == 0)
            {
                leaderCount.push(i);
            }
            else
            {
                if (A[leaderCount.peek()] == A[i])
                {
                    leaderCount.push(i);
                }
                else
                {
                    leaderCount.pop();
                }
            }      
        }
        
        // second for loop is used to confirm whether or not the determined leader is an actual leader value
        int count = 0;
        for (int i=0; i<A.length; i++)
        {
            if (A[i] == A[leaderCount.peek()])
            {
                count++;
            }
        }

        //comparing the count to half the lenght of the array.
        if (count > (A.length/2))
        {
            return leaderCount.peek();
        }
        else
        {
            return -1;
        }
        
    }   
    
    public static void main(String[] args) 
    {
        int test_array_a[] = {23, 23, 67, 23, 67, 23, 45};
        int test_array_b[] = {23, 24, 67, 23, 67, 23, 45};

        int test_result = leader(test_array_a);
        System.out.println("Leader of Array A: " + test_result);

        test_result = leader(test_array_b);
        System.out.println("Leader of Array B: " + test_result);
    }    
}