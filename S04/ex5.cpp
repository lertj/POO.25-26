#include <iostream>

using namespace std;

void func(int v[], int n)
{
    int start = 0;
    int end, maxlength;
    int finalStart, finalEnd;
    for (int i = 1; i < n; i++)
    {
        if (v[i] < v[i - 1])
        {
            end = i;
            maxlength = max(maxlength, end - start);
            if (end - start >= maxlength)
            {
                finalStart = start;
                finalEnd = end;
            }
            start = i + 1;
        }
    }
    for (int i = finalStart; i < finalEnd; i++)
        cout << v[i] << " ";
    cout << endl;
}

int main()
{
    int n;
    cout << "Introduceti numarul de elemente: ";
    cin >> n;
    int* v = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "v[" << i << "] = ";
        cin >> v[i];
    }
    cout << "\n\n";
    func(v, n);
    delete[] v;
    return 0;
}
