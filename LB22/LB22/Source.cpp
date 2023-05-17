#include <iostream>
#include <string>

using namespace std;

int stringToInt(const string& str)
{
    long long result = 0;
    int sign = 1;
    int i = 0;

    if (str[0] == '-')
    {
        sign = -1;
        i = 1;
    }

    for (; i < str.size(); i++)
    {
        if (isdigit(str[i]))
        {
            result = result * 10 + (str[i] - '0');

            if (result > numeric_limits<int>::max())
            {
                throw overflow_error("������������.");
            }
        }
        else
        {
            throw invalid_argument("�������� ����");
        }
    }

    return static_cast<int>(result * sign);
}

int main()
{
    setlocale(LC_ALL, "");
    string input;
    cout << "������� �����: ";
    cin >> input;

    try
    {
        int result = stringToInt(input);
        cout << "���������: " << result << endl;
    }
    catch (const exception& e)
    {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}