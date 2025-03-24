#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_FILES 100   // Maximum number of text files to search
#define MAX_FILENAME 256
#define MAX_CONTENT 5000
#define MAX_KEYWORD 50

// Structure to store file name and keyword frequency
typedef struct {
    char filename[MAX_FILENAME];
    int keywordCount;
} FileResult;

// Function to convert string to lowercase
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + ('a' - 'A');
        }
    }
}

// Function to count keyword occurrences in a file
int countKeywordInFile(char *filename, char *keyword) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open file %s\n", filename);
        return -1;
    }

    char content[MAX_CONTENT];
    int count = 0;

    while (fgets(content, MAX_CONTENT, file)) {
        toLowerCase(content);  // Convert file content to lowercase
        char *ptr = content;
        
        // Search for keyword in line
        while ((ptr = strstr(ptr, keyword)) != NULL) {
            count++;
            ptr++;  // Move pointer forward to avoid infinite loop
        }
    }

    fclose(file);
    return count;
}

// Function to sort results based on keyword frequency (Descending Order)
void sortResults(FileResult results[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (results[j].keywordCount < results[j + 1].keywordCount) {
                FileResult temp = results[j];
                results[j] = results[j + 1];
                results[j + 1] = temp;
            }
        }
    }
}

// Function to search for keyword in multiple files
void searchKeyword(char *directory, char *keyword) {
    DIR *dir;
    struct dirent *entry;
    FileResult results[MAX_FILES];
    int fileCount = 0;

    // Open the directory containing text files
    if ((dir = opendir(directory)) == NULL) {
        printf("Error: Could not open directory %s\n", directory);
        return;
    }

    // Convert keyword to lowercase
    toLowerCase(keyword);

    // Read files in the directory
    while ((entry = readdir(dir)) != NULL) {
        if (strstr(entry->d_name, ".txt") != NULL) {  // Check if file is a text file
            char filepath[MAX_FILENAME];
            snprintf(filepath, MAX_FILENAME, "%s/%s", directory, entry->d_name);

            int count = countKeywordInFile(filepath, keyword);
            if (count > 0) {
                strcpy(results[fileCount].filename, entry->d_name);
                results[fileCount].keywordCount = count;
                fileCount++;
            }
        }
    }
    closedir(dir);

    // Sort results based on relevance
    if (fileCount > 0) {
        sortResults(results, fileCount);

        // Display results
        printf("\n🔍 **Search Results for '%s':**\n", keyword);
        printf("---------------------------------------\n");
        for (int i = 0; i < fileCount; i++) {
            printf("📄 File: %s | 🔢 Keyword Count: %d\n", results[i].filename, results[i].keywordCount);
        }
    } else {
        printf("\n❌ No results found for '%s'.\n", keyword);
    }
}

int main() {
    char directory[MAX_FILENAME];
    char keyword[MAX_KEYWORD];

    // Get directory and keyword from user
    printf("Enter directory containing text files: ");
    scanf("%s", directory);
    printf("Enter keyword to search: ");
    scanf("%s", keyword);

    // Perform search
    searchKeyword(directory, keyword);

    return 0;
}
