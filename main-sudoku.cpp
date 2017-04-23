#include <cstdlib>
#include <iostream>
#include <sstream>

using namespace std;

void ausgabe(string alles[9][9])
{
      int i = 0, a =0;
    while(i < 9)
    {
            string zeile = "";
            a = 0;
            while(a<9)
            {
                zeile = zeile + "|"+ alles[i][a];
                a++;       
            }
            cout << zeile << endl;
            cout << "------------------" << endl;
            i++;      
    }
}

bool containsQuader( int startSpalte, int startZeile, string alles[9][9], string str, bool ausgeben)
{
     if(ausgeben){
      cout << "Checke Quader... " << startSpalte << " " << startZeile << endl;}
      int spalte;
      int zeile = startZeile;
      while(zeile < 3 + startZeile)
                {
                      spalte = startSpalte;
                      while(spalte < 3 + startSpalte)
                      {
                              if(alles[zeile][spalte] == str){if(ausgeben){cout << "In Quader " << zeile << " " <<spalte << endl;} return true;}
                              spalte++;        
                      }
                      zeile++;  
                }
                if(ausgeben){
                cout << "nicht in Quader" << endl;}
                return false;
}

bool setzbar(string alles[9][9], int zeile, int spalte, string str, bool ausgeben)
{
      //feld schon besetzt
      if(alles[zeile][spalte] != " "){if(ausgeben){cout << "besetzt" << endl;} return false; }
      
      //zeile nach rechts
      int i = 0;
      while(i < 9)
      {
              if(alles[zeile][i] == str){ if(ausgeben){cout << "in der Horizontalen " << zeile << " " << i << endl;} return false;}     
              i++;   
      }if(ausgeben){cout << "Nicht in der Horizontalen..." << endl;}
      
      //spalte runter
      i = 0;
      while(i < 9)
      {
              if(alles[i][spalte] == str){ if(ausgeben){cout << "In der Vertikalen " << i << " " << spalte << endl;} return false;}   
              i++;     
      } if(ausgeben){cout << "Nicht in der Vertikalen..." << endl;}
      
      bool inQuader = false;
      
      //9er pack
      //erste reihe

      if(spalte < 3 && zeile < 3){inQuader = containsQuader(0,0,alles,str,ausgeben);}
      
      if(spalte < 6 && spalte > 2 && zeile < 3){inQuader = containsQuader(3,0,alles,str,ausgeben);}

      if(spalte > 5 && zeile < 3){inQuader = containsQuader(6,0,alles,str,ausgeben);}
      
      //zweite reihe
      if(spalte < 3 && zeile < 6 && zeile > 2){inQuader = containsQuader(0,3,alles,str,ausgeben);}
      
      if(spalte < 6 && zeile < 6 && zeile > 2 && spalte > 2){inQuader = containsQuader(3,3,alles,str,ausgeben);}

      if(spalte > 5 && zeile < 6 && zeile > 2){inQuader = containsQuader(6,3,alles,str,ausgeben);}
      
      //dritte reihe
      if(spalte < 3 && zeile > 5){inQuader = containsQuader(0,6,alles,str,ausgeben);}
      
      if(spalte < 6 && zeile > 5 && spalte > 2){inQuader = containsQuader(3,6,alles,str,ausgeben);}

      if(spalte > 5 && zeile > 5){inQuader = containsQuader(6,6,alles,str,ausgeben);}
      
      if(inQuader){return false;}
      else{return true;}
}

int main(int argc, char *argv[])
{
    /*string all[9][9] = 
    {
        {"6","2"," ", " ", "5", "1", " ", " ", "7"},
        {"5","8","3", "2", " ", " ", "1", " ", "6"},
        {" "," "," ", "6", " ", "8", " ", " ", "4"},
        {"3"," ","1", "5", "8", " ", "9", " ", " "},        
        {" "," ","2", " ", "9", " ", " ", " ", "1"},
        {" "," ","5", "1", " ", "2", "7", " ", "8"},
        {" "," ","7", " ", "1", " ", "6", " ", " "},
        {"1","9"," ", "4", " ", " ", "8", " ", "3"},
        {"2"," ","8", "3", " ", "6", "4", "1", " "},
    };*/
    
    string all[9][9] = 
    {
        {"7"," "," ", " ", "2", " ", "8", "1", " "},
        {"8"," "," ", " ", " ", "6", " ", " ", "2"},
        {" ","1"," ", " ", " ", " ", " ", " ", "4"},
        {" "," ","7", "8", "1", " ", "5", " ", " "},        
        {" ","8"," ", " ", " ", " ", " ", "9", "7"},
        {" "," ","5", " ", "4", "2", "6", " ", " "},
        {"3"," "," ", " ", " ", " ", " ", "4", " "},
        {"5"," "," ", "9", " ", " ", " ", " ", " "},
        {" ","9","6", " ", "7", " ", " ", " ", "8"},
    };                           
        
    ausgabe(all);
    
    cout << "Was wollen sie tun? test/loesen"<<endl;
    string option;
    cin >> option;
    
    if(option == "test")
    {
        string eingabe;
        int sp,zei;
        cout << "Bitte Spalte eingeben:" << endl;
        cin >> sp;
        cout << "Bitte Zeile eingeben:" << endl;
        cin >> zei;
        cout << "Bitte Zahl zum einfügen eingeben:"<<endl;
        cin >> eingabe;
        if(setzbar(all,zei - 1,sp - 1,eingabe,true)){cout << "Setzbar!" << endl;}
        else{cout << "Nicht setzbar!" << endl;}
    }
    if(option == "loesen")
    {
        int durchlauf = 0;
        bool wasgefunden = true;
        while(wasgefunden)
        {
         wasgefunden = false;
         //------------------------------------------------Suche nach einzig passenden-------
         int i = 0, a = 0;
         while(i < 9) // zeile
                {   
                    a = 0;
                while(a < 9) // spalte
                {
                        string vorschlag = "99";
                        int c = 1;
                        while(c < 10) //vorschläge
                        { 
                                //int to string
                                  string cStri;
                                  ostringstream sstr;
                                  sstr << c;
                                  cStri = sstr.str();
                                  //ende string to int
                                  
                                  if(setzbar(all,i,a,cStri,false))
                                  {
                                             if(vorschlag == "99")   
                                             {vorschlag = cStri;}         
                                             else{vorschlag = "100";}
                                  }
                                  c++;       
                        }             
                        //wenn vorschlag gesetzt wurde (!= 99) und er nicht zweimal gesetzt wurde (!= 100)
                        //sudoku verändern
                        if(vorschlag != "100" && vorschlag != "99")
                        {
                            all[i][a] = vorschlag; 
                            cout << "Gefunden: " << vorschlag << " auf  Z "<< i +1 << " - S " << a+1 << endl;
                            wasgefunden = true;
                        }        
                        a++;
                }   
                i++;     
            }     
            //-----------------------------------------------------------------Ende Suche nach einzig passenden----------
            
            //----------------------------------------------------------------suche nach nötigen-----------
            
            //Code
            
            //-----------------------------------------------------------------Ende Suche nach nötigen
            
            //Ausgabe
            cout << "------------------------------ " << "Durchlauf: " << durchlauf << " ------------------------------" << endl;
            ausgabe(all);
            durchlauf++;
        }
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}
