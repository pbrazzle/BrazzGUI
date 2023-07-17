#include "DialogHandling/DialogHandling.hpp"

#include <cstring>
#include <windows.h>

using namespace BrazzGUI;

bool DialogHandling::showOKCancel(std::string& title, std::string& message) {
    auto result = MessageBox(NULL, message.c_str(), title.c_str(), MB_OKCANCEL);
    return result == IDOK;
}

std::filesystem::path DialogHandling::showFileSave() {
    OPENFILENAME data;
    std::memset(&data, 0, sizeof(OPENFILENAME));
    data.lStructSize = sizeof(OPENFILENAME);
    char* buf = new char[1024];
    data.lpstrFile = buf;
    data.nMaxFile = 1024;
    data.Flags = OFN_ENABLESIZING | OFN_EXPLORER;

    auto result = GetSaveFileName(&data);

    if (result == 0) return std::filesystem::path();
    std::string filename(data.lpstrFile);
    delete[] buf;

    return std::filesystem::path(filename);
}

std::filesystem::path DialogHandling::showFileOpen() {
    OPENFILENAME data;
    std::memset(&data, 0, sizeof(OPENFILENAME));
    data.lStructSize = sizeof(OPENFILENAME);
    char* buf = new char[1024];
    data.lpstrFile = buf;
    data.nMaxFile = 1024;
    data.Flags = OFN_ENABLESIZING | OFN_EXPLORER | OFN_FILEMUSTEXIST;

    auto result = GetOpenFileName(&data);

    if (result == 0) return std::filesystem::path();
    std::string filename(data.lpstrFile);
    delete[] buf;

    return std::filesystem::path(filename);
}