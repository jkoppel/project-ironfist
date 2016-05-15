#include <string>

extern const std::string gameAction;
extern const std::string mapAction;
extern const std::string open;

// Category and action describe the event sent to Google Analytics.
// Both are strings, should be lower case, except for compound names,
// for which "interior names" should start with an upper case.
// Example: "open", "gameAction" and "mapAction".
void send_event(const std::string &category, const std::string &action);