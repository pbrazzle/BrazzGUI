#ifndef BRAZZGUI_FILESELECTDIALOG
#define BRAZZGUI_FILESELECTDIALOG

#include <filesystem>

namespace BrazzGUI
{

/*
*   TODO document this class
*/
class FileSelectDialog
{
    public:
        FileSelectDialog() = default;

        /*
        *   TODO document this function
        */
        std::filesystem::path show();
};

}

#endif