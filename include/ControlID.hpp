#ifndef CONTROL_ID
#define CONTROL_ID

namespace BrazzGUI {
/**
 * TODO document this class
 */
class ControlID {
    private:
    int id;

    public:
    /**
     * TODO document this function
     */
    ControlID(const int&);

    /**
     * TODO document this function
     */
    bool operator<(const ControlID& rhs) const;

    /**
     * TODO document this function
     */
    bool operator!=(const ControlID& rhs) const;

    /**
     * TODO document this function
     */
    int getValue() const;
};
} // namespace BrazzGUI

#endif