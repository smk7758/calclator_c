#include "calclator.h"

int main(int argc, char** argv) {
    // vec_t* line_vec = vec_new();
    char line[DEFAULT_LINE_SIZE];
    int size = 0;
    if (argc > 1) {
        printf("FILE READ: %s \n",  argv[1]);

        FILE* fpo;
        if ((fpo = fopen(argv[1], "r")) == NULL) {
            printf("[Error] cannot open the file: %s \n", argv[1]);
        } else {
            fscanf(fpo, "%s", line);
            fclose(fpo);
        }
        printf("contents: %s \n", line);

        Node *root = parse(line);

        const int result = eval(root);

        printf("%s = %d \n", line, result);

        FILE* fpw;
        char* file_write_name = strcat(argv[1], "_out");
        if ((fpw = fopen(file_write_name, "w")) == NULL) {
            printf("[Error] cannot open the file: %s \n", argv[1]);
        } else {
            fprintf(fpw, "%d", result);
            fclose(fpw);
        }
    } else {
        scanf("%s", line);

        Node *root = parse(line);

        const int result = eval(root);

        printf("%s = %d \n", line, result);
    }

    return 0;
}
