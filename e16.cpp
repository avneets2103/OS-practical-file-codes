// Writing a Program to Simulate Enhanced Second Chance Page Replacement Algorithm
#include <stdio.h>
#include <stdlib.h>
#define MAX_FRAMES 100
#define MAX_PAGES 1000
// A page structure with a page number and a reference bit
typedef struct
{
    int page_number;
    int reference_bit;
} Page;
int main()
{
    int num_frames, num_pages, i, j, k, page_faults = 0;
    Page pages[MAX_PAGES], frames[MAX_FRAMES];
    printf("Enter the number of frames: ");
    scanf("%d", &num_frames);
    printf("Enter the number of pages: ");
    scanf("%d", &num_pages);
    printf("Enter the page numbers: ");
    for (i = 0; i < num_pages; i++)
    {
        scanf("%d", &pages[i].page_number);
        pages[i].reference_bit = 0;
    }
    // Initialize frames to -1
    for (i = 0; i < num_frames; i++)
    {
        frames[i].page_number = -1;
        frames[i].reference_bit = 0;
    }
    // Loop through each page
    for (i = 0; i < num_pages; i++)
    {
        // Check if the page is already in a frame
        for (j = 0; j < num_frames; j++)
        {
            if (frames[j].page_number == pages[i].page_number)
            {
                frames[j].reference_bit = 1; // Set reference bit to 1
                break;
            }
        }
        // If the page is not in a frame
        if (j == num_frames)
        {
            int min_index = 0;
            int min_reference_bit = frames[min_index].reference_bit;
            // Find the page with the smallest reference bit in the frames
            for (k = 1; k < num_frames; k++)
            {
                if (frames[k].reference_bit < min_reference_bit)
                {
                    min_index = k;
                    min_reference_bit = frames[k].reference_bit;
                }
            }
            // Replace the page in the frame with the smallest reference bit
            frames[min_index].page_number = pages[i].page_number;
            frames[min_index].reference_bit = 0;
            page_faults++;
        }
        // Shift the reference bits of all pages in the frames to the right
        for (j = 0; j < num_frames; j++)
        {
            frames[j].reference_bit >>= 1;
        }
    }
    printf("Number of page faults: %d\n", page_faults);
    return 0;
}
