    #include <iostream>
    using namespace std;

    int* maxwell(int* a, int* b)
    {
        if (*a > *b)
            return a;
        else
            return b;
    }

    void swap1(int* a, int* b)
    {
        int* temp = a;
        a = b;
        b = temp;
    }

    void swap2(int* a, int* b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    int main()
    {
        int array[6] = { 5, 3, 4, 17, 22, 19 };

        int* ptr = maxwell(array, &array[2]); 
        // setting ptr to the pointer that has the maximum value that it points to.
        // 5 > 4
        // in this case ptr is pointing to array[0]

        *ptr = -1;         
        // setting the value the pointer is pointing to to -1
        // array[6] = { -1, 3, 4, 17, 22, 19 };

        ptr += 2;
        // pointing the pointer to the third object of array
        // in this case ptr is pointing to array[2]

        ptr[1] = 9;
        // setting array[3] = 9;
        // array[6] = { -1, 3, 4, 9, 22, 19 };
        // ptr is still pointing array[2]

        *(array+1) = 79;
        // setting array[1] = 79;
        // array[6] = { -1, 79, 4, 9, 22, 19 }; 
        // ptr is still pointing array[2]

        cout << &array[5] - ptr << endl;
        // &array[5] is the pointer (address) to the last (6th) object in the array.
        // ptr points to the 3rd object in the array.
        // 5 - 2 = 3
        // outputs:
        //3

        swap1(&array[0], &array[1]);
        // swap1 swaps the input pointers
        // that's a copy of pointers, and doesn't modify value of the pointer

        swap2(array, &array[2]);
        // swap2 swaps the value that the input pointers point to
        // array[6] = { 4, 79, -1, 9, 22, 19 };

        for (int i = 0; i < 6; i++)
            cout << array[i] << endl;
        // outputs:
        //4
        //79
        //-1
        //9
        //22
        //19

    } 