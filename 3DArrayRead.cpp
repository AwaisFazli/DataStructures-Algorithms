#include <iostream>
using namespace std;

int main()
{

    int h, w, l, i, j, k;

    cout << "Enter the height of the matrix ";
    cin >> h;
    cout << "Enter the width of the matrix ";
    cin >> w;
    cout << "Enter the length of the matrix ";
    cin >> l;
    cout << endl;
    // cout << h << w << l;

    int arr1[h][w][l], arr2[h][w][l], sum[h][w][l];

    for (i = 0; i < h; i++)
    {
        for (j = 0; j < w; j++)
        {
            for (k = 0; k < l; k++)
            {
                cout << "Enter value for arr1"
                     << "[" << i << "][" << j << "][" << k << "] = ";
                cin >> arr1[i][j][k];
            }
        }
    }

    cout << endl
         << "=================================" << endl
         << endl;

    for (i = 0; i < h; i++)
    {
        for (j = 0; j < w; j++)
        {
            for (k = 0; k < l; k++)
            {
                cout << "Enter value for arr2"
                     << "[" << i << "][" << j << "][" << k << "] = ";
                cin >> arr2[i][j][k];
            }
        }
    }

    cout << endl
         << "=================================" << endl
         << endl;

    for (i = 0; i < h; i++)
    {
        for (j = 0; j < w; j++)
        {
            for (k = 0; k < l; k++)
            {
                sum[i][j][k] = arr1[i][j][k] + arr2[i][j][k];
                cout << "sum"
                     << "[" << i << "][" << j << "][" << k << "] = " << sum[i][j][k] << endl;
            }
        }
    }
    return 0;
}
