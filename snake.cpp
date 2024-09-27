#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

bool gameOver;
const int height = 20;
const int width = 40;
int x, y;           // positions for the head of the snake
int fruitx, fruity; // position for the fruit of the snake
int score;

// for the tails
int tailx[100], taily[100]; // array to store the positions of the tail
int ntail;                  // length of the tail

enum eDirection
{
    STOP = 0,
    UP,
    DOWN,
    LEFT,
    RIGHT
};
eDirection dir;

void setup()
{
    gameOver = false;
    dir = STOP;

    // initially, the snake appears in the middle of the game
    x = width / 2;
    y = height / 2;

    // initialize fruit position
    fruitx = rand() % width;
    fruity = rand() % height;

    // reset score and tail length
    score = 0;
    ntail = 0;
}

// Function to move the console cursor to a specific position
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void draw()
{
    gotoxy(0, 0); // Move the cursor to the top-left corner

    // Print top border
    for (int i = 0; i < width; i++)
        cout << "#";
    cout << endl;

    // Print the game board
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0 || j == width - 1)
            {
                cout << "#"; // Print borders
            }
            else if (i == y && j == x)
            {
                cout << "O"; // Print snake head
            }
            else if (i == fruity && j == fruitx)
            {
                cout << "F"; // Print fruit
            }
            else
            {
                bool print = false;

                // Print the tail
                for (int k = 0; k < ntail; k++)
                {
                    if (tailx[k] == j && taily[k] == i)
                    {
                        cout << "o"; // Print tail segment
                        print = true;
                    }
                }

                if (!print)
                    cout << " ";
            }
        }
        cout << endl;
    }

    // Print bottom border
    for (int i = 0; i < width; i++)
        cout << "#";
    cout << endl;

    // Display score
    cout << "Score: " << score << endl;
}

void input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'w':
            dir = UP;
            break;
        case 'a':
            dir = LEFT;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'd':
            dir = RIGHT;
            break;
        default:
            break;
        }
    }
}

void logic()
{
    // Store the previous positions of the head
    int prevX = x;
    int prevY = y;

    // Store the previous positions of the tail
    int prevTailX, prevTailY;
    int tempX, tempY;

    // Move the tail
    if (ntail > 0)
    {
        prevTailX = tailx[0];
        prevTailY = taily[0];
        tailx[0] = prevX;
        taily[0] = prevY;

        for (int i = 1; i < ntail; i++)
        {
            tempX = tailx[i];
            tempY = taily[i];
            tailx[i] = prevTailX;
            taily[i] = prevTailY;
            prevTailX = tempX;
            prevTailY = tempY;
        }
    }

    // Move the head
    switch (dir)
    {
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    default:
        break;
    }

    // Check for collisions with the boundaries
    if (x < 0 || x >= width || y < 0 || y >= height)
        gameOver = true;

    // Check for collisions with the tail
    for (int i = 0; i < ntail; i++)
    {
        if (tailx[i] == x && taily[i] == y)
        {
            gameOver = true;
        }
    }

    // If the snake eats the fruit
    if (x == fruitx && y == fruity)
    {
        score += 10;
        fruitx = rand() % width;
        fruity = rand() % height;
        ntail++; // Increase tail length
    }
}

int main()
{
    setup();
    while (!gameOver)
    {
        draw();
        input();
        logic();
        Sleep(100); // Control game speed
    }

    return 0;
}
