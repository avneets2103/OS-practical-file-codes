// Write a program to simulate Second Chance page replacement algorithm.

#include <stdio.h>
#include <stdlib.h>
#define MAX_FRAMES 10     // maximum number of frames
#define MAX_PAGES 20      // maximum number of pages
int frames[MAX_FRAMES];   // frames to hold pages
int ref_bits[MAX_FRAMES]; // reference bits for each frame
int main()
{
    int pages[MAX_PAGES]; // array to hold page references
    int num_pages;        // number of page references
    int num_frames;       // number of frames allocated
    int page_faults = 0;  // count of page faults
    int frame_ptr = 0;    // pointer to the frame to be replaced
    printf("Enter the number of page references: ");
    scanf("%d", &num_pages);
    printf("Enter the page references: ");
    for (int i = 0; i < num_pages; i++)
    {
        scanf("%d", &pages[i]);
    }
    printf("Enter the number of frames: ");
    scanf("%d", &num_frames);
    // initialize frames and reference bits to -1 (empty frame)
    for (int i = 0; i < num_frames; i++)
    {
        frames[i] = -1;
        ref_bits[i] = 0;
    }
    // iterate over the page references
    for (int i = 0; i < num_pages; i++)
    {
        int page = pages[i];
        int found = 0; // flag to indicate if page is found in frames
        // check if page is already in a frame
        for (int j = 0; j < num_frames; j++)
        {
            if (frames[j] == page)
            {
                ref_bits[j] = 1; // set reference bit to 1
                found = 1;
                break;
            }
        }
        // if page is not found in frames, replace a frame using second chancealgorithm
        if (!found)
        {
            while (1)
            {
                if (ref_bits[frame_ptr] == 0)
                { // if reference bit is 0, replace frame
                    frames[frame_ptr] = page;
                    ref_bits[frame_ptr] = 1;
                    page_faults++;
                    frame_ptr = (frame_ptr + 1) % num_frames; // move frame pointer to next frame 
                    break;
                }
                else
                {
                    ref_bits[frame_ptr] = 0;                  // set reference bit to 0
                    frame_ptr = (frame_ptr + 1) % num_frames; // move frame pointer to next frame
                }
            }
        }
        // print the current state of frames
        printf("Page %d: ", page);
        for (int j = 0; j < num_frames; j++)
        {
            if (frames[j] == -1)
            {
                printf("- ");
            }
            else
            {
                printf("%d ", frames[j]);
            }
        }
        printf("\n");
    }
    printf("Total page faults: %d\n", page_faults);
    return 0;
}