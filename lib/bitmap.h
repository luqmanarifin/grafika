#ifndef BITMAP__
#define BITMAP__ 1

class Bitmap
{
public:
  Bitmap(void (*fun[5]) (int, int)) {
    printChar = fun;
  }
  ~Bitmap();

  void printText(char* s) {
    for (char *c = s; *c != NULL; ++c) {
      printChar[(*c)-'A']();
    }
  }
  
private:
  void (**printChar) (int, int);
};

#endif
