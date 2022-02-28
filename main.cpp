#include <iostream>
#include <vector>

// determining the type of a two-dimensional matrix with elements of a boolean type
#define MatrixBool std::vector<std::vector<bool>>

// data film
MatrixBool film;
int n,m;




/*!
 * @brief Initialization of a matrix with the size of N-rows and M-columns.
 * @param n - number of lines.
 * @param m - number of columns.
 * @return Returns a matrix of type 'MatrixBool'.
 */
MatrixBool matrixInit(int n, int m)
{
    MatrixBool matrix;

    matrix.resize(n);
    for(int i=0; i<n; i++)
        matrix[i].resize(m, true);

    return matrix;
}

/*!
 * @brief Printing a bubble matrix into the console.
 */
void filmPrint()
{
    for(int i=0; i<film.size(); i++) {
        for(int j=0; j<film[i].size(); j++)
            std::cout << (film[i][j]?'O':'X');
        std::cout << std::endl;
    }
}

/*!
 * @brief "Popping" bubbles of a rectangular area defined by coordinates (x1,y1)-(x2,y2).
 * @param x1 - the column number of the left edge of the area.
 * @param y1 - the line number of the top edge of the region.
 * @param x2 - the column number of the right edge of the region.
 * @param y2 - the line number of the bottom edge of the area.
 */
void burstingBubbles(int x1, int y1, int x2, int y2)
{
    for(int i=y1; i<=y2; i++)
        for(int j=x1; j<=x2; j++)
            if( film[i][j] ) {
                film[i][j] = false;
                filmPrint();
                std::cout << "Pop!\n";
            }
}

/*!
 * @brief The function of finding out if there are whole bubbles of bubbles.
 * @return Return true if there are integers, false otherwise;
 */
bool areThereAnyBubbles()
{
    for(int i=0; i<film.size(); i++)
        for(int j=0; j<film[i].size(); j++)
            if( film[i][j] )
                return true;
    return false;
}

int main() {
    // size input
    do {
        std::cout << "Enter N, M:";
        std::cin >> n >> m;
    }while( (n<1) || (m<1) );

    // initial
    film = matrixInit(n, m);

    // source output
    filmPrint();

    do{
        int x1,y1, x2,y2;

        // coord input
        while( true ) {
            // input
            std::cout
                << "\nNote:\n"
                << "1) x in [1.." << m << "];\n"
                << "2) y in [1.." << n << "];\n"
                << "3) x1 <= x2 and y1 <= y2;\n"
                << "Enter x1, y1, x2, y2:";
            std::cin >> x1 >> y1 >> x2 >> y2;

            // input validation
            if(    (x1 >= 1) && (x1 <= m) && (y1 >= 1) && (y1 <= n)
                && (x2 >= 1) && (x2 <= m) && (y2 >= 1) && (y2 <= n)
                && (x1 <= x2) && (y1 <= y2) )
            {
                break;
            }

            // error output
            std::cout << "Input error! Try again.\n";
        }

        // bursting
        burstingBubbles(x1-1, y1-1, x2-1, y2-1);

    }while( areThereAnyBubbles() );

    return 0;
}
