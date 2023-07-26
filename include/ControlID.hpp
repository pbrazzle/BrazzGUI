#ifndef CONTROL_ID
#define CONTROL_ID

namespace BrazzGUI {
/**
 * Each Control has a unique ControlID value
 * This value is used to link Events to the relevant Control
 */
class ControlID {
    private:
    // ID value for the ControlID
    int id;

    static int nextID;

    public:
    ControlID();

    /**
     * Creates a ControlID
     *
     * @param id Value for the ID
     */
    ControlID(const int& id);

    /**
     * Less than operator for ControlIDs
     *
     * @param rhs ControlID to compare to
     * @return false if this ControlIDs value is less than rhs's value, true
     * otherwise
     */
    bool operator<(const ControlID& rhs) const;

    /**
     * Inequality operator for ControlIDs
     *
     * @param rhs ControlID to compare to
     * @return true if both ControlIDs have the same value, false otherwise
     */
    bool operator!=(const ControlID& rhs) const;

    /**
     * Gets for ID value for this ControlID
     *
     * @return Value of this ControlID
     */
    int getValue() const;
};
} // namespace BrazzGUI

#endif