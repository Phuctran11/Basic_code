#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    int a[N], b[M];
    for (int i = 0; i < N; i++) 
    {
        cin >> a[i];
    }
    for (int i = 0; i < M; i++) 
    {
        cin >> b[i];
    }
    int arr[N][M];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
        }
    }
    
    // check loi nhuan
    int money = 0;
    int game[1000], resource[1000];
    int m = 0, n = 0;
    for (int i = 0; i < N; i++)
    {
        int sum = 0;
        for (int j = 0; j < M; j++)
        {
            if (arr[i][j] == 1)
            {
                sum += b[j];
            }
        }
        if (sum <= a[i])
        {
            money += a[i] - sum;
            game[m] = i + 1;
            m++;
            for (int k = 0; k<M; k++)
            {
                
                if ( arr[i][k] == 1)
                {
                    resource[n] = k + 1; n++;// luu resource can dung vao mang resource
                    arr[i+1][k] = 0;
                }
            }
        }

    }
    
    // sắp xếp và loại bỏ các phần tử trùng lặp trong mảng resource
    sort(resource, resource + n);
    resource[unique(resource, resource + n) - resource] = 0;
    
    cout << money << endl;
    for (int i = 0; i < m; i++)
    {
        cout << game[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        if (resource[i] != 0)
        {
            cout << resource[i] << " ";
        }
    }
    return 0;
}
