public class question3 
{
    public static long exponentiation(long x, int n)
    {
        //x^0=1
        if (n == 0)
        {
            return 1;
        }
        //x^1=x
        else if (n == 1)
        {
            return x;
        }
        else 
        {
            double result;
            double exp_result;
            //divide exponent by 2 and multiply result by 2
            if ((n%2) == 0)
            {
                exp_result = exponentiation(x, (n/2));
                result = exp_result * exp_result;
            }
            //if there is a remainder, multiply an extra x
            else
            {
                exp_result = exponentiation(x, (n/2)); //gets rid of the odd exponent and multiplies by x to take it into account
                result = exp_result * exp_result * x;
            }
            return (long)result;
        }
    }
    
    
    public static void main(String[] args) 
    {
        long test_base = 2;
        int test_exponent = 63;

        long test_result = exponentiation(test_base, test_exponent);
        System.out.print(test_base + "^" + test_exponent + " = " + test_result);
    }
}


/*__________
a) please see code above

b) The running time complexity of this algorithm is O(log n), as when we double the the n value or exponent in the function, we would only be adding one extra recursive run of the exponentiation function.

c) The number times the function is run when we have any x value with the exponent 63 is 6 times. Since the algorithm divides the exponent by half until it gets to 1, the function would run with the value 63,31,15,7,3 and 1. 
When the exponent is 1 there is no multiplication ocurring. However on the other 5 the exponent of the base to the power of half that exponent is going to by multiplied by itself and then times one to take into account the odd numbers.
This makes a total of 5 lines in which multiplication was run, since each line makes 2 multiplications there is a total of 10 multiplications made.

Please note that by sticking to the long data type provided in the questions, there might be exponents that provide a result too big for ut long data type, if this is the case in an operation, the function would output its highest
 possible value (9223372036854775807)
____________*/