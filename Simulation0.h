# include "DoublyLinkedList.h"
# include <fstream>
# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
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
//asigning each line to its corecct varibel
  if(inputfile.is_open()){
    std::cout << "reading" << '\n';

  inputfile >> numOpenWindows;

  inputfile >> arrivaltime;

  // IF ABLE TO READ FILE
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
  int numStudentsMoreThen10 = 0;
  Node<Student>* curr = statQueue->getFrontNode();
  std::vector< int > v;
//looping trough student queue
  while(curr != nullptr){
    Student student = curr -> data;
//Adding to vector to get median at pos
    v.push_back(student.getWaittime());
    totalwaittime += student.getWaittime();
    curr = curr->next;
//Getting wait time over 10 mins
    if(student.getWaittime() >= 10){
      numStudentsMoreThen10++;
    }
    }

    // Mean Student Wait Time
  float avargeWaitTime = totalwaittime/(float)statQueue->getSize() ;
  std::cout << "Avarge wait time: "<< avargeWaitTime << '\n';

    // Median Student Wait Time
    // Sort vector from smallest to largest
  sort(v.begin(), v.end());
    // If Size of Vector is Even
  if (v.size() % 2 == 0){
      std::cout << "Median = " << (v[v.size()/2 - 1] + v[v.size()/2]) / 2 << endl;
        }
    // If size is Odd
  else{
      cout<< "Median = " << v[v.size()/2] << endl;
   }
    for(int i=0; i < v.size(); i++){
    std::cout << v.at(i) << ' ';
  }
    // Longest Student Wait Time
  int n = v.size();
  cout << v[n - 1] << endl;
    // number of students waiting over 10 minutes
  std::cout << "Student Waiting more then 10 minuets: " << numStudentsMoreThen10 <<'\n';



}

void simulator(DubLinkList<Student> * StudentQueue,   DubLinkList<Window> * WindowQueue, DubLinkList<Student> * statQueue){
  int simtime =100;
  int clocktic =0;
  int servistime = -1;
  int windowStarttime = -1;
    // Checking i Queue is empty and that clocktic isless then our simulation time
  while((clocktic < simtime) && (!StudentQueue->AllStudentdone())){

    std::cout <<"clocktick: " <<clocktic << '\n';
    //Condtion to reopen window after used by student
    if(clocktic == (windowStarttime+servistime)){
      WindowQueue->Assign(true);
    }
    bool firstAvailable = WindowQueue->isAvailable();
//if there are open windows available
    if(firstAvailable == true){

      Student s = StudentQueue-> getFront();
      // students who are waiting

      if(s.getA()<=clocktic){
    //Student Is servised and availbe window is gien to sudent
        std::cout << "ASSIGNING STUDENT TO A WINDOW" << '\n';
// Progressing student queue as well as conserving student statistics to stat queue
      s = StudentQueue->removeFront();
      statQueue->insertAtTail(s);
      windowStarttime = clocktic;
      servistime = s.getW();
      WindowQueue->Assign(false);

      StudentQueue->Setstudentwaittime(clocktic);


      }
    // Conditions if no students are available
      if(s.getA()> clocktic){
        std::cout << "no students but windows are is Available idle time ++" << '\n';
  //no students but windows are isAvailable idle time ++
        WindowQueue->SetWindowidletime();
      }
    }
    else{
  // Condition for windows being full
      std::cout << "WINDOW NOT AVAILABLE students waiting" << '\n';
//For all student in StudentQueue increment wait time
    StudentQueue->Setstudentwaittime(clocktic);
    }
    clocktic++;
// Displaying remainder of students as well as current clocktick
    std::cout << "----clocktick----: " << clocktic <<endl;
    std::cout <<" Students remaining: " << '\n';
    StudentQueue-> print();
    std::cout << "---------" << '\n';

  }
// Calling stat function
  stat(WindowQueue,statQueue);
  std::cout << "Getting out of simulator" << '\n';
}
