#include <string>

extern const std::string gameAction;
extern const std::string mapAction;
extern const std::string open;

void send_event(const std::string &category, const std::string &action);