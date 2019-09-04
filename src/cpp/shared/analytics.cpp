#include <WinSock2.h>

#include "Poco/Net/HTTPClientSession.h"
#include "Poco/Net/HTTPRequest.h"
#include "Poco/URI.h"
#include "Poco/UUID.h"
#include "Poco/UUIDGenerator.h"

#include "analytics.h"
#include "base.h"
#include "prefs.h"

extern const std::string gameAction = "gameAction";
extern const std::string mapAction = "mapAction";
extern const std::string analytics_open = "open";

static const std::string IRONFIST_TRACKER_ID("UA-24357556-4");
static bool analyticsEnabled = true;
static bool analyticsInitialized = false;
static const std::string registryPref = "IronfistAnalyticsEnabled";

void AnalyticsInit() {
  int res = read_pref<DWORD>(registryPref);
  if (res == -1) { // no key in registry
    analyticsEnabled = true;
    write_pref<DWORD>(registryPref, 1);
  } else {
    analyticsEnabled = res;
  }
  analyticsInitialized = true;
}

const std::string createOrGetUuid() {
  std::string uuid;
  bool getUuid = read_pref<std::string>("Uuid", uuid);
  if (!getUuid) {
    Poco::UUID pocoUuid = Poco::UUIDGenerator().create();
    uuid = pocoUuid.toString();
    bool setUuid = write_pref("Uuid", uuid);
  }
  return uuid;
}

void send_event_with_internet(const std::string &category, const std::string &action) {
  static const std::string uuid = createOrGetUuid();
  Poco::Net::HTTPClientSession session("www.google-analytics.com");
  Poco::Net::HTTPRequest req(Poco::Net::HTTPRequest::HTTP_POST, "/collect", Poco::Net::HTTPMessage::HTTP_1_1);
  Poco::URI uri("");
  uri.addQueryParameter("v", "1");
  uri.addQueryParameter("tid", IRONFIST_TRACKER_ID);
  uri.addQueryParameter("cid", uuid);
  uri.addQueryParameter("t", "event");
  uri.addQueryParameter("an", "Ironfist");
  uri.addQueryParameter("ec", category);
  uri.addQueryParameter("ea", action);
  uri.addQueryParameter("el", uuid);
  req.setContentLength(uri.getRawQuery().length());
  session.sendRequest(req) << uri.getRawQuery();
}

void send_event(const std::string &category, const std::string &action) {
  if (!analyticsInitialized) {
    AnalyticsInit();
  }
  if (analyticsEnabled) {
    try {
      send_event_with_internet(category, action);
    }
    catch (...) { // no internet
      analyticsEnabled = false;
    }
  }
}