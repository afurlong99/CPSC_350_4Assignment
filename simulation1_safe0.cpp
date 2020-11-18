# include "DoublyLinkedList.h"
# include <fstream>
# include "Student.h"
# include "Window.h"
# include <iostream>
# include <string>

using namespace std;

  int reader(const char * fname, DubLinkList<Student> * StudentQueue){
  string line;
  int numOpenWindows;
  int arrivaltime;
  int windowtime;
  int NumNewStudent;
  Student newstudent;
  std::cout << fname << '\n';
  fstream inputfile;
   inputfile.open(fname);
  if(inputfile.is_open()){
    std::cout << "reading" << '\n';

  inputfile >> numOpenWindows;

  inputfile >> arrivaltime;
  while(inputfile.eof() != true){
    inputfile >> NumNewStudent;
    int count;
    count = NumNewStudent;
    while(count > 0){
        newstudent.setA(arrivaltime);
        inputfile >> windowtime;
        newstudent.setW(windowtime);
        StudentQueue->insertAtTail(newstudent);
        count--;
    }
    inputfile >> arrivaltime;
  }
  return numOpenWindows;
 }
}

void stat(DubLinkList<Window> * WindowQueue, DubLinkList<Student> * statQueue){
  int totalwaittime =0;
  Node<Student>* curr = statQueue->getFrontNode();
  while(curr != nullptr){
    Student student = curr -> data;
    std::cout << "Each student wait time: "<<student.getWaittime() << '\n';
    totalwaittime += student.getWaittime();
    curr = curr->next;
  }
  std::cout << "Total wait time: "<<totalwaittime << '\n';
}

void simulator(DubLinkList<Student> * StudentQueue,   DubLinkList<Window> * WindowQueue, DubLinkList<Student> * statQueue){
  int simtime =20;
  int clocktic =0;
  int servistime = -1;
  int windowStarttime = -1;

  while((clocktic < simtime) && (!StudentQueue->AllStudentdone())){
    
    std::cout <<"clocktick: " <<clocktic << '\n';

    if(clocktic == (windowStarttime+servistime)){
      WindowQueue->Assign(true);
    }
    bool firstAvailable = WindowQueue->isAvailable();

    if(firstAvailable == true){
  //    std::cout <<"Window Available: " <<firstAvailable << '\n';

      Student s = StudentQueue-> getFront();
      if(s.getA()<=clocktic){
    //Student Is servised and availbe window is gien to sudent
        std::cout << "ASSIGNING STUDENT TO A WINDOW" << '\n';

      s = StudentQueue->removeFront();
      statQueue->insertAtTail(s);
      windowStarttime = clocktic;
      servistime = s.getW();
      WindowQueue->Assign(false);

      StudentQueue->Setstudentwaittime(clocktic);


      }
      if(s.getA()> clocktic){
        std::cout << "no students but windows are isAvailable idle time ++" << '\n';
        std::cout << "Student arrival time:"<<s.getA()<<endl ;
  //no students but windows are isAvailable idle time ++
        WindowQueue->SetWindowidletime();
      }
    }
    else{
      std::cout << "WINDOW NOT AVAILBE STudents waiting" << '\n';
//For all student in StudentQueue increment wait time
    StudentQueue->Setstudentwaittime(clocktic);
    }
    clocktic++;

    std::cout << "----clocktick----: " << clocktic <<" Number of students remaining: " << '\n';
    StudentQueue-> print();
    std::cout << "---------" << '\n';

  }
  stat(WindowQueue,statQueue);
  std::cout << "getting out of simulator" << '\n';
}

int main(int argc, char const *argv[]) {
  int * serviswindows = 0;
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


  for( int i=0; i <num;i++){
    WindowQueue->insertAtTail(Window());
  }
}

std::cout << "in main about to cal sim" << '\n';
  simulator(StudentQueue, WindowQueue, statQueue);



  return 0;
}
