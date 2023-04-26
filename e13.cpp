// Write a program to simulate LRU page replacement algorithm.

#include <stdio.h>
#include <stdlib.h>
struct PageFrame
{
    int pageNumber;
    int lastAccessTime;
};
int main()
{
    int numPageFrames, numPages, pageFaults = 0;
    printf("Enter the number of page frames: ");
    scanf("%d", &numPageFrames);
    struct PageFrame *frames = (struct PageFrame *)malloc(numPageFrames *
                                                          sizeof(struct PageFrame));
    for (int i = 0; i < numPageFrames; i++)
    {
        frames[i].pageNumber = -1;
        frames[i].lastAccessTime = 0;
    }
    printf("Enter the number of pages: ");
    scanf("%d", &numPages);
    int *pages = (int *)malloc(numPages * sizeof(int));
    printf("Enter the page reference string:\n");
    for (int i = 0; i < numPages; i++)
    {
        scanf("%d", &pages[i]);
    }
    for (int i = 0; i < numPages; i++)
    {
        int j, pageFound = 0;
        for (j = 0; j < numPageFrames; j++)
        {
            if (frames[j].pageNumber == pages[i])
            {
                frames[j].lastAccessTime = i;
                pageFound = 1;
                break;
            }
        }
        if (!pageFound)
        {
            int oldestPage = 0;
            for (j = 0; j < numPageFrames; j++)
            {
                if (frames[j].lastAccessTime < frames[oldestPage].lastAccessTime)
                {
                    oldestPage = j;
                }
            }
            frames[oldestPage].pageNumber = pages[i];
            frames[oldestPage].lastAccessTime = i;
            pageFaults++;
        }
    }
    printf("Number of page faults: %d\n", pageFaults);
    free(frames);
    free(pages);
    return 0;
}