void initLibrary();
void print(uint64_t* s);
void printString(uint64_t* s);

void println();

uint64_t main() {
  initLibrary();
  printString("12/03/2018");
  print("Hello Selfie");
  println();
}
