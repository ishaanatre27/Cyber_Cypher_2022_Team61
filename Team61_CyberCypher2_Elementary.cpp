#include <iostream>
using namespace std;

int checkEVStationUrban(float pop, float ar, float v){
  float density = pop/ar;
  if(density>1000){
    if(v>300){
      cout << "A high number of level 3 charging station can be depoloyed in this area"<<endl;
      return 0;
    }
    else {
      cout << "A high number of level 2 charging stations can be deployed in this area"<<endl;
      return 0;
    }
  }
  else{
    if(v>300){
      cout << "A few level 3 charging stations can be deployed in this area"<<endl;
    }
    else{
      cout << "A few level 2 charging stations can be deployed in this area"<<endl;
    }
  }
}
int checkEVStationRural(float pop,float ar,bool x,bool y){
  if(x){
    if(pop>20000){
      cout << "A high number of Level 3 charging stations can be deployed in this village"<<endl;
      return 0;
    }
    else{
      cout << "A few level 3 charging stations can be deployed in this village"<<endl;
    }
  }
  else if(y){
    if(pop>20000){
      cout << "A high number of Level 2 charging stations can be deployed in this village"<<endl;
      return 0;
    }
    else{
      cout << "A few level 2 charging stations can be deployed in this village"<<endl;
    }
  }
}

int main(){
  float populationUrban,populationRural,area,voltage;
  int var=1;
  bool p,s;
  char ans,ans2,var2;
  while (var){
  cout << "Do you want to check if Energy Station can be deployed in an Urban or Rural Region(U/R): ";
  cin >> ans;
  if(ans == 'U'){
    cout << "Enter Polulation of the City: ";
    cin >> populationUrban;
    cout << "Enter approx Area of the City(km^2): ";
    cin >> area;
    cout << "Enter voltage to be provided to the station: ";
    cin >> voltage;
    checkEVStationUrban(populationUrban,area,voltage);
  }
  else if(ans == 'R'){
      cout << "Enter Population of the Village: ";
      cin >> populationRural;
      cout << "Enter Area of the Village(km^2): ";
      cin >> area;
      cout << "Is a power grid available(Y/N): ";
      cin >> var2;
      if(var2 == 'Y'){
        p = 1;
      }
      else {
        p = 0;
      }
      cout << "Is solar power available(Y/N): ";
      cin >> var2;
      if(var2 == 'Y'){
        s = 1;
      }
      else {
        s = 0;
      }
      if (!p && !s){
        cout << "No charging station can be deployed here"<<endl;
        continue;
      }
      if (p){
        checkEVStationRural(populationRural,area,p,0);
      }
      else if(s){
        checkEVStationRural(populationRural,area,0,s);
      }
    }
    else{
      cout << "Enter valid output"<<endl;
      continue;
    }
  cout << "Do you want to check again for another place?(Y/N): ";
    cin >> ans2;
  if(ans2 == 'Y'){
    var = 1;
    continue;
  }
    else if (ans2 == 'N'){
      cout << "Thank You for using our program."<<endl;
      break;
    }
  }

  return 0;
}
