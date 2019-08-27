#include <iostream>
#include "mechanic.hpp"
#include <windows.h>

constexpr int size_x = 20;
constexpr int size_y = 20;
unsigned long int counter = 0;

void mechanic::game()
{
    system("CLS");
    int status = 0;
    int show = 0;
    std::vector <std::vector<int> > board;
    std::vector <std::vector<int> > new_board;
    for(int i=0; i<size_x; i++)
    {
        board.push_back(std::vector<int>());
        new_board.push_back(std::vector<int>());
        for (int j = 0; j < size_y; j++)
        {
            board[i].push_back(0);
            new_board[i].push_back(0);
        }
        
    }
    for (int i=5; i<15; i++)
    {
        board[i][9] = 1;
    }

    while(true)
    {
    show_board(board, size_x, size_y);
    std::cout << "\n\n";
    for(int i=0; i<size_x; i++)
    {
        for (int j = 0; j < size_y; j++)
        {
            status = check_state(board, i, j);
            show = check_show(board, i, j, status);
            new_board[i][j] = show;
        }
    }
    board.swap(new_board);
    std::cout << "Generation: " << ++counter << "\n";
    Sleep(500);
    system("CLS");
    }
}
int mechanic::check_state( std::vector <std::vector<int> > board, int id_x, int id_y)
{
    int result = 0;
    if (board[id_x][id_y]==1)
    {
        result = 1;
    }
    return result;
}
void mechanic::show_board( std::vector <std::vector<int> > board,
        int size_x, int size_y)
{
    for(int i=0; i<(size_x); i++)
    {
        for (int j = 0; j < (size_y); j++)
        {
            std:: cout<< board[i][j] << " ";
        }
        std::cout<< "\n";
    }
}

int mechanic::check_show( std::vector <std::vector<int> > board, 
        int id_x, int id_y, int state)
{
    int survive = 0;
    int buff = 0;
    if(id_x == 0)
    {
        if(id_y == 0)
        {
            if(board[id_x+1][id_y] == 1) buff++;
            if(board[id_x][id_y+1] == 1) buff++;
            if(board[id_x+1][id_y+1] == 1) buff++;
        }
        else if (id_y == size_y-1)
        {
            if(board[id_x][id_y-1] == 1) buff++;
            if(board[id_x+1][id_y] == 1) buff++;
            if(board[id_x+1][id_y-1] == 1) buff++;
        }
        else
        {
            if(board[id_x][id_y-1] == 1) buff++;
            if(board[id_x][id_y+1] == 1) buff++;
            if(board[id_x+1][id_y-1] == 1) buff++;
            if(board[id_x+1][id_y] == 1) buff++;
            if(board[id_x+1][id_y+1] == 1) buff++;
        }
    }
    else if (id_x == size_x-1)
    {
        if(id_y == 0)
        {
            if(board[id_x-1][id_y] == 1) buff++;
            if(board[id_x][id_y+1] == 1) buff++;
            if(board[id_x-1][id_y+1] == 1) buff++;
        }
        else if (id_y == size_y-1)
        {
            if(board[id_x][id_y-1] == 1) buff++;
            if(board[id_x-1][id_y] == 1) buff++;
            if(board[id_x-1][id_y-1] == 1) buff++;
        }
        else
        {
            if(board[id_x][id_y-1] == 1) buff++;
            if(board[id_x][id_y+1] == 1) buff++;
            if(board[id_x-1][id_y-1] == 1) buff++;
            if(board[id_x-1][id_y] == 1) buff++;
            if(board[id_x-1][id_y+1] == 1) buff++;
        }
    }
    else if(id_y == 0)
    {
        if(board[id_x][id_y+1] == 1) buff++;
        if(board[id_x+1][id_y] == 1) buff++;
        if(board[id_x+1][id_y+1] == 1) buff++;
        if(board[id_x-1][id_y] == 1) buff++;
        if(board[id_x-1][id_y+1] == 1) buff++;
    }
    else if(id_y == size_y-1)
    {
        if(board[id_x][id_y-1] == 1) buff++;
        if(board[id_x+1][id_y] == 1) buff++;
        if(board[id_x+1][id_y-1] == 1) buff++;
        if(board[id_x-1][id_y] == 1) buff++;
        if(board[id_x-1][id_y-1] == 1) buff++;
    }
    else
    {
        if(board[id_x][id_y+1] == 1) buff++;
        if(board[id_x+1][id_y] == 1) buff++;
        if(board[id_x+1][id_y+1] == 1) buff++;
        if(board[id_x-1][id_y] == 1) buff++;
        if(board[id_x-1][id_y+1] == 1) buff++;
        if(board[id_x+1][id_y-1] == 1) buff++;
        if(board[id_x][id_y-1] == 1) buff++;
        if(board[id_x-1][id_y-1] == 1) buff++;
    }
    

    if(state == 1 && (buff == 2 || buff == 3))
    {
        survive = 1;
    }
    else if(state == 0 && buff == 3)
    {
        survive = 1;
    }

    return survive;
}
