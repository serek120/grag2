#include <iostream>
#include <cstdio>
#include "namespace.hpp"
#include "booleans.cpp"
#include <Windows.h>
#include <shellapi.h>

char buffer[256];

bool isThiren = false;
bool isHuman = false;

/*
void static ahhShitHereWeGoAgain() {
    printf("It seem's that you occuared an error while in game");
    exit(0xe00);
} 
*/

int static characterdesign2() {
    game::CS::CreateStartMEM("start", "ABCD");

    game::DelayedPrinter printer(10);
    printer.printWithDelay(" Looks like you chosed your race to be Thiren");
    printer.printWithDelay( "now you will get assigned random amount of points to each charisma, body phisuice" );

    return ERROR;
}

int static characterdesign() {
    game::DelayedPrinter printer(30);
    printer.printWithDelay("----Race you choose may unlock or block some dialogues in the game----");
    printer.printWithDelay("there are two main races dominant among humans, you can choose what race you are");
    printer.printWithDelay("Are you a \033[1;35;47m'Thiren'\033[0m");
    printer.printWithDelay("\033[1;32;47mor\033[0m");
    printer.printWithDelay("you are a \033[1;31;47m'Human'\033[0m");
    while (true) {
        printf("> :");

        

        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("Invalid input\n");
            continue;
        }

        buffer[strcspn(buffer, "\n")] = '\0';

        if (strcmp(buffer, "Thiren") == 0) {
            printer.printWithDelay("You chose Thiren");
            isThiren = true;
            game::sequence(4, 400);
            return characterdesign2();
        } else if (strcmp(buffer, "Human") == 0) {
            printer.printWithDelay("You chose Human");
            isHuman = true;
        } else {
            printf("Invalid input\n");
            continue;
        }


    }
    return 0x1;
    
}

int main() {

    ShowEQ();


   /* if (!CheckFileAndContinueToNextPhase("start.jfif", "ABCD"))
        game::CS::CreateStartMEM("start", "ABCD");
    else if (CheckFileAndContinueToNextPhase("start.jfif", "ABCD"))
        ahhShitHereWeGoAgain();

    game::showMessageBox("siema", "siema");
    */
    game::DelayedPrinter printer(1);
    printer.printWithDelay("Welcome to the game \033[1;32;41m`I still haven't named it`\033[0m, it is a text-based RPG written on the so-called \033[35m`knee`\033[0m");
    printer.printWithDelay("Type \033[1;32;41m`Start`\033[0m with a capital letter to start the game\nor \033[1;32;41m`Exit`\033[0m also with a capital letter to exit the game");
    

    while (true) {
        printf("> :");

        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("Invalid input.\n");
            continue;
        }

        buffer[strcspn(buffer, "\n")] = '\0';

        if (strcmp(buffer, "Start") == 0) {
            game::sequence(1, 400);
            return characterdesign();
        } else if (strcmp(buffer, "Exit") == 0) {
            break;
        } else if (strcmp(buffer, "ellen joe") == 0) {
            game::sequence(3, 100);
            game::DelayedPrinter printer(700);
            printer.printWithDelay("You discovered an easter egg.");
            system("start https://i.imgur.com/LlgUaHi.jpeg");
            auto criterror = [] () { game::criterr("error", "error"); };
            std::thread criterrorThread(criterror);
            criterrorThread.join();
            std::exit(0x000202);
        } else {
            printf("Invalid input. Please type 'Start' or 'Exit'.\n");
        }
    }

    return 0;
}
