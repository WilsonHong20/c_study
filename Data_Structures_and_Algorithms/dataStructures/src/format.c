#include "../include/format.h"

void print_string(const char* str){
    printf("String: %s\n",str);
}
void print_interger(int num){
    printf("Interger: %d\n",num);
}
void print_float(float num){
     printf("Float: %f\n",num);
}
void print_array(int size,int arr[]){
     printf("Array: ");
     for (int i = 0; i < size; i++)
     {
        printf("%d ", arr[i]);
     }
     printf("\n");
}
void va_format(const char* format, ...){
    va_list args;
    va_start(args,format);

    for (; *format != '\0';  format++)
    {
        switch (*format)
        {
        case 's':
            print_string(va_arg(args,const char*));
            break;
        case 'd':
            print_interger(va_arg(args,int));
            break;
        case 'f':
            print_float(va_arg(args,double));
            break;
        case 'a':
            print_array(va_arg(args,int),va_arg(args,int*));
            break;      
        default:
            printf("Unknown type\n");
            break;
        }
    }
    va_end(args);
}
