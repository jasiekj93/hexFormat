
/**
 * @file hexSequence.cpp
 * @author Adrian Szczepanski
 * @date 17-08-2022
 * @brief 
 * @details
 */

#include <cstdio>
#include <cerrno>
#include <cstdlib>

static constexpr auto DEFAULT_ROW_WIDTH = 16;
static constexpr auto DEFAULT_START_NUMBER = 0;
static constexpr auto DEFAULT_END_NUMBER = 64;
static constexpr auto DEFAULT_INCREMENT = 1;

int main(int argc, char** argv)
{
    auto startNumber = DEFAULT_START_NUMBER;
    auto endNumber = DEFAULT_END_NUMBER;
    auto increment = DEFAULT_INCREMENT;

    if(argc == 2)
    {
        endNumber = strtoul(argv[1], nullptr, 0);
    }
    else if(argc >= 3)
    {
        startNumber = strtoul(argv[1], nullptr, 0);
        endNumber = strtoul(argv[2], nullptr, 0);
    }

    if(argc >= 4)
        increment = strtoul(argv[3], nullptr, 0);

    if(endNumber == 0 
        || startNumber > endNumber
        || increment == 0)
    {
        errno = EINVAL;
        perror("");
        exit(EXIT_FAILURE);
    }

    fputs("{ ", stdout);
    auto printedCount = 0;

    for(auto i = startNumber; i <= endNumber; i += increment)
    {
        printf("0x%02x, ", startNumber + i);
        printedCount++;

        if((printedCount % DEFAULT_ROW_WIDTH) == 0 && (i > 0))
            fputs("\r\n", stdout);
    }
    
    fputs("};\r\n", stdout);
    return 0;
}