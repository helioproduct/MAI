#include <stdio.h>

int main()
{
    int matrix[7][7];
    int size;
    scanf("%d", &size);
    
    for (int i = 0; i < size; i++) 
        for (int j = 0; j < size; j++) 
            scanf("%d", &matrix[i][j]);

    enum State {
        START,
        LEFT,
        UP,
        RIGHT,
        DOWN,
        FINISH,
    } state = START;
            
    int i, j, offset, position;
    int result[7][7];
            
    while (state != FINISH)
    {                
        switch (state)
        {
        case START:
            i = j = size - 1;
            offset = 0;
            position = 0;
            state = LEFT;
            break;
        
        case LEFT:
            if (j == offset)
                state = UP; 
            else
            {
                j--; 
                position++;       
            }
            break;
        
        case UP:
            if (i == offset)
                state = RIGHT;
            else
            {
                i--;  
                position++;  
            }
            break;
        
        case RIGHT:
            if (j == size - 1 - offset)
            {
                state = DOWN;
                offset++;
            } 
            else
            {
                j++;
                position++;
            }
            break;
        
        case DOWN:
            if (i == size - 1 - offset)
                state = LEFT;
            else
            {
                i++;
                position++;            
            }
            break;
        }

        result[position / size][position % size] = matrix[i][j];   

        if (position == size * size - 1)
        {
            state = FINISH;
        }    
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", result[i][j]);
        }
    }    
}
