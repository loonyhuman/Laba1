#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <vector>

using namespace std;

int myRand()
{
   return  rand()%1000;
}

int main() {

    /// Автоматическая рандомизация
    srand( time(0) );

    int i = 0;

    ///////////////////////////////// Объявление переменных \\\\\\\\\\\\\\\\\\\\\\

    // Число столбцов
    int columns = 0;

    /// Массив для хранения данных
    int * data;


    ///////////////////////////////// Блок с вводом данных \\\\\\\\\\\\\\\\\\\\\\\\\

    cout << "Enter number of elements";
    cin >> columns;

    if (columns < 1)
    {
        cout <<  "Error";
        return 1;
    }

    data = new int [columns];

    cout << "Please, enter 'R', if you want have random generation, or 'D' for normal" << endl;
    char a = 0;
    cin >> a;

    if ( a == 'R')
    {
          for (i = 0; i < columns; i++)
          {
             data[i] = myRand();
          }
    }
    else
    {
        if ( a == 'D')
        {
            int i = 0;
            while (i < columns)
            {
                cin >> data[i];
                if (data[i] > 1000 || data[i] < 0)
                {
                    cout <<  "Error";
                    return 2;
                }
                i++;
            }

        }
        else
        {
            cout <<  "Error";
            return 2;
        }

    }



    ////////////////////////// Обработка \\\\\\\\\\\\\\\\\\\\\\\\\\\\\

 /// Сортировка пузырьком
 for (int k = 0; k < columns-1; k++) {
  for ( int l = 0; l < columns - k - 1; l++)
   if (data[l] > data[l + 1]) {
    int r =  data[l + 1];
    data[l + 1] = data[l];
    data[l] = r;
   }
 }

/// Создаем контейнер, чтобы удалить одинаковые
 vector <int> Vdata;

 for (int p = 0; p < columns ; p++)
 {
  Vdata.push_back (data[p]);
 }

 /// Создаем контейнер, чтобы хранить данные о первоначальных числах
 vector <int> Fdata;

 for (int p = 0; p < columns ; p++)
 {
  Fdata.push_back (data[p]);
 }

    /// Ищем максимальный столбец

    int j = 0;
    int max = 0;

    for (int i = 0; i < columns; i ++)
    {
         if (data[i] > max)
         {
             max = data[i];
             j = i;
         }
    }

    /// Теперь мы знаем, что j - номер столбца, который содержит максимальное число элементов

    for (i = 0; i < columns; i ++)
    {
        data[i] = (data[i] * 80 )/ max;
        if (data[i] == 0)
        {
            data[i] = 1;
        }
    }



    /// Удаление повторяющихся
    for (i = 0; i < Vdata.size(); i++) {
      for (int n = 0; n < Vdata.size();n++) {
        if (i != n )
        {
         if (Vdata[n] == Vdata[i])
          Vdata.erase(Vdata.begin() + n);
        }
      }
     }

 /// Создаем контейнер, чтобы хранить данные о первоначальных числах Vdata
 vector <int> Sdata;

 for (int p = 0; p < Vdata.size() ; p++)
 {
  Sdata.push_back (Vdata[p]);
 }


 /// Нормировка массива Vdata
     max = 0;
     for (int i = 0; i < Vdata.size(); i ++)
     {
      if (Vdata[i] > max)
      {
       max = Vdata[i];
       j = i;
      }
     }

     for (i = 0; i < Vdata.size(); i ++)
     {
      Vdata[i] = (Vdata[i] * 80 )/ max;
      if (Vdata[i] == 0)
      {
       Vdata[i] = 1;
      }
     }



    //////////////////////   Вывод \\\\\\\\\\\\\\\\\\\\\\\\\\\\\


   for (i = 0; i <columns; i ++)
   {
    cout << Fdata[i] << " | " ;
    for (int h = 0; h < data[i]; h++)
    {
     cout << '*';
    }
    cout << endl;
   }

 cout << "Demonstration of ERASE algorithm"<< endl;

    for (i = 0; i <Vdata.size(); i ++)
    {
     cout << Sdata[i] << " | " ;
        for (int h = 0; h < Vdata[i]; h++)
        {
           cout << '*';
        }
        cout << endl;
    }


    return 0;

 }