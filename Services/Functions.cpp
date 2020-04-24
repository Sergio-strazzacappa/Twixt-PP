#include "Functions.h"

void string_to_point(string s, char &x, int &y)
{
    x = ' ';
    y = 0;
    int digit = 1;
    int size = s.size();

    for (int i = 0; i < size; i++)
    {
        if (s[i] >= 'A' &&
            s[i] <= 'L')
        {
            x = s[i];
        }
        else if (s[i] >= '1' &&
                 s[i] <= '9')
        {
            y += s[i] * digit;
            digit * 10;
        }
    }
    y -= 48;
}