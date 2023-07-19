#include "TabGroup.hpp"

#include "ControlHandling/ControlStyling.hpp"
#include "EventHandling/EventSlotting.hpp"

using namespace BrazzGUI;

TabGroup::TabGroup() : Control(ControlType::TabGroup) {
    EventHandling::connect(Event(id, EventType::RESIZED), [&](const Event& e) {
        for (auto& c : tabControls) {
            c->setX(ControlStyling::getTabAreaX(id));
            c->setY(ControlStyling::getTabAreaY(id));
            c->setWidth(ControlStyling::getTabAreaWidth(id));
            c->setHeight(ControlStyling::getTabAreaHeight(id));
        }
    });
    EventHandling::connect(
        Event(id, EventType::TAB_CHANGED), [&](const Event& e) {
            for (auto& c : tabControls) {
                ControlStyling::setVisible(c->getID(), false);
            }
            auto selectedID =
                tabControls[ControlStyling::getSelectedTabIndex(id)]->getID();
            ControlStyling::setVisible(selectedID, true);
        });
}

void TabGroup::addTab(std::string tabName, Control* tabControl) {
    ControlStyling::addTab(id, tabName);
    tabControls.push_back(tabControl);
    ControlStyling::setChild(id, tabControl->getID());
}

int TabGroup::getClientWidth() const {
    return ControlStyling::getClientWidth(id);
}

int TabGroup::getClientHeight() const {
    return ControlStyling::getClientHeight(id);
}