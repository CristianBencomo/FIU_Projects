#!/bin/bash
# sum or average of 3 entered numbers based on user's choice

echo "Would you like to calculate the sum or the average?"
while [ -z "${OPERATION}" ]
do
    read OPERATION
    if [[ "$OPERATION" == "sum" ]]; then
        echo "you have selected summation"
        
        echo "please enter 3 numbers to add"
        read NUM1
        read NUM2
        read NUM3

        ((SUM=NUM1+NUM2+NUM3))

        echo "The sum of the 3 numbers you selected is: " $SUM    

    elif [[ "$OPERATION" == "average" ]]; then
        echo "you have selected average"

        echo "please enter 3 numbers to find the acerage"
        read NUM1
        read NUM2
        read NUM3

        ((AVG=(NUM1+NUM2+NUM3)/3))
        echo "the average of the 3 numbers you selected is: " $AVG

    else
        echo "Not a valit input, please enter either "sum" or "average""
        OPERATION=
    fi

done

exit 0
