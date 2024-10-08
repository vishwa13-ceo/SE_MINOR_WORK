#include <stdio.h>
#include <fcntl.h>   // for open(), O_RDONLY, O_WRONLY
#include <unistd.h>  // for read(), write(), close()

int main() {
    // Open the input file in read mode
    int inputFile = open("input.txt", O_RDONLY);
    if (inputFile < 0) {
        // If there's an error opening the file, print this message
        printf("Error: Can't open input file\n");
        return 1;
    }

    // Open the output file in write mode (or create it if not there)
    int outputFile = open("output.txt", O_WRONLY | O_CREAT, 0644);
    if (outputFile < 0) {
        // If there's an error opening/creating the output file
        printf("Error: Can't open or create output file\n");
        close(inputFile);  // Close the input file since it was opened successfully
        return 1;
    }

    // Buffer to store the file contents
    char buffer[100];
    int bytesRead;

    // Read from the input file and write to the output file
    while ((bytesRead = read(inputFile, buffer, sizeof(buffer))) > 0) {
        write(outputFile, buffer, bytesRead);
    }

    // Close both files after the operation is done
    close(inputFile);
    close(outputFile);

    // Let the user know the copying is done
    printf("File copy completed successfully!\n");
    return 0;
}
