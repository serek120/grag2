#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include <chrono>
#include <thread>
#include <cstdio>
#include <ctime>
#include <iostream>
#include <fstream>
#include <filesystem>


extern bool isThiren;
extern bool isHuman;

namespace game {
    class DelayedPrinter {
    public:
        explicit DelayedPrinter(int delay_ms)
            : delay_ms_(delay_ms) {
        }
        void printWithDelay(const char* text) const {
            for (const char* c = text; *c != '\0'; ++c) {
                std::printf("%c", *c);
                std::fflush(stdout);
                std::this_thread::sleep_for(std::chrono::milliseconds(delay_ms_));
            }
            std::printf("\n");
        }
    private:
        int delay_ms_;
    };
		// this function will make a fake loading not needed but i think we will confuse some palyer's
    void loading(int czas) {
        const int krok = 200;
        int ilosc_krokow = (czas * 1000) / krok;
        const char animacja[] = {'|', '/', '-', '\\'};
        int anim_index = 0;

        std::cout << "\033[1;31mLoading: \033[0m" << std::flush;
        for (int i = 0; i < ilosc_krokow; i++) {
            std::cout << "\b" << animacja [anim_index] << std::flush;
            anim_index = (anim_index + 1) % 4;
            std::this_thread::sleep_for(std::chrono::milliseconds(krok));
        }
        std::cout << "\033[1;32mDone\033[0m" << std::endl;
    }

    void cls(int delay) {
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        system("cls");
    }

    void sleep_for(int delay_ms_) {
        std::this_thread::sleep_for(std::chrono::milliseconds(delay_ms_));
    }

    void sequence(int time, int time2) {
        game::cls(time2);
        game::loading(time);
        game::cls(time2);
    }

    #include <Windows.h>

    std::wstring convertToWideString(const char* narrowStr) {
        int len = MultiByteToWideChar(CP_UTF8, 0, narrowStr, -1, NULL, 0);
        std::wstring wideStr(len, 0);
        MultiByteToWideChar(CP_UTF8, 0, narrowStr, -1, &wideStr [0], len);
        return wideStr;
    }

    void showMessageBox(const char* title, const char* message) {
        std::thread([title, message]() {
            std::wstring wTitle = convertToWideString(title);
            std::wstring wMessage = convertToWideString(message);

            while (true) {
                int response = MessageBox(NULL, wMessage.c_str(), wTitle.c_str(), MB_OKCANCEL | MB_ICONWARNING);
                if (response == IDCANCEL || response == IDOK) {
                    break;
                }

            }
            }).join();
    }

					// makes a file and opens its  for scarying the player
    void scaryfile(const std::string& filename, const std::string& filecontent) {
        std::string filepath = std::filesystem::current_path().string() + "/" + filename + ".txt";
        std::ofstream file(filepath);

        if (file.is_open()) {
            file << filecontent;
            file.close();
        }
        else {
            std::cerr << "Failed to create file: " << filepath << std::endl;
        }
    }

    // Function to open the file based on the OS
    void openFile(const std::string& filename) {
        std::string filepath = std::filesystem::current_path().string() + "/" + filename + ".txt";

#ifdef _WIN32
        ShellExecuteA(NULL, "open", filepath.c_str(), NULL, NULL, SW_SHOWNORMAL);
#else
        std::string command = "xdg-open " + filepath + " &";
        system(command.c_str());
#endif
    }
	// Showing fake UAC prompt (for some purpose is needed there)
    void showFakeUAC() {
        SHELLEXECUTEINFO sei = { sizeof(sei) };
        sei.lpVerb = L"runas";  // Requests admin rights
        sei.lpFile = L"cmd.exe"; // Fake command
        sei.hwnd = NULL;
        sei.nShow = SW_HIDE;  // Hide the actual window

        if (!ShellExecuteEx(&sei)) {
            std::cerr << "Failed to create UAC prompt!" << std::endl;
            exit(ERROR_CREATE_FAILED);
        }
    }

    void criterr(const char* title, const char* message) {
        std::wstring wTitle = convertToWideString(title);
        std::wstring wMessage = convertToWideString(message);
      //  HWND hWnd = GetConsoleWindow();
        MessageBeep(MB_ICONERROR);
        MessageBox(NULL, wMessage.c_str(), wTitle.c_str(), MB_OKCANCEL | MB_ICONERROR);

    }

    // ( Namespace game::Thrd:: ... )

    namespace Thrd {
        void pissingofplayer(const char* title, const char* message) {
            auto criterror = [title, message]() { game::criterr(title, message); };
            std::thread criterrorThread(criterror);
            criterrorThread.join();
        }

    } // End of namespace Tthrd

    namespace CS {
        void CreateStartMEM(const std::string& Filename, const std::string Exp_Phrase) {
            std::ofstream File(Filename);
            File << Exp_Phrase;
            File.close();
        }


    }
} // End of namespace game

#endif // GAME_HPP
