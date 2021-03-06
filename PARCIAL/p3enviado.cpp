//
// Created by misash on 23/10/21.
//


#include <iostream>
#include <queue>
#include <list>

#include <bits/stdc++.h>


using namespace std;


template<class T>
class CSortMatrix
{
public:
    CSortMatrix();
    ~CSortMatrix();
    void Ins(T v);
    void Print();
    void expand(int);
    int** map;
    int size_y, size_x;
    int n_elements;
    //my atributes
    int **current;
    vector<T> vec;
};

template<class T>
CSortMatrix<T>::CSortMatrix()
{
    size_y = 3;
    size_x = 5;
    map = new int*[size_y];
    for (int i = 0; i < size_y; i++)
        map[i] = 0;
    map[0] = new int[size_x];
    n_elements = 0;
    current = map;
}

template<class T>
CSortMatrix<T>::~CSortMatrix()
{
    //..
}

template<class T>
void CSortMatrix<T>::expand(int len){

    if(!len) return ;

    //
    delete [] map;
    size_y = len;
    CSortMatrix();
    //

    for (int i = 1; i <= len ; ++i) {
        map[i] = new int[size_x];
    }
}



template<class T>
void CSortMatrix<T>::Ins(T v)
{

//    vector<T> vec;
    vec.push_back(v);
    sort(vec.begin(), vec.end());
    expand(vec.size()/size_x);

    n_elements = 0;
    for (int i = 0; i < vec.size(); ++i) {
        current  = &map[n_elements/size_x];
        *(*current + n_elements%size_x) = vec[i];
        n_elements++;
    }

}

template<class T>
void CSortMatrix<T>::Print()
{
    int y, x, ne = 0;
    for ( y = 0; y < size_y; y++ )
    {
        if ( map[y] != 0 )
        {
            for ( x = 0; x < size_x; x++ )
            {
                std::cout<<map[y][x]<<" ";
                if ( ++ne == n_elements ) return;
            }
            std::cout<<"\n";
        }
        else
        {
            std::cout<<"----\n";
        }
    }
    std::cout<<"\n***********************\n";
}

int main()
{
    CSortMatrix<int> sm;
    sm.Ins(82); sm.Ins(44); sm.Ins(52);sm.Ins(77); sm.Ins(46);sm.Ins(99);sm.Ins(26);
    sm.Print();
    sm.Ins(64); sm.Ins(10); sm.Ins(4); sm.Ins(33); sm.Ins(13); sm.Ins(81); sm.Ins(35);
    sm.Print();
    sm.Ins(17); sm.Ins(3); sm.Ins(20); sm.Ins(54); sm.Ins(73); sm.Ins(12); sm.Ins(92);
    sm.Print();
    sm.Ins(93); sm.Ins(48); sm.Ins(67); sm.Ins(22); sm.Ins(28); sm.Ins(56); sm.Ins(25);
    sm.Print();
    sm.Ins(38); sm.Ins(14); sm.Ins(50);

    sm.Print();
}
