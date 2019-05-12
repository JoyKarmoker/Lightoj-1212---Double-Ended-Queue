#include<bits/stdc++.h>
using namespace std;
void pushLeft(int array[], int target, int size, int total_numbers_in_array)
{
    if( total_numbers_in_array == (size))
    {
        return ;
    }

    else
    {
        for(int i =  total_numbers_in_array; i<0; i--)
        {
            for(int j =  total_numbers_in_array-1; ; j--)
            {
                array[i] = array[j];
            }
        }

        array[0] = target;
    }

    return ;
}

void pushRight(int array[], int target, int size, int total_numbers_in_array)
{
    if( total_numbers_in_array == (size))
    {
        return ;
    }

    else
    {
        array[total_numbers_in_array] = target;

        return;
    }
}

int popLeft(int array[], int total_numbers_in_array)
{
    int ret = array[0];
    for(int i = 0; i<total_numbers_in_array; i++)
    {
        array[i+1] = array[i];
    }

    return ret;

}
int popRight(int array[], int total_numbers_in_array)
{
    int ret, i;
    i = total_numbers_in_array-1;
    //ret = array[i];

    return array[i];
}
int main()
{
    int t, n, m, num, num_in_array, cano = 1;
    string cmnd;
    int arr[15];
    scanf("%d", &t);

    while(t--)
    {
        memset(arr, 0, sizeof(arr));
        num_in_array = 0;

        scanf("%d %d", &n, &m);
        printf("Case %d:\n", cano++);

        while(m--)
        {
           cin >> cmnd;

           if(cmnd == "pushLeft")
           {
               scanf("%d", &num);

               if(num_in_array < n)
               {
                   pushLeft(arr, num, n, num_in_array);
                    printf("Pushed in left: %d\n", num);
                    num_in_array++;
               }

               else
               {
                   printf("The queue is full\n");
               }
           }

           else if(cmnd == "pushRight")
           {
               scanf("%d", &num);

               if(num_in_array < n)
               {
                   pushRight(arr, num, n, num_in_array);
                    printf("Pushed in right: %d\n", num);
                    num_in_array++;
               }

               else
               {
                   printf("The queue is full\n");
               }


           }

           else if(cmnd == "popLeft")
           {
               if(num_in_array == 0)
               {
                   printf("The queue is empty\n");
               }

               else
               {
                   num = popLeft(arr, num_in_array);
                   printf("Popped from left: %d\n", num);
                    num_in_array--;
               }
           }

           else
           {

               if(num_in_array == 0)
               {
                   printf("The queue is empty\n");
               }

               else
               {
                   num = popRight(arr, num_in_array);
                   printf("Popped from right: %d\n", num);
                    num_in_array--;
               }

           }
        }

    }




    return 0;
}

