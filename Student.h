class Student{


  int waitTime;
  int windowtime;
  int avgwindowtime;
  int arrivaltime;

public:

  Student(){
    arrivaltime = 0;
    windowtime = 0;
    avgwindowtime = 0;
    waitTime =0;
  }
  void print(){
  cout<< "S arrivaltime: "  << arrivaltime<< endl;
  cout<< "S windowtime: "  << windowtime<< endl;
  cout<< "S waitTime: "<< waitTime<<endl;
  cout<< "----------"<<endl;
  }
  int getW(){
    return windowtime;
  }
  int getA(){
  return arrivaltime;
}
int getAv(){
return avgwindowtime;
}

void setA(int a){
 arrivaltime = a;
}
void setW(int w){
 windowtime = w;
}

void setAv(int av){
 avgwindowtime = av;
}


void setwaitime(int w){

  waitTime += w;
}



int getWaittime(){

  return waitTime;
}




//Window intreface

void setisAvailable(bool v){
  ;
}
bool getisAvailable(){
  return true;
}
void setidle(int i){
  ;
}
int getidle(){
  return 0;
}



};
