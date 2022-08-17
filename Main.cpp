/**
 * @file Main.cpp
 * @author Adrian Szczepanski
 * @date 17-08-2022
 * @brief 
 * @details
 */

#include <cstdio>
#include <cerrno>
#include <cstdlib>

static constexpr auto DEFAULT_ROW_WIDTH = 16;
static constexpr auto DEFAULT_SIZE = 64;
static const char* defaultFileName = "/dev/random";

int main(int argc, char** argv)
{
    auto fileName = defaultFileName;
    auto size = DEFAULT_SIZE;

    if(argc >= 2)
        fileName = argv[1];

    if(argc >= 3)
        size = strtoul(argv[2], nullptr, 0);

    if(size == 0)
    {
        errno = EINVAL;
        perror("");
        exit(EXIT_FAILURE);
    }

    auto file = fopen(fileName, "rb");

    if(file == nullptr)
    {
        perror("");
        exit(EXIT_FAILURE);
    }

    auto counter = 0;
    fputs("{ ", stdout);

    while (counter < size)
    {
        auto byte = fgetc(file);

        if(feof(file))
        {
            fputs("};\r\n", stdout);
            return 0;
        }

        if(ferror(file))
            return 1;

        printf("0x%02x, ", byte);
        counter++;

        if((counter % DEFAULT_ROW_WIDTH) == 0)
            fputs("\r\n", stdout);
    }
    
    fputs("};\r\n", stdout);
    fclose(file);
    return 0;
}