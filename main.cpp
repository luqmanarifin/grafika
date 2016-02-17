#include <iostream>
#include <fstream>
using namespace std;

int main () {
  ofstream myfile;
  myfile.open ("example.txt");
  int j = 0;
  myfile << "    //Kiri\n";
  for(int i = 0;i < 15;i++) {
	myfile << "    addPoint(Point(420, "<<j<<"));\n";
	j = j + 30;
	myfile << "    addPoint(Point(420, "<<j<<"));\n";
  }
  myfile << "    //Kanan\n";
  for(int i = 0;i < 15;i++) {
	myfile << "    addPoint(Point(540, "<<j<<"));\n";
	j = j - 30;
	myfile << "    addPoint(Point(540, "<<j<<"));\n";
  }
  myfile.close();
  return 0;
}
