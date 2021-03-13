#include <iostream>
using namespace std;

char in[8][8];
char out[8][8];

int key1[16] = {2, 3, 6, 10, 12, 15, 16, 21, 33, 35, 39, 43, 44, 46, 49, 63};
int key2[16] = {5, 9, 11, 22, 23, 26, 27, 31, 34, 38, 45, 50, 55, 56, 59, 62};
int key3[16] = {0, 14, 17, 19, 20, 24, 28, 30, 42, 47, 48, 51, 53, 57, 60, 61};
int key4[16] = {1, 4, 7, 8, 13, 18, 25, 29, 32, 36, 37, 40, 41, 52, 54, 58};

int main(void)
{
    int k = 0;
    
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            cin >> in[i][j];
    
    for (int i = 0; i <= 1; i++)
        for (int j = 0; j < 8; j++)
        {
            out[i][j] = in[key1[k] / 8][key1[k] % 8];
            ++k;
        }
            
    k = 0;
            
    for (int i = 2; i <= 3; i++)
        for (int j = 0; j < 8; j++)
        {
            out[i][j] = in[key2[k] / 8][key2[k] % 8];
            ++k;
        }
            
    k = 0;
            
    for (int i = 4; i <= 5; i++)
        for (int j = 0; j < 8; j++)
        {
            out[i][j] = in[key3[k] / 8][key3[k] % 8];
            ++k;
        }
    
    k = 0;
    
    for (int i = 6; i <= 7; i++)
        for (int j = 0; j < 8; j++)
        {
            out[i][j] = in[key4[k] / 8][key4[k] % 8];
            ++k;
        }
            
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
            cout << out[i][j];
        cout << endl;
    }
    
}