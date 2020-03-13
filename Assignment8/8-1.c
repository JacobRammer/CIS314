/*
 * Jacob Rammer
 * Assignment 8
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    unsigned char data[4];
	unsigned int tag;
	unsigned char valid;
} Line;

typedef struct
{
    Line *lines;
    int numLines;
} Cache;

unsigned int getOffset(unsigned int address)
{
    // 4B blocks, so offset is bits 0-1
    return address & 0x3;
}

unsigned int getSet(unsigned int address)
{
    // 16 sets, so offset is bits 2-6
    return (address >> 2) & 0xF;
}

unsigned int getTag(unsigned int address)
{
    // Offset and set are 6 bits total, so tag is high-order 26 bits
    return address >> 6;

}

Cache* mallocCache(int numLines)
{


    Cache* cache = (Cache*)malloc(16* sizeof(Cache));  // allocate for the cache struct
    cache->numLines = numLines;
    cache->lines = (Line*)malloc(sizeof(int) * numLines);  // allocate for the line struct
    return cache;

}

void freeCache(Cache* cache)
{
    free(cache->lines);
    free(cache);
}

void printCache(Cache* cache)
{
    // TODO - print all valid lines in the cache.

    for(int i = 0; i < 4; i++)
    {
        Line* line = &cache->lines[i];
        if (line->valid)
        {
            unsigned char* tempCahce = line->data;
            //set: 0 - tag: 1 - valid: 1 - data: dd cc 00 00
            printf("Set: %x - tag: %x - valid %u data: %.2x %.2x %.2x %.2x\n", i, line->tag, line->valid, tempCahce[0],
                   tempCahce[1], tempCahce[2], tempCahce[3]);
        }
    }
}

void readValue(Cache* cache, unsigned int address)
{
    // TODO - check the cache for a cached byte at the specified address.
    // If found, indicate a hit and print the byte. If not found, indicate
    // a miss due to either an invalid line (cold miss) or a tag mismatch
    // (conflict miss).

    unsigned int offset = getOffset(address);
    unsigned int set = getSet(address);
    unsigned tag = getTag(address);

    Line* newLine = &cache->lines[set];
    //looking for set: 1 - tag: 0
    printf("Looking for set: %x - tag %x\n", set, tag);
    if (newLine->valid)
    {
        unsigned char* data = newLine->data;
        // found set: 0 - tag: 1 - offset: 0 - valid: 1 - data: dd
        printf("found set: %x - tag: %x - offset: %x - valid: %u - data: %.2x\n",
				set, newLine->tag, offset, newLine->valid, data[offset]);
        if (newLine->tag == tag)  // check the tag to see if they're equal, which is a cache hit
        {
            printf("Hit!\n");
        } else // if the the newline is valid but the tags do not match, it's a miss
            printf("tags don't match - miss!\n");

    } else
        printf("no valid line found - miss!\n");
}

void writeValue(Cache* cache, unsigned int address, unsigned char* newData)
{
    // Calculate set and tag for address
    unsigned int set = getSet(address);
    unsigned int tag = getTag(address);
    // Get pointer to cache line in the specified set
    Line *line = &cache->lines[set];
    // Determine if we have a valid line in the cache that does not contain the
    // specified address - we detect this by checking for a tag mismatch
    if (line->valid && line->tag != tag)
    {
        unsigned char *data = line->data;
        printf("evicting line - set: %x - tag: %x - valid: %u - data: %.2x %.2x %.2x %.2x\n",
               set, line->tag, line->valid, data[0], data[1], data[2], data[3]);
    }

    // Copy new data to line (could use memcpy here instead)
    for (int i = 0; i < 4; ++i)
        line->data[i] = newData[i];
    // Update line tag, mark line as valid
    line->tag = tag;
    line->valid = 1;
    printf("wrote set: %x - tag: %x - valid: %u - data: %.2x %.2x %.2x %.2x\n",
           set, line->tag, line->valid, newData[0], newData[1], newData[2], newData[3]);


}

int main()
{

    Cache *cache = mallocCache(16);

	// Loop until user enters 'q'
	char c;
	do {
		printf("Enter 'r' for read, 'w' for write, 'p' to print, 'q' to quit:");
		scanf(" %c", &c);
		if (c == 'r') {
			printf("Enter 32-bit unsigned hex address:");\
			unsigned int a;
			scanf(" %x", &a);

			readValue(cache, a);
		} else if (c == 'w') {
			printf("Enter 32-bit unsigned hex address:");

			unsigned int a;
			scanf(" %x", &a);

			printf("Enter 32-bit unsigned hex value:");

			unsigned int v;
			scanf(" %x", &v);

			// Get byte pointer to v
			unsigned char *data = (unsigned char *)&v;
			writeValue(cache, a, data);
		} else if (c == 'p') {
			printCache(cache);
		}
	} while (c != 'q');

	freeCache(cache);
    return 0;
}