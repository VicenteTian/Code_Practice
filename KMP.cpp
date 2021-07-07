#include <iostream>
#include <string>
using namespace std;
void get_next(string t, int next[])
{
    next[0] = -1;
    int j = 0, k = -1;
    while (j < t.length())
    {
        if (k == -1 || t[k] == t[j])
        {
            ++j;
            ++k;
            if (t[j]==t[k])
            {
                next[j] = next[k];
            }
            
            next[j] = k;
        }
        else
        {
            k = next[k];
        }
    }
}
int Index_KMP(string S, string T)
{
    int i = 0, j = 0;
    int sl = S.length();
    int tl = T.length();
    int *next = new int[tl];
    get_next(T, next);
    while ((i < sl) && (j < tl))
    {
        if (j == -1 || S[i] == T[j])
        {
            ++i;
            ++j;         
        }
        else
        {
            j = next[j];
        }
    }
    if (j == T.length())
    {
        return i - j;
    }
    else
    {
        return -1;
    }
}

int main()
{
    string s = "vctrabaabcxx";
    string t = "aabc";
    int next[6] = {0};
    cout << Index_KMP(s, t) << endl;
    system("pause");
    return 0;
}