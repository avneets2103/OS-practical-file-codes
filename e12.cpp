// Simulating FIFO Page Replacement Algorithm
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int frames, pages, faults = 0, pointer = 0, flag1, flag2, i, j, k;
    printf("Enter number of frames: ");
    scanf("%d", &frames);
    int *ref_string = (int *)malloc(frames * sizeof(int));
    int *memory = (int *)malloc(frames * sizeof(int));
    int *flag = (int *)malloc(frames * sizeof(int));
    for (i = 0; i < frames; i++)
    {
        memory[i] = -1;
        flag[i] = 0;
    }
    printf("Enter number of pages: ");
    scanf("%d", &pages);
    int *page_string = (int *)malloc(pages * sizeof(int));
    printf("Enter the reference string: ");
    for (i = 0; i < pages; i++)
        scanf("%d", &page_string[i]);
    for (i = 0; i < pages; i++)
    {
        flag1 = flag2 = 0;
        for (j = 0; j < frames; j++)
        {
            if (memory[j] == page_string[i])
            {
                flag[j] = 1;
                flag1 = flag2 = 1;
                break;
            }
        }
        if (flag1 == 0)
        {
            for (j = 0; j < frames; j++)
            {
                if (memory[j] == -1)
                {
                    faults++;
                    memory[j] = page_string[i];
                    flag2 = 1;
                    break;
                }
            }
        }
        if (flag2 == 0)
        {
            flag[pointer] = 0;
            faults++;
            memory[pointer] = page_string[i];
            pointer++;
            if (pointer == frames)
                pointer = 0;
        }
        printf("\n");
        for (j = 0; j < frames; j++)
        {
            printf("%d\t", memory[j]);
        }
    }
    printf("\n\nTotal Page Faults = %d", faults);
    return 0;
}
