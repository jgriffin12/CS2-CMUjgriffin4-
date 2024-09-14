#include "gameOfLife.h"

/*
Function to clear terminal depending on OS
*/
void clearScreen()
{
    // use "cls" in windows and "clear" command in Mac and Linux
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

/*
Function to initialize all cells in the board.
Takes in 2D array of pointers and size of array
Should create structs and populate the array
*/

void initCells(Cell* board[][10], int boardSize)
{
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 4; j++){
            board[i][j] = 0; 
        }
    }
}

/*
Function to read the board from a file
Prompt for the file to read inside of the function
Structure of file should consist of 10 lines of 0 or 1 to indicate cell state
*/
void readBoard(Cell* board[][10], int boardSize) 
{
    // I wasn't sure if we needed the user to enter file name? 
    string fileName;
    cout << "Please enter the file name of the board you would like to read: ";
    cin >> fileName;

    string temp;
    ifstream fin;
    fin.open(fileName);
    while (!fin.eof())
    {
        for (int i = 0; i < boardSize; i++)
        {
            for (int j = 0; j < boardSize; j++)
            {
                fin >> temp;
                Cell* someCell = new Cell();
                someCell -> state = temp[j];
                someCell -> x = i;
                someCell -> y = j;
                board[i][j] = someCell;
            }
        }
    }
    fin.close();
}

/*
Function to print out all cells to cout -- watch videos on how to use pointer in 2d array (currently printing memory address instead of value). 
Figure out how to dereference values correctly.
*/
void printCells(Cell* board[][10], int boardSize)
{
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardSize; j++)
        {
           char cellState = board[i][j] -> state;      // Converts ASCII 48 to "0"
           cout << cellState;
        }
        cout << endl;
    }
}

/*
Function to count the number of live neighbors for each cell.
Must use the x, y position stored with each cell to determine which neighbors they have
*/
void findNumNeighbors(Cell* board[][10], int boardSize, Cell* curCell) 
{
    int count = 0;          // Start tracking number of live cells (<2: cell dies, 2+3: cell lives to next gen, 3<: cell dies from overpopulation, = 3: becomes live cell )
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardSize; j++)
        {
            if (board[i][j] -> state = 1)
            {
                count += 1; 
            }
        }
    }
}

/*
Function to update each cell's state based on number of neighbors
Must use following rules:

Any live cell with fewer than two live neighbors dies, as if by underpopulation.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by overpopulation.
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

Return if you updated cells or not to break out of while loop from main.
*/
bool updateCellState(Cell* board[][10], int boardSize) 
{
    return false;
}