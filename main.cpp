#include <iostream>
#include "voisinage.h"
#include "etat.h"
#include <fstream>
#include <string>


class Cellule {
public:

    Case coordonne;
    Etat etat;

    Cellule() {
       coordonne = Case(0,0);
       etat = Etat();
       //etat.l_etat_possible[0] = "mort";
       //etat.l_etat_possible[1] = "vivant";


    }
    explicit Cellule(Etat e) : etat(e), coordonne(0,0) {


    }


};



int main() {

    int cpt =5;

    Cellule reseau[10][10];
    string l_etat[] = {"mort","vivant","test","", ""};
    //cout << l_etat[2]<<endl;
    int i = 0;
    while (!l_etat[i].empty()) {
        //cout <<"ok" <<endl;
        i++;
    }
    int nb_etat = 3;
    string* list_etat= new string[10]();


    ifstream fichier("D:/LO21/testLifeGame/test.txt");
    string ligne;


    Voisinage voisi;



    if (fichier){
        fichier >> nb_etat;
        cout << nb_etat <<endl;

        for (int i = 0;i <nb_etat; i++) {
            fichier >> ligne;
            list_etat[i] = ligne;
        }

        for (int i = 0;i <nb_etat; i++) {
            cout << list_etat[i] <<endl;
        }


        getline(fichier,ligne);
        getline(fichier,ligne);
        int x_centre = 4, y_centre = 4;

        int cpt=0;

        for (int i =0; i<9 ; i++) {
            getline(fichier,ligne);


            for (int j = 0; j<9; j++) {
                //cout << ligne[j] -47 <<endl;

                if (ligne[j] - 48  == 1){
                    cout << i-x_centre <<" " <<j-y_centre <<endl;
                    voisi.ensemble_case[cpt].setX(i-x_centre);
                    voisi.ensemble_case[cpt].setY(j-y_centre);
                    cpt ++;

                }
            }
        }

        voisi.setNbCellule(cpt + 1);





    }
    else
        cout << " erreur" <<endl;


    fichier.close();

    Etat etat_base;
    etat_base.defListEtat(list_etat);

    for (int i = 0; i<10 ; i++) {
        for (int j = 0; j<10 ; j++) {
            reseau[i][j].etat = etat_base;
        }
    }

    //cout << etat_base.l_etat_possible[1];


    for (int i = 0; i<10 ; i++) {
        for (int j = 0; j<10 ; j++) {

            //reseau[i][j].etat.defListEtat(l_etat);

            reseau[i][j].coordonne.setX(i);
            reseau[i][j].coordonne.setY(j);
            //reseau[i][j].etat.defListEtat(l_etat);

            //cout <<  reseau[i][j].etat.l_etat_possible[0] << "  " <<  reseau[i][j].etat.l_etat_possible[1] << endl;

            if (i%3==0){

                reseau[i][j].etat.setEtat("vivant");
                cpt --;
            }
            else {
                reseau[i][j].etat.setEtat("mort");
                //cpt =5;

            }




        }
    }



    for (int i = 0; i<10 ; i++) {
        for (int j = 0; j<10 ; j++) {


            if (reseau[i][j].etat.getEtat() == "vivant"){

                cout << "1";
            }
            else {
                cout <<"0";
            }


        }
        cout <<endl;
    }





    //Case test[3];

    //test[0].setX(2);

    /*
    Voisinage voisi;
    voisi.i = 0;
    //printf("%d\n\n",voisi.ensemble_case[1]);

    //voisi.ensemble_case[0] = new Case();

    voisi.ensemble_case[0].setX(-1);
    voisi.ensemble_case[0].setY(-1);

    voisi.ensemble_case[1].setX(-1);
    voisi.ensemble_case[1].setY(0);

    voisi.ensemble_case[2].setX(-1);
    voisi.ensemble_case[2].setY(1);

    voisi.ensemble_case[3].setX(0);
    voisi.ensemble_case[3].setY(-1);

    voisi.ensemble_case[4].setX(0);
    voisi.ensemble_case[4].setY(1);

    voisi.ensemble_case[5].setX(1);
    voisi.ensemble_case[5].setY(-1);

    voisi.ensemble_case[6].setX(1);
    voisi.ensemble_case[6].setY(0);

    voisi.ensemble_case[7].setX(1);
    voisi.ensemble_case[7].setY(1);


    voisi.setNbCellule(8);

    */

    int nb_vivant_tab[10][10];


    while (1) {
        for (int i = 0; i<10 ; i++) {
            for (int j = 0; j<10 ; j++) {

                int nb_vivant = 0;

                for (int k =0; k <voisi.getNbCelluleVoisi(); k++) {



                    int xtest, ytest;
                    if (j == 0 && voisi.ensemble_case[k].gety() <0) {
                        ytest = 9;
                    }
                    else if (j == 9 && voisi.ensemble_case[k].gety() >0) {
                        ytest = 0;
                    }
                    else {
                        ytest = j+voisi.ensemble_case[k].gety();
                    }

                    if (i == 0 && voisi.ensemble_case[k].getX() <0) {
                        xtest = 9;
                    }
                    else if (i == 9 && voisi.ensemble_case[k].getX() >0) {
                        xtest = 0;
                    }
                    else {
                        xtest = i+voisi.ensemble_case[k].getX();
                    }





                    if (reseau[xtest][ytest].etat.getEtat() == "vivant"){
                        nb_vivant ++;
                        //cout << "vivant co : " << xtest << "-" << ytest <<endl;

                    }

                }
                //cout << "nb vivant case "<< i << "-" << j << " : " << nb_vivant << endl << endl;
                nb_vivant_tab[i][j] = nb_vivant;
            }
        }
        cout <<endl;

        for (int i = 0; i<10 ; i++) {
            for (int j = 0; j<10 ; j++) {
                if (reseau[i][j].etat.getEtat() == "mort" && nb_vivant_tab[i][j] == 3){
                    reseau[i][j].etat.setEtat("vivant");
                    //cout << "nait" << endl;
                }
                if (reseau[i][j].etat.getEtat() == "vivant" && (nb_vivant_tab[i][j] == 3 || nb_vivant_tab[i][j] == 2) ){
                    reseau[i][j].etat.setEtat("vivant");
                    //cout <<"survit" << endl;
                }
                else {
                    reseau[i][j].etat.setEtat("mort");
                    //cout << "mourut" <<endl;
                }


            }
        }




        int tmp;


        for (int i = 0; i<10 ; i++) {
            for (int j = 0; j<10 ; j++) {


                if (reseau[i][j].etat.getEtat() == "vivant"){

                    cout << "1";
                }
                else {
                    cout <<"0";
                }


            }
            cout <<endl;
        }
        cout <<endl;

        cin >> tmp;
        if (tmp == 1){
            break;
        }
    }


//*/






    return 0;
}
