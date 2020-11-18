# include "DLinkedList.h"
# include <fstream>
# include "Student.h"
# include "Window.h"
# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
# include "Simulation.cpp"
using namespace std;

int main(int argc, char const *argv[]) {
// Creating required data structures
  DubLinkList<Student> * StudentQueue = new DubLinkList<Student>();
  DubLinkList<Window> * WindowQueue = new DubLinkList<Window>();
  DubLinkList<Student> * statQueue = new DubLinkList<Student>();


  if(argc != 2){
    std::cout << "Usage:" << argv[0]<< "inputfile.txt"<< endl;
  }
else{
  int num = reader(argv[1], StudentQueue);
  std::cout << "---------" << '\n';
  StudentQueue-> print();
  std::cout << "---------" << num << '\n';

// Adding to window queue
  for( int i=0; i <num;i++){
    WindowQueue->insertAtTail(Window());
  }
}
//Calling simulator
  simulator(StudentQueue, WindowQueue, statQueue);



  return 0;
}
