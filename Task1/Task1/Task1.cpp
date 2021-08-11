
#include <iostream>
using namespace std;

int main()
{
    int n,flag;
    int m;
    cin >> n;
    cin >> m;
    int* array = new int[n];
    for (int i = 0; i < n; i++) {
        array[i] = i+1;
    }
    flag = 0;
    do {
       cout << array[flag];
        flag = (flag + m - 1) % n;


    } while(flag!=0);
    delete[] array;
    return 0;
}

