/* public class ProgA{
    public static void main(String[] args){
        int[] a = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        printArray("a", a);
        int[] b = new int[12];
        cumSum(a, b);
        printArray("b", b);
    }
    public static void printArray(String s, int[] a) {
        System.out.println(s + ":");
        for (int i = 0; i < a.length; i++)
        {
            System.out.print(a[i] + " ");
        }
        System.out.println();
    }
    public static void cumSum(int[] a, int[] b){
        int c = 0;
        for (int i = 0; i < a.length; i++)
        {
            c += a[i];
            b[i] = c;
        }
    }
}
*/

#include <stdio.h>

void printArray(char a[], int b[], int size);
void printArray2(char a[], int b);
void cumSum(int a[], int b[], int size);

int main(int argc, char *argv[])
{
    int a[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    printArray("a", a, sizeof(a) / sizeof(*a));

    int b[12];
    cumSum(a, b, 12);
    printArray("b", b, 12);

    printf("\n");
}

void printArray(char a[], int b[], int size)
{
    printf("%s: ", a);
    for (int i = 0; i < size; i++)
    {
        printf("%d    ", b[i]);
    }
    printf("\n");
}

void cumSum(int a[], int b[], int size)
{
    int c = 0;
    for (int i = 0; i < size; i++)
    {
        c += a[i];
        b[i] = c;
    }
}