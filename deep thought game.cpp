#include<iostream>
#include<windows.h>

using namespace std;

int main(){

    int choiceMain;
    int days = 30;
    int tempCount;
    string garbage;
    srand(time(0));

    int answerCount = 0;
    int answerCompletion = 0;
    int answerCost = 2;
    int unitsUsedAnswer = 0;
    bool answerInProgess = false;

    int upgradeChoice;

    int processingCost = 1;
    int processingCount = 0;
    int unitsUsedProcessing = 0;
    bool upgradeProcessing = false;

    bool upgradeHardware = false;
    int hardwareCost = 1;
    int unitsUsedHardware = 0;
    int hardwareCount = 0;
    int hardwareLevel = 0;

    int repairCost = 2;
    int repairCount = 0;
    int unitsUsedRepair = 0;
    bool repair = false;

    int abortChoice = 0;

    int countUnit;
    int units = 5;
    int unitsTotal = 5; 
    int tempUnits = 0;
    int unitsLost = 0;

    int overloadFailure = 4;
    int randNum = 0;
    bool lastUnitMessage = false;
    bool zeroUnitMessage = false;

    bool keepPlayingMessage = false;
    char keepPlaying = 'y';

    do { //main game loop
        do { //turn loop
            //actions & in progress displays
            cout << "-----------------\t\t\t\t\t\t-----------------";
            cout << "\nActions:\t\t\t\t\t\t\tIn Progress:";

            //answer
            if (answerInProgess == false) {
                cout << "\n1. Calculate Part of the Answer ";
                for (int count = 0; count < answerCost; count++){
                    cout << "[-]";
                }
            } else {
                cout << "\n\t\t\t\t\t\t\t        1. Calculate Part of the Answer ";
                tempCount = answerCount;
                for (int count = 0; count < answerCost; count++) {
                    cout << "[";
                    if (tempCount > 0) {
                        cout << "X";
                    } else {
                        cout << "-";
                    }
                    cout << "]";
                    tempCount--;
                }
            }

            //upgrade
            cout << "\n2. Upgrade Systems";
            if (upgradeProcessing == true) {
                cout << "\t\t\t\t\t\t2. Upgrade Processing ";
                tempCount = processingCount;
                for (int count = 0; count < processingCost; count++) {
                    cout << "[";
                    if (tempCount > 0) {
                        cout << "X";
                    } else {
                        cout << "-";
                    }
                    cout << "]";
                    tempCount--;
                }
            }

            //overload
            if (unitsTotal > 0) {
                cout << "\n3. Overload";
                if ((overloadFailure - 20*hardwareLevel) > 0 && (overloadFailure - 20*hardwareLevel) < 100) {
                    if ((overloadFailure - 20*hardwareLevel) < 10) {
                        cout << " ";
                    }
                    cout << "   (Chance of Failure: " << overloadFailure - 20*hardwareLevel + 1 << "%)";
                } else if ((overloadFailure - 20*hardwareLevel) >= 100) {
                    cout << "   (Chance of Failure: 100%)";
                } else {
                    cout << "    (Chance of Failure: 0%)";
                }
            }

            //upgrade
            if (unitsTotal == 0) {
                cout << "\n\t\t\t\t";
            }
            if (upgradeHardware == true) {
                cout << "\t\t\t\t3. Upgrade Hardware ";
                tempCount = hardwareCount;
                for (int x = 0; x < hardwareCount; x++) {
                    cout << "[";
                    if (tempCount > 0) {
                        cout << "X";
                    } else {
                        cout << "-";
                    }
                    cout << "]";
                    tempCount--;
                }
            }

            //repair
            if (repair == false) {
                cout << "\n4. Repair\t\t\t";
                for (int count = 0; count < repairCost; count++){
                    cout << "[-]";
                }
            } else {
                cout << "\n\t\t\t\t\t\t\t\t4. Repair ";
                tempCount = repairCount;
                for (int count = 0; count < repairCost; count++) {
                    cout << "[";
                    if (tempCount > 0) {
                        cout << "X";
                    } else {
                        cout << "-";
                    }
                    cout << "]";
                    tempCount--;
                }
            }

            cout << "\n5. Abort Programs\t\t\t\t\t\t-----------------";
            cout << "\n6. End Day";
            cout << "\n0. Quit Game";
            cout << "\n-----------------\t\t\t\t\t\t-----------------";
            //end action & progress displays

            //timer display
            cout << "\nDays Until Destruction: " << days;

            //answer display
            if (answerCompletion == 0) {
                cout << "\t\t\t\t\tThe Answer: [-][-][-][-][-][-]";
            } else if (answerCompletion == 1) {
                cout << "\t\t\t\t\tThe Answer: [1][-][-][-][-][-]";
            } else if (answerCompletion == 2) {
                cout << "\t\t\t\t\tThe Answer: [1][0][-][-][-][-]";
            } else if (answerCompletion == 3) {
                cout << "\t\t\t\t\tThe Answer: [1][0][1][-][-][-]";
            } else if (answerCompletion == 4) {
                cout << "\t\t\t\t\tThe Answer: [1][0][1][0][-][-]";
            } else if (answerCompletion == 5) {
                cout << "\t\t\t\t\tThe Answer: [1][0][1][0][1][-]";
            }
            //end answer display

            cout << "\n-----------------\t\t\t\t\t\t-----------------";
            cout << "\nUnits:";
            cout << "\n";

            //begin unit display
            //ADD LATER: temp units display as Y instead of X
            countUnit = units + tempUnits;
            for (int count = 0; count < unitsTotal; count++) {
                cout << "[";
                if (countUnit > 0) {
                    cout << "X";
                } else {
                    cout << "-";
                }
                cout << "]";
                if ((count % 9) == 0 && count != 0 && count < (unitsTotal-1) && count != 1) {
                    cout << "\n";
                }
                countUnit--;
            }
            if (countUnit > 0) {
                for (countUnit = countUnit; countUnit > 0; countUnit--) {
                    cout << " X";
                }
            }
            cout << "\n(Available Units: " << units + tempUnits << ")";
            cout << "\n(Units Lost: " << unitsLost << ")";
            //end unit display

            cout << "\n-----------------";

            cout << "\nWhat is your choice:";

            //begin error trap   
            if (!cin.good()) { 
                cin.clear(); 
                string garbage;
                cin >> garbage;
            }
            cin >> choiceMain;

            //cheat code
            if (choiceMain == 123) {
                units += 20;
                unitsTotal += 20;
            }
            if (choiceMain > 6 || choiceMain < 0 || !cin.good()) {
                system("cls");
            }

        } while (choiceMain > 6 || choiceMain < 0 || !cin.good());
        //end error trap

        //begin choices
        if (choiceMain == 1) {
            //calculate answer
            if (answerInProgess == false && (units + tempUnits) >= answerCost) {
                answerCount = answerCost;
                unitsUsedAnswer = 0;
                if (tempUnits > 0) {
                    tempUnits -= answerCost;
                    if (tempUnits < 0) {
                        unitsUsedAnswer = -tempUnits;
                        units += tempUnits;
                        tempUnits = 0;
                    }
                } else {
                    units -= answerCost;
                    unitsUsedAnswer = answerCost;
                }
                answerInProgess = true;
            }
        } else if (choiceMain == 2) {
            //upgrade systems
            do {
                do {//upgrade error trap and input loop
                    system("cls");
                    cout << "Available Upgrades:";
                    cout << "\n-----------------";
                    cout << "\n";
                    if (upgradeProcessing == false) {
                        cout << "1. Upgrade Processing ";
                        for (int count = 0; count < processingCost; count++) {
                            cout << "[-]";
                        }
                    }
                    cout << "\n";
                    if (upgradeHardware == false) {
                        cout << "2. Upgrade Hardware ";
                        for (int count = 0; count < hardwareCost; count++) {
                            cout << "[-]";
                        }
                    }
                    cout << "\n-----------------";
                    cout << "\n0. Exit Menu";
                    cout << "\nWhat is you choice:";

                    if (!cin.good()) { 
                        cin.clear(); 
                        string garbage;
                        cin >> garbage;
                    }
                    cin >> upgradeChoice;

                } while (upgradeChoice > 2 || upgradeChoice < 0 || !cin.good());
                //end upgrade error trap and input

                if (upgradeChoice == 1) {
                    //upgrade processing 
                   if (upgradeProcessing == false && (units + tempUnits) >= processingCost) {
                        processingCount = processingCost;
                        unitsUsedProcessing = 0;
                        if (tempUnits > 0) {
                            tempUnits -= processingCost;
                            if (tempUnits < 0) {
                                unitsUsedProcessing = -tempUnits;
                                units += tempUnits;
                                tempUnits = 0;
                            }
                        } else {
                            units -= processingCost;
                            unitsUsedProcessing = processingCost;
                        }
                        upgradeProcessing = true;
                    }
                } else  if (upgradeChoice == 2) {
                    
                    if (upgradeHardware == false && (units + tempUnits) >= hardwareCost) {
                        hardwareCount = hardwareCost;
                        unitsUsedHardware = 0;
                        if (tempUnits > 0) {
                            tempUnits -= hardwareCost;
                            if (tempUnits < 0) {
                                unitsUsedHardware = -tempUnits;
                                units += tempUnits;
                                tempUnits = 0;
                            }
                        } else {
                            units -= hardwareCost;
                            unitsUsedHardware = hardwareCost;
                        }
                        upgradeHardware = true;
                    }

                }
            } while (upgradeChoice != 0);

        } else if (choiceMain == 3) {
            //overload
            if (unitsTotal > 0) {
                tempUnits++;
                randNum = rand() % 100 + 20*hardwareLevel;
                if (unitsTotal == 1 && randNum >= overloadFailure && lastUnitMessage == false) {
                    system("cls");
                    cout << "Gambling with your last unit makes you feel nervous... as nervous as a supercomputer can feel anyways.\n\n\n";
                    system("pause");
                    lastUnitMessage = true;
                } else if (randNum < overloadFailure) {
                    unitsTotal--;
                    unitsLost++;
                    system("cls");
                    cout << "Overload has caused damage and you lost a unit...\n\n\n";
                    system("pause");
                }
                overloadFailure += 5;
            }
            if (unitsTotal == 0 && zeroUnitMessage == false) {
                system("cls");
                cout << "Wow, you have zero permanent units. Hope you have a plan.\n\n\n";
                system("pause");
                zeroUnitMessage = true;
            }

        } else if (choiceMain == 4) {
            //repair
            if (repair == false && (units + tempUnits) >= repairCost) {
                repairCount = repairCost;
                unitsUsedRepair = 0;
                if (tempUnits > 0) {
                    tempUnits -= repairCost;
                    if (tempUnits < 0) {
                        unitsUsedRepair = -tempUnits;
                        units += tempUnits;
                        tempUnits = 0;
                    }
                } else {
                    units -= repairCost;
                    unitsUsedRepair = repairCost;
                }
                repair = true;
            }
        } else if (choiceMain == 5) {
            //abort
            do {
                system("cls");
                cout << "-----------------";

                cout << "\n";
                if (answerInProgess == true) {
                    cout << "1. Calculate Part of the Answer ";
                    tempCount = answerCount;
                    for (int count = 0; count < answerCost; count++) {
                        cout << "[";
                        if (tempCount > 0) {
                            cout << "X";
                        } else {
                            cout << "-";
                        }
                        cout << "]";
                        tempCount--;
                    }
                }

                cout << "\n";
                if (upgradeProcessing == true) {
                    cout << "2. Upgrade Processing ";
                    tempCount = processingCount;
                    for (int count = 0; count < processingCost; count++) {
                        cout << "[";
                        if (tempCount > 0) {
                            cout << "X";
                        } else {
                            cout << "-";
                        }
                        cout << "]";
                        tempCount--;
                    }
                }

                cout << "\n";
                if (upgradeHardware == true) {
                    cout << "3. Upgrade Hardware ";
                    tempCount = hardwareCount;
                    for (int x = 0; x < hardwareCount; x++) {
                        cout << "[";
                        if (tempCount > 0) {
                            cout << "X";
                        } else {
                            cout << "-";
                        }
                        cout << "]";
                        tempCount--;
                    }
                }

                cout << "\n";
                if (repair == true) {
                    cout << "4. Repair ";
                    tempCount = repairCount;
                    for (int count = 0; count < repairCost; count++) {
                        cout << "[";
                        if (tempCount > 0) {
                            cout << "X";
                        } else {
                            cout << "-";
                        }
                        cout << "]";
                        tempCount--;
                    }
                }

                cout << "-----------------";
                cout << "\n0. Exit Menu";

            } while (abortChoice != 0);

        } else {
            //end day
            days --;

            //answer progression
            if (answerInProgess == true) {
                answerCount--;
                if (answerCount == 0) {
                    units += unitsUsedAnswer;
                    answerCompletion++;
                    answerCost++;
                    answerInProgess = false;
                }
            }

            //upgrade processing 
            if (upgradeProcessing == true) {
                processingCount--;
                if (processingCount == 0){
                    units += unitsUsedProcessing + 1;
                    processingCost++;
                    unitsTotal++;
                    upgradeProcessing = false;
                }
            }

            //upgrade hardware
             if (upgradeHardware == true) {
                hardwareCount--;
                if (hardwareCount == 0){
                    units += unitsUsedHardware;
                    hardwareCost++;
                    upgradeHardware = false;
                    hardwareLevel++;
                }
            }

            //repair
            if (repair == true) {
                repairCount--;
                if (repairCount == 0){
                    unitsTotal += unitsLost;
                    units += unitsUsedRepair + unitsLost;
                    repairCost++;
                    unitsLost = 0;
                    overloadFailure = 4;
                    repair = false;
                }
            }

            //get rid of temporary unit gained through overload
            tempUnits = 0;

            //if lost permanent unit slot to overload, gets rid of excess units
            if (units > unitsTotal) {
                units = unitsTotal;
            }
        }
        system("cls");

        if (units == 0 && tempUnits == 0 && unitsTotal == 0 && keepPlayingMessage == false) {
            do {
                cout << "You have no units in any way, shape, or form. The only hope of winning at this point is if the last part of The Answer is being calculated.";

                if (cin.good() == false) {
                    cin.clear();
                    cin >> garbage;
                }
                cout << "\n\nWould you like to keep playing (y/n):";
                cin >> keepPlaying;

            } while ((keepPlaying != 'y' && keepPlaying != 'n') || !cin.good());
            if (keepPlaying == 'n') {
                choiceMain = 0;
            }
            keepPlayingMessage = true;
            system("cls");
        }

    } while (choiceMain != 0 && days > -1 && answerCompletion < 6); //end main game loop
    return 0;
}
