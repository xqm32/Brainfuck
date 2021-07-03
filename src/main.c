#include <stdio.h>
#include <string.h>

int main() {
    char program[1000];
    char memory[1000];
    char *prog_ptr=program, *mem_ptr=memory;
    FILE *src=fopen("bf.bf", "r");
    memset(program, 0, 1000);
    memset(memory, 0, 1000);
    fread(program, sizeof(char), 1000, src);
    for (; *prog_ptr!='\0'; ++prog_ptr) {
        switch (*prog_ptr)
        {
        case '>':
            ++mem_ptr;
            break;
        case '<':
            --mem_ptr;
            break;
        case '+':
            ++*mem_ptr;
            break;
        case '-':
            --*mem_ptr;
            break;
        case '.':
            putchar(*mem_ptr);
            break;
        case ',':
            *mem_ptr=getchar();
            break;
        case '[':
            if (*mem_ptr!=0)
                break;
            ++prog_ptr; // 从下一个指令开始判断
            for (int i=1; i!=0; ++prog_ptr) {
                if (*prog_ptr==']')
                    --i;
                else if (*prog_ptr=='[')
                    ++i;
            }
            break;
        case ']':
            if (*mem_ptr==0)
                break;
            --prog_ptr; // 从下一个指令开始判断
            for (int i=1; i!=0; --prog_ptr) {
                if (*prog_ptr=='[')
                    --i;
                else if (*prog_ptr==']')
                    ++i;
            }
            break;
        default:
            break;
        }
    }
}