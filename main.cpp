#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdio.h>

int huzz(int& osszkartyaertek);
void arcoskaryta(int kartya);
int stand(int& osztolapja);

int main() {
    srand(time(0));
    int penz = 5000, tet;
    while (true)
    {
        int kartya1 = rand() % 10 + 2, kartya2 = rand() % 10 + 2, osztolapja = rand() % 10 + 2, kivalaszt = rand() % 2;
        int splitkartya1 = 0, splitkartya2 = 0;
        if (kartya1 == 11 && kartya2 == 11) {
            kartya2 = 1;
        }
        int osszkartyaertek = kartya1 + kartya2;
        char dontes;
        std::cout << "Egyenleged: " << penz << std::endl;
        std::cout << "Tedd meg a teted" << std::endl;
        std::cin >> tet;
        if (penz < 0) {
            std::cout << "Sajnos elfogyot a penzed" << std::endl;
            return 0;
        }
        else if (tet > penz) {
            std::cout << "Sajnos nincs ennyi penzed" << std::endl;
            break;
        }
        penz -= tet;
        std::cout << "Az elso kartyad: "; arcoskaryta(kartya1);
        std::cout << "A masodik kartyad: "; arcoskaryta(kartya2);
        std::cout << "Kartyaid osszege: " << osszkartyaertek << std::endl;
        std::cout << "Az oszto lapja: "; arcoskaryta(osztolapja);
        std::cout << "Kartya huzzashoz nyomj egy (k)" << std::endl;
        std::cout << "Ha nem szeretnel kartyat huzni akkor nyomj (t)" << std::endl;
        std::cout << "Ha kiszeretnel lepni a jatekbol nyomj (x)" << std::endl;
        std::cout << "Ha duplazni szeretnel akkor nyomj (d)" << std::endl;
        if (kartya1 == kartya2) {
            std::cout << "Ha splitelni szeretnel akkor nyomj (s)" << std::endl;
        }
        if (osszkartyaertek == 21) {
            std::cout << "Gratulalok BlackJackked van nyertel" << std::endl;
            penz += tet * 2.5f;
        }
        do {
            std::cin >> dontes;
            switch (dontes) {
            case 'k':
                huzz(osszkartyaertek);
                std::cout << "Kartyaid osszege: " << osszkartyaertek << std::endl;
                break;
            case 't':
                stand(osztolapja);
                break;
            case 'd':
                penz -= tet;
                huzz(osszkartyaertek);
                std::cout << "Kartyaid osszege: " << osszkartyaertek << std::endl;
                stand(osztolapja);
                break;
            case 's':
                splitkartya1 = kartya1;
                splitkartya2 = kartya2;
                osszkartyaertek = 0;
                std::cout << "Elso kartyad erteke: " << huzz(splitkartya1) << std::endl;
                std::cout << "Masodik kartyad erteke: " << huzz(splitkartya2) << std::endl;
                stand(osztolapja);
                break;
            }
            if (osztolapja > 21) {
                if (dontes == 'd' || dontes == 's') {
                    std::cout << "Gratulalok nyertel" << std::endl << '\n';
                    penz += tet * 4;
                    break;
                }
                else if (dontes != 'd' && dontes != 's') {
                    std::cout << "Gratulalok nyertel" << std::endl << '\n';
                    penz += tet * 2;
                    break;
                }
            }
            else if (osztolapja > splitkartya1 && dontes == 's' || osztolapja > splitkartya2 && dontes == 's') {
                if (osztolapja > splitkartya1 && osztolapja > splitkartya2) {
                    std::cout << "Sajnos vesztetel" << std::endl << '\n';
                    penz -= tet;
                    break;
                }
                std::cout << "Sajnos vesztetel" << std::endl << '\n';
                break;
            }
            else if (osztolapja < splitkartya1 && dontes == 's' || osztolapja < splitkartya2 && dontes == 's') {
                if (osztolapja < splitkartya1 && osztolapja < splitkartya2) {
                    std::cout << "Gratulalok nyertel" << std::endl << '\n';
                    penz += tet * 4;
                    break;
                }
                std::cout << "Gratulalok nyertel" << std::endl << '\n';
                penz += tet * 2;
                break;
            }
            else if (osztolapja >= 17 && osztolapja < osszkartyaertek) {
                if (dontes == 'd') {
                    std::cout << "Gratulalok nyertel" << std::endl << '\n';
                    penz += tet * 4;
                    break;
                }
                else if (dontes != 'd') {
                    std::cout << "Gratulalok nyertel" << std::endl << '\n';
                    penz += tet * 2;
                    break;
                }
            }
            else if (osszkartyaertek > 21) {
                if (dontes != 'd' || dontes != 's') {
                    std::cout << "Sajnos vesztetel" << std::endl << '\n';
                    break;
                }
                std::cout << "Sajnos vesztetel" << std::endl << '\n';
                penz -= tet;
                break;
            }
            else if (osztolapja >= 17 && osztolapja > osszkartyaertek) {
                if (dontes != 'd' || dontes != 's') {
                    std::cout << "Sajnos vesztetel" << std::endl << '\n';
                    break;

                }
                std::cout << "Sajnos vesztetel" << std::endl << '\n';
                penz -= tet;
                break;
            }
            else if (osztolapja >= 17 && osszkartyaertek == osztolapja || splitkartya1 == osztolapja || splitkartya2 == osztolapja) {
                std::cout << "A kartyaitok erteke ugyan annyi szoval vissza nyered a teted" << std::endl << '\n';
                penz += tet;
                break;
            }
            if (dontes == 'x') {
                exit(3);
            }
        } while (true);
    }
    return 0;
}
int huzz(int& osszkartyaertek) {
    int randomkaryta = rand() % 10 + 2;
    if (osszkartyaertek >= 11 && randomkaryta == 11) {
        randomkaryta = 1;
    }
    osszkartyaertek += randomkaryta;
    return osszkartyaertek;
}
void arcoskaryta(int kartya) {
    int kivalaszt = rand() % 2;
    char fejeskartyak[] = { 'Q', 'K', 'J' };
    if (kartya == 10) {
        std::cout << fejeskartyak[kivalaszt] << std::endl;
    }
    if (kartya == 11) {
        std::cout << "A" << std::endl;
    }
    else {
        std::cout << kartya << std::endl;
    }
}
int stand(int& osztolapja) {
    std::cout << "Az oszto lapja: "; arcoskaryta(osztolapja);
    int i = 0;
    do {
        huzz(osztolapja);
        std::cout << osztolapja << std::endl;
        i++;
    } while (osztolapja < 17);
    return osztolapja;
}
