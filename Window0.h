class Window{

bool isAvailable;
int idle;
public:

Window(){
    isAvailable = true;
    idle = 0;
  }
void setisAvailable(bool v){
  isAvailable = v;
}
bool getisAvailable(){
  return isAvailable;
}
void setidle(int i){
  idle += i;
}
int getidle(){
  return idle;
}

//Student interface
void print(){
cout<< "WINDOW Is Available: "  << isAvailable<< endl;
cout<< "WINDOW idle time: "  << idle << endl;
}
int getW(){
  return 0;
}
int getA(){
return 0;
}
int getAv(){
return 0;
}
void setA(int a){
;
}
void setW(int w){
;
}
void setAv(int av){
;
}

void setwaitime(int w){
  ;
}
int getWaittime(){
  ;
}




};
