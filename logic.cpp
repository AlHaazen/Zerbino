#include "logic.h"
#include <string>

//int l2=0;

vector<char> transform(string num, int from, int to)
{
    vector<char> vec;
    char c;
    bool isNeg=false;
    int temp;
    if(from==10)
    {
       if (num.at(0)=='-') {num.erase(0,1);isNeg++;}
       int decNum=0;
       for(int i=0;i<num.size();i++)
           decNum+=toInt(num[i])*pow(10,num.size()-i-1);
       cout<<"Decnum\t"<<decNum<<endl;
        while(decNum!=0)
        {
        temp=decNum%to;
        c=toChar(temp);
        cout<<"temp\t"<<temp<<"\tchar c\t"<<c<<endl;
        vec.push_back(c);
        decNum/=to;
        }

        if(isNeg) vec.push_back('-');

       return vec;
    }

    else
    {
        int decNum=0;
        for(int i=0;i<num.size();i++)
           decNum+=toInt(num[i])*pow(from,num.size()-1-i);

        string NormalS="";
        string s="";
        int i=0,temp=decNum;

        if (decNum<0) {NormalS="-";decNum*=-1;}
//
        while(temp!=0)
        {i++;
            temp/=10;
        }
        for(int j=0;j<i;j++)
        {
            s+=toChar(decNum%10);
            decNum/=10;
        }
//
        for(int i=s.size()-1;i>=0;i--)
            NormalS+=s.at(i);

        return transform(NormalS,10,to);


    }

}

int toInt(char c)
{
    if(c>65)
        return c-55;
    else return c-48;
}

char toChar(int num)
{
    if(num>=10)
        return 55+num;
    else return 48+num;
}

vector<char> toVec(string s)
{
    vector<char> a;
    for(int i=0;i<s.size();i++)
        a.push_back(s[i]);
   return a;

}

int preventOGul(string num, int from, int to)
{
    int i=0;
    for(int j=0;j<num.size();j++)
        if(toInt(num.at(j))>i) i=num.at(j);
      throw 2;
}

string multipl(string s1, string s2)
{
    int l1=s1.length();
    int l2=s2.length();

    //Робимо динамічний масив через вектор у векторі
    vector< vector<int> > matrix;
      matrix.resize(l1);
      for(int i=0;i<l1;i++)
        matrix[i].resize(l2);

    //Проініціалізуємо масив 1
      for(int i=0;i<l1;i++)
          for(int j=0;j<l2;j++)
              matrix[i][j]=1;

   //Викидаємо із матриці 1 і заміняємо їх нулями
      for(int i=l1-1;i>=0;i--)
          if (s1.at(i)=='0')
              for(int j=0;j<l2;j++)
                  matrix[i][j]=0;

      for(int i=0;i<l2;i++)
          if(s2.at(l2-1-i)=='0')
              for(int j=0;j<l1;j++)
                  matrix[j][i]=0;
  //Виводимо матрицю

      for(int i=0;i<l1;i++)
      {
          for(int j=0;j<l2;j++)
              cout<<matrix[i][j]<<' ';
          cout<<endl;
      }
      cout<<endl;


      fig(&matrix);

      string s="";
      for(int i=matrix.at(0).size()-1;i>=0;i--)
          s+=toChar(matrix.at(0).at(i));
      cout<<s;

      return s;


}


