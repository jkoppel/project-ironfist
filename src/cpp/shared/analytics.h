#include <string>

extern const std::string gameAction;
extern const std::string mapAction;
extern const std::string analytics_open;

// Category and action describe the event sent to Google Analytics.
// Both are strings, and should be lowerCamelCase
// Example: "open", "gameAction" and "mapAction".
void send_event(const std::string &category, const std::string &action);
