#include "ControlID.hpp"

using namespace BrazzGUI;

int ControlID::nextID = 0;

ControlID::ControlID() : id(nextID) { nextID++; }

ControlID::ControlID(const int& i) : id(i) {}

bool ControlID::operator<(const ControlID& rhs) const { return id < rhs.id; }

bool ControlID::operator!=(const ControlID& rhs) const { return id != rhs.id; }

int ControlID::getValue() const { return id; }