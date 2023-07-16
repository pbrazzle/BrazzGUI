#ifndef FONT
#define FONT

namespace BrazzGUI {
/**
 * Fonts contain all style information about a Controls text
 */
class Font {
    private:
    int size;

    public:
    /**
     * Creates a default Font
     */
    Font() = default;

    /**
     * Creates a Font with a given size
     *
     * @param size Size for this Font
     */
    Font(const int& size);

    /**
     * Returns the size of this Font
     *
     * @return Size of this Font
     */
    int getSize() const;

    /**
     * Sets a new size for this Font
     *
     * @param size New size for this Font
     */
    void setSize(const int& size);
};
} // namespace BrazzGUI

#endif