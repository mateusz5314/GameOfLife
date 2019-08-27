#pragma once
#include <vector>

class mechanic
{
    protected:
        int check_state( std::vector <std::vector<int> > board, int id_x, int id_y);
        int check_show( std::vector <std::vector<int> > board, 
                int id_x, int id_y, int state);
        void show_board( std::vector <std::vector<int> > board,
                int size_x, int size_y);
        void set_vector(std::vector <std::vector<int> > board, int size_x, int size_y);
    public:
        void game();
};