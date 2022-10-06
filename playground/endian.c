
#if defined __LITTLE_ENDIAN__
  #define PRINT_VALUE(ptr) (printf("%X.%X.%X.%X\n", ptr[3], ptr[2], ptr[1], ptr[0]))
#elif defined __BIG_ENDIAN__
  #define PRINT_VALUE(ptr) (printf("%X.%X.%X.%X\n", ptr[0], ptr[1], ptr[2], ptr[3]))
#endif

int main() {
  char* ptr = "abcd";
  PRINT_VALUE(ptr);
}