void fig(vector< vector<int> > *matrix)
{
    //Треба юзати matrix->at(i).at(j) для  matrix[i][j]
    int l1=matrix->size();
    int l2=matrix->at(0).size();


    while(matrix->size()>1)
    {



    for(int i=0;i<l1-1;i++)
    {

        for(int j=0;j<l2;j++)
        {


            if((matrix->at(i).at(j)==1)) //Буква Т
            {
                if((j+2)<(matrix->at(i).size())) // Якщо не виходимо за межі матриці
                {
                    if((matrix->at(i).at(j+1)==0)&&(matrix->at(i).at(j+2)==0)&&(matrix->at(i+1).at(j+1)==1))
                    {
                        matrix->at(i).at(j)=0;
                        matrix->at(i).at(j+1)=1;
                        matrix->at(i+1).at(j+1)=0;
                        matrix->at(i).at(j+2)=1;
                        for(int i=0;i<matrix->size();i++)
{
                            for(int j=0;j<matrix->at(0).size();j++)
                                cout<<matrix->at(i).at(j)<<' ';
                            cout<<endl;

                        }
                        cout<<endl;
                    }
                    // Тут фігурні дужки, щоб компілятор розрізняв, до якого ІФу належить цей ЕЛСЕ
                }
               else  //Якщо виходимо
                {
                    for(int i=0;i<l1;i++) //Розширяємо масив
                    {
                        matrix->at(i).resize(l2+2);
                    }
                    l2+=2;
                    for(int i=0;i<l1;i++) //Заповнюємо нулями, можна оптимізувати
                    {
                        matrix->at(i).at(l2-1)=0;
                        matrix->at(i).at(l2-2)=0;

                    }

                    if((matrix->at(i).at(j+1)==0)&&(matrix->at(i).at(j+2)==0)&&(matrix->at(i+1).at(j+1)==1))
                    {
                        matrix->at(i).at(j)=0;
                        matrix->at(i).at(j+1)=1;
                        matrix->at(i+1).at(j+1)=0;
                        matrix->at(i).at(j+2)=1;
                        for(int i=0;i<matrix->size();i++)
{
                            for(int j=0;j<matrix->at(0).size();j++)
                                cout<<matrix->at(i).at(j)<<' ';
                            cout<<endl;

                        }
                        cout<<endl;
                    }

                }
            }

            if((matrix->at(i).at(j)==1)) //Об'єднані фігури Г та зсув; Можна запхати Т
            {
                if((j+1)<(matrix->at(i).size())) //Якщо не виходимо за межі
                {
                    if((matrix->at(i).at(j+1)==1)&&(matrix->at(i+1).at(j+1)==1)) // Буква Г
                    {
                        matrix->at(i).at(j)=0;
                        matrix->at(i).at(j+1)=0;
                        matrix->at(i+1).at(j+1)=0;
                        for(int i=0;i<matrix->size();i++)
{
                            for(int j=0;j<matrix->at(0).size();j++)
                                cout<<matrix->at(i).at(j)<<' ';
                            cout<<endl;

                        }
                        cout<<endl;
                    }
                    else //ЯКЩО ЗАБРАТИ ЦЕЙ ЕЛСЕ, ТО ВолошУн рак, Юрі +1 бал
                    if(matrix->at(i+1).at(j+1)==0) // Зсув вниз
                    {
                        matrix->at(i).at(j)=0;
                        matrix->at(i+1).at(j+1)=1;

                        for(int i=0;i<matrix->size();i++)
{
                            for(int j=0;j<matrix->at(0).size();j++)
                                cout<<matrix->at(i).at(j)<<' ';
                            cout<<endl;

                        }
                        cout<<endl;

                    }
                }
                else //Буквою Г неможливо виїхати за масив, тому цей випадок тільки для Зсуву *Може не працювати*
                {
                    for(int i=0;i<l1;i++) //Розширяємо масив
                    {
                        matrix->at(i).resize(l2+1);
                        matrix->at(i).at(l2+1)=0;
                    }
                    l2++;


                    matrix->at(i).at(j)=0;
                    matrix->at(i+1).at(j+1)=1;

                    for(int i=0;i<matrix->size();i++)
{
                        for(int j=0;j<matrix->at(0).size();j++)
                            cout<<matrix->at(i).at(j)<<' ';
                        cout<<endl;

                    }
                    cout<<endl;
                }
            }
        }
    }

    bool q=false;
    while(q==false)
    {
        for(int i=0;i<l2;i++)
            if(matrix->at(0).at(i)==1)
                q=true;
        if(q==false) matrix->erase(matrix->begin());
    }


     l1=matrix->size();
     l2=matrix->at(0).size();


    }

}


vector<char> toNegBin(string s)
{

    vector< vector<int> > matrix;

    matrix.resize(2);
    matrix.at(0).resize(s.length());
    matrix.at(1).resize(s.length());
    for(int i=0;i<=1;i++)
    {
        for(int j=0;j<s.length();j++)
        {

            matrix.at(i).at(j)=1;
            if((i==0)&&(j%2==0))
                matrix.at(i).at(j)=0;
            cout<<matrix.at(i).at(j);
        }
        cout<<endl;
    }
    cout<<endl;

    for(int i=0;i<s.length();i++)
        if(s.at(i)=='0')
        {
            matrix.at(0).at(s.length()-1-i)=0;
            matrix.at(1).at(s.length()-1-i)=0;

        }

    for(int i=0;i<=1;i++)
    {
        for(int j=0;j<s.length();j++)
        {
            cout<<matrix.at(i).at(j);
        }
        cout<<endl;
    }
     cout<<endl;
    fig(&matrix);

        string ss="";
        for(int i=matrix.at(0).size()-1;i>=0;i--)
            ss+=toChar(matrix.at(0).at(i));
        cout<<ss;
}



