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
    for (int i = 0; i < boardSize; i++) 
    {
        for (int j = 0; j < boardSize; j++)
        {
            board[i][j] = new Cell(); //Creating new cell
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

    int i = 0; 
    string temp;
    ifstream fin;
    fin.open(fileName);
    //Read file by line
    while (getline(fin, temp) && i < boardSize)
    {
        for (int j = 0; j < boardSize && j < temp.size(); j++)
        {
            Cell* someCell = new Cell();
            someCell -> state = (temp[j] == '1'); 
            someCell -> x = i;
            someCell -> y = j;
            board[i][j] = someCell;
        }
        //Move to next line
        i++; 
    }
    fin.close();
}

/*
Function to print out all cells 
*/
void printCells(Cell* board[][10], int boardSize)
{
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardSize; j++)
        {
           char cellState = board[i][j] -> state ? '1' : '0';   // Assigns the state to True if '1'. . If false, '0'
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
    // Initialize x and y
    int x,y; 

    // Set number of live neighbors for the current cell to 0
    curCell -> numLiveNeighbors = 0; 
    curCell -> x; 
    curCell -> y; 

    /*Loop through 3x3 grid. C = curCell
    x x x
    x C x
    x x x
    */

    for (int dx = -1; dx <= 1; dx++)
    {
        for (int dy = -1; dy <= 1; dy++)
        {
            if (dx ==0 && dy ==0)
            {
                //Current cell and continue
                continue; 
            }
            int neighbor_x = x + dx;
            int neighbor_y = y + dy; 

            //Check 
            if (neighbor_x >= 0 && neighbor_x < boardSize && neighbor_y >= 0 && neighbor_y < boardSize)
            {
                if (board [neighbor_x][neighbor_y] -> state == true)
                {
                    curCell -> numLiveNeighbors += 1; 
                }
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
    bool updatedBoard = false; 
    Cell* newBoard[10][10]; 

    //Initialize newBoard
    for (int i = 0; i < boardSize; i++) 
    {
        for (int j = 0; j < boardSize; j++)
        {
            newBoard[i][j] = new Cell(); //Creating new cell
            newBoard[i][j] -> x = i; 
            newBoard[i][j] -> y = j; 
        }
    }
}

