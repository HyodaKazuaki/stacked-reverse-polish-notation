// Stacked reverse polish notation
// Copyright (C) HyodaKazuaki
// This program is released under the MIT License.

#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

class Number
{
    private:
        int number;
        Number *preview;
    public:
        Number(int num, Number *prev) {
            number = num;
            preview = prev;
        }

        int getNumber() {
            return number;
        }
        Number* getPreview() {
            return preview;
        }
};

int main(int argc, char *argv[]) {
    int i, j, num, size_arg;
    int num_1, num_2;
    Number *top_number = NULL;
    // Get all command-line args.
    for (i = 1; i < argc; i++){
        // check is arg number?
        if((int)argv[i][0] >= (int)'0' && (int)argv[i][0] <= (int)'9'){
            num = 0;
            // Get number from command-line args.
            size_arg = strlen(argv[i]);
            for (j = 0; j < size_arg; j++){
                num += ((int)argv[i][size_arg - j - 1] - (int)'0') * (int)powf(10, j);
            }
            // set number
            top_number = new Number(num, top_number);
        }
        else {
            // check any operator
            num_2 = top_number->getNumber();
            top_number = top_number->getPreview();
            if(top_number == NULL) {
                printf("Argument error\n");
                return 1;
            }
            num_1 = top_number->getNumber();
            top_number = top_number->getPreview();
            switch(argv[i][0]){
                case '+':
                    num = num_1 + num_2;
                    break;
                case '-':
                    num = num_1 - num_2;
                    break;
                case '*':
                    num = num_1 * num_2;
                    break;
                case '/':
                default:
                    printf("Implemantation Exception.\n");
                    return 1;
            }
            top_number = new Number(num, top_number);
        }
    }
    printf("answer: %d\n", top_number->getNumber());
    return 0;
}