string divide(string A, string B, int accuracy)
{

    vector< vector<int> > matrixAB;
    vector< vector<int> > matrixCD;

    //Заганяємо матрицю AB
    matrixAB.resize(A.length()+accuracy);

    for(int i=0;i<matrixAB.size();i++)
        matrixAB.at(i).resize(B.length()+1);

    for(int i=0;i<A.size();i++)
        matrixAB.at(i).at(0)=toInt(A.at(i));

     addB(&matrixAB, B);

    for(int i=0;i<matrixAB.size();i++)
{
        for(int j=0;j<matrixAB.at(0).size();j++)
            cout<<matrixAB.at(i).at(j)<<' ';
        cout<<endl;

    }
    cout<<endl;

    figN(&matrixAB);

    return "";



}


void addB(vector<vector<int> > *matrixAB,string B)
{
    bool q=true;
    for(int i=0;i<matrixAB->size();i++)
    {
        for(int j=1;j<matrixAB->at(0).size();j++)
            if(matrixAB->at(i).at(j)==1) q=false;
        if((matrixAB->at(i).at(0)==1)&&q)
           for(int j=1;j<matrixAB->at(0).size();j++)
               matrixAB->at(i).at(j)=toInt(B.at(j-1));
    }
}


void figN(vector<vector<int> > *matrixAB)
{

    //Треба юзати matrix->at(i).at(j) для  matrix[i][j]
    int l1=matrixAB->size();
    int l2=matrixAB->at(0).size();


    for(int i=0;i<l1-1;i++)
    {

        for(int j=1;j<l2-1;j++)
        {


            if((matrixAB->at(i).at(j-1)==0)) //Буква Т
            {
                if((j+1)<(matrixAB->at(i).size())) // Якщо не виходимо за межі матриці
                {
                    if((matrixAB->at(i).at(j)==0)&&(matrixAB->at(i).at(j+1)==1)&&(matrixAB->at(i+1).at(j)==1))
                    {
                        matrixAB->at(i).at(j)=1;
                        matrixAB->at(i).at(j-1)=1;
                        matrixAB->at(i+1).at(j)=0;
                        matrixAB->at(i).at(j+1)=0;
                        for(int i=0;i<matrixAB->size();i++)
{
                            for(int j=0;j<matrixAB->at(0).size();j++)
                                cout<<matrixAB->at(i).at(j)<<' ';
                            cout<<endl;

                        }
                        cout<<endl;
                    }
                    // Тут фігурні дужки, щоб компілятор розрізняв, до якого ІФу належить цей ЕЛСЕ
                }
            }

            if((matrixAB->at(i).at(j)==1)) //Об'єднані фігури Г та зсув; Можна запхати Т
            {
                    if((matrixAB->at(i).at(j)==1)&&(matrixAB->at(i).at(j-1)==1)&&(matrixAB->at(i+1).at(j-1)==1)) // Буква Г
                    {
                        matrixAB->at(i).at(j)=0;
                        matrixAB->at(i).at(j-1)=0;
                        matrixAB->at(i+1).at(j-1)=0;

                        for(int i=0;i<matrixAB->size();i++)
{
                            for(int j=0;j<matrixAB->at(0).size();j++)
                                cout<<matrixAB->at(i).at(j)<<' ';
                            cout<<endl;

                        }
                        cout<<endl;
                    }
                    else //ЯКЩО ЗАБРАТИ ЦЕЙ ЕЛСЕ, ТО ВолошУн рак, Юрі +1 бал
                    if(matrixAB->at(i+1).at(j-1)==0) // Зсув вниз
                    {
                        matrixAB->at(i).at(j)=0;
                        matrixAB->at(i+1).at(j-1)=1;

                        for(int i=0;i<matrixAB->size();i++)
{
                            for(int j=0;j<matrixAB->at(0).size();j++)
                                cout<<matrixAB->at(i).at(j)<<' ';
                            cout<<endl;

                        }
                        cout<<endl;

                    }


            }
        }
    }





}
