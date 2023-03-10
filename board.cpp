#include <iostream>
#include <string>
using namespace std;


class Piece{
    private:
    public:
    string type;
    bool color;
    int x;
    int y;
    int id;

    
    Piece(int x, int y, string type, bool color) : x(x), y(y), type(type), color(color) {}
    void move(int new_x, int new_y) {
        x = new_x;
        y = new_y;
    }
};

class Pawn : public Piece{
    private:
    public:
    Pawn(int x, int y, bool color) : Piece(x, y, "pawn", color){}

};


class Board {
    private:
    public: 
    Piece* board[8][8];

    Board(){
        for(int x = 0; x < 8; x++) {
            for(int y = 0; y < 8; y++) {
                board[x][y] = nullptr; // Initialize the element to a null pointer
            }
        }
    }
    void add_pieces(){
        for(int x = 0; x < 8; x++) {
            for(int y = 0; y < 8; y++) {
                if (x == 1){
                    board[x][y] = new Pawn(x, y, 0);
                }
                else if (x == 6) {
                    board[x][y] = new Pawn(x, y, 1);
                }
            }
        }
    }

    void show_board(){
        for(int x = 0; x < 8; x++) {
            for (int y = 0; y < 8; y++) {
                if (board[x][y] != nullptr) { // Check whether the pointer is a null pointer
                    cout << board[x][y]->type << " ";
                } else {
                    cout << "**** "; // Print a blank space if the pointer is a null pointer
                }
            }
            cout << endl;
        }
    }

};

int main() {
    Board board1;
    board1.show_board();
    cout << endl << endl << endl;
    board1.add_pieces();
    board1.show_board();
}