#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

char oper = '+';
int z;

double pluss(double x, double y)
{
    return (x + y);
}

double minuss(double x, double y)
{
    return (x - y);
}

double dels(double x, double y)
{
    if (y != 0)
    {
        return (x / y);
    }
    else
    {
        cout << "Деление на 0 недопустимо." << endl;
        return -1;
    }
}

double ymns(double x, double y)
{
    return (x * y);
}

double steps(double x, double y)
{
    return pow(x, y);
}

void calc_oper(double x, char oper, double y)
{
    switch (oper)
    {
    case '+':
        cout << pluss(x, y) << endl;
        break;
    case '-':
        cout << minuss(x, y) << endl;
        break;
    case '*':
        cout << ymns(x, y) << endl;
        break;
    case '/':
        if (y == 0)
        {
            cout << "Деление на 0 недопустимо." << endl;
            return;
        }
        cout << dels(x, y) << endl;
        break;
    case '^':
        cout << steps(x, y) << endl;
        break;
    default:
        cout << "Недопустимая операция" << endl;
        break;
    }
}

void simpl_calc()
{
    double x, y;
    int endsss = 1;
    do
    {
        cout << "Введите 1-ое число: ";
        cin >> x;
        cout << "Введите 2-ое число: ";
        cin >> y;
        cout << "Введите оператор: ";
        cin >> oper;
        calc_oper(x, oper, y);
        cout << "Желаете продолжить? (0 - нет, 1 - да): ";
        cin >> endsss;
        cin.clear();
    } while (endsss == 1);
}

void mat_calc()
{
    int m, n;
    cout << "Введите количество строк матрицы: ";
    cin >> m;
    cout << "Введите количество столбцов матрицы: ";
    cin >> n;

    if (m <= 0 || n <= 0)
    {
        cout << "Неверные размеры матрицы." << endl;
        return;
    }

    int **a = new int *[m];
    int **b = new int *[m];
    int **d = new int *[m];
    for (int i = 0; i < m; i++)
    {
        a[i] = new int[n];
        b[i] = new int[n];
        d[i] = new int[n];
    }

    char m_op;

    cout << "Введите элементы матрицы A:" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "A[" << i << "][" << j << "]: ";
            cin >> a[i][j];
        }
    }

    cout << "Введите элементы матрицы B:" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "B[" << i << "][" << j << "]: ";
            cin >> b[i][j];
        }
    }

    cin.ignore(32767, '\n');
    cout << "Введите + или - для операции: ";
    cin >> m_op;

    if (m_op != '+' && m_op != '-')
    {
        cout << "Недопустимая операция." << endl;
        return;
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (m_op == '+')
            {
                d[i][j] = a[i][j] + b[i][j];
            }
            else if (m_op == '-')
            {
                d[i][j] = a[i][j] - b[i][j];
            }
        }
    }

    cout << "Результат операции:" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << d[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < m; i++)
    {
        delete[] a[i];
        delete[] b[i];
        delete[] d[i];
    }
    delete[] a;
    delete[] b;
    delete[] d;
}

int main()
{
    int endsss = 1;
    do
    {
        cout << "Консольный калькулятор" << endl;
        cout << "Выберите режим работы. (1) - числовой калькулятор, (2) - матричный калькулятор" << endl;
        cin >> z;

        while (z != 1 && z != 2)
        {
            cout << "Вы не ввели 1 или 2! Повторите ввод." << endl;
            cin >> z;
        }

        if (z == 1)
        {
            simpl_calc();
        }
        else if (z == 2)
        {
            mat_calc();
        }

        if (endsss == 1) {
            cout << "Желаете продолжить? (0 - нет, 1 - да): ";
            cin >> endsss;
            cin.clear();
        }
    } while (endsss == 1);

    return 0;
}
