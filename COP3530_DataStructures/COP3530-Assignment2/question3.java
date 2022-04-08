public class question3
{
    public void replaceKey(Integer oldKey, Integer newKey)
    {
        for(int i=1; i<= array.length; i++)
        {
            if (oldKey == array[i])
            {
                array[i] = newKey;
                percolateDown(i);
                return;
            }
        }
        System.out.println("Old key was not found, no changes made.");
        return;
    }
}