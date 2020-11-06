#include <stdio.h>

int data[8];
int error[3];

void read_data(int data[])
{
    for (int i = 0; i < 8; i++)
    {
        data[i] = getchar() - '0';
    }
}

void write_data(int data[])
{
    for (int i = 0; i < 8; i++)
    {
        printf("%d", data[i]);
    }
}

void count_control(int data[])
{
    data[4] = data[1] ^ data[2] ^ data[3];
    data[5] = data[0] ^ data[2] ^ data[3];
    data[6] = data[0] ^ data[1] ^ data[3];
}

int check_code(int data[])
{
    if ( (data[4] == data[1] ^ data[2] ^ data[3]) && (data[5] == data[0] ^ data[2] ^ data[3]) && (data[6] == data[0] ^ data[1] ^ data[3]) )
        return 1;
    else
        return 0;
}

int mod_2(int data[])
{
    int q = 0;

    for (int i = 0; i < 8; i++)
    {
        if (data[i] == 1)
            q++;
    }

    if ((q % 2) == 0)
        return 1;
    else
        return 0;
}

int int_error(int error[])
{
    int q = 0;

    for (int i = 4; i > 0; i /= 2)
    {
        q += i * (*error);
        ++error;
    }

    return q;
}

void correction_error(int data[], int error[])
{
    error[0] = data[0] ^ data[1] ^ data[3];
    error[1] = data[0] ^ data[2] ^ data[3];
    error[2] = data[1] ^ data[2] ^ data[3];

    data[int_error(error)] = 1 - data[int_error(error)];
}

int main(void)
{
    read_data(data);
    switch(mod_2(data))
    {
    case 1:
        if (!(check_code(data)))
            printf("%s", "2 errors\n");

        break;

    case 0:
        if (check_code(data))
        {
            data[7] = 1 - data[7];
            printf("%s", "last bit error\n");
        }

        else
        {
            correction_error(data, error);
            printf("%s", "error in Hamming code\n");
        }

    }

    write_data(data);
}
