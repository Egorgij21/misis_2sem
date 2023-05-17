#include <iostream>
#include <vector>

class Rect{
public:
int LTX = 0;
int LTY = 0;
int RBX = 0;
int RBY = 0;
std::vector< std::vector<int> > field;
public:
    Rect(){
        std::vector<int> a (0);
        field.push_back(a);
        field[0][0] = 0;
    }
    Rect(int LTX_input, int LTY_input, int RBX_input, int RBY_input){
        if(RBX_input - LTX_input == RBY_input - LTY_input){
            throw("Rect is not a square");
        }
        if(RBX_input - LTX_input == 0 || RBY_input - LTY_input == 0){
            throw("Wrong input");
        }
        std::vector<int> a (RBX_input + 2);
        for(int i = 0; i < RBY_input + 2; i++){
            field.push_back(a);
        }
        std::vector<int> row (0);
        std::vector<int> col (0);
        for(int i = 0; i < RBX_input + 2; i++){
            if(i < LTX_input || i > RBX_input){
                row.push_back(0);
            }
            else{
                row.push_back(1);
            }
        }
        for(int i = 0; i < RBY_input + 2; i++){
            if(i < LTY_input || i > RBY_input){
                row.push_back(0);
            }
            else{
                row.push_back(1);
            }            
        }
        field[LTX_input] = row;
        field[RBX_input] = row;  
        field[LTY_input] = col;
        field[RBY_input] = col;  
    }
    void show(Rect& rect){
        for(int col_count = 0; col_count < rect.field.size(); col_count++){
            for(int row_count = 0; row_count < field[col_count].size(); row_count++){
                std::cout << field[col_count][row_count];
            }
            std::cout << std::endl;
        }
    }
};

class Square{
public:
int LTX = 0;
int LTY = 0;
int RBX = 0;
int RBY = 0;
std::vector< std::vector<int> > field;
public:
    Square(){
        std::vector<int> a (0);
        field.push_back(a);
        field[0][0] = 0;
    }
    Square(int LTX_input, int LTY_input, int RBX_input, int RBY_input){
        if(RBX_input - LTX_input != RBY_input - LTY_input){
            throw("Square is not a rect");
        }
        if(RBX_input - LTX_input == 0 || RBY_input - LTY_input == 0){
            throw("Wrong input");
        }
        std::vector<int> a (RBX_input + 2);
        for(int i = 0; i < RBY_input + 2; i++){
            field.push_back(a);
        }
        std::vector<int> row (0);
        std::vector<int> col (0);
        for(int i = 0; i < RBX_input + 2; i++){
            if(i < LTX_input || i > RBX_input){
                row.push_back(0);
            }
            else{
                row.push_back(1);
            }
        }
        for(int i = 0; i < RBY_input + 2; i++){
            if(i < LTY_input || i > RBY_input){
                row.push_back(0);
            }
            else{
                row.push_back(1);
            }            
        }
        field[LTX_input] = row;
        field[RBX_input] = row;  
        field[LTY_input] = col;
        field[RBY_input] = col;  
    }
    void show(Square& square){
        for(int col_count = 0; col_count < square.field.size(); col_count++){
            for(int row_count = 0; row_count < field[col_count].size(); row_count++){
                std::cout << field[col_count][row_count];
            }
            std::cout << std::endl;
        }
    }
};

class Quad{

};

int main(){
    //Rect my_rect(2, 3, 5, 7);
    Square my_square(0, 0, 2, 2);
    auto f = my_square.field;
    //std::cout << f[2].size();
    /*
    std::vector<int> a (2 + 1);
    for(int i = 0; i < a.size(); i++){
        std::cout << a[i];
    }
    */
    for(int i = 0; i < f.size(); i++){
        for(int j = 0; j < f[i].size(); j++){
            std::cout << f[i][j];
        }
        std::cout << std::endl;
    }
    //my_square.show(my_square);
}