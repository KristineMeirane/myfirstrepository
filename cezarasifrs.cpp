#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

void ierakstisana_txt(string teksts){
ofstream file;
char nosaukums [20];
cout<<"\nIevadiet nosaukumu failam: "<<endl;
cin>>nosaukums;
strcat(nosaukums,".txt");
file.open(nosaukums);
if (!file) {
           cout<<"\nIerakstisanas kluda"; 
		   system("pause>nul"); 
		   exit(1);}
file<<teksts;
file.close();
cout<<"\nFails txt ierakstits!";   
}


string lasisana_txt(string teksts){
ifstream file;
char nosaukums [20];
cout<<"\nIevadiet nosaukumu failam: "<<endl<<endl;
cin>>nosaukums;
strcat(nosaukums,".txt");
file.open(nosaukums);
if (!file) {
           cout<<"\nLasisanas kluda"; 
		   system("pause>nul"); 
		   exit(2);}
file>>teksts;
file.close();
return teksts; 
}


string sifresana (string teksts, int nobide){
string izvads="";
int garums=teksts.length(), i;
for (i=0; i<garums;i++){
	if (teksts[i]>='a' && teksts[i]<='z') {
		teksts[i]=teksts[i]+nobide;
		if (teksts[i] > 'z') teksts[i] = teksts[i] - 'z' + 'a' -1;
		izvads+=teksts[i];
	}
	else if (teksts[i]>='A' && teksts[i]<='Z') {
		teksts[i]=teksts[i]+nobide;
        if (teksts[i] > 'Z') teksts[i] = teksts[i] - 'Z' + 'A' -1;
		izvads+=teksts[i];
	}
	else izvads+=teksts[i];
}
return izvads;	
}


string atsifresana (string teksts, int nobide){
string izvads="";
int garums=teksts.length(), i;
for (i=0; i<garums;i++){
	if (teksts[i]>='a' && teksts[i]<='z') {
		teksts[i]=teksts[i]-nobide;
		if (teksts[i] < 'a') teksts[i] = teksts[i] + 'z' - 'a' +1;
		izvads+=teksts[i];
	}
	else if (teksts[i]>='A' && teksts[i]<='Z') {
		teksts[i]=teksts[i]-nobide;
        if (teksts[i] < 'A') teksts[i] = teksts[i] + 'Z' - 'A' +1;
		izvads+=teksts[i];
	}
	else izvads+=teksts[i];
}
return izvads;	
}


int main(){
char mas[100];
int darbiba, nobide;
string teksts;
do{
  system("cls");
  cout<<"\n\nDarbibu izvelne"<<endl<<endl;
  cout<<"Nr.1    TXT faila ierakstisana"<<endl;
  cout<<"Nr.2    TXT faila lasisana"<<endl;
  cout<<"Nr.3    Sifret konsole"<<endl;
  cout<<"Nr.4    Atsifret konsole"<<endl;
  cout<<"Nr.5    Sifret TXT faila"<<endl;
  cout<<"Nr.6    Atsifret TXT failu"<<endl;
  cout<<"Nr.0    Izeja"<<endl;
  
  cout<<"\nIevadiet darbibas numuru: ";
  cin>>darbiba;
  switch(darbiba){  case 1: cout<<"\nIevadiet tekstu kuru gribat ierakstit txt faila: "<<endl;
                            cin>>teksts;
                            ierakstisana_txt(teksts);
                            system("Pause>nul");
  	                        break;
  	                        
  	                        
  	                case 2: teksts=lasisana_txt(teksts);
  	                        cout<<teksts<<endl;
                            system("Pause>nul");
  	                        break;
  
  
                    case 3: cout<<"\nIevadiet tekstu kuru gribat sifret: "<<endl;
                            cin>>teksts;
                            cout<<"\nIevadiet par cik simboliem gribat sifret: "<<endl;
                            cin>>nobide;
                            teksts=sifresana(teksts, nobide);
                            cout<<"\nSifrets teksts: ";
                            cout<<teksts<<endl;
                            system("Pause>nul");
  	                        break;
  	                        
  	                        
  	                case 4: cout<<"\nIevadiet tekstu kuru gribat atsifret: "<<endl;
                            cin>>teksts;
                            cout<<"\nIevadiet par cik simboliem gribat atsifret: "<<endl;
                            cin>>nobide;
                            teksts=atsifresana(teksts, nobide);
                            cout<<"\nAtsifrets teksts: ";
                            cout<<teksts<<endl;
                            system("Pause>nul");
  	                        break;
  	                
  	                
  	                case 5: cout<<"\nIevadiet tekstu kuru gribat sifret: "<<endl;
                            cin>>teksts;
                            cout<<"\nIevadiet par cik simboliem gribat sifret: "<<endl;
                            cin>>nobide;
                            teksts=sifresana(teksts, nobide);
					        ierakstisana_txt(teksts);
                            system("Pause>nul");
  	                        break;
  	                        
  	                        
  	                case 6: teksts=lasisana_txt(teksts);
  	                        cout<<"\nIevadiet par cik simboliem gribat sifret: "<<endl;
                            cin>>nobide;
                            teksts=atsifresana(teksts, nobide);
                            cout<<"\nAtsifresana: "<<endl;
                            ierakstisana_txt(teksts);
                            system("Pause>nul");
  	                        break;
  	                        
  	            
                    case 0: cout<<"\nProgrammas izeja...";
  	                        system("Pause>nul");
  	                        break;
  	                        
  	                        
                 	default: cout<<"\nTadas darbibas nav!";
                 }
  }
while(darbiba!=0);

system("Pause>nul");
return 0;
}

