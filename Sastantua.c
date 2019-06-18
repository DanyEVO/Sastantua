#include <stdio.h>

void sastantua(int num_tiers);
int calc_max_width(int num_tiers);
void put_spaces(int first_half);
void put_characters(int width, int height, int cursor, int current_tier, int num_tiers);

int main()
{
    int num_tiers;
    printf("Insert the number of tiers: ");
    scanf(" %d", &num_tiers);

    sastantua(num_tiers);

    return 0;
}

void sastantua(int num_tiers)
{
    int current_tier;
    int height;
    int width = 1;
    int cursor;

    int max_width = calc_max_width(num_tiers);

    for(current_tier = 1; current_tier <= num_tiers; current_tier++)
    {
        height = current_tier + 2; 
        // Every tier has a height that is with two units bigger: height = tier + 2.

        for(cursor = 0; cursor < height; cursor++)
        {
            width += 2;
            // The width of every line expands with 2 every time: current_width = last_width + 2.
            put_spaces(max_width / 2 - width / 2);
            put_characters(width, height, cursor, current_tier, num_tiers);
            printf("\n");
        }

        width += 4 + 2 * ((current_tier - 2) / 2);
    }
}

int calc_max_width(int num_tiers)
{
   int result = 0;
   int move;

   for(move = 0; move < num_tiers; move++)
   {
       result += (num_tiers + 2) * 2;
   }

   result += (num_tiers + 2) / 2;
   return result;
}

void put_spaces(int first_half)
{
	int space;

	for(space = 0; space < first_half; space++)
	{
		printf(" ");
	}
}

void put_characters(int width, int height, int cursor, int current_tier, int num_tiers)
{
	int position;
	int door = 1 + 2 * ((current_tier - 1) / 2);

	for(position = 0; position < width; position++)
	{
		if(position == 0)
			printf("/");
		else if(position == width - 1)
			printf("\\");
		else
			if(current_tier == num_tiers && position >= (width - door) / 2 
			  && position < (width + door) / 2 && height - cursor <= door)
				if(door >= 5 && cursor == height - door / 2 - 1 && position == (width + door)/2 - 2)
					printf("$");
				else
					printf("|");
			else
				printf("*");	
	}
}



